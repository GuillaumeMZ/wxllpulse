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
				avmm::Codec codec {static_cast<AVCodecID>(codecType)};
				_codecContext = avmm::CodecContext {codec, stream.get_codec_parameters()};

				return;
			}
		}

		throw std::runtime_error("VideoDecoder::VideoDecoder: could not find a video stream.");
	}

	RgbFrame VideoDecoder::decode_next_video_frame()
	{
		_formatContext.read_frame(_packet);
		_codecContext.send_packet(_packet);
		_codecContext.receive_frame(_frame);

		RgbFrame result;
		return result;
	}
}