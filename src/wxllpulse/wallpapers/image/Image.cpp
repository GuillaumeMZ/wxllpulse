#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <stdexcept>

namespace wxp
{
	Image::Image(const std::filesystem::path& path):
		_width {},
		_height {},
		_image { stbi_load(path.c_str(), &_width, &_height, nullptr, 3) }
	{
		if(_image == nullptr)
		{
			throw std::runtime_error("Image::from_file(): image loading failed.");
		}
	}

	Image::~Image()
	{
		stbi_image_free(_image);
	}

	int Image::get_width() const
	{
		return _width;
	}

	int Image::get_height() const
	{
		return _height;
	}

	const void* Image::get_pixels() const
	{
		return (const void*) _image;
	}
}