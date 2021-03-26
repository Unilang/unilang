package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "tr",
    srcs = ["tr.cpp"],
    hdrs = ["tr.hpp"],
    deps = [
        "@glut",
        "@libXxf86vm",
        "@x11",
        "@xorg_libXext",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":tr",
        "@GL",
        "@glut",
        "@libXxf86vm",
        "@x11",
        "@xorg_libXext",
    ],
)
