package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "file_upload_settings",
    deps = [
        "//code/utilities/program/wrappers/git/upload:github_upload_settings",
        "//code/utilities/web/dropbox:upload_to_dropbox_strategy",
        "//code/utilities/web/gdrive:gdrive_upload_settings",
    ],
)

hcp(
    name = "file_uploader",
    deps = [
        "//code/utilities/output/upload:file_upload_settings",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/program/wrappers/git/upload:github_uploader",
        "//code/utilities/web/dropbox:dropbox_uploader",
        "//code/utilities/web/dropbox:upload_to_dropbox_strategy",
        "//code/utilities/web/gdrive:gdrive_uploader",
    ],
)
