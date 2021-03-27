package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "execution_endpoint",
    deps = [
        "//code/programs/repo_tools/remote_execution/server/capabilities:server_capabilities_getter",
        "//code/programs/repo_tools/remote_execution/server/settings:server_settings",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/output/logging:debug_spdlog",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "@semver",
    ],
)
