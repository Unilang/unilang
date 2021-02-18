package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "boilerplate_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/export_file_settings",
        "//code/utilities/linguistics/computer/filename:file_name_getter",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta:boilerplate_printer",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl:meta_block_printer",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "package_name_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/export_file_settings",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "imports_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "class_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:virtual_method_checker",
        "//code/utilities/comments/doxygen/maker:doxygen_block_printer",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/frontends/java/parts:data_members_getter",
        "//code/utilities/linguistics/computer/frontends/java/parts:methods_getter",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/code/query:class_name_getter",
    ],
)

hcp(
    name = "data_members_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/comments/doxygen/maker:doxygen_block_printer",
        "//code/utilities/code/query:data_member_visibility",
        "//code/utilities/code/query:data_member_storage_specifier",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/linguistics/computer/keywords/visibility:visibility_keyword_getter",
        "//code/utilities/linguistics/computer/keywords/storage:storage_keyword_getter",
        "//code/utilities/linguistics/computer/keywords/mutability:mutability_keyword_getter",
        "//code/utilities/code/query:data_member_mutability",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
        "//code/utilities/linguistics/computer/frontends/parts/identifier:data_member_to_identifier",
        "//code/utilities/linguistics/computer/types/default_initialize:default_initialize_getter",
    ],
)

hcp(
    name = "methods_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:data_member_visibility",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/linguistics/computer/keywords/visibility:visibility_keyword_getter",
    ],
)
