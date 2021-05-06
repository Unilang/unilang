package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "bazel_query_runner",
    deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
        "//code/utilities/program/inputs/flags:flag_util",
        "//code/utilities/program/inputs/flags/data:flags",
        "//code/utilities/program/wrappers/bazel:run_environment",
        "//code/utilities/program/wrappers/bazel/query:query_deps_flags",
        "//code/utilities/random:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@bazel//:build_proto_cpp",
        "@bazel//:spawn_proto_cpp",
    ],
)

hcp(
    name = "bazel_aquery_runner",
    deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/inputs/flags:flag_util",
        "//code/utilities/program/inputs/flags/data:flags",
        "//code/utilities/program/wrappers/bazel:run_environment",
        "//code/utilities/program/wrappers/bazel/query:query_deps_flags",
        "//code/utilities/random:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/program/wrappers/bazel/query/data:aquery_results",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
        "//code/utilities/time/profile:function_profiler",
        "@bazel//:analysis_proto_cpp",
        "@bazel//:spawn_proto_cpp",
    ],
)

hcp(
    name = "bazel_cquery_runner",
    deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
        "//code/utilities/program/inputs/flags:flag_util",
        "//code/utilities/program/inputs/flags/data:flags",
        "//code/utilities/program/wrappers/bazel:run_environment",
        "//code/utilities/program/wrappers/bazel/query:query_deps_flags",
        "//code/utilities/program/wrappers/bazel/query/data:cquery_results",
        "//code/utilities/random:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/time/profile:function_profiler",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@bazel//:analysis_proto_cpp",
        "@bazel//:spawn_proto_cpp",
    ],
)

hcp(
    name = "query_deps_flags",
    deps = [
    ],
)
