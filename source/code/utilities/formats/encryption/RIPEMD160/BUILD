package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "ripemd160_hasher",
    deps = [
        "@openssl//:crypto",
        "@secp256k1//:lib",
    ],
)
