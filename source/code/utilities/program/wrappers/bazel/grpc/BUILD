package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "grpc_log_data",
    deps = [
        "@bazel//:remote_execution_log_cpp",
    ],
)

hcp(
    name = "grpc_log_parser",
    deps = [
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
        "//code/utilities/time/profile:function_profiler",
        "//code/utilities/program/wrappers/bazel/grpc:grpc_log_data",
    ],
)