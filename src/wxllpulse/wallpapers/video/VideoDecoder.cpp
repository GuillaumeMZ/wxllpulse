#include "VideoDecoder.hpp"

namespace wxp
{
	VideoDecoder::VideoDecoder(const std::filesystem::path& video_path):
			_formatContext { video_path },
			_packet {},
			_frame {}
	{
		//simplify this with ranges ?
		for(auto stream: _formatContext.get_streams())
		{
			auto codecType = stream.get_codec_parameters().get_codec_type();
			if(codecType == AVMEDIA_TYPE_VIDEO)
			{
				_codec = avmm::Codec {stream.get_codec_parameters().get_codec_id()};
				_codecContext = avmm::CodecContext {_codec, stream.get_codec_parameters()}; //error: temporary context is freed; codeccontext is closed

				return;
			}
		}

		throw std::runtime_error("VideoDecoder::VideoDecoder: could not find a video stream.");
	}

	avmm::Frame& VideoDecoder::decode_next_video_frame()
	{
		_formatContext.read_frame(_packet);
		_codecContext.send_packet(_packet);
		_codecContext.receive_frame(_frame);

		return _frame;
	}
}