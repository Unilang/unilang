package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "single_file_profile",
    depends = [
    ],
    description = "profile compilation performance of individual cc file",
    deps = [
        "//code/programs/repo_tools/single_file_profile:task_executer",
        "//code/programs/repo_tools/single_file_profile/program_options:lib",
    ],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/single_file_profile/program_options:lib",
        "//code/utilities/build/profiler:branch_profile_compilation_timer",
        "//code/utilities/build/profiler/data:profile_results",
        "//code/utilities/build/profiler/data:profile_settings",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/math",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
