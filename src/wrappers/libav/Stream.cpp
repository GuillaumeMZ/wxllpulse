#include "Stream.hpp"

#include <stdexcept>

namespace avmm
{
	Stream::Stream():
		_stream{nullptr}
	{
	}

	Stream::Stream(AVStream *source):
		_stream{source}
	{
		if(source == nullptr)
		{
			throw std::runtime_error("Stream::Stream(AVStream*): source is nullptr.");
		}
	}

	CodecParameters Stream::get_codec_parameters() const
	{
		return CodecParameters{_stream->codecpar};
	}

	std::int64_t Stream::get_frames_count() const
	{
		return _stream->nb_frames;
	}
}