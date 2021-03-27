package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "arch_pruner",
    depends = [],
    description = "prune arch from static objects of .tgz files",
    deps = [
        "//code/programs/nvidia/program_options:lib",
        "//code/utilities/formats/objects:arch_prune_settings",
        "//code/utilities/formats/objects:tgz_cuda_arch_pruner",
    ],
)
