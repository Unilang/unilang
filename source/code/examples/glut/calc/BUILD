package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "hdrs",
    hdrs = [
        "calc.h",
    ],
)

cc_binary(
    name = "main",
    srcs = ["calc.c"],
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
