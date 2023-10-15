add_requires("cxxopts", "stb")

target("wxllpulse")
    set_default(true)
    set_kind("binary")
    set_languages("cxx17")

    add_includedirs("src")
    add_files("src/**.cpp")
    add_links("avformat", "avcodec", "avutil", "swscale", "X11")
    add_packages("cxxopts", "stb")