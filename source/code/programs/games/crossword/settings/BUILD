package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "crossword_puzzle_settings",
    deps = [
        "//code/programs/games/crossword/settings:crossword_output_settings",
        "//code/programs/games/crossword/settings:crossword_random_place_settings",
        "//code/utilities/colors/defaults:color_palettes",
        "//code/utilities/data_structures/dimensions:two_d_dimensions",
        "//code/utilities/types/char:optional_letter_case",
    ],
)

hcp(
    name = "crossword_puzzle_settings_getter",
    deps = [
        "//code/programs/games/crossword:crossword_words",
        "//code/programs/games/crossword/settings:crossword_puzzle_settings",
        "//code/utilities/colors/defaults:color_palettes",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
    ],
)

hcp(
    name = "crossword_random_place_settings",
    deps = [
    ],
)

hcp(
    name = "crossword_output_settings",
    deps = [
    ],
)
