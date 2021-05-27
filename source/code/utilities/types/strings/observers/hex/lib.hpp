#pragma once
#include <string>

//to hex
std::string AsHexString(int c);
std::string to_caps_hex(unsigned char *s);
std::string to_caps_hex(std::string const& str);
std::string to_caps_hex_p2(std::string const& str);
std::string string_to_hex(const std::string& input);

//from hex
std::string unhex(std::string const& str);
std::string hex_to_string(const std::string& input);
int hex_value(unsigned char hex_digit);