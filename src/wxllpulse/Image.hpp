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
			static Image from_memory(void* data, int width, int height);
			~Image();

			void* get_pixels() const;
			void scale(ScalingMode scaling_mode);

		private:
			Image() = default;

		private:
			unsigned char* _image;
			int _width;
			int _height;
	};
}