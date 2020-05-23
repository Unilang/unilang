# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def gtest():
    http_archive(
        name = "gtest",
        build_file = "//bazel/deps/build_files:gtest.BUILD",
        sha256 = "3efbb860886c6018d707f1b5ee3e84d4ef63517ee85744aa2a8cb12b2feef57b",
        strip_prefix = "googletest-e5e2ef7cd27cc089c1d8302a11970ef870554294",
        urls = [
            "https://github.com/Unilang/googletest/archive/e5e2ef7cd27cc089c1d8302a11970ef870554294.tar.gz",
        ],
    )
