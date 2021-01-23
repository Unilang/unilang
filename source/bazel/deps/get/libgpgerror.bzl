# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def libgpgError():
    http_archive(
        name = "libgpgerror",
        build_file = "//bazel/deps/build_files:libgpgerror.BUILD",
        sha256 = "46d749c769008a225c26d140632303f15c699f4b903f57920e55560c63eeb868",
        strip_prefix = "libgpg-error-8047ca99858a7ee812ef11ed3bd2868e920ac1b7",
        urls = [
            "https://github.com/Unilang/libgpg-error/archive/8047ca99858a7ee812ef11ed3bd2868e920ac1b7.tar.gz",
        ],
        patches = [
            "//bazel/deps/build_files:libgpg-error.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )