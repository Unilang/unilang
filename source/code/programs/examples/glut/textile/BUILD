package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "//code/utilities/formats/sgi:load_rgb",
        "@GL",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
