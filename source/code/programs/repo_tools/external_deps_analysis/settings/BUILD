package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "settings",
    deps = [
    ],
)

hcp(
    name = "settings_getter",
    deps = [
        "//code/programs/repo_tools/external_deps_analysis/program_options:lib",
        "//code/programs/repo_tools/external_deps_analysis/settings",
    ],
)
