#pragma once

extern "C" {
	#include <libavformat/avformat.h>
}

#include "CodecParameters.hpp"

namespace avmm
{
    class Stream
    {
		friend class FormatContext;

        public:
			Stream(); //should become private

			CodecParameters get_codec_parameters() const;

		private:
			explicit Stream(AVStream *source);

		private:
			AVStream *_stream;
    };
}