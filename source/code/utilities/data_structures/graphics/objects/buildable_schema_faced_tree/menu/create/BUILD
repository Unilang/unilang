package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "schema_tree_menu_creation_settings",
    deps = [
    ],
)

hcp(
    name = "schema_tree_menu_creator",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:global_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:local_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu/create:schema_tree_menu_creation_settings",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/select_menu",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
    ],
)
