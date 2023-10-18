#pragma once

#include "wxllpulse/x11/X11RootWindow.hpp"

namespace wxp
{
	class Wallpaper
	{
		public:
			virtual void set_as_current(X11RootWindow& root_window) = 0;
	};
}