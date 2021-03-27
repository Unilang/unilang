package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "scan_results",
    deps = [
        "//code/programs/repo_tools/build_determinism/scans/augment_scan:augment_scan_results",
        "//code/programs/repo_tools/build_determinism/scans/environment_scan:environment_scan_results",
    ],
)

hcp(
    name = "scan_results_printer",
    deps = [
        "//code/programs/repo_tools/build_determinism:scan_utilities",
        "//code/programs/repo_tools/build_determinism/scans:scan_results",
        "//code/programs/repo_tools/build_determinism/settings:settings_getter",
        "//code/utilities/output/printers:lib",
    ],
)

hcp(
    name = "scanner",
    deps = [
        "//code/programs/repo_tools/build_determinism/scans:scan_results",
        "//code/programs/repo_tools/build_determinism/scans/augment_scan:augment_scanner",
        "//code/programs/repo_tools/build_determinism/scans/environment_scan:environment_scanner",
        "//code/programs/repo_tools/build_determinism/settings:ab_settings",
        "//code/programs/repo_tools/build_determinism/settings:settings_getter",
    ],
)
