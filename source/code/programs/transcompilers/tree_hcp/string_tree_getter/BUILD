package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "hcp_maker",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/programatic:code_getter",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:code",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:function",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/wrap:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

cc_binary(
    name = "string_tree_getter",
    srcs = ["main.cpp"],
    deps = [
        ":hcp_maker",
        "//code/programs/transcompilers/tree_hcp/string_tree_getter/program_options:lib",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)
