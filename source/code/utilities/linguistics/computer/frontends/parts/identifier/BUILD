package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "function_argument_to_identifier",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
    ],
)

hcp(
    name = "function_result_to_identifier",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
    ],
)

hcp(
    name = "data_member_to_identifier",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/code/query:data_member_mutability",
        "//code/utilities/code/query:data_member_storage_specifier",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/converters:lib",
    ],
)
