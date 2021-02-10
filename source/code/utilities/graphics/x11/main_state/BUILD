package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

#data
hcp(
    name = "window_creation_settings",
    deps = [
        "@system//:X11_hdrs",
        "@system//:X11",
        "//code/utilities/data_structures/position:position",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    ],
)

hcp(
    name = "setup_display_settings",
    deps = [
        "@system//:X11_hdrs",
        "@system//:X11",
        "//code/utilities/graphics/x11/main_state:window_creation_settings",
    ],
)

#functionality
hcp(
    name = "x11_main_state_creator",
    deps = [
        ":setup_display_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/data:x11_bg_fg_colors",
        "//code/utilities/graphics/x11/data:x11_window_geometry",
        "//code/utilities/graphics/x11/main_state:x11_display_getter",
        "//code/utilities/graphics/x11/main_state:x11_color_getter",
        "@system//:X11_hdrs",
        "@system//:X11",
    ],
)

hcp(
    name = "x11_display_getter",
    deps = [
        ":setup_display_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/data:x11_bg_fg_colors",
        "//code/utilities/graphics/x11/data:x11_window_geometry",
        "@system//:X11_hdrs",
        "@system//:X11",
        "@system//:Xext",
    ],
)

hcp(
    name = "x11_color_getter",
    deps = [
        ":setup_display_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/data:x11_bg_fg_colors",
        "//code/utilities/graphics/x11/data:x11_window_geometry",
        "@system//:X11_hdrs",
        "@system//:X11",
    ],
)

