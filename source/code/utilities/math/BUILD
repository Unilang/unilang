package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "math",
    deps = [],
)

hcp(
    name = "pi_calculator",
    deps = [
        "//code/utilities/math/gmp:lib",
    ],
)
