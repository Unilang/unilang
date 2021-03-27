package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "assets",
    deps = [
        "//code/utilities/graphics/sfml/data:moving_text",
        "//code/utilities/peripheral/sound/sfml:sound",
        "@sfml",
    ],
)

hcp(
    name = "assets_loader",
    deps = [
        "//code/programs/games/scattergories/gui/assets",
        "//code/programs/games/scattergories/gui/state:game_state",
        "//code/utilities/fonts/font_files:droid_sans_mono",
        "//code/utilities/fonts/sfml:font_loader",
        "//code/utilities/linguistics:scattergories_categories",
        "//code/utilities/peripheral/sound/sfml:sound_loader",
        "//code/utilities/random:lib",
        "@sfml",
    ],
)
