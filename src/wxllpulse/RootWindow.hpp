#pragma once

namespace wxp
{
	struct Image
	{
		unsigned int width;
		unsigned int height;

		//TODO: find something better
		union
		{
			const unsigned char* cuc_pixels;
			char* pixels;
		} data;
	};

	class RootWindow
	{
		public:
			virtual void setBackground(const Image& image) = 0;
	};
}