# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def uuid():
    http_archive(
        name = "uuid",
        build_file = "//bazel/deps/build_files:uuid.BUILD",
        sha256 = "9283885688c5ab1c90c9e4072484b14937062a634632400a356ded8972317afd",
        strip_prefix = "uuid-f895102e2ddaf86387a62c3544abb78c0a5cfbae",
        urls = [
            "https://github.com/Unilang/uuid/archive/f895102e2ddaf86387a62c3544abb78c0a5cfbae.tar.gz",
        ],
    )
