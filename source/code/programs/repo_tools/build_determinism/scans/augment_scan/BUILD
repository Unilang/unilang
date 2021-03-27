package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "augment_scan_results",
    deps = [
    ],
)

hcp(
    name = "augment_scanner",
    deps = [
        "//code/programs/repo_tools/build_determinism:determinism_ab_runner",
        "//code/programs/repo_tools/build_determinism:determinism_problem_getter",
        "//code/programs/repo_tools/build_determinism:file_isolator",
        "//code/programs/repo_tools/build_determinism:reporter",
        "//code/programs/repo_tools/build_determinism:scan_utilities",
        "//code/programs/repo_tools/build_determinism:subcommand_filter",
        "//code/programs/repo_tools/build_determinism/scans/augment_scan:augment_scan_results",
        "//code/programs/repo_tools/build_determinism/settings:ab_settings",
        "//code/programs/repo_tools/build_determinism/settings:settings_getter",
        "//code/utilities/filesystem/files/moving:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper_deriver",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/random:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
