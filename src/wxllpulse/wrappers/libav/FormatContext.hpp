#pragma once

#include <filesystem>
#include <optional>
#include <vector>

extern "C"
{
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
}

#include "Packet.hpp"
#include "Stream.hpp"

namespace avmm
{
    class FormatContext
    {
        public:
			explicit FormatContext(const std::filesystem::path& path);
			FormatContext(const FormatContext&) = delete;
			FormatContext(FormatContext&&) = delete;
			FormatContext& operator=(const FormatContext&) = delete;
			FormatContext& operator=(FormatContext&&) = delete;
            ~FormatContext();

            const std::vector<Stream>& get_streams();
			void read_frame(Packet& frame);

        private:
            AVFormatContext *_context;
            std::optional<std::vector<Stream>> _streams;
    };
}