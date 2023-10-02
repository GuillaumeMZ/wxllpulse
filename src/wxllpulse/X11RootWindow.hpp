#pragma once

#include <X11/Xlib.h> //aka twitter

namespace wxp
{
	/**
	 * Represents the root Window of a specific screen.
	 */
	class X11RootWindow
	{
		public:
			explicit X11RootWindow(int screen_number);
			~X11RootWindow();

		private:
			Display* _display;
			Window _window;
	};
}