#pragma once
#include <string>

//stripping
std::string Strip_Out_Data_Between_First_Set_Of_Single_Quotes(std::string const& str);
std::string Strip_Out_Data_Between_First_Set_Of_Double_Quotes(std::string const& str);
std::string Strip_Out_Data_Between_First_Set_Of_Square_Brackets(std::string & str);
std::string Strip_Out_From_End_Until_Char_Is_Found(std::string const& str, char const& c);
std::string Strip_Out_From_Front_Until_Char_Is_Found(std::string const& str, char const& c);
std::string Strip_Out_From_Front_Until_Number_Is_Found(std::string const& str);
std::string Strip_Out_All_Numbers(std::string const& str);

std::string Get_File_Name_From_File_Path(std::string const& file_path);
std::string Get_File_Path_Without_The_Filename(std::string file_path);
