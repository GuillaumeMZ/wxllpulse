#include <stdexcept>

#include "ImageWallpaper.hpp"

namespace wxp
{
	ImageWallpaper::ImageWallpaper(const Image& image):
		_image { image }
	{
	}

	void ImageWallpaper::setAsCurrent(RootWindow& root_window)
	{
		root_window.setBackground(_image);
	}
}