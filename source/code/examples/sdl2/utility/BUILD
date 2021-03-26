load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/graphics/sdl:sdl_initializer",
        "//code/utilities/graphics/sdl:sdl_window_creator",
        "@GL",
        "@SDL_image//:hdrs",
        "@sdl2//:sdl2_hdrs",
        "@system//:SDL2",
        "@system//:SDL2_image",
    ],
)
