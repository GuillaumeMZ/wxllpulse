#pragma once

#include <X11/Xlib.h>
#include "Rgb24Pixmap.hpp"

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

			void set_background(const Rgb24Pixmap& rgb_24_pixmap);

		private:
			void update_window_properties();

		private:
			Display* _display;
			Window _window;
			Screen* _screen;
			Pixmap _pixmap;
	};
}