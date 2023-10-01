#pragma once

extern "C" {
	#include <libavutil/avutil.h>
	#include <libswscale/swscale.h>
}

namespace swsmm
{
	struct ImageDimensions
	{
		int width;
		int height;
	};

	class ScaleContext
	{
		public:
			ScaleContext(ImageDimensions source_dimensions,
						 AVPixelFormat source_pixel_format,
						 ImageDimensions dest_dimensions,
						 AVPixelFormat dest_format,
						 int flags);
			~ScaleContext();

			void scale(const uint8_t *const srcSlice[],
					   const int srcStride[],
					   int srcSliceY,
					   int srcSliceH,
					   uint8_t *const dst[],
					   const int dstStride[]);

		private:
			SwsContext *_context;
	};
}
