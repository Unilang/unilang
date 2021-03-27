package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "deskstock_state",
    deps = [
        "//code/programs/deskstock/settings:deskstock_settings",
        "//code/utilities/program/inputs/config:config_monitor_settings",
    ],
)

hcp(
    name = "deskstock_settings",
    deps = [
        "//code/programs/deskstock/settings:monitor_settings",
        "//code/programs/deskstock/settings:startup_settings",
        "//code/programs/deskstock/settings:system_effect_settings",
        "//code/programs/deskstock/settings:value_get_settings",
    ],
)

hcp(
    name = "value_get_settings",
    deps = [
        "//code/programs/deskstock/settings:mouse_value_settings",
        "//code/programs/deskstock/settings:simulation_value_settings",
        "//code/programs/deskstock/settings:user_command_settings",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp(
    name = "simulation_value_settings",
    deps = [
    ],
)

hcp(
    name = "system_effect_settings",
    deps = [
        "//code/programs/deskstock/settings:user_command_settings",
        "//code/utilities/peripheral/screen/good_bad:good_bad_screen_tint_settings",
        "//code/utilities/terminal/good_bad:good_bad_terminal_settings",
        "//code/utilities/terminal/mouse:mouse_terminal_settings",
    ],
)

hcp(
    name = "startup_settings",
    deps = [
        "//code/utilities/program/common_actions/locale:locale_settings",
        "//code/utilities/system:check_installed_program_settings",
    ],
)

hcp(
    name = "user_command_settings",
    deps = [
    ],
)

hcp(
    name = "mouse_value_settings",
    deps = [
    ],
)

hcp(
    name = "monitor_settings",
    deps = [
    ],
)
