#include "VideoDecoder.hpp"

namespace wxp
{
	VideoDecoder::VideoDecoder(const std::filesystem::path& video_path):
			_formatContext { video_path }
	{
		//simplify this with ranges ?
		for(auto stream: _formatContext.get_streams())
		{
			auto codecType = stream.get_codec_parameters().get_codec_type();
			if(codecType == AVMEDIA_TYPE_VIDEO)
			{
				_videoStream = stream;
				_codec = avmm::Codec {static_cast<AVCodecID>(codecType)};
				_codecContext = avmm::CodecContext {_codec, stream.get_codec_parameters()};
				break;
			}
		}

		throw std::runtime_error("VideoDecoder::VideoDecoder: could not find a video stream.");
	}

	RgbFrame VideoDecoder::decode_next_video_frame()
	{
		_
	}
}