package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")


hcp(name = "knuth_plass_entry")
hcp(name = "knuth_plass_reflower",deps = [
    "//code/utilities/linguistics/grammar:grammar_adjuster",
    "//code/utilities/linguistics/grammar/settings:comment_grammar_settings",
    "//code/utilities/types/strings/observers/reflow/settings:comment_reflow_settings",
    "//code/utilities/types/strings/observers/splitting:words_deriver",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/trimming:lib",
    "//code/utilities/types/strings/observers/reflow/algorithms:knuth_plass_entry",
])
hcp(name = "greedy_reflower",deps = [
    "//code/utilities/linguistics/grammar:grammar_adjuster",
    "//code/utilities/linguistics/grammar/settings:comment_grammar_settings",
    "//code/utilities/types/strings/observers/reflow/settings:comment_reflow_settings",
    "//code/utilities/types/strings/observers/splitting:words_deriver",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/trimming:lib",
])