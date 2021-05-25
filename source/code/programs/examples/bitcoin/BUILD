load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

package(
    default_visibility = ["//visibility:public"],
)

hcp(
    name = "bitcoin_wallet",
    deps = [],
)

cpp_main(
    name = "gen",
    deps = [
        "@openssl//:crypto",
        "@secp256k1//:lib",
        "//code/programs/examples/bitcoin:bitcoin_wallet",
    ],
)

cpp_main(
    name = "gen2",
    deps = [
        "@openssl//:crypto",
        "@secp256k1//:lib",
    ],
)

cpp_main(
    name = "gen3",
    deps = [
        "@openssl//:crypto",
        "@secp256k1//:lib",
    ],
)

