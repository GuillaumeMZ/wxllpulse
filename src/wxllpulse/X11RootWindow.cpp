#include <stdexcept>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h> //XDestroyImage

#include "X11RootWindow.hpp"

namespace wxp
{

	X11RootWindow::X11RootWindow(int screen_number)
	{
		_display = XOpenDisplay(":0");
		if(_display == nullptr)
		{
			throw std::runtime_error("Unable to open the X11 display.");
		}

		//TODO: find a way to check if errors occurred
		_screen = XScreenOfDisplay(_display, screen_number);
		_window = XRootWindow(_display, screen_number); //we can use screen->root instead
		_pixmap = XCreatePixmap(_display, _window, _screen->width, _screen->height, 24);
	}

	X11RootWindow::~X11RootWindow()
	{
		XFreePixmap(_display, _pixmap);
		XCloseDisplay(_display);
	}

	void X11RootWindow::setBackground(const Image& image)
	{
		//Interesting: https://stackoverflow.com/questions/17017432/linux-c-ximage-rgb-bgr

		//https://itecnote.com/tecnote/how-to-upload-32-bit-image-to-server-side-pixmap/
		//maybe create the XImage in the ctor so that it can be reused...
		XImage *x11_image = XCreateImage(_display, _screen->root_visual, 24, ZPixmap, 0, (char*)image.pixels, image.width, image.height, 32, 0);
		if(x11_image == nullptr)
		{
			throw std::runtime_error("X11RootWindow::setBackground(): unable to create the image.");
		}

		XPutImage(_display, _pixmap, _screen->default_gc, x11_image, 0, 0, 0, 0, image.width, image.height);

		updateWindowProperties();
		XSetWindowBackgroundPixmap(_display, _window, _pixmap);

		XClearWindow(_display, _window);
		XFlush(_display);

		//... and destroy it in the dtor
		XDestroyImage(x11_image);
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