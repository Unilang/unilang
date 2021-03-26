package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "hdrs",
    hdrs = [
        "head.h",
        "memory.h",
    ],
)

filegroup(
    name = "data",
    srcs = [
        "faceline.dat",
        "index.dat",
        "muscle.dat",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "display.c",
        "fileio.c",
        "main.c",
        "make_face.c",
        "muscle.c",
    ],
    data = [
        ":data",
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
