#pragma once

#include <filesystem>

namespace wxp
{
	enum class ScalingMode
	{
		Test
	};

	struct WallpaperSettings
	{
		const int screenWidth;
		const int screenHeight;
		const ScalingMode scalingMode;
		const std::filesystem::path resourcePath;
	};
}