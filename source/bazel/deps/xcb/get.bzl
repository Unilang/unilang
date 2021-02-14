# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def xcb():
    http_archive(
        name = "xcb",
        build_file = "//bazel/deps/xcb:build.BUILD",
        sha256 = "0e6dceb9133b42a405d06b7336ba0f06884e3bad8af080d817243c78c4a6e409",
        strip_prefix = "xcb-libxcb-ee9dfc9a7658e7fe75d27483bb5ed1ba4d1e2c86",
        urls = [
            "https://github.com/Unilang/xcb-libxcb/archive/ee9dfc9a7658e7fe75d27483bb5ed1ba4d1e2c86.tar.gz",
        ],
        patches = [
            "//bazel/deps/xcb/patches:config.patch",
            "//bazel/deps/xcb/patches:gen.patch",
        ],
        patch_args = [
            "-p1",
        ],
        patch_cmds = [
            "mv src/ xcb/",
        ],
    )