#include "VideoWallpaper.hpp"

namespace wxp
{
	VideoWallpaper::VideoWallpaper(WallpaperSettings wallpaper_settings):
		_wallpaperSettings { std::move(wallpaper_settings) },
		_decoder { _wallpaperSettings.resourcePath },
		_scaledFrame { _wallpaperSettings.screenWidth, _wallpaperSettings.screenHeight }
	{
	}

	void VideoWallpaper::set_as_current(X11RootWindow& root_window)
	{
		/*
			while(true)
		 	{
		 		auto frame = _decoder.decode_next_video_frame();
		 		if(frame is the last frame of the stream)
		 		{
		 			_decoder.rewind();
				}

		 		scale frame
				root_window.set_background(frame);
				sleep(frame_delay);
			}
		 */
		/*
			//convert image to rgb
			swsmm::ScaleContext scaleContext ({frame.get_width(), frame.get_height()},
											  static_cast<AVPixelFormat>(frame._frame->format),
											  {frame.get_width(), frame.get_height()},
											  AV_PIX_FMT_RGB24,
											  SWS_FAST_BILINEAR);

			AVFrame* resultf

			scaleContext.scale(frame._frame->data, frame._frame->linesize, 0, frame.get_height(), resultf->data, resultf->linesize);

			Image result = Image::from_memory(resultf->data[0], 1920, 1080);

			//display it
			root_window.set_background(result);

			break; //TODO: support multi-stream videos
		
		}*/
	}
}