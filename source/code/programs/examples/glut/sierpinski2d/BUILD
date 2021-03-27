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
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
        "@system//:X11",
        "@system//:glut",
    ],
)
