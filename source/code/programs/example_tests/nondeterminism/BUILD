package(default_visibility = ["//visibility:public"])

load("//bazel/rules/nondeterminism:deterministic_output.bzl", "deterministic_output")
load("//bazel/rules/nondeterminism:epoch_file.bzl", "create_file_with_epoch")
load("//bazel/rules/nondeterminism:random_file.bzl", "create_file_with_randomness")

deterministic_output("example_file")

create_file_with_epoch("epoch_file")

create_file_with_randomness("random_file")
