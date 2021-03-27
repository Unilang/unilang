package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
    ],
    deps = [
        "//code/programs/games/scattergories/gui/assets:assets_loader",
        "//code/programs/games/scattergories/gui/core:frame_renderer",
        "//code/programs/games/scattergories/gui/core:state_updater",
        "//code/programs/games/scattergories/gui/state:game_state",
        "//code/programs/games/scattergories/gui/state:game_state_getter",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        #"@SDL2",
        #"@glfw",
        #"@opengl",
        "@GL",
        "@sfml",
    ],
)
