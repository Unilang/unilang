# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def comGithubGrpcGrpc():
    http_archive(
        name = "com_github_grpc_grpc",
        sha256 = "b3a6378b08680d9c39bf91968b2bbb6a419d203a9d4ca7debd82dbe866014ec9",
        strip_prefix = "grpc-ac6f3a78188ee157a38973e7847a02aba80f4d1f",
        urls = [
            "https://github.com/Unilang/grpc/archive/ac6f3a78188ee157a38973e7847a02aba80f4d1f.tar.gz",
        ],
    )