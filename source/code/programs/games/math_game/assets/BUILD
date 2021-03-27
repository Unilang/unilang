package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "title_screen_assets",
    deps = [
        "//code/utilities/graphics/sfml/sprite:textured_sprite",
        "@sfml",
    ],
)

hcp(
    name = "character_selection_assets",
    deps = [
        "//code/utilities/graphics/sfml/sprite:textured_sprite",
        "@sfml",
    ],
)

hcp(
    name = "character",
    deps = [
        "//code/utilities/graphics/sfml/sprite:textured_sprite",
        "@sfml",
    ],
)

hcp(
    name = "assets",
    deps = [
        "//code/programs/games/math_game/assets:character",
        "//code/programs/games/math_game/assets:character_selection_assets",
        "//code/programs/games/math_game/assets:title_screen_assets",
        "//code/utilities/graphics/sfml/sprite:textured_sprite",
        "//code/utilities/peripheral/sound/sfml:sound",
        "@sfml",
    ],
)

hcp(
    name = "assets_loader",
    deps = [
        "//code/programs/games/math_game/assets",
        "//code/utilities/fonts/sfml:font_loader",
        "//code/utilities/graphics/sfml/sprite:textured_sprite_loader",
        "//code/utilities/peripheral/sound/sfml:music_loader",
        "//code/utilities/peripheral/sound/sfml:sound_loader",
        "@sfml",
    ],
)
