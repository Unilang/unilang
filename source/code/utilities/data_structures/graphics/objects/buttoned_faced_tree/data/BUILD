package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")


enum_cpp(
    name = "draw_strategy",
    values = [
        "regular_tree",
        "wide_tree",
    ],
)

hcp(
    name = "button_face_tree_draw_settings",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:draw_strategy",
        "//code/utilities/data_structures/line_break:should_line_break",
        "@tree",
    ],
)

hcp_and_hcp_pos(
    name = "button_face_tree",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:draw_strategy",
        "//code/utilities/data_structures/line_break:should_line_break",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree_draw_settings",
        "@tree",
    ],
)