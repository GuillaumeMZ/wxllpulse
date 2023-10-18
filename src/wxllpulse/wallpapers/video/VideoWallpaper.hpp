#pragma once

#include <filesystem>

#include "wxllpulse/wallpapers/Wallpaper.hpp"
#include "VideoDecoder.hpp"

namespace wxp
{
	class VideoWallpaper: public Wallpaper
	{
		public:
														// v use VideoWallpaperSettings instead ?
			explicit VideoWallpaper(const std::filesystem::path& video_path);
			VideoWallpaper(const VideoWallpaper&) = delete;
			VideoWallpaper(VideoWallpaper&&) = delete;
			VideoWallpaper& operator=(const VideoWallpaper&) = delete;
			VideoWallpaper& operator=(VideoWallpaper&&) = delete;
			~VideoWallpaper() = default;

			void set_as_current(X11RootWindow& root_window/* ScalingMode scaling_mode */) override;

		private:
			VideoDecoder _decoder;
	};
}
