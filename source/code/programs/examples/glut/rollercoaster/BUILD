package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "matrix",
    srcs = [
        "matrix.c",
    ],
    hdrs = [
        "matrix.h",
    ],
)

filegroup(
    name = "data",
    srcs = [
        "rc.def",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "defrc.c",
        "rc.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":matrix",
        "@GL",
        "@glut",
        "@x11",
    ],
)
