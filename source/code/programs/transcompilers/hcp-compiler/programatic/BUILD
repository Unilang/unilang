package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "code_getter",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/programs/transcompilers/hcp-compiler/programatic:function_getter",
        "//code/programs/transcompilers/hcp-compiler/programatic:header_getter",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:code",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "header_getter",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:headers",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "function_getter",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:function",
        "//code/utilities/types/converters:lib",
    ],
)
