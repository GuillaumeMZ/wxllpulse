#include "Frame.hpp"

#include <stdexcept>

namespace avmm
{
	Frame::Frame():
		_frame{av_frame_alloc()}
	{
		if(_frame == nullptr)
		{
			throw std::runtime_error("Frame::Frame(): frame allocation failed.");
		}
	}

	Frame::~Frame()
	{
		av_frame_free(&_frame);
	}

	int Frame::get_width() const
	{
		return _frame->width;
	}

	int Frame::get_height() const
	{
		return _frame->height;
	}
}
