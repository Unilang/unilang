load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@system//:GL",
        "@system//:GLFW_hdrs",
        "@system//:GL_hdrs",
        "@system//:X11",
        "@system//:X11_hdrs",
        "@system//:glfw",
        "@xscreensaver//:vroot",
    ],
)
