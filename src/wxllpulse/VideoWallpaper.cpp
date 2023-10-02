#include "VideoWallpaper.hpp"

namespace wxp
{
	VideoWallpaper::VideoWallpaper(const std::string& video_path)
	{

	}

	VideoWallpaper::~VideoWallpaper()
	{

	}

	void VideoWallpaper::update(RootWindow &root_window)
	{
		//stb_image has a function to convert YCbCr to RGB !
		//would be easier to use than swscale imo
		//coz stb writes directly to a raw array that we can pass to libx11
	}
}