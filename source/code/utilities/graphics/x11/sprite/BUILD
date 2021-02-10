package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "sprite",
    deps = [
        "@system//:X11_hdrs",
        "@system//:X11",
    ],
)

hcp(
    name = "sprite_loader",
    deps = [
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/sprite",
    ],
)

hcp(
    name = "sprite_window",
    deps = [
        "//code/utilities/graphics/x11/sprite",
    ],
)

hcp(
    name = "sprite_window_creator",
    deps = [
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/sprite",
        "//code/utilities/graphics/x11/sprite:sprite_window",
    ],
)

hcp(
    name = "sprite_window_drawer",
    deps = [
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/sprite:sprite_window",
    ],
)
