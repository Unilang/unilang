package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "base58_hasher",
    deps = [
        "//code/utilities/types/strings/observers/hex:lib",
        "@openssl//:crypto",
        "@secp256k1//:lib",
        "@libbase58//:lib",
    ],
)
