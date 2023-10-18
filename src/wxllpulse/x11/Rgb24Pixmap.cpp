#include "Rgb24Pixmap.hpp"

namespace wxp
{
	std::unique_ptr<XImage> Rgb24Pixmap::into_ximage() const
	{
		auto result = std::make_unique<XImage>((XImage){
			.width = get_width(), .height = get_height(),
			.xoffset = 0,
			.format = ZPixmap,
			.data = (char *) get_pixels(),
			.byte_order = MSBFirst,
			.bitmap_unit = 32, .bitmap_bit_order = LSBFirst, .bitmap_pad = 32, //unused but must be set
			.depth = 24,
			.bytes_per_line = 3 * get_width(),
			.bits_per_pixel = 24,
			.red_mask = 0xff0000, .green_mask = 0xff00, .blue_mask = 0xff,
			.obdata = nullptr
		});

		XInitImage(result.get());

		return result;
	}
}