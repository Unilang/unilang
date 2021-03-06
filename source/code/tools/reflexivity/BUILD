package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "reflexive_refresher",
    deps = [
        "//code/tools/reflexivity:target_build_file_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/deps_define/scan:deps_repo_scanner",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/publish:all_essay_publisher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/utilities/build:self_builder",
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/logo:unilang_logo_creator",
        "//code/utilities/output/publisher/essay:essay_publisher",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/name:program_name_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "target_build_file_refresher",
    deps = [
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/utilities/build:self_builder",
    ],
)

cpp_main(
    name = "reflexive_refresh",
    deps = [
        "//code/tools/reflexivity:reflexive_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/output/publisher/essay:essay_publisher",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/name:program_name_getter",
    ],
)

cpp_main(
    name = "build_gen",
    deps = [
        "//code/tools/reflexivity:target_build_file_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)

cpp_main(
    name = "concept_tree",
    deps = [
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/filesystem/paths:lib",
    ],
)

cpp_main(
    name = "unilang_logo",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/logo:unilang_logo_creator",
    ],
)

cpp_main(
    name = "hello_world_gif",
    deps = [
        "//code/utilities/code/animate:unilang_hello_world_gif",
        "//code/utilities/filesystem/paths:lib",
    ],
)

cpp_main(
    name = "generate_essays",
    deps = [
        "//code/tools/reflexivity/publish:all_essay_publisher",
    ],
)
