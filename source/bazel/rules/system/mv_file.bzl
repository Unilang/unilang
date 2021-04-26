def mv_file(name, file_from, file_to):
    native.genrule(
        name = name + "_target",
        srcs = [file_from],
        outs = [file_to],
        output_to_bindir = 1,
        cmd = "mv $< $@",
    )
