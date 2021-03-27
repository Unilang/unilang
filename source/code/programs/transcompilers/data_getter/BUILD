package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "data_getter",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/transcompilers/data_getter/program_options:lib",
        "//code/programs/transcompilers/hcp-compiler/programatic:code_getter",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:code",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
    ],
)
