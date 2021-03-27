package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:gtest.bzl", "gtest")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

gtest(
    name = "bst_swap_test",
    deps = [
        "//code/programs/puzzles/hackerrank:bst_swap_algorithm",
        "//code/programs/puzzles/hackerrank:bst_swap_solution",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_five_ptrs",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_four_ptrs",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_three_ptrs",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_in_out",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_sliding_window_two_ptrs",
        "//code/utilities/data_structures/tree/bst:binary_nodes",
        "//code/utilities/types/tree/bst:prebuilt_bst_trees",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

# The algorithms
enum_cpp(
    name = "bst_swap_algorithm",
    values = [
        "hackerrank_recursive_five",
        "hackerrank_recursive_four",
        "hackerrank_recursive_three",
        "sliding_window_and_pair",
        "inorder_outorder_three",
        "morris_hickey_two",
    ],
)

hcp(
    name = "bst_swap_solution_geeks_five_ptrs",
    deps = [
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "bst_swap_solution_geeks_four_ptrs",
    deps = [
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "bst_swap_solution_geeks_three_ptrs",
    deps = [
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "bst_swap_solution_sliding_window_two_ptrs",
    deps = [
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "bst_swap_solution_in_out",
    deps = [
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "bst_swap_solution_morris_hickey",
    deps = [
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_five_ptrs",
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/tree/bst:annotated_bst_fix",
        "//code/utilities/types/tree/bst:annotated_bst_state",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "bst_swap_solution",
    deps = [
        "//code/programs/puzzles/hackerrank:bst_swap_algorithm",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_five_ptrs",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_four_ptrs",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_geeks_three_ptrs",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_in_out",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_morris_hickey",
        "//code/programs/puzzles/hackerrank:bst_swap_solution_sliding_window_two_ptrs",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)
