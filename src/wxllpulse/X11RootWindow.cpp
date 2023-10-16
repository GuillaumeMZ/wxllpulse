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

	void X11RootWindow::setBackground(const Image& image /* Pixmap pixmap */)
	{
		//TODO: check if it succeeded
		//move the pixmap creation to another class
		XImage x11_image;
		prepareImage(&x11_image, image.get_pixels());

		XPutImage(_display, _pixmap, _screen->default_gc, &x11_image, 0, 0, 0, 0, _screen->width, _screen->height);
		updateWindowProperties();

		XSetWindowBackgroundPixmap(_display, _window, _pixmap);
		XClearWindow(_display, _window);
		XFlush(_display);
	}

	void X11RootWindow::updateWindowProperties()
	{
		//Is it really necessary to do that after the first setAsCurrent since it will be the same pixmap ? alloc'd in the ctor
		//TODO: check the results of these calls

		Atom xrootpmap_id = XInternAtom(_display, "_XROOTPMAP_ID", True);
		Atom esetroot_pmap_id = XInternAtom(_display, "ESETROOT_PMAP_ID", True);

		//should we kill the client that owns the current pixmap, as hsetroot does ?
		//https://github.com/himdel/hsetroot/blob/master/hsetroot.c#L87

		XChangeProperty(_display, _window, xrootpmap_id, XA_PIXMAP, 32, PropModeReplace, reinterpret_cast<unsigned char*>(&_pixmap), 1);
		XChangeProperty(_display, _window, esetroot_pmap_id, XA_PIXMAP, 32, PropModeReplace, reinterpret_cast<unsigned char*>(&_pixmap), 1);
	}

	void X11RootWindow::prepareImage(XImage* x11_image, void* pixels_blob)
	{
		//todo: remove magic numbers
		x11_image->width = _screen->width;
		x11_image->height = _screen->height;
		x11_image->xoffset = 0;
		x11_image->format = ZPixmap;
		x11_image->data = reinterpret_cast<char *>(pixels_blob);
		x11_image->byte_order = MSBFirst; //without this, the image would be rendered in bgr mode
		x11_image->bitmap_unit = 32;
		x11_image->bitmap_bit_order = LSBFirst;
		x11_image->bitmap_pad = 32;
		x11_image->depth = 24;
		x11_image->bytes_per_line = 3 * _screen->width;
		x11_image->bits_per_pixel = 24;
		x11_image->red_mask = 0xff0000;
		x11_image->green_mask = 0xff00;
		x11_image->blue_mask = 0xff;
		x11_image->obdata = nullptr;

		XInitImage(x11_image);
	}
}