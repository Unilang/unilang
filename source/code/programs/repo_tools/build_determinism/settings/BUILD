package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "settings",
    deps = [
        "//code/programs/repo_tools/build_determinism/settings:ab_settings",
        "//code/programs/repo_tools/build_determinism/settings:report_settings",
        "//code/utilities/data_structures:concurrency",
        "//code/utilities/program/wrappers/bazel:build_settings",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
    ],
)

hcp(
    name = "report_settings",
    deps = [
    ],
)

hcp(
    name = "settings_getter",
    deps = [
        "//code/programs/repo_tools/build_determinism/program_options:lib",
        "//code/programs/repo_tools/build_determinism/settings",
        "//code/utilities/program/wrappers/bazel/setup:default_bazel_setup_settings",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper",
        "//code/utilities/program/wrappers/git/repo_establisher:default_repo_location_getter",
    ],
)

hcp(
    name = "ab_settings",
    deps = [
        "//code/utilities/program/wrappers/bazel:build_settings",
    ],
)
