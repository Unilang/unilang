package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

#build main and deploy stuff
cc_binary(
    name = "word_builder",
    srcs = ["word_builder.cpp"],
    data = ["@scrabble_words//:all"],
    deps = [
        "//code/programs/games/word_build/cli:word_builder_game_maker",
    ],
)

hcp(
    name = "word_builder_game_maker",
    deps = [
        "//code/programs/games/word_build/cli:html_exporter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/build_word/game:build_word_puzzle",
        "//code/utilities/linguistics/build_word/game:puzzle_builder",
        "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings_getter",
        "//code/utilities/random:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)

hcp(
    name = "html_exporter",
    deps = [
        "//code/utilities/colors/defaults:color_palettes",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/linguistics/build_word/game:build_word_puzzle",
        "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings",
        "//code/utilities/peripheral/printer:pdf_printer",
        "//code/utilities/program/call:lib",
        "//code/utilities/random:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/vectors/creators:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
