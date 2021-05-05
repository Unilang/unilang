package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "metrics_publisher",
    deps = [
        "//code/utilities/data_structures/endpoint:endpoint",
        "//code/utilities/web/statsd:statsd_nc_poster",
    ],
)
