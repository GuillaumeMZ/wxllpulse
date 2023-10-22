#pragma once

extern "C"
{
	#include <libavcodec/avcodec.h>
	#include <libavutil/avutil.h>
}

#include <cstdint>

namespace avmm
{
	class Frame
	{
		friend class CodecContext;

		public:
			Frame();
			Frame(int desired_width, int desired_height /* AVPixelFormat format */);
			~Frame();

			[[nodiscard]] int get_width() const;
			[[nodiscard]] int get_height() const;

			[[nodiscard]] std::int64_t get_dts() const;
			[[nodiscard]] std::int64_t get_pts() const;

		private:
			AVFrame* _frame;
	};
}
