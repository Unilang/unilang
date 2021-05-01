load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("@rules_pkg//:pkg.bzl", "pkg_deb", "pkg_tar")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")

def distributable_cpp_main(name, description, depends = [], deps = []):
    AMD_64_EXTENSION = "-debian-amd64"
    EVERYTHING_EXTENSION = "-debian-all"
    MAINTAINER = "Trevor Hickey <TrevorJamesHickey@gmail.com>"
    DEFAULT_VERSION = "1.0"
    DEFAULT_HOMEPAGE = "none"
    DATA_TARGET = ":" + name + "-data"

    cpp_main(name, deps)

    # package the binaries into tar files
    package_binaries(
        name = name,
        binary_targets = [":" + name],
    )

    # create debian files
    amd_name = name + AMD_64_EXTENSION
    pkg_deb(
        name = amd_name,
        data = DATA_TARGET,
        package = name,
        architecture = "amd64",
        maintainer = MAINTAINER,
        version = DEFAULT_VERSION,
        description = description,
        homepage = DEFAULT_HOMEPAGE,
        depends = depends,
    )

    all_name = name + EVERYTHING_EXTENSION
    pkg_deb(
        name = all_name,
        data = DATA_TARGET,
        package = name,
        architecture = "all",
        maintainer = MAINTAINER,
        version = DEFAULT_VERSION,
        description = description,
        homepage = DEFAULT_HOMEPAGE,
        depends = depends,
    )
    
    # create a file grouping of deb files so a program can access them for software deployment
    group_name = name + "_debs"
    native.filegroup(
        name = group_name,
        srcs = [name,amd_name,all_name],
    )
