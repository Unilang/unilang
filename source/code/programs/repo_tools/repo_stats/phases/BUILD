package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "clone_phase",
    deps = [
        "//code/programs/repo_tools/repo_stats/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel/fetch:bazel_fetch_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_cquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/bazel/clean:bazel_clean_runner",
        "//code/utilities/web/statsd:statsd_nc_poster",
        "//code/utilities/data_structures/counters/unique_counter:unique_counter",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/data_structures/endpoint:endpoint",
        "//code/utilities/metrics:metrics_publisher",
    ],
)

hcp(
    name = "fetch_phase",
    deps = [
        "//code/programs/repo_tools/repo_stats/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel/fetch:bazel_fetch_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_cquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/bazel/clean:bazel_clean_runner",
        "//code/utilities/web/statsd:statsd_nc_poster",
        "//code/utilities/data_structures/counters/unique_counter:unique_counter",
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/program/wrappers/bazel/fetch:fetch_results",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/data_structures/endpoint:endpoint",
        "//code/utilities/metrics:metrics_publisher",
        "//code/programs/repo_tools/repo_stats/phases:bes_metrics_getter",
    ],
)

hcp(
    name = "query_phase",
    deps = [
        "//code/programs/repo_tools/repo_stats/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel/fetch:bazel_fetch_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_cquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/bazel/clean:bazel_clean_runner",
        "//code/utilities/web/statsd:statsd_nc_poster",
        "//code/utilities/data_structures/counters/unique_counter:unique_counter",
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/program/wrappers/bazel/fetch:fetch_results",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/data_structures/endpoint:endpoint",
        "//code/utilities/metrics:metrics_publisher",
    ],
)

hcp(
    name = "bes_metrics_getter",
    deps = [
        "//code/programs/repo_tools/repo_stats/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel/fetch:bazel_fetch_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_cquery_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/bazel/clean:bazel_clean_runner",
        "//code/utilities/web/statsd:statsd_nc_poster",
        "//code/utilities/data_structures/counters/unique_counter:unique_counter",
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/program/wrappers/bazel/fetch:fetch_results",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/data_structures/endpoint:endpoint",
        "//code/utilities/metrics:metrics_publisher",
        "//code/programs/repo_tools/repo_stats/phases/data:bes_metrics",
    ],
)