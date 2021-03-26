package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "agviewer",
    srcs = ["agviewer.c"],
    hdrs = ["agviewer.h"],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "agv_example.c",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":agviewer",
        "@GL",
        "@glut",
        "@x11",
    ],
)
