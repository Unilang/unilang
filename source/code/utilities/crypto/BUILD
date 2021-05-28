package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

hcp(
    name = "bitcoin_wallet_generator",
    deps = [
        "//code/programs/examples/bitcoin:bitcoin_wallet",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/encryption/BASE58:base58_hasher",
        "//code/utilities/formats/encryption/RIPEMD160:ripemd160_hasher",
        "//code/utilities/formats/encryption/SHA256:sha256_hasher",
        "//code/utilities/linguistics/dictionary:scrabble_2019",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/observers/hex:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@boost//:algorithm",
        "@boost//:range",
        "@fmt",
        "@libbase58//:lib",
        "@openssl//:crypto",
        "@secp256k1//:lib",
    ],
)

gtest(
    name = "bitcoin_wallet_generator_test",
    deps = [
        "//code/utilities/crypto:bitcoin_wallet_generator",
    ],
)
