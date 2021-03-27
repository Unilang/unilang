load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [],
    deps = [
        "//code/utilities/program/wrappers/zenity/color_picker",
        "//code/utilities/program/wrappers/zenity/color_picker:color_picker_settings",
    ],
)
