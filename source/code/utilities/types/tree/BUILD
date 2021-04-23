package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

hcp(
    name = "full_path_name",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/tree/bst:annotated_bst_state",
        "//code/utilities/types/tree/bst:annotated_bst_visualizer",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "children_path_names",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/tree/converters:path_to_iterator",
    ],
)

hcp(
    name = "shortest_unique_name",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/tree/converters:path_to_iterator",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "first_full_path_name",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/tree:full_path_name",
    ],
)

hcp(
    name = "all_paths",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/tree/converters:path_to_iterator",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "parent_path",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/tree/converters:path_to_iterator",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
    ],
)
