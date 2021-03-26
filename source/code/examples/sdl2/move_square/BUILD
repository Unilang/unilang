load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@GL",
        "@SDL_image",
        "@sdl2",
    ],
)

cc_binary(
    name = "main2",
    srcs = ["main.cpp"],
    deps = [
        "@GL",
        "@SDL_image//:hdrs",
        "@sdl2//:sdl2_hdrs",
        "@system//:SDL2",
        "@system//:SDL2_image",
    ],
)
