#include <stdexcept>

#include "ImageWallpaper.hpp"

namespace wxp
{
	ImageWallpaper::ImageWallpaper(const Image& image):
		_image { image }
	{
	}

	void ImageWallpaper::set_as_current(X11RootWindow& root_window)
	{
		root_window.set_background(_image);
	}
}