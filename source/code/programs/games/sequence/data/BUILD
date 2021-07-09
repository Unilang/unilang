package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "game_state",
    deps = [
        "//code/programs/games/sequence/data:board_space",
        "//code/programs/games/sequence/data:player_state",
        "//code/utilities/assets:playing_card_assets",
        "//code/utilities/data_structures:playing_card",
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/image:data_uri_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:optional",
        "@crow",
    ],
)

hcp(
    name = "player_state",
    deps = [
        "//code/utilities/data_structures:playing_card",
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:optional",
        "@crow",
    ],
)

hcp(
    name = "board_space",
    deps = [
        "//code/utilities/data_structures:playing_card",
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:optional",
        "@crow",
    ],
)
