package(
    default_visibility = ["//visibility:public"],
)

# Controller Implementations
cc_binary(
    name = "joycons",
    srcs = ["joycons.cpp"],
    linkopts = [
    ],
    deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "@glfw",
        #"@opengl",
        "@sfml",
    ],
)

cc_binary(
    name = "f310_gamepads",
    srcs = ["f310_gamepads.cpp"],
    linkopts = [
    ],
    deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "@glfw",
        #"@opengl",
        "@sfml",
    ],
)

# SFML generic
cc_binary(
    name = "joystick",
    srcs = ["joystick.cpp"],
    linkopts = [
    ],
    deps = [
        "@sfml",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
    ],
    linkopts = [
    ],
    deps = [
        "@GL",
        "@sfml",
    ],
)
