package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "regular_action",
    values = [

        #navigating game phases
        "restart_game",
        "end_game",
        "go_to_menu",

        #main game control
        "move_left",
        "move_right",
        "select",
        "backspace",
        "clear",
        "none",
    ],
)

hcp(
    name = "regular_actions_getter",
    deps = [
        "//code/programs/games/word_build/gui/core/regular_actions:regular_action",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepad_phases",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
    ],
)
