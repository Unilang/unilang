# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def plantuml():
    http_archive(
        name="plantuml" ,
        build_file="//bazel/deps/build_files:plantuml.BUILD" ,
        sha256="684149be1def4fcb1c146ca07cfad0d0baec68014dc689dc32212d0b29db2949" ,
        strip_prefix="plantuml-9ba7d08d5247cac5ec47a5f0052da3aaad0e8479" ,
        urls = [
            "https://github.com/Unilang/plantuml/archive/9ba7d08d5247cac5ec47a5f0052da3aaad0e8479.tar.gz",
        ]
    )
