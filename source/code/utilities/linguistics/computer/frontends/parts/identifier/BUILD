package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "function_argument_to_identifier",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "function_result_to_identifier",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "data_member_to_identifier",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:data_member_mutability",
        "//code/utilities/code/query:data_member_storage_specifier",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "function_name_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:class_name_getter",
        "//code/utilities/code/query:data_member_visibility",
        "//code/utilities/code/query:function_is_constructor",
        "//code/utilities/code/query:function_return_type_getter",
        "//code/utilities/code/query:function_visibility",
        "//code/utilities/comments/doxygen/maker:doxygen_block_printer",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/linguistics/computer/keywords/visibility:visibility_keyword_getter",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
