#pragma once

#include <string>
#include <X11/Xlib.h>

namespace wxp
{
	enum class ScalingMode
	{
		Fill,
		Fit,
		Stretch,
		Center
	};

	class Image
	{
		public:
			static Image from_file(const std::string& path);
			static Image from_memory/*_rgb*/(void* data, int width, int height);
			// static Image from_memory_format(void* data, int width, int height, Format format);
			~Image();

			void* get_pixels() const;
			void scale(ScalingMode scaling_mode);
			//

		private:
			Image() = default;

		private:
			bool _should_free;
			unsigned char* _image;
			int _width;
			int _height;
	};
}