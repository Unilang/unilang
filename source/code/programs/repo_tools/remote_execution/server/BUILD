package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "server",
    deps = [
        "//code/programs/repo_tools/remote_execution/server/action_cache:action_cache_endpoint",
        "//code/programs/repo_tools/remote_execution/server/bytestream:bytestream_endpoint",
        "//code/programs/repo_tools/remote_execution/server/capabilities:capabilities_endpoint",
        "//code/programs/repo_tools/remote_execution/server/cas:cas_endpoint",
        "//code/programs/repo_tools/remote_execution/server/execution:execution_endpoint",
        "//code/programs/repo_tools/remote_execution/server/settings:server_settings",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/output/logging:debug_spdlog",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "@semver",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/repo_tools/remote_execution/server",
        "//code/programs/repo_tools/remote_execution/server/settings:server_settings",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
    ],
)
