load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

def string_tree_default_references(name):
    #the file names to use
    target_name = name + "_string_default_references_json"
    outfile = name + ".json"

    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [],
        outs = [outfile],
        tools = ["//code/programs/transcompilers/tree_hcp/string_tree_default_references:string_tree_default_references"],
        cmd = "$(location //code/programs/transcompilers/tree_hcp/string_tree_default_references:string_tree_default_references) -o $@",
    )
