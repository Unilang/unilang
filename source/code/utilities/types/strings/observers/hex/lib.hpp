#pragma once
#include <string>

//to hex
std::string AsHexString(int c);
std::string to_caps_hex(unsigned char *s);
std::string to_caps_hex(std::string const& str);
std::string to_caps_hex_p2(std::string const& str);

//from hex
std::string unhex(std::string const& str);