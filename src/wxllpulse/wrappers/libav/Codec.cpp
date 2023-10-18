#include "Codec.hpp"

#include <stdexcept>

namespace avmm
{
	Codec::Codec(AVCodecID codec_id):
		_codec { avcodec_find_decoder(codec_id) }
	{
		if(_codec == nullptr)
		{
			throw std::runtime_error("Codec::from_codec_id(): no matching codec has been found.");
		}
	}
}