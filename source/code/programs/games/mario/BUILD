package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("@rules_pkg//:pkg.bzl", "pkg_deb", "pkg_tar")

hcp(
    name = "mario_runner",
    deps = [
        "//code/programs/games/mario:game_settings",
        "//code/programs/games/mario/engine:physics_state",
        "//code/programs/games/mario/engine/user_input:user_action",
        "//code/programs/games/mario/engine/user_input:user_action_getter",
        "//code/programs/games/mario/sound:sounds_loader",
        "//code/programs/games/mario/sprites",
        "//code/programs/games/mario/sprites:sprites_loader",
        "//code/utilities/graphics/x11:lib",
        "//code/utilities/graphics/x11/events:global_event_listener",
        "//code/utilities/graphics/x11/geometry:window_geometry_getter",
        "//code/utilities/graphics/x11/loop:x11_looper",
        "//code/utilities/graphics/x11/main_state:x11_main_state_creator",
        "//code/utilities/graphics/x11/sprite:sprite_loader",
        "//code/utilities/graphics/x11/sprite:sprite_window_creator",
        "//code/utilities/graphics/x11/sprite:sprite_window_drawer",
        "//code/utilities/peripheral/sound:music_player",
        "//code/utilities/peripheral/sound/sdl:sdl_audio",
        "//code/utilities/types/booleans:lib",
    ],
)

# hcp(
#     name = "mario_documentation_getter",
#     deps = [
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )

hcp(
    name = "game_settings",
    deps = [
        "//code/utilities/graphics/x11/main_state:setup_display_settings",
    ],
)

#build main and deploy stuff
cc_binary(
    name = "mario",
    srcs = ["mario.cpp"],
    deps = [
        "//code/programs/games/mario:mario_runner",
    ],
)

package_binaries(
    name = "mario",
    binary_targets = [":mario"],
)

pkg_tar(
    name = "mario_all_deb_data",
    extension = "tar.gz",
    deps = [
        ":mario-data",
        "//code/programs/games/mario/assets:mario_assets-data",
    ],
)

MAINTAINER = "Trevor Hickey <TrevorJamesHickey@gmail.com>"

DEFAULT_VERSION = "1.0"

DEFAULT_HOMEPAGE = "none"

pkg_deb(
    name = "mario-debian-amd64",
    architecture = "amd64",
    data = ":mario_all_deb_data",
    depends = ["libsdl2-mixer-2.0-0"],
    description = "mario on your desktop",
    homepage = DEFAULT_HOMEPAGE,
    maintainer = MAINTAINER,
    package = "mario",
    version = DEFAULT_VERSION,
)
