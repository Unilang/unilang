# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def rulesFuzzing():
    http_archive(
        name = "rules_fuzzing",
        sha256 = "d6cd2fda74ddf25a066585b7af378cfcbdb7ddcca783480432cb0debfbce6907",
        strip_prefix = "rules_fuzzing-ce7b85c762cbb8ff2697b053ae7b7c9e43dd4a99",
        urls = [
            "https://github.com/Unilang/rules_fuzzing/archive/ce7b85c762cbb8ff2697b053ae7b7c9e43dd4a99.tar.gz",
        ],
    )
