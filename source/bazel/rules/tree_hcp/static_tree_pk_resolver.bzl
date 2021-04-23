load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

def static_tree_pk_resolver(tree, references):
    #the file names to use
    target_name = tree + "_static_tree_pk_resolver_build"
    in_file1 = tree + ".dat"
    in_file2 = references + ".json"
    outfile1 = tree + "_static_tree_pk_resolver.hpp"
    outfile2 = tree + "_static_tree_pk_resolver.cpp"

    #create the tree struct source files
    native.genrule(
        name = target_name,
        srcs = [in_file1, in_file2],
        outs = [outfile1, outfile2],
        tools = ["//code/programs/transcompilers/tree_hcp/static_tree_pk_resolver:static_tree_pk_resolver"],
        cmd = "$(location //code/programs/transcompilers/tree_hcp/static_tree_pk_resolver:static_tree_pk_resolver) -i $(SRCS) --name {}  -o $(@D)".format(tree + "_static_tree_pk_resolver"),
    )

    #compile cpp object
    real_deps = []
    real_deps += ["@tree"]
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    real_deps += ["//code/utilities/code:concept_static_tree_structs"]
    real_deps += ["//code/utilities/formats/json/overloads:tree_json_converters"]
    cpp_object(tree + "_static_tree_pk_resolver", real_deps)
