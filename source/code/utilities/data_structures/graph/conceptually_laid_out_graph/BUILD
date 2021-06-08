package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "conceptually_laid_out_node",
    deps = [
        "//code/utilities/data_structures/position",
    ],
)

hcp(
    name = "conceptually_laid_out_edge",
    deps = [
    ],
)

hcp(
    name = "conceptually_laid_out_graph",
    deps = [
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph:conceptually_laid_out_edge",
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph:conceptually_laid_out_node",
    ],
)
