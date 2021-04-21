package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "build_plan_deps",
    depends = [
    ],
    description = "analyze dependencies between build plans",
    deps = [
        "//code/programs/repo_tools/build_plan_deps:task_executer",
        "//code/programs/repo_tools/build_plan_deps/program_options:lib",
    ],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/build_plan_deps/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/build/build_repo_establisher:build_repo_settings",
        "//code/utilities/build/profiler:branch_profile_compilation_timer",
        "//code/utilities/build/profiler/data:profile_results",
        "//code/utilities/build/profiler/data:profile_settings",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/math",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/queue:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/data_structures/build_plan:build_plan_cpp_proto",
        "//code/utilities/data_structures/graph/unique_str_vertex_graph:lib",
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)