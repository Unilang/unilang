package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "frame_renderer",
    deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "@sfml",
    ],
)

hcp(
    name = "state_updater",
    deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/core:character_select_screen_handler",
        "//code/programs/games/math_game/core:main_screen_handler",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "@sfml",
    ],
)

hcp(
    name = "main_screen_handler",
    deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/time:timer_transition",
        "@sfml",
    ],
)

hcp(
    name = "character_select_screen_handler",
    deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/time:timer_transition",
        "//code/utilities/types/vectors/observers:lib",
        "@sfml",
    ],
)
