package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "catching_main",
    deps = [
        "//code/utilities/program/common_actions/signals:all_signal_setter",
        "//code/utilities/program/common_actions/backtrace:backtrace",
        "//code/utilities/program/common_actions/backtrace:exceptions",
    ],
)