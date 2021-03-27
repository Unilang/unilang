package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "node_edge_data",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
    ],
)

hcp(
    name = "edge_data",
    deps = [
        ":connection",
        ":event_interval",
    ],
)

hcp(
    name = "event_interval",
    deps = [
    ],
)

hcp(
    name = "connection",
    deps = [
        ":edge_type",
    ],
)

enum_cpp(
    name = "edge_type",
    values = [
        "directed",
        "undirected",
    ],
)
