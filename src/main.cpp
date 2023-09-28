#include <iostream>

#include <SDL.h>

constexpr auto WXLLPULSE_INITIALISATION_FLAGS = SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS;

int main()
{
    if(SDL_InitSubSystem(WXLLPULSE_INITIALISATION_FLAGS) != 0)
    {
        //todo: log
        std::exit(1);
    }

    auto window = SDL_CreateWindow("Test",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     800,
                     600,
                     0);

    SDL_Event event;
    while(true)
    {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT)
        {
            break;
        }
    }

    SDL_DestroyWindow(window);

    SDL_QuitSubSystem(WXLLPULSE_INITIALISATION_FLAGS);
}