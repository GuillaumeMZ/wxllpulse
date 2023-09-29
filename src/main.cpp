#include <iostream>

#include <SDL.h>
#include <X11/Xlib.h>

//av* libraries don't include extern "C" when compiled as C++
//see https://stackoverflow.com/a/17785329
extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
}

#include "wrappers/libav/FormatContext.hpp"

constexpr auto WXLLPULSE_INITIALISATION_FLAGS = SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS;

int main()
{
    avmm::FormatContext format = avmm::FormatContext::from_file("/home/guillaume/salter.mp4");
	for(auto stream: format.get_streams())
	{
		//...
	}

    AVFormatContext *formatContext = avformat_alloc_context();
    avformat_open_input(&formatContext, "/home/guillaume/salter.mp4", nullptr, nullptr);




    std::cout << "format " << formatContext->iformat->long_name << ", lasts " << formatContext->duration << "us\n";

    avformat_find_stream_info(formatContext, nullptr);
    for(int i = 0; i < formatContext->nb_streams; i++)
    {
        AVCodecParameters *localCodecParams = formatContext->streams[i]->codecpar;
        const AVCodec *localCodec = avcodec_find_decoder(localCodecParams->codec_id);

        if(localCodecParams->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            std::cout << "video coded found: " << localCodec->long_name << "\n";
            AVCodecContext *codecContext = avcodec_alloc_context3(localCodec);

            avcodec_parameters_to_context(codecContext, localCodecParams);
            avcodec_open2(codecContext, localCodec, nullptr);

            AVPacket *packet = av_packet_alloc();
            AVFrame *frame = av_frame_alloc();

            //read one frame; decode it; try to extract the image
            av_read_frame(formatContext, packet);
            avcodec_send_packet(codecContext, packet);
            avcodec_receive_frame(codecContext, frame);

            //see https://stackoverflow.com/questions/66384258/sws-scale-yuv-to-rgb-conversion
            //to convert yuv to rgb

            av_frame_free(&frame);
            av_packet_free(&packet);

            avcodec_close(codecContext);
            avcodec_free_context(&codecContext);
        }
    }

    avformat_free_context(formatContext);

    /*if(SDL_InitSubSystem(WXLLPULSE_INITIALISATION_FLAGS) != 0)
    {
        //todo: log
        std::exit(1);
    }

    Display* x_display = XOpenDisplay(":0");
    if(x_display == nullptr)
    {
        //todo: log
        std::exit(1);
    }

    //window is an integer type
    Window x_root_window = XDefaultRootWindow(x_display);

    auto window_access = SDL_CreateWindowFrom(reinterpret_cast<void*>(x_root_window));
    if(window_access == nullptr)
    {
        //todo: log
        std::exit(2);
    }

    auto renderer = SDL_CreateRenderer(window_access, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        //todo: log
        std::exit(1);
    }

    //works when picom is NOT running
    //see https://github.com/chjj/compton/issues/162#issuecomment-31171707
    //fix: set properties _XROOTPMAP_ID or _XSETROOT_ID (how ?)
    //see this interesting discussion about potential fixes: https://github.com/glouw/paperview/issues/1
    //todo: look at XSetWindowBackgroundPixmap
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    while(true)
    {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT)
        {
            break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window_access);

    std::cout << "still alive\n";

    SDL_QuitSubSystem(WXLLPULSE_INITIALISATION_FLAGS);

    XCloseDisplay(x_display);*/
}