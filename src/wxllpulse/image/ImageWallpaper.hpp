#pragma once

#include <string>

#include "wxllpulse/Wallpaper.hpp"
#include "Image.hpp"

namespace wxp
{
	class ImageWallpaper: public Wallpaper
	{
		public:
			// should we replace this by something like "ImageWallpaperSettings" ?
			explicit ImageWallpaper(const Image& image);

			void setAsCurrent(X11RootWindow& root_window /* ScalingMode scaling_mode */) override;

		private:
			const Image& _image;
	};
}
