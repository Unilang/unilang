package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")

hcp(
    name = "meta_settings",
    deps = [
    ],
)

hcp(
    name = "noogle_result",
    deps = [
    ],
)

hcp(
    name = "queue_state",
    deps = [
    ],
)

# hcp(
#     name = "noogle_documentation_getter",
#     deps = [
#         "//code/programs/noogle/program_options:lib",
#         "//code/utilities/documentation:common_documentation_getter",
#         "//code/utilities/formats/json/converters:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )

hcp(
    name = "query_extender",
    deps = [
        "//code/programs/noogle/settings:noogle_settings",
    ],
)

hcp(
    name = "results_shower",
    deps = [
        "//code/programs/noogle:noogle_result",
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/chart/ascii:chart_getter",
        "//code/utilities/colors:lib",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
        "//code/utilities/output/printers:lib",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/characteristic:is_month_word_checker",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "results_url_to_html_converter",
    deps = [
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/url:url_parser",
        "@boost//:asio",
    ],
)

hcp(
    name = "noogle_results_extractor",
    deps = [
        "//code/programs/noogle:noogle_result",
        "//code/programs/noogle:token_adder",
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp(
    name = "html_sanitizer",
    deps = [
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/html:html_raw_text_getter",
        "//code/utilities/web:lib",
        "//code/utilities/web/url:url_parser",
    ],
)

hcp(
    name = "noogle_runner",
    deps = [
        "//code/programs/noogle:meta_settings",
        "//code/utilities/web/chrome/driver:chrome_driver_selector",
        "//code/utilities/web/automate/browser:browser_creator",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/automate/navigation:browser_navigator",
        "//code/programs/noogle/settings:default_settings_getter",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "@pybind11",
        "@boost//:asio",
        #"@boost//:stacktrace",
        "//code/utilities/web/url:url_parser",
        "//code/programs/noogle/settings:noogle_settings",
        "//code/utilities/data_structures/queue:safe_queue",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/web/google:google_search_url_deviser",
        "//code/utilities/web/google:google_json_url_deviser",
        "//code/utilities/web:lib",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/output/printers:lib",
        "//code/programs/noogle:noogle_result",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/characteristic:spirit_numeric_checker",
        "//code/programs/noogle/program_options:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/chart/ascii:chart_getter",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/characteristic:english_number_to_integral_converter",
        "//code/utilities/types/strings/observers/characteristic:is_english_number_checker",
        "//code/programs/noogle:results_shower",
        "//code/utilities/web/bing:bing_json_url_deviser",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/types/strings/transformers/html:html_raw_text_getter",
        "//code/programs/noogle:token_adder",
        "//code/programs/noogle:query_extender",
        "//code/utilities/program/common_actions/signals:lib",
        "//code/programs/noogle/state:noogle_state_getter",
        "//code/utilities/web/search_engines:search_engine_url_deviser",
        "//code/utilities/formats/json/converters:lib",
        "//code/programs/noogle:results_url_getter",
        "//code/programs/noogle:results_url_to_html_converter",
        "//code/programs/noogle:html_sanitizer",
        "//code/programs/noogle:input_poller",
        "//code/utilities/ncurses:scoped_getch",
        "//code/programs/noogle:noogle_results_extractor",
    ],
)

hcp(
    name = "input_poller",
    deps = [
        "//code/programs/noogle/state:noogle_running_stats",
        "@getch",
    ],
)

hcp(
    name = "results_url_getter",
    deps = [
        "//code/programs/noogle:results_shower",
        "//code/programs/noogle/settings:default_settings_getter",
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/chart/ascii:chart_getter",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/characteristic:english_number_to_integral_converter",
        "//code/utilities/types/strings/observers/characteristic:is_english_number_checker",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/html:html_raw_text_getter",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/automate/browser:browser_creator",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/automate/navigation:browser_navigator",
        "//code/utilities/web/bing:bing_json_url_deviser",
        "//code/utilities/web/google:google_json_url_deviser",
        "//code/utilities/web/google:google_search_url_deviser",
        "//code/utilities/web/search_engines:search_engine_fetch_settings",
        "//code/utilities/web/search_engines:search_engine_url_deviser",
        "//code/utilities/web/url:url_parser",
        "@fmt",
        "@pybind11",
    ],
)

hcp(
    name = "token_adder",
    deps = [
        "//code/programs/noogle/settings:noogle_settings",
        "//code/programs/noogle/state:noogle_running_stats",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/characteristic:english_number_to_integral_converter",
        "//code/utilities/types/strings/observers/characteristic:is_english_number_checker",
        "//code/utilities/types/strings/observers/characteristic:spirit_numeric_checker",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

distributable_data(
    name = "chrome_drivers",
    description = "chrome drivers for automating google chrome with selenium",
    file_groups = ["@chrome_drivers//:all"],
)

distributable_cpp_main(
    name = "noogle",
    depends = [
        "zlib1g-dev",
        "unzip",
        "python3",
        "python3-bs4",
    ],
    description = "google but numbers",
    deps = [
        "//code/programs/noogle:meta_settings",
        "//code/programs/noogle:noogle_runner",
        "//code/programs/noogle/program_options:lib",
    ],
)
