#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

void source_info_example()
{
    auto console = spdlog::stdout_logger_mt("console");
    spdlog::set_default_logger(console);
    spdlog::set_pattern("[source %s] [function %!] [line %#] %v");

    SPDLOG_LOGGER_INFO(console, "log with source info"); // Console: "[source example.cpp] [function source_info_example] [line 10] log with source info"
    SPDLOG_INFO("global log with source info"); // Console: "[source example.cpp] [function source_info_example] [line 11] global logger with source info"

    console->info("source info is not printed"); // Console: "[source ] [function ] [line ] source info is not printed"
}


int main(){
    source_info_example();
}