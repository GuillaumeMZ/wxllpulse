#pragma once

extern "C" {
	#include <libavcodec/avcodec.h>
	#include <libavutil/avutil.h>
}

namespace avmm
{
	class Frame
	{
		friend class CodecContext;

		public:
			Frame();
			~Frame();

			int get_width() const;
			int get_height() const;

		private:
			AVFrame *_frame;
	};
}