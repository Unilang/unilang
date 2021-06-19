package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "chrome_trace",
    deps = [
        "//code/utilities/profiling/chrome_tracing/data:chrome_trace_event",
    ],
)

hcp(
    name = "chrome_trace_event",
    deps = [],
)
