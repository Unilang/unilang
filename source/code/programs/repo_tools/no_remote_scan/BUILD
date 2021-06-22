package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/no_remote_scan/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/bazel/test:bazel_test_runner",
        "//code/utilities/types/general:lib",
        "//code/utilities/program/wrappers/buildozer:buildozer_runner",
        "//code/utilities/types/function:lib",
        "//code/utilities/program/wrappers/git/update:git_updater",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)

hcp(
    name = "no_remote_scan_documentation_getter",
    deps = [
        "//code/programs/repo_tools/no_remote_scan/program_options:lib",
        "//code/utilities/code:concept_static_tree_structs",
    ],
)

distributable_cpp_main(
    name = "no_remote_scan",
    depends = [
    ],
    description = "run a scan of no-remote tests and fix what is possible",
    deps = [
        "//code/programs/repo_tools/no_remote_scan:task_executer",
        "//code/programs/repo_tools/no_remote_scan/program_options:lib",
    ],
)
