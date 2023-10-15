#pragma once

#include "RootWindow.hpp"

namespace wxp
{
	class Wallpaper
	{
		public:
			virtual void setAsCurrent(RootWindow& root_window) = 0;
	};
}