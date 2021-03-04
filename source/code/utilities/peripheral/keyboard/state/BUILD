package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

enum_cpp(
    name = "key_state",
    values = [
        "down",
        "pressed",
        "none",
    ],
)

hcp(
    name = "keyboard_state",
    deps = [
        "//code/utilities/peripheral/keyboard/state:key_state",
    ],
)

hcp(
    name = "imgui_keyboard_state_getter",
    deps = [
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/utilities/peripheral/keyboard/state:buffered_chars_getter",
        "//code/utilities/peripheral/keyboard/state:keyboard_state",
    ],
)

hcp(
    name = "buffered_chars_getter",
    deps = [
        "//code/utilities/graphics/imgui/loop:mechanics",
    ],
)

hcp(
    name = "key_codes",
    deps = [
    ],
)
