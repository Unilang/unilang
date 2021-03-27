package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "game_state",
    deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/linguistics/build_word/game:build_word_puzzle",
        "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads_phases",
        "//code/utilities/peripheral/keyboard/joycons",
        "@sfml",
    ],
)

hcp(
    name = "game_state_getter",
    deps = [
        "//code/programs/games/scattergories/gui/state:game_state",
        "//code/utilities/linguistics/build_word/game:puzzle_builder",
        "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings_getter",
        "//code/utilities/peripheral/keyboard/joycons",
    ],
)
