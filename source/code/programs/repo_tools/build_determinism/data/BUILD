package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "determinism_problem_type",
    values = [
        "input_size",
        "output_size",
        "missing_input",
        "missing_output",
        "wrong_input_hash",
        "wrong_output_hash",
    ],
)

hcp(
    name = "determinism_problem",
    deps = [
        "//code/programs/repo_tools/build_determinism/data:determinism_problem_type",
    ],
)

hcp(
    name = "spawn_pairings",
    deps = [
        "@bazel//:spawn_proto_cpp",
    ],
)

hcp(
    name = "determinism_pairings",
    deps = [
        "@bazel//:spawn_proto_cpp",
    ],
)
