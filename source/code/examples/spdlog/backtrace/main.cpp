#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

int main(){
    // // Loggers can store in a ring buffer all messages (including debug/trace) and display later on demand.
    // // When needed, call dump_backtrace() to see them

    // spdlog::enable_backtrace(32); // Store the latest 32 messages in a buffer. Older messages will be dropped.
    // // or my_logger->enable_backtrace(32)..
    // for(int i = 0; i < 100; i++)
    // {
    //   spdlog::debug("Backtrace message {}", i); // not logged yet..
    // }
    // // e.g. if some error happened:
    // spdlog::dump_backtrace(); // log them now! show the last 32 messages

    // // or my_logger->dump_backtrace(32)..
}