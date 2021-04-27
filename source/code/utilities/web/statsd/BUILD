package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "statsd_nc_poster",
    deps = [
        "//code/utilities/types/strings/transformers/wrap:lib",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
    ],
)
