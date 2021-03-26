package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = [
        "def_logo.c",
        "opengl_logo.c",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@GL",
        "@glut",
        "@x11",
    ],
)
