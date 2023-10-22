#pragma once

#include <string>

#include "wxllpulse/wallpapers/Wallpaper.hpp"
#include "wxllpulse/wallpapers/WallpaperSettings.hpp"
#include "Image.hpp"

namespace wxp
{
	class ImageWallpaper: public Wallpaper
	{
		public:
			explicit ImageWallpaper(WallpaperSettings wallpaper_settings);

			void set_as_current(X11RootWindow& root_window) override;

		private:
			WallpaperSettings _wallpaperSettings;
			Image _image;
	};
}
