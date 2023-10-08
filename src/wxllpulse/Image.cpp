#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <stdexcept>

namespace wxp
{
	Image Image::from_file(const std::string& path)
	{
		//temporary test code using stb; I'm searching for a better image manipulation lib
		Image result {};
		result._image = stbi_load(path.c_str(), &result._width, &result._height, nullptr, 3);
		if(result._image == nullptr)
		{
			throw std::runtime_error("Image::from_file(): image loading failed.");
		}

		return result;
	}

	Image Image::from_memory(void* data, int width, int height)
	{
		//needs improvement (and a better lib)
		Image result {};
		result._image = static_cast<unsigned char *>(data);
		result._width = width;
		result._height = height;

		return result;
	}

	Image::~Image()
	{
		stbi_image_free(_image);
	}

	void* Image::get_pixels() const
	{
		return _image;
	}

	void Image::scale(ScalingMode scaling_mode) //TODO
	{

	}
}