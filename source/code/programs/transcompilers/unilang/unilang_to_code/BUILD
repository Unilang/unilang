package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "unilang_to_code",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/ide/global_actions:save_state_serializer",
        "//code/programs/transcompilers/unilang/unilang_to_code/program_options:lib",
        "//code/utilities/code/save:save_state_loader",
        "//code/utilities/code/save:state_to_code_converter",
        "//code/utilities/formats/json/converters:json_file_io",
    ],
)
