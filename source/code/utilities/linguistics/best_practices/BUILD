package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "best_practice",
    deps = [],
)

hcp(
    name = "best_practices",
    deps = [":best_practice"],
)

hcp(
    name = "get_best_practices",
    deps = [":best_practices"],
)
