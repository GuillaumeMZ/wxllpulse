#pragma once

#include <filesystem>
#include <string>

#include "wxllpulse/x11/Rgb24Pixmap.hpp"

namespace wxp
{
	class Image: public Rgb24Pixmap
	{
		public:
			explicit Image(const std::filesystem::path& path);
			~Image();

			[[nodiscard]] int get_width() const override;
			[[nodiscard]] int get_height() const override;
			[[nodiscard]] const void *get_pixels() const override;

		private:
			int _width;
			int _height;
			unsigned char* _image;
	};
}