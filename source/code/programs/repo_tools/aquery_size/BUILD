package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/aquery_size/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
    ],
)

distributable_cpp_main(
    name = "aquery_size",
    depends = [
    ],
    description = "find sizes of files from aquery",
    deps = [
        "//code/programs/repo_tools/aquery_size:task_executer",
        "//code/programs/repo_tools/aquery_size/program_options:lib",
    ],
)
