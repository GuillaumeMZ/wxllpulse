#include "ScaleContext.hpp"

#include <stdexcept>

namespace swsmm
{
	//that's fucking disgusting
	ScaleContext::ScaleContext(ImageDimensions source_dimensions,
							   AVPixelFormat source_pixel_format,
							   ImageDimensions dest_dimensions,
							   AVPixelFormat dest_pixel_format,
							   int flags):

		_context{sws_getContext(source_dimensions.width,
								source_dimensions.height,
								source_pixel_format,
								dest_dimensions.width,
								dest_dimensions.height,
								dest_pixel_format,
								flags,
								nullptr,
								nullptr,
								nullptr)}
	{
		if(_context == nullptr)
		{
			throw std::runtime_error("ScaleContext::ScaleContext: context creation failed.");
		}
	}

	ScaleContext::~ScaleContext()
	{
		sws_freeContext(_context);
	}

	void ScaleContext::scale(const uint8_t *const *srcSlice,
							 const int *srcStride,
							 int srcSliceY,
							 int srcSliceH,
							 uint8_t *const *dst,
							 const int *dstStride)
	{

	}
}