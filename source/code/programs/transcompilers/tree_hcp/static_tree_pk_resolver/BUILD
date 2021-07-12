package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "pk_resolver",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/programatic:code_getter",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:code",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:function",
        "//code/programs/transcompilers/shared:json_gen",
        "//code/programs/transcompilers/tree_hcp/shared:path_naming",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/data_structures/tree/generic:string_to_string_tree",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/output/printers:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/strings/observers/characteristic:is_cpp_keyword_checker",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/wrap:lib",
        "//code/utilities/types/tree:all_paths",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:shortest_unique_name",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

cc_binary(
    name = "static_tree_pk_resolver",
    srcs = ["main.cpp"],
    deps = [
        ":pk_resolver",
        "//code/programs/transcompilers/tree_hcp/static_tree_pk_resolver/program_options:lib",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)
