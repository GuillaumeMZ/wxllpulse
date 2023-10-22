#include "Frame.hpp"

#include <stdexcept>

extern "C"
{
	#include <libavutil/imgutils.h> //av_image_alloc
}

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

	Frame::Frame(int desired_width, int desired_height):
		Frame()
	{
		av_image_alloc(_frame->data, _frame->linesize, desired_width, desired_height, AV_PIX_FMT_RGB24, 1);
		//TODO: check return code

		//Must be set manually
		_frame->width = desired_width;
		_frame->height = desired_height;
		_frame->format = AV_PIX_FMT_RGB24;
	}

	Frame::~Frame()
	{
		//TODO: call av_freep if av_image_alloc was called (?) | ImageFrame subclass ?
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

	std::int64_t Frame::get_dts() const
	{
		return _frame->pkt_dts;
	}

	std::int64_t Frame::get_pts() const
	{
		return _frame->pts;
	}
}
