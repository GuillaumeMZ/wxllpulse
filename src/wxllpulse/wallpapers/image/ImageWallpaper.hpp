#pragma once

#include <string>

#include "wxllpulse/wallpapers/Wallpaper.hpp"
#include "Image.hpp"

namespace wxp
{
	class ImageWallpaper: public Wallpaper
	{
		public:
			// should we replace this by something like "ImageWallpaperSettings" ?
			explicit ImageWallpaper(const Image& image);

			void set_as_current(X11RootWindow& root_window /* ScalingMode scaling_mode */) override;

		private:
			const Image& _image;
	};
}
