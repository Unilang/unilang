package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "gexf_formatter",
    deps = [
        "//code/programs/gcalviz/exporters/data:edge_data",
        "//code/programs/gcalviz/exporters/data:node_edge_data",
        "//code/programs/gcalviz/exporters/formatters:gexf_attribute",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/json/extraction:json_extractor",
        "//code/utilities/formats/xml:xml_string_escaper",
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
    name = "graphml_formatter",
    deps = [
        "//code/programs/gcalviz/exporters/data:node_edge_data",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
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
    name = "gexf_attribute",
    deps = [
        "//code/utilities/formats/json/extraction:json_extraction_settings",
    ],
)
