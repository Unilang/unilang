#pragma once
#include <csignal>
#include <iostream>

template <typename Fun>
void Bind_All_Signals_To_Handler(Fun fun){
    std::signal(SIGABRT, fun);
    std::signal(SIGFPE, fun);
    std::signal(SIGILL, fun);
    std::signal(SIGINT, fun);
    std::signal(SIGSEGV, fun);
    std::signal(SIGTERM, fun);
}
