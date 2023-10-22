#include "CodecContext.hpp"

#include <stdexcept>

namespace avmm
{
	CodecContext::CodecContext(const Codec& codec, const CodecParameters& codec_parameters)
	{
		_context = avcodec_alloc_context3(codec._codec);
		if(_context == nullptr)
		{
			throw std::runtime_error("CodecContext::from_codec(): context allocation failed.");
		}

		int parametersLoadingResult = avcodec_parameters_to_context(_context, codec_parameters._parameters);
		if(parametersLoadingResult < 0)
		{
			throw std::runtime_error("CodecContext::from_codec(): avcodec_parameters_to_context() failed.");
		}

		int codecOpeningResult = avcodec_open2(_context, codec._codec, nullptr);
		if(codecOpeningResult != 0)
		{
			throw std::runtime_error("CodecContext::from_codec(): avcodec_open2() failed.");
		}
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