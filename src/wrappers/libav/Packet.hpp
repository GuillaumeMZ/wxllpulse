#pragma once

extern "C" {
	#include <libavcodec/avcodec.h>
}

namespace avmm
{
	class Packet
	{
		friend class CodecContext;
		friend class FormatContext;

		public:
			Packet();
			~Packet();

		private:
			AVPacket *_packet;
	};
}
