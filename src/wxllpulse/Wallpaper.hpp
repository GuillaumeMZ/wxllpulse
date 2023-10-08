#pragma once

#include "X11RootWindow.hpp"

namespace wxp
{
	class Wallpaper
	{
		public:
			virtual void setAsCurrent(X11RootWindow& root_window) = 0;
	};
}