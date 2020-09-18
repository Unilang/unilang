# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def glog():
    http_archive(
        name = "glog",
        sha256 = "bae42ec37b50e156071f5b92d2ff09aa5ece56fd8c58d2175fc1ffea85137664",
        strip_prefix = "glog-0a2e5931bd5ff22fd3bf8999eb8ce776f159cda6",
        urls = [
            "https://github.com/Unilang/glog/archive/0a2e5931bd5ff22fd3bf8999eb8ce776f159cda6.tar.gz",
        ],
        repo_mapping = {
            "@com_github_gflags_gflags": "@gflags",
        },
    )
