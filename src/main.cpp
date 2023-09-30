#include <iostream>

#include "wrappers/libav/FormatContext.hpp"
#include "wrappers/libav/Codec.hpp"
#include "wrappers/libav/Packet.hpp"
#include "wrappers/libav/Frame.hpp"
#include "wrappers/libav/CodecContext.hpp"

int main()
{
	using namespace avmm;

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
	}
}