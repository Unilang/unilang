package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "connections_exporter",
    deps = [
        "//code/programs/gcalviz/exporters/data:edge_data",
        "//code/programs/gcalviz/exporters/data:node_edge_data",
        "//code/programs/gcalviz/exporters/formatters:gexf_formatter",
        "//code/programs/gcalviz/exporters/formatters:graphml_formatter",
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
        "//code/utilities/web/endpoints/gcal/data:gcal_sorted_events",
    ],
)

hcp(
    name = "metrics_exporter",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
        "//code/utilities/time/date:rfc333_datetime_within_range_checker",
        "//code/utilities/types/strings/observers/comparing:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/web/endpoints/gcal/data:gcal_rooms",
        "//code/utilities/web/endpoints/gcal/data:gcal_sorted_events",
    ],
)

hcp(
    name = "email_exporter",
    deps = [
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
        "//code/utilities/web/endpoints/gcal/data:gcal_rooms",
        "//code/utilities/web/endpoints/gcal/data:gcal_sorted_events",
    ],
)

hcp(
    name = "email_user_info_exporter",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/attribute_check:json_attribute_check_settings",
        "//code/utilities/formats/json/attribute_check:json_attribute_checker",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/program/common_actions/signals:lib",
        "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
        "//code/utilities/time/date:rfc333_datetime_within_range_checker",
        "//code/utilities/types/strings/observers/comparing:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/web/automate/browser:browser_creator",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/automate/browser:default_browser_settings_getter",
        "//code/utilities/web/automate/navigation:browser_navigator",
        "//code/utilities/web/endpoints/gcal/data:gcal_rooms",
        "//code/utilities/web/endpoints/gcal/data:gcal_sorted_events",
        "@pybind11",
    ],
)

hcp(
    name = "user_location_info_exporter",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/attribute_check:json_attribute_check_settings",
        "//code/utilities/formats/json/attribute_check:json_attribute_checker",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/program/common_actions/signals:lib",
        "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
        "//code/utilities/time/date:rfc333_datetime_within_range_checker",
        "//code/utilities/types/strings/observers/comparing:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/web/automate/browser:browser_creator",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/automate/browser:default_browser_settings_getter",
        "//code/utilities/web/automate/navigation:browser_navigator",
        "//code/utilities/web/endpoints/gcal/data:gcal_rooms",
        "//code/utilities/web/endpoints/gcal/data:gcal_sorted_events",
        "@pybind11",
    ],
)
