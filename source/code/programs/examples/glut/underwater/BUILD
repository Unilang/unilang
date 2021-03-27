package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "dino",
    srcs = ["dino.c"],
    hdrs = [
        "dino.h",
    ],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_library(
    name = "texload",
    srcs = ["texload.c"],
    hdrs = [
        "texload.h",
    ],
    deps = [
        "@glut",
        "@x11",
    ],
)

filegroup(
    name = "data",
    srcs = [
        "floor.rgb",
    ] + glob([
        "*.bw",
    ]),
)

cc_binary(
    name = "main",
    srcs = [
        "underwater.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":dino",
        ":texload",
        "@GL",
        "@glut",
        "@x11",
    ],
)
