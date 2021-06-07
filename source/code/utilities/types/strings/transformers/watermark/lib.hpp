#pragma once
#include <string>
#include <vector>


//converters assuming the string represents a binary stream
std::wstring To_Watermark_From_Binary(std::string str);
std::string From_Watermark_To_Binary(std::wstring str);
std::vector<std::wstring> To_Watermark_From_Binary(std::vector<std::string> const& str);
std::vector<std::string> From_Watermark_To_Binary(std::vector<std::wstring> w);

//actual watermark converters
std::vector<std::wstring> Str_To_Watermark(std::string str);
std::string Watermark_To_Str(std::vector<std::wstring> str);
