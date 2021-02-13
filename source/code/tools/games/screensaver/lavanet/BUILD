load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@system//:X11",
        "@system//:X11_hdrs",
        "@xscreensaver//:vroot",
    ],
)
