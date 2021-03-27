package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "bazelrc_refresher",
    deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/docker/data:apt_get_command",
        "//code/programs/reflexivity/docker/data:docker_settings",
        "//code/programs/reflexivity/docker/data:docker_settings_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/converters:lib",
    ],
)
