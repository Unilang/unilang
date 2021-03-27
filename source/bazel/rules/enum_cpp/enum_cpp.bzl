def enum_cpp(name, values = []):
    #implicit file names
    explicit_cpp_file = name + ".cpp"
    explicit_hpp_file = name + ".hpp"
    enum_target_name = name + "_enum"
    cpp_target_name = name

    #converting bazel rules to c++ enum files
    native.genrule(
        name = enum_target_name,
        srcs = [],
        outs = [explicit_cpp_file, explicit_hpp_file],
        tools = ["//code/programs/transcompilers/enum_cpp:enum_cpp"],
        cmd = "$(location //code/programs/transcompilers/enum_cpp:enum_cpp) --enum_name {} --enum_values {} -o $(@D)".format(name, " ".join(values)),
    )

    #compile object file
    native.cc_library(
        name = cpp_target_name,
        srcs = [explicit_cpp_file],
        hdrs = [explicit_hpp_file],
    )
