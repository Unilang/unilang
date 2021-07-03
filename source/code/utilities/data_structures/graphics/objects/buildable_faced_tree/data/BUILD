package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "buildable_face_tree_state",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/select_menu:positioned_select_menu",
        "@tree",
    ],
)

hcp_and_hcp_pos(
    name = "buildable_face_tree",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree_state",
    ],
)
