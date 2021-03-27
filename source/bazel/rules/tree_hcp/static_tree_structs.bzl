load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

def static_tree_structs(name):
    #the file names to use
    target_name = name + "_static_tree_structs_dat"
    in_file = name + ".dat"
    outfile1 = name + "_static_tree_structs.hpp"
    outfile2 = name + "_static_tree_structs.cpp"

    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [in_file],
        outs = [outfile1, outfile2],
        tools = ["//code/programs/transcompilers/tree_hcp/static_tree_structs:static_tree_structs"],
        cmd = "$(location //code/programs/transcompilers/tree_hcp/static_tree_structs:static_tree_structs) -i $(SRCS) --name {}  -o $(@D)".format(name + "_static_tree_structs"),
    )

    #compile cpp object
    real_deps = []
    real_deps += ["@tree"]
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    real_deps += ["//code/utilities/formats/json/overloads:tree_json_converters"]
    cpp_object(name + "_static_tree_structs", real_deps)
