add_requires("libsdl")

target("wxllpulse")
    set_default(true)
    set_kind("binary")
    set_languages("cxx17")

    add_files("src/**.cpp")
    add_links(
        "avformat",
        "avcodec",
        "swscale", -- YUV -> RGB conversion
        "X11"
    )
    add_packages("libsdl") -- is it really needed ?