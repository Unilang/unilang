load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

def string_tree_getter(name):
    #the file names to use
    target_name = name + "_string_tree_getter_dat"
    in_file = name + ".dat"
    outfile = name + "_string_tree_getter.hcp"

    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [in_file],
        outs = [outfile],
        tools = ["//code/programs/transcompilers/tree_hcp/string_tree_getter:string_tree_getter"],
        cmd = "$(location //code/programs/transcompilers/tree_hcp/string_tree_getter:string_tree_getter) -i $(SRCS) -o $@",
    )

    #compile hcp file
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/data_structures/tree/generic:string_to_string_tree",
        "//code/utilities/types/strings/transformers/appending:lib",
    ]
    hcp(name + "_string_tree_getter", deps)
