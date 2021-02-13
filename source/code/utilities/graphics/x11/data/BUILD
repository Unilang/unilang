package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "x11_bg_fg_colors",
    deps = [
        "@system//:X11",
        "@system//:X11_hdrs",
    ],
)

hcp(
    name = "x11_window_geometry",
    deps = [
        "@system//:X11",
        "@system//:X11_hdrs",
    ],
)

hcp(
    name = "main_x11_state",
    deps = [
        ":x11_bg_fg_colors",
        ":x11_window_geometry",
        "@system//:X11",
        "@system//:X11_hdrs",
    ],
)
