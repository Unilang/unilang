package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "bazel_wrapper",
    deps = [
    ],
)

hcp(
    name = "bazel_wrapper_deriver",
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper",
        "//code/utilities/system:lib",
    ],
)
