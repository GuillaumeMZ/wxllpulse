#pragma once

extern "C" {
	#include <libavcodec/avcodec.h>
}

#include "Codec.hpp"
#include "Frame.hpp"
#include "Packet.hpp"
#include "CodecParameters.hpp"

namespace avmm
{
	class CodecContext
	{
		public:
			CodecContext(const Codec& codec, const CodecParameters& codec_parameters);
			~CodecContext();

			void send_packet(Packet& packet);
			void receive_frame(Frame& frame);

		private:
			AVCodecContext *_context;
	};
}
