package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/shared_objects/shared_object_trace:correlated_so_ldd",
        "//code/programs/repo_tools/shared_objects/shared_object_trace:file_and_type",
        "//code/programs/repo_tools/shared_objects/shared_object_trace:ignore_deps",
        "//code/programs/repo_tools/shared_objects/shared_object_trace:so_ldd_correlation_visualizer",
        "//code/programs/repo_tools/shared_objects/shared_object_trace/program_options:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/other:file_and_ldd_results",
        "//code/utilities/filesystem/files/observers/other:ldd_results_getter",
        "//code/utilities/filesystem/files/observers/other:lib",
        "//code/utilities/filesystem/files/observers/other:recursive_ldd_results_getter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "file_and_type",
    deps = [
    ],
)

hcp(
    name = "correlated_so_ldd",
    deps = [
        "//code/programs/repo_tools/shared_objects/shared_object_trace:file_and_type",
        "//code/utilities/filesystem/files/observers/other:file_and_ldd_results",
    ],
)

hcp(
    name = "correlation_results",
    deps = [
        "//code/programs/repo_tools/shared_objects/shared_object_trace:correlated_so_ldd",
        "//code/programs/repo_tools/shared_objects/shared_object_trace:file_and_type",
    ],
)

hcp(
    name = "so_ldd_correlation_visualizer",
    deps = [
        "//code/programs/repo_tools/shared_objects/shared_object_trace:correlated_so_ldd",
        "//code/programs/repo_tools/shared_objects/shared_object_trace:correlation_results",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

# hcp(
#     name = "shared_object_trace_documentation_getter",
#     deps = [
#         "//code/programs/repo_tools/shared_objects/shared_object_trace/program_options:lib",
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )

hcp(
    name = "ignore_deps",
    deps = [
        "//code/utilities/language_basic/std_hackery:std_aliases",
    ],
)

distributable_cpp_main(
    name = "shared_object_trace",
    depends = [
    ],
    description = "track shared objects from 3rd party libraries to other third party libaries that use them",
    deps = [
        "//code/programs/repo_tools/shared_objects/shared_object_trace:task_executer",
        "//code/programs/repo_tools/shared_objects/shared_object_trace/program_options:lib",
    ],
)
