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


}