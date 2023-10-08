#include "wxllpulse/X11RootWindow.hpp"
#include "wxllpulse/ImageWallpaper.hpp"

int main()
{
	wxp::X11RootWindow root{0};
	wxp::Image image = wxp::Image::from_file("/home/guillaume/output.png");
	wxp::ImageWallpaper wallpaper{image};
	wallpaper.setAsCurrent(root);
}