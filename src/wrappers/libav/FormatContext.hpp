#pragma once

#include <optional>
#include <string>
#include <vector>

extern "C" {
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
			FormatContext(const FormatContext&) = delete;
			FormatContext(FormatContext&&) noexcept;
            ~FormatContext();

			FormatContext& operator=(const FormatContext&) = delete;
			FormatContext& operator=(FormatContext&&) noexcept;

            static FormatContext from_file(const std::string& path);

            const std::vector<Stream>& get_streams();

			void read_frame(Packet& frame);

        private:
            FormatContext();

        private:
            AVFormatContext *_context;
            std::optional<std::vector<Stream>> _streams;
    };
}