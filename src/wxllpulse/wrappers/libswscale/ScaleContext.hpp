#pragma once

extern "C" {
	#include <libswscale/swscale.h>
}

#include <libavutil/avutil.h>

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
						 int flags = 0);
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
