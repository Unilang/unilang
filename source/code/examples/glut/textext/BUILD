package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "data",
    srcs = glob([
        "*.bw",
    ]),
)

cc_library(
    name = "textmap",
    srcs = [
        "textmap.cpp",
    ],
    hdrs = [
        "textmap.hpp",
    ],
    deps = [
        "//code/utilities/formats/sgi:load_rgb",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = [":data"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":textmap",
        "@GL",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
