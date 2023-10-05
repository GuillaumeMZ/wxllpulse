#include "VideoWallpaper.hpp"

namespace wxp
{
	VideoWallpaper::VideoWallpaper(const std::string& video_path)
	{

	}

	VideoWallpaper::~VideoWallpaper()
	{

	}

	void VideoWallpaper::update(RootWindow &root_window/* ScalingMode scaling_mode */)
	{
		//stb_image has a function to convert YCbCr to RGB !
		//would be easier to use than swscale imo
		//coz stb writes directly to a raw array that we can pass to libx11

		/*using namespace avmm;

	FormatContext format = FormatContext::from_file("/home/guillaume/salter.mp4");
	for (const auto &stream: format.get_streams())
	{
		CodecParameters codecParameters = stream.get_codec_parameters();

		if (codecParameters.get_codec_type() != AVMEDIA_TYPE_VIDEO) //MediaType::Video
		{
			continue;
		}

		const Codec codec = Codec::from_codec_id(codecParameters.get_codec_id());
		CodecContext codecContext = CodecContext::from_codec(codec, codecParameters);

		Packet packet;
		Frame frame;

		format.read_frame(packet);
		codecContext.send_packet(packet);
		codecContext.receive_frame(frame);

		std::cout << "frame width: " << frame.get_width() << "\n";
	}*/
	}
}