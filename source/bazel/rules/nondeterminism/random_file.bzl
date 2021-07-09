def create_file_with_randomness(name):
    target_name = name
    outfile = name + "_random.txt"

    native.genrule(
        name = target_name,
        srcs = [],
        outs = [outfile],
        cmd = """
              echo $$RANDOM > $(OUTS)
              """,
    )

def create_file_with_different_data_10_percent_of_time(name):
    target_name = name
    outfile = name + "10_percent_random.txt"

    native.genrule(
        name = target_name,
        srcs = [],
        outs = [outfile],
        cmd = """
              random_number=$$(shuf -i 1-10 -n 1)
              if [ "$$random_number" == "1" ]; then echo "1" > $(OUTS); else echo "not 1" > $(OUTS); fi
              """,
    )
