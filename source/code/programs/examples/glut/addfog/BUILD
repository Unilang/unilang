package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "add_fog",
    srcs = [
        "addfog.cpp",
    ],
    hdrs = [
        "addfog.hpp",
    ],
    deps = [
        "@GL",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "depthcue",
    srcs = [
        "depthcue.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":add_fog",
        "@GL",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "teapots",
    srcs = [
        "teapots.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":add_fog",
        "@GL",
        "@glut",
        "@x11",
    ],
)
