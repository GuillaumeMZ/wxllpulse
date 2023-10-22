#pragma once

#include <filesystem>

#include "wxllpulse/wallpapers/Wallpaper.hpp"
#include "wxllpulse/wallpapers/WallpaperSettings.hpp"
#include "wxllpulse/wrappers/libav/Frame.hpp"
#include "VideoDecoder.hpp"

namespace wxp
{
	class VideoWallpaper: public Wallpaper
	{
		public:
			explicit VideoWallpaper(WallpaperSettings wallpaper_settings);
			VideoWallpaper(const VideoWallpaper&) = delete;
			VideoWallpaper(VideoWallpaper&&) = delete;
			VideoWallpaper& operator=(const VideoWallpaper&) = delete;
			VideoWallpaper& operator=(VideoWallpaper&&) = delete;
			~VideoWallpaper() = default;

			void set_as_current(X11RootWindow& root_window) override;

		private:
			WallpaperSettings _wallpaperSettings;
			VideoDecoder _decoder;
			avmm::Frame _scaledFrame;
	};
}
