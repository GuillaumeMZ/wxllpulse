#include "CodecContext.hpp"

#include <stdexcept>

namespace avmm
{
	CodecContext CodecContext::from_codec(const Codec &codec, const CodecParameters& codec_parameters)
	{
		CodecContext result;
		result._context = avcodec_alloc_context3(codec._codec);
		if(result._context == nullptr)
		{
			throw std::runtime_error("CodecContext::from_codec(): context allocation failed.");
		}

		int parameters_loading_result = avcodec_parameters_to_context(result._context, codec_parameters._parameters);
		if(parameters_loading_result < 0)
		{
			throw std::runtime_error("CodecContext::from_codec(): avcodec_parameters_to_context() failed.");
		}

		int codec_opening_result = avcodec_open2(result._context, codec._codec, nullptr);
		if(codec_opening_result != 0)
		{
			throw std::runtime_error("CodecContext::from_codec(): avcodec_open2() failed.");
		}

		return result;
	}

	CodecContext::~CodecContext()
	{
		//according to the documentation, avcodec_close shouldn't be used
		avcodec_free_context(&_context);
	}

	void CodecContext::send_packet(Packet& packet)
	{
		int sending_result = avcodec_send_packet(_context, packet._packet);
		if(sending_result != 0)
		{
			throw std::runtime_error("CodecContext::send_packet(Packet&): sending failed.");
		}
	}

	void CodecContext::receive_frame(Frame& frame)
	{
		int receive_result = avcodec_receive_frame(_context, frame._frame);
		if(receive_result != 0)
		{
			throw std::runtime_error("CodecContext::receive_frame(Frame&): receiving failed.");
		}
	}
}