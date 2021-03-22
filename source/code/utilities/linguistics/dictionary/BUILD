package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "scrabble_2019",
    data = ["@scrabble_words//:all"],
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
    ],
)

hcp(
    name = "dictionary_getter",
    deps = [
        "@nuspell"
    ],
)

hcp(
    name = "dictionary_spellcheck_results",
    deps = [
    ],
)


hcp(
    name = "dictionary_spellcheck",
    deps = [
        "@nuspell",
        "//code/utilities/linguistics/dictionary:dictionary_spellcheck_results",
    ],
)

