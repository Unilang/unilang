# THIS WAS COPIED FROM:
# https://github.com/bazelbuild/remote-apis/blob/master/external/BUILD.googleapis
# And then I adjusted it because I had a newer version of googleapis
# I would have liked to use th BUILD files that were already in googleapis but it was difficult,
# because remote-apis don't use them directly.  And its hard to have both the self-hosted googleapi BUILDS + custom.
package(default_visibility = ["//visibility:public"])

load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

licenses(["notice"])

proto_library(
    name = "google_api_annotations_proto",
    srcs = ["google/api/annotations.proto"],
    deps = [
        ":google_api_http_proto",
        "@com_google_protobuf//:descriptor_proto",
    ],
)

cc_grpc_library(
    name = "google_api_annotations_cc_proto",
    srcs = ["google/api/annotations.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [":google_api_http_cc_proto",
    
    ],
)

proto_library(
    name = "google_api_http_proto",
    srcs = ["google/api/http.proto"],
)

cc_grpc_library(
    name = "google_api_http_cc_proto",
    srcs = ["google/api/http.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [],
)

proto_library(
    name = "google_longrunning_operations_proto",
    srcs = ["google/longrunning/operations.proto"],
    deps = [
        ":google_api_annotations_proto",
        ":google_api_client_proto",
        ":google_api_http_proto",
        ":google_rpc_status_proto",
        "@com_google_protobuf//:any_proto",
        "@com_google_protobuf//:descriptor_proto",
        "@com_google_protobuf//:duration_proto",
        "@com_google_protobuf//:empty_proto",
    ],
)

cc_grpc_library(
    name = "google_longrunning_operations_cc_proto",
    srcs = ["google/longrunning/operations.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [
        ":google_api_annotations_cc_proto",
        ":google_api_client_cc_proto",
        ":google_api_http_cc_proto",
        ":google_rpc_status_cc_proto",
    ],
)

proto_library(
    name = "google_rpc_status_proto",
    srcs = ["google/rpc/status.proto"],
    deps = ["@com_google_protobuf//:any_proto"],
)

cc_grpc_library(
    name = "google_rpc_status_cc_proto",
    srcs = ["google/rpc/status.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [],
)

proto_library(
    name = "google_api_client_proto",
    srcs = ["google/api/client.proto"],
    deps = [
        "@com_google_protobuf//:descriptor_proto",
    ],
)

cc_grpc_library(
    name = "google_api_client_cc_proto",
    srcs = ["google/api/client.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [],
)

proto_library(
    name = "google_bytestream_bytestream_proto",
    srcs = ["google/bytestream/bytestream.proto"],
    deps = [
        ":google_api_annotations_proto",
        "@com_google_protobuf//:wrappers_proto",
    ],
)

cc_grpc_library(
    name = "google_bytestream_bytestream_cc_proto",
    srcs = ["google/bytestream/bytestream.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [
        ":google_api_annotations_cc_proto",
    ],
)
