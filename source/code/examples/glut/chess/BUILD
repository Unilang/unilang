package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "chess_class",
    srcs = [
        "chess.c",
    ],
    hdrs = [
        "chess.h",
    ],
    deps = [
        "@glut",
        "@x11",
    ],
)

filegroup(
    name = "data",
    srcs = [
        "chess.inp",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "animate.c",
        "main.c",
        "pathplan.c",
        "texture.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":chess_class",
        "@GL",
        "@glut",
        "@x11",
    ],
)
