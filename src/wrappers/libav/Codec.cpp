#include "Codec.hpp"

#include <stdexcept>

namespace avmm
{
	Codec Codec::from_codec_id(AVCodecID codec_id)
	{
		const AVCodec* codec = avcodec_find_decoder(codec_id);
		if(codec == nullptr)
		{
			throw std::runtime_error("Codec::from_codec_id(): no matching codec has been found.");
		}

		return Codec{codec};
	}

	Codec::Codec(const AVCodec *source):
		_codec{source}
	{
		//private ctor, no need to check that source != nullptr
	}
}