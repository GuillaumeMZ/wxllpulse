#pragma once

#include <string>

#include "Wallpaper.hpp"

namespace wxp
{
	class ImageWallpaper: public Wallpaper
	{
		public:
			explicit ImageWallpaper(const std::string& image_path);
			~ImageWallpaper();

			void update(RootWindow& root_window) override;

		private:
			bool _has_been_set_yet;

			int _width;
			int _height;
			unsigned char* _image;
	};
}
