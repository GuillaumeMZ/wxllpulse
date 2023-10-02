#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "ImageWallpaper.hpp"

namespace wxp
{
	ImageWallpaper::ImageWallpaper(const std::string& image_path):
		_has_been_set_yet { false },
		_image { stbi_load(image_path.c_str(), nullptr, nullptr, nullptr, 3) } //loading only 3 channels (skipping alpha)
	{
		if(_image == nullptr)
		{
			//TODO: better error message
			throw std::runtime_error("Image loading failed.");
		}


	}

	void ImageWallpaper::update(X11RootWindow& root_window)
	{
		if(_has_been_set_yet)
		{
			return;
		}

		//see https://solarianprogrammer.com/2019/06/10/c-programming-reading-writing-images-stb_image-libraries/
	}
}