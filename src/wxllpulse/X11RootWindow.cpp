#include <stdexcept>

#include "X11RootWindow.hpp"

namespace wxp
{

	X11RootWindow::X11RootWindow(int screen_number):
		_display { XOpenDisplay(":0") },
		_window{ XRootWindow(_display, screen_number) }
	{
		if(_display == nullptr)
		{
			throw std::runtime_error("Unable to open the X11 display.");
		}
	}

	X11RootWindow::~X11RootWindow()
	{
		XCloseDisplay(_display);
	}

	void X11RootWindow::setBackground()
	{

	}
}