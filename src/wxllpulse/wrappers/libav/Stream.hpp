#pragma once

#include <cstdint>

extern "C"
{
	#include <libavformat/avformat.h>
}

#include "CodecParameters.hpp"

namespace avmm
{
    class Stream
    {
		friend class FormatContext;

        public:
			Stream() = delete;

			[[nodiscard]] CodecParameters get_codec_parameters() const;
			[[nodiscard]] std::int64_t get_frames_count() const;

		private:
			explicit Stream(AVStream *source);

		private:
			AVStream *_stream;
    };
}