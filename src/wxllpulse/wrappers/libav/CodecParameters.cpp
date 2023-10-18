#include "CodecParameters.hpp"

#include <stdexcept>

namespace avmm
{
	AVCodecID CodecParameters::get_codec_id() const
	{
		return _parameters->codec_id;
	}

	AVMediaType CodecParameters::get_codec_type() const
	{
		return _parameters->codec_type;
	}

	CodecParameters::CodecParameters(AVCodecParameters *source):
		_parameters{source}
	{
		if(source == nullptr)
		{
			throw std::runtime_error("CodecParameters::CodecParameters(AVCodecParameters*): source is nullptr.");
		}
	}
}