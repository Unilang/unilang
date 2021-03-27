package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "settings",
    deps = [
        "//code/utilities/program/wrappers/bazel:build_settings",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup",
        "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_settings",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
    ],
)

hcp(
    name = "settings_getter",
    deps = [
        "//code/programs/repo_tools/build_tools/program_options:lib",
        "//code/programs/repo_tools/build_tools/settings",
    ],
)
