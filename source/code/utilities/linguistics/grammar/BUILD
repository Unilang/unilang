package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "grammar_adjuster",
    deps = [
        "//code/utilities/linguistics/grammar/settings:comment_grammar_settings",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:words_deriver",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/linguistics/dictionary:dictionary_getter",
        "//code/utilities/linguistics/dictionary:dictionary_spellcheck",
        "//code/utilities/output/printers:lib",
        "@nuspell",
    ],
)
