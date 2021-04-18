package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "color_transitioner",
    deps = [
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
    ],
)

hcp(
    name = "color_shader",
    deps = [
        "//code/utilities/colors/transformers:color_clamp",
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
        "//code/utilities/data_structures/color:transparent_rgb_color",
    ],
)

hcp(
    name = "color_tinter",
    deps = [
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
    ],
)

hcp(
    name = "screen_position_to_rgb",
    deps = [
        "//code/utilities/colors/converters:hsv_to_rgb_converter",
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/math",
    ],
)

hcp(
    name = "color_clamp",
    deps = [
        "//code/utilities/colors/converters:hsv_to_rgb_converter",
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/math",
    ],
)
