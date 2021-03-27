package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "noogle_settings",
    deps = [
        "//code/programs/noogle/settings:html_sanitize_settings",
        "//code/programs/noogle/settings:query_expand_settings",
        "//code/programs/noogle/settings:result_to_html_settings",
        "//code/programs/noogle/settings:search_engine_credentials",
        "//code/programs/noogle/settings:show_results_settings",
        "//code/programs/noogle/settings:token_identifier_settings",
        "//code/programs/noogle/settings:url_filter_settings",
        "//code/programs/noogle/settings:word_filter_settings",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/search_engines:search_engine_url_devise_settings",
    ],
)

hcp(
    name = "query_expand_settings",
    deps = [
    ],
)

hcp(
    name = "word_filter_settings",
    deps = [
    ],
)

hcp(
    name = "token_identifier_settings",
    deps = [
    ],
)

hcp(
    name = "url_filter_settings",
    deps = [
    ],
)

hcp(
    name = "search_engine_credentials",
    deps = [
    ],
)

hcp(
    name = "result_to_html_settings",
    deps = [
    ],
)

hcp(
    name = "html_sanitize_settings",
    deps = [
    ],
)

hcp(
    name = "show_results_settings",
    deps = [
        "//code/utilities/chart/ascii:chart_get_settings",
    ],
)

hcp(
    name = "default_settings_getter",
    deps = [
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/settings:query_expand_settings",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/web/automate/browser:default_browser_settings_getter",
        "//code/utilities/web/chrome/driver:chrome_driver_selector",
    ],
)
