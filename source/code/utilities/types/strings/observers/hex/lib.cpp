#include "code/utilities/types/strings/observers/hex/lib.hpp"
#include "boost/algorithm/hex.hpp"
#include <sstream>
#include <stdexcept>

std::string AsHexString(int c){
  std::ostringstream s;
  s << std::hex << std::uppercase << c;
  return s.str();
}

std::string to_caps_hex(unsigned char *s){
    std::stringstream ss;
    for(int i=0; i<32; ++i)
        ss << std::hex << std::uppercase << (unsigned int)s[i];
    std::string mystr = ss.str();
    return mystr;
}

std::string to_caps_hex(std::string const& str){
    std::stringstream ss;
    for(int i=0; i<str.size(); ++i)
        ss << std::hex << std::uppercase << (unsigned int)str[i];
    std::string mystr = ss.str();
    return mystr;
}

std::string to_caps_hex_p2(std::string const& str){
    std::stringstream ss;
    for(int i=0; i<str.size(); ++i)
        ss << std::hex << std::setfill('0') << std::setw(2)  << static_cast<unsigned int>(static_cast<unsigned char>(str[i]));
    std::string mystr = ss.str();
    return mystr;
}

std::string unhex(std::string const& str){
    std::string new_str;
    boost::algorithm::unhex ( str, std::back_inserter (new_str));
    return new_str;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

int hex_value(unsigned char hex_digit)
{
    static const signed char hex_values[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int value = hex_values[hex_digit];
    if (value == -1) throw std::invalid_argument("invalid hex digit");
    return value;
}

std::string hex_to_string(const std::string& input)
{
    const auto len = input.length();
    if (len & 1) throw std::invalid_argument(std::string("odd length= ") + std::to_string(input.length()) + "/" + std::to_string(input.size()));

    std::string output;
    output.reserve(len / 2);
    for (auto it = input.begin(); it != input.end(); )
    {
        int hi = hex_value(*it++);
        int lo = hex_value(*it++);
        output.push_back(hi << 4 | lo);
    }
    return output;
}