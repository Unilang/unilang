package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
    ],
    deps = [
        "//code/programs/games/ur/assets:assets_loader",
        "//code/programs/games/ur/core:frame_renderer",
        "//code/programs/games/ur/core:state_updater",
        "//code/programs/games/ur/state:game_state_getter",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "@GL",
        "@sdl2",
        "@sfml",
    ],
)

enum_cpp(
    name = "game_phase",
    values = [
        "main_menu",
        "starting_game",
        "playing_game",
        "end_game",
    ],
)
