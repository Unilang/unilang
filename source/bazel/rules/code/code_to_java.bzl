load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/data:data_getter.bzl", "data_getter")

def code_to_java(name):
    target_name = name + "_java"
    input_name = name + ".json"
    output_name = name + ".java"

    #create file
    native.genrule(
        name = target_name,
        srcs = [input_name],
        outs = [output_name],
        tools = ["//code/programs/transcompilers/code/code_to_java:code_to_java"],
        cmd = "$(location //code/programs/transcompilers/code/code_to_java:code_to_java) -i $(SRCS) -o $@",
    )
