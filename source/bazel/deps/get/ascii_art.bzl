# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def asciiArt():
    http_archive(
        name = "ascii_art",
        build_file = "//bazel/deps/build_files:ascii_art.BUILD",
        sha256 = "f9c39de719465379496a44f02e2886074af962a3d2497bb0a9d2fbb91af935cd",
        strip_prefix = "ascii_art-fede354e511b5be12726a67abaa3d561ffc763db",
        urls = [
            "https://github.com/Unilang/ascii_art/archive/fede354e511b5be12726a67abaa3d561ffc763db.tar.gz",
        ],
    )
