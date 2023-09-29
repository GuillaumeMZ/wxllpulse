#pragma once

extern "C" {
	#include <libavformat/avformat.h>
}

namespace avmm
{
    class Stream
    {
        public:
			Stream();
			explicit Stream(AVStream *source);

		private:
			AVStream *_stream;
    };
}