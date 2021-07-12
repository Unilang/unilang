package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "buildable_schema_faced_tree_state",
    deps = [
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:schema_path_settings",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
    ],
)

hcp(
    name = "schema_path_settings",
    deps = [
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
    ],
)

hcp_and_hcp_pos(
    name = "buildable_schema_faced_tree",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:buildable_schema_faced_tree_state",
    ],
)

hcp(
    name = "default_schema_path_settings",
    deps = [
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/code/properties/style_theme:style_lookup_map_getter",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_default_schema",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:schema_path_settings",
    ],
)
