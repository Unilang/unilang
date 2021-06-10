package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "fitted_faced_label_graph_creator",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph:conceptually_laid_out_graph",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph/data:fitted_faced_label_graph",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
    ],
)