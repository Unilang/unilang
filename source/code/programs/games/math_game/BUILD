package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "math_game",
    srcs = ["math_game.cpp"],
    linkopts = [
    ],
    deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/core:frame_renderer",
        "//code/programs/games/math_game/core:state_updater",
        "//code/programs/games/math_game/state:game_state",
        "//code/programs/games/math_game/state:game_state_getter",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "@GL",
        "@glfw",
        "@sdl2",
        "@sfml",
    ],
)
