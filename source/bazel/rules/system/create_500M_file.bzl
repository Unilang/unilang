def create_500M_file(name):
    native.genrule(
        name = name + "_target",
        outs = [name],
        output_to_bindir = 1,
        cmd = "truncate -s 500M $@",
    )
