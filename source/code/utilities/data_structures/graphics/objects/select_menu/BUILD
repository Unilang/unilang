package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp_and_hcp_pos(
    name = "select_menu",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "//code/utilities/data_structures/graphics/objects/select_menu:select_menu_control_settings",
    ],
)

hcp(
    name = "select_menu_control_settings",
    deps = [
    ],
)
