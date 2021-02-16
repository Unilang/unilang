package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "comment_style_category")

hcp(
    name = "comment_settings",
    deps = [
        "//code/utilities/comments/code/settings:comment_style_category",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/comments/language:c_comment_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_settings",
        "//code/utilities/types/strings/observers/reflow/settings:comment_reflow_settings",
    ],
)
