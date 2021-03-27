package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")

hcp(
    name = "deskstock_runner",
    deps = [
        "//code/programs/deskstock:default_settings_getter",
        "//code/programs/deskstock:float_sourcer",
        "//code/programs/deskstock:meta_settings",
        "//code/programs/deskstock:system_effecter",
        "//code/programs/deskstock/settings:deskstock_settings",
        "//code/programs/deskstock/settings:deskstock_state",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/chinese:chinese_translations",
        "//code/utilities/math",
        "//code/utilities/output/upload:file_uploader",
        "//code/utilities/peripheral/screen:screen_tint_setter",
        "//code/utilities/peripheral/screen/good_bad:good_bad_screen_tint_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/common_actions/locale:locale_setter",
        "//code/utilities/program/inputs/config:config_monitor",
        "//code/utilities/program/inputs/config:config_monitor_settings",
        "//code/utilities/system:installed_programs_checker",
        "//code/utilities/terminal/good_bad:good_bad_terminal_changer",
        "//code/utilities/time/date:lib",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/endpoints/stock:stock_getter",
    ],
)

hcp(
    name = "float_sourcer",
    deps = [
        "//code/programs/deskstock/settings:deskstock_state",
        "//code/utilities/peripheral/mouse:mouse_controller",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/web:lib",
    ],
)

hcp(
    name = "system_effecter",
    deps = [
        "//code/programs/deskstock/settings:deskstock_state",
        "//code/utilities/peripheral/screen:screen_tint_setter",
        "//code/utilities/program/call:lib",
        "//code/utilities/terminal/good_bad:good_bad_terminal_changer",
        "//code/utilities/terminal/mouse:mouse_terminal_changer",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)

hcp(
    name = "default_settings_getter",
    deps = [
        "//code/programs/deskstock/settings:deskstock_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web/endpoints/stock:stock_getter",
    ],
)

# hcp(
#     name = "deskstock_documentation_getter",
#     deps = [
#         "//code/programs/deskstock:default_settings_getter",
#         "//code/programs/deskstock/settings:startup_settings",
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/formats/json/converters:type_to_json_string",
#         "//code/utilities/types/converters:lib",
#     ],
# )

hcp(
    name = "meta_settings",
    deps = [
    ],
)

distributable_cpp_main(
    name = "deskstock",
    depends = [
        "zlib1g-dev",
        "unzip",
        "redshift",
        "libxdo-dev",
    ],
    description = "Feel the stock market while you work",
    deps = [
        "//code/programs/deskstock:deskstock_runner",
        "//code/programs/deskstock:meta_settings",
    ],
)
