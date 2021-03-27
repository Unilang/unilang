package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/header_remover/program_options:lib",
        "//code/utilities/build/profiler:profile_compilation_timer",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/header_detection:cpp_header_detector",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/streams/filestreams/write_all:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)

distributable_cpp_main(
    name = "header_remover",
    depends = [
    ],
    description = "removes headers from file",
    deps = [
        "//code/programs/repo_tools/header_remover:task_executer",
        "//code/programs/repo_tools/header_remover/program_options:lib",
    ],
)
