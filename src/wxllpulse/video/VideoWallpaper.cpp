#include <libavutil/imgutils.h>
#include "VideoWallpaper.hpp"
#include "wxllpulse/image/Image.hpp"
#include "wrappers/libswscale/ScaleContext.hpp"
#include "wrappers/libav/CodecParameters.hpp"
#include "wrappers/libav/Codec.hpp"
#include "wrappers/libav/CodecContext.hpp"
#include "wrappers/libav/FormatContext.hpp"

namespace wxp
{
	VideoWallpaper::VideoWallpaper(const std::filesystem::path& video_path):
		_decoder { video_path }
	{
	}

	void VideoWallpaper::setAsCurrent(X11RootWindow& root_window/* ScalingMode scaling_mode */)
	{
		/*
			while(true)
		 	{
		 		auto frame = _decoder.decode_next_video_frame();
		 		if(frame is the last frame of the stream)
		 		{
		 			_decoder.rewind();
				}

				root_window.setBackground(frame);
				sleep
			}
		 */
		/*
		using namespace avmm;

		FormatContext _formatContext {_path};

		for (const auto &stream: _formatContext.get_streams())
		{
			CodecParameters codecParameters = stream.get_codec_parameters();

			if (codecParameters.get_codec_type() != AVMEDIA_TYPE_VIDEO)
			{
				continue;
			}

			const Codec codec { codecParameters.get_codec_id() };
			CodecContext codecContext { codec, codecParameters };

			Packet packet;
			Frame frame;

			//decode packet
			_formatContext.read_frame(packet);
			codecContext.send_packet(packet);
			codecContext.receive_frame(frame);

			//convert image to rgb
			swsmm::ScaleContext scaleContext ({frame.get_width(), frame.get_height()},
											  static_cast<AVPixelFormat>(frame._frame->format),
											  {frame.get_width(), frame.get_height()},
											  AV_PIX_FMT_RGB24,
											  SWS_FAST_BILINEAR);

			AVFrame* resultf = av_frame_alloc();
			av_image_alloc(resultf->data, resultf->linesize, 1920, 1080, AV_PIX_FMT_RGB24, 1);
			resultf->width = 1920;
			resultf->height = 1080;
			resultf->format = AV_PIX_FMT_RGB24;

			scaleContext.scale(frame._frame->data, frame._frame->linesize, 0, frame.get_height(), resultf->data, resultf->linesize);

			Image result = Image::from_memory(resultf->data[0], 1920, 1080);

			//display it
			root_window.setBackground(result);

			break; //TODO: support multi-stream videos
			*/
		}
	}
}