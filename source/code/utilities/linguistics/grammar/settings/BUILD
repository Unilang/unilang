package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "comment_grammar_puncuation_settings",
    deps = [
    ],
)

hcp(
    name = "comment_grammar_preposition_settings",
    deps = [
    ],
)

hcp(
    name = "comment_grammar_cliche_settings",
    deps = [
    ],
)

hcp(
    name = "comment_grammar_sarcasm_settings",
    deps = [
    ],
)

hcp(
    name = "comment_grammar_bad_word_settings",
    deps = [
    ],
)

hcp(
    name = "comment_grammar_spellcheck_settings",
    deps = [
    ],
)

hcp(
    name = "comment_grammar_settings",
    deps = [
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_bad_word_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_cliche_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_preposition_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_puncuation_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_spellcheck_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_sarcasm_settings",
    ],
)
