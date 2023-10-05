#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <iostream>
#include <stdexcept>

#include "X11RootWindow.hpp"

namespace wxp
{
	X11RootWindow::X11RootWindow(int screen_number)
	{
		_display = XOpenDisplay(":0");
		if (_display == nullptr)
		{
			throw std::runtime_error("Unable to open the X11 display.");
		}
		XSetCloseDownMode(_display, RetainPermanent); //Do not automatically destroy the pixmap when the application is closed.

		//TODO: find a way to check if errors occurred
		_screen = XScreenOfDisplay(_display, screen_number);
		_window = XRootWindow(_display, screen_number); //we can use screen->root instead
		_pixmap = XCreatePixmap(_display, _window, _screen->width, _screen->height, _screen->root_depth);
	}

	X11RootWindow::~X11RootWindow()
	{
		//DO NOT CALL XFREEPIXMAP ! If the pixmap is destroyed, other applications won't be able to fetch it
		XCloseDisplay(_display);
	}

	void X11RootWindow::setBackground(const Image& image)
	{
		//TODO: check if it succeeded
		cairo_surface_t *pixmap_surface = cairo_xlib_surface_create(_display, _pixmap, _screen->root_visual, image.width, image.height);
		cairo_surface_t *image_surface = cairo_image_surface_create_for_data(image.pixels, CAIRO_FORMAT_RGB24, image.width, image.height, image.width * 4);
		cairo_t *pixmap_context = cairo_create(pixmap_surface);

		cairo_set_source_surface(pixmap_context, image_surface, 0., 0.);
		cairo_paint(pixmap_context);
		cairo_surface_flush(pixmap_surface);

		updateWindowProperties();

		XSetWindowBackgroundPixmap(_display, _window, _pixmap);
		XClearWindow(_display, _window);
		XFlush(_display);

		cairo_destroy(pixmap_context);
		cairo_surface_destroy(image_surface);
		//cairo_surface_destroy(pixmap_surface);
	}

	void X11RootWindow::updateWindowProperties()
	{
		//Is it really necessary to do that after the first update since it will be the same pixmap ? alloc'd in the ctor
		//TODO: check the results of these calls

		Atom xrootpmap_id = XInternAtom(_display, "_XROOTPMAP_ID", True);
		Atom esetroot_pmap_id = XInternAtom(_display, "ESETROOT_PMAP_ID", True);

		//should we kill the client that owns the current pixmap, as hsetroot does ?
		//https://github.com/himdel/hsetroot/blob/master/hsetroot.c#L87

		XChangeProperty(_display, _window, xrootpmap_id, XA_PIXMAP, 32, PropModeReplace, reinterpret_cast<unsigned char*>(&_pixmap), 1);
		XChangeProperty(_display, _window, esetroot_pmap_id, XA_PIXMAP, 32, PropModeReplace, reinterpret_cast<unsigned char*>(&_pixmap), 1);
	}
}