package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "reference_lookup_map",
    deps = [
    ],
)

hcp(
    name = "reference_lookup_map_getter",
    deps = [
        "//code/utilities/code/references:reference_lookup_map",
        "//code/utilities/output/printers:lib",
    ],
)
