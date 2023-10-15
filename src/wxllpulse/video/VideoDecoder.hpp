#pragma once

#include <filesystem>

#include "wrappers/libav/Codec.hpp"
#include "wrappers/libav/CodecContext.hpp"
#include "wrappers/libav/FormatContext.hpp"
#include "wrappers/libav/Stream.hpp"
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
			avmm::Stream _videoStream;
			avmm::Codec _codec;
			avmm::CodecContext _codecContext;
	};
}