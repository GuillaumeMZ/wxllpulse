#pragma once

#include <string>

#include "wrappers/libav/Codec.hpp"
#include "wrappers/libav/CodecContext.hpp"
#include "wrappers/libav/CodecParameters.hpp"
#include "wrappers/libav/FormatContext.hpp"
#include "wrappers/libav/Frame.hpp"
#include "wrappers/libav/Packet.hpp"
#include "wrappers/libav/Stream.hpp"

#include "Wallpaper.hpp"

namespace wxp
{
	class VideoWallpaper: public Wallpaper
	{
		public:
			explicit VideoWallpaper(const std::string& video_path);
			VideoWallpaper(const VideoWallpaper&) = delete;
			VideoWallpaper(VideoWallpaper&&) = delete;
			VideoWallpaper& operator=(const VideoWallpaper&) = delete;
			VideoWallpaper& operator=(VideoWallpaper&&) = delete;
			~VideoWallpaper() = default;

			void setAsCurrent(X11RootWindow& root_window/* ScalingMode scaling_mode */) override;

		private:
			avmm::FormatContext _formatContext;
	};
}
