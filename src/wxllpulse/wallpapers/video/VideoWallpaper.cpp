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

	void VideoWallpaper::set_as_current(X11RootWindow& root_window/* ScalingMode scaling_mode */)
	{
		/*
			while(true)
		 	{
		 		auto frame = _decoder.decode_next_video_frame();
		 		if(frame is the last frame of the stream)
		 		{
		 			_decoder.rewind();
				}

				root_window.set_background(frame);
				sleep
			}
		 */
		/*
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
			root_window.set_background(result);

			break; //TODO: support multi-stream videos
		
		}*/
	}
}