#pragma once

namespace wxp
{
	struct Image
	{
		unsigned int width;
		unsigned int height;

		unsigned char* pixels;
	};

	class RootWindow
	{
		public:
			virtual void setBackground(const Image& image) = 0;
	};
}