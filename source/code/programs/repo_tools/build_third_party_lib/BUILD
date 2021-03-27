package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "build_third_party_lib",
    depends = [
    ],
    description = "build a third party library in parts",
    deps = [
        "//code/programs/repo_tools/build_third_party_lib:task_executer",
        "//code/programs/repo_tools/build_third_party_lib/program_options:lib",
    ],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/build_third_party_lib:visualizer",
        "//code/programs/repo_tools/build_third_party_lib/program_options:lib",
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
    ],
)

hcp(
    name = "visualizer",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
