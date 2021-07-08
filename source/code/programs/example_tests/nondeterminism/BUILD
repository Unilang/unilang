package(default_visibility = ["//visibility:public"])

load("//bazel/rules/nondeterminism:deterministic_output.bzl", "deterministic_output")
load("//bazel/rules/nondeterminism:epoch_file.bzl", "create_file_with_epoch")
load("//bazel/rules/nondeterminism:random_file.bzl", "create_file_with_randomness")
load("//bazel/rules/nondeterminism:random_file.bzl", "create_file_with_different_data_10_percent_of_time")

deterministic_output("is_deterministic")

create_file_with_epoch("epoch_file")

create_file_with_randomness("random_file")
create_file_with_different_data_10_percent_of_time("10_percent_different");
