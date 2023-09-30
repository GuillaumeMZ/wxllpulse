#include "FormatContext.hpp"

#include <stdexcept>

namespace avmm
{
    FormatContext::FormatContext():
            _context{avformat_alloc_context()},
            _streams{std::nullopt}
    {
        if(_context == nullptr)
        {
            throw std::runtime_error("FormatContext::FormatContext(): context allocation failed.");
        }
    }

	FormatContext::FormatContext(FormatContext&& rhs) noexcept:
		_context{rhs._context},
		_streams{std::move(rhs._streams)}
	{
		rhs._context = nullptr;
		rhs._streams = std::nullopt;
	}

    FormatContext::~FormatContext()
    {
		if(_context == nullptr)
		{
			return;
		}

        avformat_free_context(_context);
        _context = nullptr;
        _streams = std::nullopt;
    }

	FormatContext &FormatContext::operator=(FormatContext&& rhs) noexcept
	{
		_context = rhs._context;
		_streams = std::move(rhs._streams);

		rhs._context = nullptr;
		rhs._streams = std::nullopt;

		return *this;
	}

    FormatContext FormatContext::from_file(const std::string& path)
	{
        FormatContext result;

        int open_result = avformat_open_input(&result._context, path.c_str(), nullptr, nullptr);
        if(open_result != 0)
        {
            throw std::runtime_error("FormatContext::from_file(): failed to open the specified file.");
        }

		return result;
    }

    const std::vector<Stream>& FormatContext::get_streams()
	{
        if(_streams.has_value())
        {
            return _streams.value();
        }

        avformat_find_stream_info(_context, nullptr);

		std::vector<Stream> result{_context->nb_streams};
		//replaceable with std::copy I think
		for(unsigned int i = 0; i < _context->nb_streams; i++)
		{
			Stream stream{_context->streams[i]};
			result[i] = stream;
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



