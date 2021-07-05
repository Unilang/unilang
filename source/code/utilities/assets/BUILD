package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "puyo",
    data = ["@PuyoPuyoAssets//:all"],
    deps = [],
)

hcp(
    name = "english_sounds",
    data = ["@english_sounds//:all"],
    deps = [],
)

hcp(
    name = "playing_card_assets",
    data = ["@playing_card_assets//:all"],
    deps = [
        "//code/utilities/data_structures:playing_card",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "chrome_drivers",
    data = ["@chrome_drivers//:all"],
    deps = [],
)
