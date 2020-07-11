# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def ubuntu1404Clang10Sysroot():
    http_archive(
        name = "ubuntu_14_04_clang_10_sysroot",
        build_file = "//bazel/deps/build_files:ubuntu_14_04_clang_10_sysroot.BUILD",
        sha256 = "6204f7998b543e7190ba55c7a0fe81d59afcaf8171e9dc34975fbf18bc9e4853",
        strip_prefix = "ubuntu_14_04_clang_10_sysroot-79690a1aefd7fd84e77e9bf785acb1dc82e55c4e",
        urls = [
            "https://github.com/Unilang/ubuntu_14_04_clang_10_sysroot/archive/79690a1aefd7fd84e77e9bf785acb1dc82e55c4e.tar.gz",
        ],
    )
