#pragma once

#include <optional>
#include <string>
#include <vector>

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
}

#include "Stream.hpp"

namespace avmm
{
    class FormatContext
    {
        public:
            ~FormatContext();
            static FormatContext from_file(const std::string& path);

            std::vector<Stream>& get_streams();

        private:
            FormatContext();

        private:
            AVFormatContext *_context;
            std::optional<std::vector<Stream>> _streams;
    };
}