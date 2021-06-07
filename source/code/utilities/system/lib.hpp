#pragma once
#include <string>

std::string whoami();
std::string hostname();
std::string env();

bool Does_Program_Exist(std::string const& prog);
void Print_Error_If_Program_Does_Not_Exist(std::string const& prog);
void Exit_With_Error_Message_If_Program_Does_Not_Exist(std::string const& prog);
