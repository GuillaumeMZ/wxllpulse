#pragma once

#include <filesystem>

#include "wxllpulse/wrappers/libav/Codec.hpp"
#include "wxllpulse/wrappers/libav/CodecContext.hpp"
#include "wxllpulse/wrappers/libav/FormatContext.hpp"
#include "wxllpulse/wrappers/libav/Stream.hpp"
#include "RgbFrame.hpp"

namespace wxp
{
	/**
	 * Serves as a facade to the libav video decoding subsystem.
	 */
	class VideoDecoder
	{
		public:
			explicit VideoDecoder(const std::filesystem::path& video_path);
			VideoDecoder(const VideoDecoder&) = delete;
			VideoDecoder(VideoDecoder&&) = delete;
			VideoDecoder& operator=(const VideoDecoder&) = delete;
			VideoDecoder& operator=(VideoDecoder&&) = delete;
			~VideoDecoder() = default;

			RgbFrame decode_next_video_frame();
			//decode_next_audio_frame

		private:
			avmm::FormatContext _formatContext;
			avmm::CodecContext _codecContext;
			avmm::Packet _packet;
			avmm::Frame _frame;
	};
}