package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "arrow",
    deps = [
        "//code/utilities/data_structures:arrow_direction",
        "//code/utilities/data_structures/position",
    ],
)
