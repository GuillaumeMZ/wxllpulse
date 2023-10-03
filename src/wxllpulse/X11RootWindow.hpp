#pragma once

#include <X11/Xlib.h> //aka twitter

#include "RootWindow.hpp"

namespace wxp
{
	/**
	 * Represents the root Window of a specific screen.
	 */
	class X11RootWindow: public RootWindow
	{
		public:
			explicit X11RootWindow(int screen_number);
			~X11RootWindow();

			void setBackground(const Image& image) override;

		private:
			void updateWindowProperties();

		private:
			Display *_display;
			Window _window;
			Screen *_screen;
			Pixmap _pixmap;
	};
}