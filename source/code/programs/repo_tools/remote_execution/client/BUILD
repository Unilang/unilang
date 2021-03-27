package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "client",
    deps = [
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/repo_tools/remote_execution/client",
        "//code/programs/repo_tools/remote_execution/server",
        "//code/programs/repo_tools/remote_execution/server/settings:server_settings",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
    ],
)
