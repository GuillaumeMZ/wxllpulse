#pragma once

#include "RootWindow.hpp"

namespace wxp
{
	class Wallpaper
	{
		public:
			virtual void update(RootWindow& root_window) = 0;
	};
}