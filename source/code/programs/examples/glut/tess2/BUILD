package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "//code/utilities/graphics/opengl:sphere",
        "@GL",
        "@glut",
        "@x11",
    ],
)
