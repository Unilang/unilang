package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "fracviewer",
    srcs = ["fracviewer.cpp"],
    hdrs = ["fracviewer.hpp"],
    deps = [
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":fracviewer",
        "@GL",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
