#pragma once

#include <X11/Xlib.h>
#include <memory>

namespace wxp
{
	class Rgb24Pixmap
	{
		public:
			[[nodiscard]] virtual int get_width() const = 0;
			[[nodiscard]] virtual int get_height() const = 0;
			[[nodiscard]] virtual const void* get_pixels() const = 0;

			[[nodiscard]] std::unique_ptr<XImage> into_ximage() const;
	};
}