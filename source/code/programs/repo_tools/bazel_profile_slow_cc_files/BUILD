package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/bazel_profile_slow_cc_files:results_filter",
        "//code/programs/repo_tools/bazel_profile_slow_cc_files:results_publisher",
        "//code/programs/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/build/efficient_target_deriver",
        "//code/utilities/build/efficient_target_deriver:target_augment_settings",
        "//code/utilities/build/profile_parser:file_duration_extractor",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/data_structures/fraction:fraction_parser",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/files/observers/other:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel:default_build_settings",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup_deriver",
        "//code/utilities/program/wrappers/bazel/setup:default_bazel_setup_settings",
        "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_deriver",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper_deriver",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/program/wrappers/git/repo_establisher:default_repo_location_getter",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "results_filter",
    deps = [
        "//code/utilities/build/profile_parser:file_duration_extractor",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "results_publisher",
    deps = [
        "//code/programs/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
        "//code/utilities/build/profile_parser:file_duration_extractor",
        "//code/utilities/build/profile_parser/data:flat_owned_duration_file",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/web/honeycomb:honeycomb_poster",
    ],
)

distributable_cpp_main(
    name = "bazel_profile_slow_cc_files",
    depends = [
    ],
    description = "parse bazel's profile file to find slow cc files with highest compilation times",
    deps = [
        "//code/programs/repo_tools/bazel_profile_slow_cc_files:task_executer",
        "//code/programs/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
    ],
)

# hcp(
#     name = "bazel_profile_slow_cc_files_documentation_getter",
#     deps = [
#         "//code/programs/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )
