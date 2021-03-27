load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/data:data_getter.bzl", "data_getter")

def unilang_to_code(name):
    #implicit file names
    input_name = name + ".unilang"
    output_name = name + ".json"
    target_name = name + "_json"
    output_target_name = name + "_json_data"

    #create json file
    native.genrule(
        name = target_name,
        srcs = [input_name],
        outs = [output_name],
        tools = ["//code/programs/transcompilers/unilang/unilang_to_code:unilang_to_code"],
        cmd = "$(location //code/programs/transcompilers/unilang/unilang_to_code:unilang_to_code) -i $(SRCS) -o $@",
    )

    #group json file
    native.filegroup(
        name = output_target_name,
        srcs = [target_name],
    )

    #create an hcp file for getting the json file
    output_getter_target_name = name + "_json_data_getter_target"
    hcp_name = name + "_json_data_getter.hcp"
    hcp_name2 = name + "_json_data_getter"
    data_getter(output_getter_target_name, hcp_name, output_name)

    hcp(hcp_name2, deps = [], data = [output_target_name])
