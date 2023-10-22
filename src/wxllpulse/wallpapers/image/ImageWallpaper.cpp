#include "ImageWallpaper.hpp"

#include <utility>

namespace wxp
{
	ImageWallpaper::ImageWallpaper(WallpaperSettings wallpaper_settings):
		_wallpaperSettings { std::move(wallpaper_settings) },
		_image { _wallpaperSettings.resourcePath }
	{
		//TODO: rescale image to the dimensions specified in _wallpaperSettings
	}

	void ImageWallpaper::set_as_current(X11RootWindow& root_window)
	{
		root_window.set_background(_image);
	}
}