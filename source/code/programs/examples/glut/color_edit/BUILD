package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "hdrs",
    hdrs = [
        "RGBA.h",
        "mallocbis.h",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "Editor.c",
        "invertmat.c",
    ],
    data = [
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":hdrs",
        "@GL",
        "@glut",
        "@x11",
    ],
)
