package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/shared_objects/find_shared_object/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/files/observers/other:recursive_ldd_results_getter",
        "//code/utilities/filesystem/files/observers/other:recursive_ldd_scan_printer",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/types/strings/observers/other:lib",
    ],
)

distributable_cpp_main(
    name = "find_shared_object",
    depends = [
    ],
    description = "find where a shared object is comming from via a particular bazel target",
    deps = [
        "//code/programs/repo_tools/shared_objects/find_shared_object:task_executer",
        "//code/programs/repo_tools/shared_objects/find_shared_object/program_options:lib",
    ],
)
