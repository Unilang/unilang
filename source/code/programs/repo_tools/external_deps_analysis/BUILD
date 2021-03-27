package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/external_deps_analysis:analysis_state",
        "//code/programs/repo_tools/external_deps_analysis:external_deps_visualizer",
        "//code/programs/repo_tools/external_deps_analysis/program_options:lib",
        "//code/programs/repo_tools/external_deps_analysis/settings",
        "//code/programs/repo_tools/external_deps_analysis/settings:settings_getter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
        "//code/utilities/types/queue:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "analysis_state",
    deps = [
    ],
)

# hcp(
#     name = "external_deps_analysis_documentation_getter",
#     deps = [
#         "//code/programs/repo_tools/external_deps_analysis/program_options:lib",
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )

hcp(
    name = "external_deps_visualizer",
    deps = [
        "//code/programs/repo_tools/external_deps_analysis:analysis_state",
        "//code/programs/repo_tools/external_deps_analysis/settings",
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

distributable_cpp_main(
    name = "external_deps_analysis",
    depends = [
    ],
    description = "dependency graph creation for 3rd party libraries in bazel",
    deps = [
        "//code/programs/repo_tools/external_deps_analysis:task_executer",
        "//code/programs/repo_tools/external_deps_analysis/program_options:lib",
    ],
)
