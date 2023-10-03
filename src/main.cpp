#include <iostream>

/*#include <stb_image.h>
#include <SDL.h>
#include <SDL_render.h>
*/

#include <unistd.h>

#include "wxllpulse/X11RootWindow.hpp"
#include "wxllpulse/ImageWallpaper.hpp"

int main()
{
	wxp::X11RootWindow root{0};
	wxp::ImageWallpaper wallpaper{"/home/guillaume/output.png"};
	wallpaper.update(root);
}