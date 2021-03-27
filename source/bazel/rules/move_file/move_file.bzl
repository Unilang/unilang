load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/data:data_getter.bzl", "data_getter")

def move_file(target_name, file_name, output_path):
    output_name = file_name + "_dummy"

    #create file
    native.genrule(
        name = target_name,
        srcs = [file_name],
        outs = [output_name],
        tools = ["//code/programs/transcompilers/file_mover:file_mover"],
        cmd = "$(location //code/programs/transcompilers/file_mover:file_mover) -m {} -i $(SRCS) -o $@".format(output_path),
    )
