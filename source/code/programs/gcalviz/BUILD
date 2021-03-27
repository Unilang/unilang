package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "meta_settings",
    deps = [
    ],
)

hcp(
    name = "gcalviz_runner",
    deps = [
        "//code/programs/gcalviz:meta_settings",
        "//code/programs/gcalviz/exporters:connections_exporter",
        "//code/programs/gcalviz/exporters:email_exporter",
        "//code/programs/gcalviz/exporters:email_user_info_exporter",
        "//code/programs/gcalviz/exporters:metrics_exporter",
        "//code/programs/gcalviz/exporters:user_location_info_exporter",
        "//code/programs/gcalviz/settings:default_settings_getter",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/attribute_check:json_attribute_check_settings",
        "//code/utilities/formats/json/attribute_check:json_attribute_checker",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
        "//code/utilities/time/date:rfc333_datetime_within_range_checker",
        "//code/utilities/types/strings/observers/comparing:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/web/automate/browser:browser_creator",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/automate/browser:default_browser_settings_getter",
        "//code/utilities/web/endpoints/gcal:gcal_credentials",
        "//code/utilities/web/endpoints/gcal:gcal_getter",
        "//code/utilities/web/endpoints/gcal/data:gcal_sorted_events",
    ],
)

# hcp(
#     name = "gcalviz_documentation_getter",
#     deps = [
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )

distributable_cpp_main(
    name = "gcalviz",
    depends = [
    ],
    description = "visualize your google calendars as a social network",
    deps = [
        "//code/programs/gcalviz:gcalviz_runner",
        "//code/programs/gcalviz:meta_settings",
    ],
)
