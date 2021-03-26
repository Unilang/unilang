package(
    default_visibility = ["//visibility:public"],
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
        "@GL",
        "@glut",
        "@libXxf86vm",
        "@x11",
        "@xorg_libXext",
    ],
)
