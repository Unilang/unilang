package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/repo_stats/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/output/printers:lib",
    ],
)

distributable_cpp_main(
    name = "repo_stats",
    depends = [
    ],
    description = "run a scan of no-remote tests and fix what is possible",
    deps = [
        "//code/programs/repo_tools/repo_stats:task_executer",
        "//code/programs/repo_tools/repo_stats/program_options:lib",
    ],
)
