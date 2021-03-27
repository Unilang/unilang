load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

def string_tree_to_static_tree_parser(name):
    #the file names to use
    target_name = name + "_string_tree_parser_dat"
    in_file = name + ".dat"
    outfile = name + "_string_tree_parser.hcp"

    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [in_file],
        outs = [outfile],
        tools = ["//code/programs/transcompilers/tree_hcp/string_tree_to_static_tree_parser:string_tree_to_static_tree_parser"],
        cmd = "$(location //code/programs/transcompilers/tree_hcp/string_tree_to_static_tree_parser:string_tree_to_static_tree_parser) -i $(SRCS) -o $@",
    )

    #compile hcp file

    #unique dep (TODO: dynamically decide)
    static_struct_dep = "//code/utilities/code:concept_static_tree_structs"

    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/data_structures/tree/generic:string_to_string_tree",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/data_structures/tree/generic/tokens:tree_token",
        "//code/utilities/types/vectors/observers:lib",
        static_struct_dep,
    ]
    hcp(name + "_string_tree_parser", deps)
