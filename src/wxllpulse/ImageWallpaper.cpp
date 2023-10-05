#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "ImageWallpaper.hpp"

namespace wxp
{
	ImageWallpaper::ImageWallpaper(const std::string& image_path):
		_has_been_set_yet { false },
		_width { -1 },
		_height { -1 },
		_image { stbi_load(image_path.c_str(), &_width, &_height, nullptr, 4) } //loading only 3 channels (skipping alpha)
	{
		if(_image == nullptr)
		{
			//TODO: better error message
			throw std::runtime_error("Image loading failed.");
		}
	}

	ImageWallpaper::~ImageWallpaper()
	{
		stbi_image_free(_image); //crashes
	}

	void ImageWallpaper::update(RootWindow& root_window)
	{
		if(_has_been_set_yet)
		{
			return;
		}

		Image image{};
		image.width = _width;
		image.height = _height;
		image.pixels = _image;

		root_window.setBackground(image);

		_has_been_set_yet = true;
	}
}