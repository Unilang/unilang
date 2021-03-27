package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/create_bazel_profile/program_options:lib",
        "//code/utilities/build/profiler:profile_compilation_timer",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel:build_settings",
        "//code/utilities/program/wrappers/bazel:default_build_settings",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup_deriver",
        "//code/utilities/program/wrappers/bazel/setup:default_bazel_setup_settings",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/program/wrappers/git/repo_establisher:default_repo_location_getter",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/streams/filestreams/write_all:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)

distributable_cpp_main(
    name = "create_bazel_profile",
    depends = [
    ],
    description = "removes headers from file",
    deps = [
        "//code/programs/repo_tools/create_bazel_profile:task_executer",
        "//code/programs/repo_tools/create_bazel_profile/program_options:lib",
    ],
)
