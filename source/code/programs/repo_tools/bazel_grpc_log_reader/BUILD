package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/bazel_grpc_log_reader/program_options:lib",
        "//code/utilities/program/wrappers/bazel/grpc:grpc_log_parser",
        "//code/utilities/profiling/chrome_tracing/data:chrome_trace",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/types/strings/observers/path:lib",
    ],
)

distributable_cpp_main(
    name = "bazel_grpc_log_reader",
    depends = [
    ],
    description = "parse a bazel grpc log",
    deps = [
        "//code/programs/repo_tools/bazel_grpc_log_reader:task_executer",
        "//code/programs/repo_tools/bazel_grpc_log_reader/program_options:lib",
    ],
)
