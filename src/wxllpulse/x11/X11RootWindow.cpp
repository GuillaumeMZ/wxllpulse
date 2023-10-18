#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <stdexcept>

#include "X11RootWindow.hpp"

namespace wxp
{
	X11RootWindow::X11RootWindow(int screen_number)
	{
		_display = XOpenDisplay(nullptr);
		if (_display == nullptr)
		{
			throw std::runtime_error("Unable to open the X11 display.");
		}
		XSetCloseDownMode(_display, RetainPermanent); //Do not automatically destroy the pixmap when the application is closed.

		//TODO: find a way to check if errors occurred
		_screen = XScreenOfDisplay(_display, screen_number);
		_window = _screen->root;
		_pixmap = XCreatePixmap(_display, _window, _screen->width, _screen->height, _screen->root_depth); //reusable ?
	}

	X11RootWindow::~X11RootWindow()
	{
		//DO NOT CALL XFreePixmap ! If the pixmap is destroyed, other applications won't be able to fetch it
		XCloseDisplay(_display);
	}

	void X11RootWindow::set_background(const Rgb24Pixmap& rgb_24_pixmap)
	{
		XPutImage(_display, _pixmap, _screen->default_gc, &x11_image, 0, 0, 0, 0, _screen->width, _screen->height);
		update_window_properties();

		XSetWindowBackgroundPixmap(_display, _window, _pixmap);
		XClearWindow(_display, _window);
		XFlush(_display);
	}

	void X11RootWindow::update_window_properties()
	{
		//Is it really necessary to do that after the first set_as_current since it will be the same pixmap ? alloc'd in the ctor
		//TODO: check the results of these calls

		Atom xrootpmap_id = XInternAtom(_display, "_XROOTPMAP_ID", True);
		Atom esetroot_pmap_id = XInternAtom(_display, "ESETROOT_PMAP_ID", True);

		//should we kill the client that owns the current pixmap, as hsetroot does ?
		//https://github.com/himdel/hsetroot/blob/master/hsetroot.c#L87

		XChangeProperty(_display, _window, xrootpmap_id, XA_PIXMAP, 32, PropModeReplace, reinterpret_cast<unsigned char*>(&_pixmap), 1);
		XChangeProperty(_display, _window, esetroot_pmap_id, XA_PIXMAP, 32, PropModeReplace, reinterpret_cast<unsigned char*>(&_pixmap), 1);
	}
}