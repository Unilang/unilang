package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/unilang:transfer_unilang_java.bzl", "transfer_unilang_java")
load("//bazel/rules/code:code_to_java.bzl", "code_to_java")
load("//bazel/rules/move_file:move_file.bzl", "move_file")
load("//bazel/rules/move_file:move_file_java.bzl", "move_java_file")

transfer_unilang_java("redis_counter", "/home/luxe/Desktop/repos/bazel-buildfarm/src/main/java/build/buildfarm/common/redis/RedisCounter.java")

transfer_unilang_java("redis_hash_map", "/home/luxe/Desktop/repos/bazel-buildfarm/src/main/java/build/buildfarm/common/redis/RedisHashMap.java")
