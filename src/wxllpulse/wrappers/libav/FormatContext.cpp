#include "FormatContext.hpp"

#include <stdexcept>

namespace avmm
{
	FormatContext::FormatContext(const std::filesystem::path &path):
		_context { avformat_alloc_context() },
		_streams { std::nullopt }
	{
        if(_context == nullptr)
        {
            throw std::runtime_error("FormatContext::FormatContext(): context allocation failed.");
        }

		int open_result = avformat_open_input(&_context, path.c_str(), nullptr, nullptr);
        if(open_result != 0)
        {
            throw std::runtime_error("FormatContext::FormatContext(): failed to open the specified file.");
        }
	}

    FormatContext::~FormatContext()
    {
		if(_context == nullptr)
		{
			return;
		}

		//using avformat_free_context causes memory leaks; using avformat_close_input instead does not.
		avformat_close_input(&_context);
        _context = nullptr;
        _streams = std::nullopt;
    }

    const std::vector<Stream>& FormatContext::get_streams()
	{
        if(_streams.has_value())
        {
            return _streams.value();
        }

        avformat_find_stream_info(_context, nullptr);

		std::vector<Stream> result;
		//replaceable with std::copy I think
		for(unsigned int i = 0; i < _context->nb_streams; i++)
		{
			Stream stream{_context->streams[i]};
			result.push_back(stream);
		}

		_streams = result;
		return _streams.value();
    }

	void FormatContext::read_frame(Packet& packet)
	{
		int read_result = av_read_frame(_context, packet._packet);
		// how to check ???
	}
}



