package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "bitcoin_wallet_generator",
    deps = [
        "//code/programs/examples/bitcoin:bitcoin_wallet",
        "//code/utilities/formats/encryption/SHA256:sha256_hasher",
        "//code/utilities/formats/encryption/RIPEMD160:ripemd160_hasher",
        "//code/utilities/formats/encryption/BASE58:base58_hasher",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/linguistics/dictionary:scrabble_2019",
        "//code/utilities/types/strings/observers/hex:lib",
        "@boost//:algorithm",
        "@boost//:range",
        "@openssl//:crypto",
        "@secp256k1//:lib",
        "@libbase58//:lib",
        "@fmt",
    ],
)