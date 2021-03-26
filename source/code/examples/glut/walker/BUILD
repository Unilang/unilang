package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "data",
    srcs = glob([
        "*.cset",
    ]),
)

cc_library(
    name = "walkviewer",
    srcs = ["walkviewer.cpp"],
    hdrs = ["walkviewer.hpp"],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_library(
    name = "walker",
    hdrs = [
        "walker.hpp",
        "win32_dirent.hpp",
    ],
    deps = [
        ":walkviewer",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "models.cpp",
        "walker.cpp",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":walker",
        ":walkviewer",
        "@GL",
        "@glut",
        "@x11",
    ],
)
