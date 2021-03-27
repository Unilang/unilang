package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "file_mover",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/transcompilers/file_mover/program_options:lib",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/moving:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/program/call:lib",
    ],
)
