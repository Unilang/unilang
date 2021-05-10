package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "get_dir_size",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp(
    name = "get_total_file_count",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)
