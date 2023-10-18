#pragma once

extern "C"
{
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

			[[nodiscard]] int get_width() const;
			[[nodiscard]] int get_height() const;

		private:
			AVFrame *_frame;
	};
}
