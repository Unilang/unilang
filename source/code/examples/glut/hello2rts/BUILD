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
        "//code/utilities/graphics/opengl:real_time_shadowing",
        "@GL",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
