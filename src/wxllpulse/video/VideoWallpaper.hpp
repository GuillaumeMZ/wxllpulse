#pragma once

#include <filesystem>

#include "wxllpulse/Wallpaper.hpp"
#include "wxllpulse/video/VideoDecoder.hpp"

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

			void setAsCurrent(RootWindow& root_window/* ScalingMode scaling_mode */) override;

		private:
			VideoDecoder _decoder;
	};
}
