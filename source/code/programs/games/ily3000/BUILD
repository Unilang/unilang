package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "ily",
    srcs = ["ily.cpp"],
    linkopts = [
        "-lGL",
        "-ludev",
    ],
    deps = [
        "//code/programs/games/ily3000/assets:assets_loader",
        "//code/programs/games/ily3000/core:frame_renderer",
        "//code/programs/games/ily3000/core:state_updater",
        "//code/programs/games/ily3000/state:game_state",
        "//code/programs/games/ily3000/state:game_state_getter",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        #"@sdl2",
        #"@glfw",
        "@GL",
        #"@opengl",
        "@sfml",
    ],
)
