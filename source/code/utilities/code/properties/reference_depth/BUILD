package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "reference_depth_map",
    deps = [
    ],
)

hcp(
    name = "reference_depth_map_getter",
    deps = [
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/output/printers:lib",
    ],
)
