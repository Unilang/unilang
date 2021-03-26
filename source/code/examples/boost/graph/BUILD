load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/utilities/data_structures/graph/unique_str_vertex_graph:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
    ],
)
