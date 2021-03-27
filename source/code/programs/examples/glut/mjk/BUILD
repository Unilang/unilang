package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "mjkimage",
    hdrs = ["mjkimage.hpp"],
)

cc_binary(
    name = "sift",
    srcs = ["sift.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":mjkimage",
        "@GL",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "warp",
    srcs = ["warp.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":mjkimage",
        "@GL",
        "@glut",
        "@x11",
    ],
)
