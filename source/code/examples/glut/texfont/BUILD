package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "data",
    srcs = glob([
        "*.txf",
    ]),
)

cc_library(
    name = "texfont",
    srcs = ["texfont.c"],
    hdrs = [
        "TexFont.h",
    ],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "demo",
    srcs = [
        "txfdemo.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":texfont",
        "@GL",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "simple",
    srcs = [
        "simpletxf.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":texfont",
        "@GL",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "show",
    srcs = [
        "showtxf.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":texfont",
        "@GL",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "gen",
    srcs = [
        "gentexfont.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":texfont",
        "@GL",
        "@glut",
        "@x11",
    ],
)
