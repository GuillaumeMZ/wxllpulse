#pragma once

#include <string>

#include "Wallpaper.hpp"

namespace wxp
{
	class ImageWallpaper: public Wallpaper
	{
		public:
			explicit ImageWallpaper(const std::string& image_path);

			void update(RootWindow& root_window) override;

		private:
			bool _has_been_set_yet;
			unsigned char* _image;
	};
}
