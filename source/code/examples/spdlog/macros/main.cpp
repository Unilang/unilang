#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG

#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

int main(int, char* [])
{

    spdlog::set_level(spdlog::level::debug); // or spdlog::set_level(spdlog::level::trace); 

    auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
    SPDLOG_LOGGER_TRACE(file_logger , "Some trace message that will not be evaluated.{} ,{}", 1, 3.23);
    SPDLOG_LOGGER_DEBUG(file_logger , "Some Debug message that will be evaluated.. {} ,{}", 1, 3.23);
    SPDLOG_DEBUG("Some debug message to default logger that will be evaluated");

}