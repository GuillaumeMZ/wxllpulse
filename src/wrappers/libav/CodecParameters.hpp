#pragma once

extern "C" {
	#include <libavcodec/avcodec.h>
}

namespace avmm
{
	class CodecParameters
	{
		friend class CodecContext;
		friend class Stream;

		public:
			AVCodecID get_codec_id() const;
			AVMediaType get_codec_type() const;

		private:
			explicit CodecParameters(AVCodecParameters *source);

		private:
			AVCodecParameters* _parameters;
	};
}