package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # BSD 3-Clause like

cc_library(
    name = "andres_graph",
    hdrs = glob([
        "include/andres/*.hxx",
        "include/andres/ilp/*.hxx",
        "include/andres/graph/*.hxx",
        "include/andres/graph/multicut/*.hxx",
        "include/andres/graph/multicut-lifted/*.hxx",
        "include/andres/graph/twocut/*.hxx",
        "include/andres/graph/twocut-lifted/*.hxx",
        "include/andres/graph/hdf5/*.hxx",
        "include/andres/graph/detail/*.hxx",
    ]),
    copts = ["-Wno-everything"],
    includes = ["include"],
)

[cc_test(
    name = "test-graph-" + test_name.replace("/", "-"),
    srcs = ["src/andres/graph/unit-test/" + test_name + ".cxx"],
    deps = [":andres_graph"],
) for test_name in (
    "graph",
    "digraph",
    "shortest-paths",
    "paths",
    "components",
    "max-flow",
    "graph-complete",
    "graph-grid",
    "dfs",
    "bfs",
    "cut-vertices",
    "bridges",
    "minimum-spanning-tree",
    "lifting",
    "multicut-lifted/kernighan-lin",
    "multicut-lifted/greedy-additive",
    "multicut/kernighan-lin",
    "multicut/greedy-additive",
)]
