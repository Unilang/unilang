load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/data:data_getter.bzl", "data_getter")

def hcp_data_getter(name, file):
    
    file_group_name = name + "_file_group"
    
    #first group the file
    native.filegroup(
        name = file_group_name,
        srcs = [file],
    )
    
    output_getter_target_name = name + "_data_getter_target"
    hcp_name = name + "_data_getter.hcp"
    data_getter(output_getter_target_name, hcp_name, file)

    hcp_name2 = name + "_data_getter"
    hcp(hcp_name2, deps = [], data = [file_group_name])