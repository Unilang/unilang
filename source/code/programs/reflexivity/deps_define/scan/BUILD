package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "deps_repo_scanner",
    deps = [
        "//code/programs/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/programs/reflexivity/bazelrc:bazelrc_refresher",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/programs/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/programs/reflexivity/deps_define/scan:repo_scanned_info",
        "//code/programs/reflexivity/docker:dockerfile_refresher",
        "//code/programs/reflexivity/settings:reflexive_refresh_settings",
        "//code/programs/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/utilities/code/artifacts/concept_tree:concept_tree_to_image",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/github:repo_getter",
        "//code/utilities/output/publisher/essay:essay_publisher",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/name:program_name_getter",
        "//code/utilities/program/wrappers/git:lib",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "repo_scanned_info",
    deps = [
        "//code/programs/reflexivity/deps_define/data:dependency_specification",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)
