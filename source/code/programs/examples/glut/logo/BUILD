package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "logo",
    hdrs = ["logo.hpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":logo",
        "@GL",
        "@glut",
        "@x11",
    ],
)
