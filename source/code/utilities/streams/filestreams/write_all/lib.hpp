#pragma once
#include <string>
#include <vector>
#include <fstream>
void Write_Each_Line_Of_Vector_Into_File(std::string const& file, std::vector<std::string> const& vec);
void Write_Byte_Vec_To_Binary_File(std::string const& file, std::vector<std::uint8_t> const& vec);
