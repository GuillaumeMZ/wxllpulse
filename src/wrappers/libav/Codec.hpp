#pragma once

//av* libraries don't include extern "C" when compiled as C++
//see https://stackoverflow.com/a/17785329
extern "C" {
	#include <libavcodec/avcodec.h>
}

namespace avmm
{
	class Codec
	{
		friend class CodecContext;

		public:
			static Codec from_codec_id(AVCodecID codec_id);

		private:
			explicit Codec(const AVCodec* source);

		private:
			const AVCodec* _codec;
	};
}