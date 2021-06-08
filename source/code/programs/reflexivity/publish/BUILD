package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "unilang_documentation_generator",
    deps = [
        "//code/utilities/assets/literature:unilang_json_data_getter",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/temp:temp_file",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/pdf:latex_template_getter",
        "//code/utilities/formats/pdf:pdf_creator",
        "//code/utilities/formats/pdf:pdf_settings",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_str_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/web/dropbox:dropbox_uploader",
    ],
)
