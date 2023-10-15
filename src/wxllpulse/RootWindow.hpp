#pragma once

#include <X11/Xlib.h>
#include "Rgb24Pixmap.hpp"

namespace wxp
{
	/**
	 * Represents the root Window of a specific screen.
	 */
	class RootWindow
	{
		public:
			explicit RootWindow(int screen_number);
			~RootWindow();

			void setBackground(const RGB24Pixmap& rgb_24_pixmap);

		private:
			void prepareImage(XImage* x11_image, void* pixels_blob);
			void updateWindowProperties();

		private:
			Display* _display;
			Window _window;
			Screen* _screen;
			Pixmap _pixmap;
	};
}