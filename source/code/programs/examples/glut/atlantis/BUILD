package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "hdrs",
    hdrs = [
        "atlantis.h",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "atlantis.c",
        "dolphin.c",
        "shark.c",
        "swim.c",
        "whale.c",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":hdrs",
        "@GL",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
