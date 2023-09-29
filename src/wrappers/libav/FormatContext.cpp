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

    FormatContext::~FormatContext()
    {
        avformat_free_context(_context);
        _context = nullptr;
        _streams = std::nullopt;
    }

    FormatContext FormatContext::from_file(const std::string& path)
	{
        FormatContext result;

        int open_result = avformat_open_input(&result._context, path.c_str(), nullptr, nullptr);
        if(open_result != 0)
        {
            throw std::runtime_error("FormatContext::from_file(): failed to open the specified file.");
        }
    }

    std::vector<Stream>& FormatContext::get_streams()
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
			result.emplace_back(_context->streams[i]);
		}

		_streams = result;
		return _streams.value();
    }
}



