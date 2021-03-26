#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#include "spdlog/spdlog.h"

int main() 
{
    
    spdlog::set_pattern("[%c] [%s:%!:%#] %v");
    SPDLOG_DEBUG("hello");
}