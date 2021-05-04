#pragma once
#include <string>
#include <vector>

std::vector<char> Convert_To_Vec_Of_Chars(std::string const& str);

std::vector<int> Collect_Whitespace_Separated_Numbers(std::string const& s);
std::vector<float> Collect_Whitespace_Separated_Floats(std::string const& s);




std::string& Indent_Each_Line_N_Amount(std::string & str, unsigned int amount);
std::string& Add_Prefix_To_Each_Line(std::string & str, std::string const& prefix);
std::string& Add_Prefix_To_All_Lines_Except_First(std::string & str, std::string const& prefix);

std::string& Turn_Any_Whitespace_Chars_Into_A_Space(std::string & str);

//transforming string functions








std::string& Move_First_Word_Of_String_To_The_End(std::string & str);






//other
    std::string& Add_File_Extension(std::string &s, std::string const& extension);
    std::string As_Added_File_Extension(std::string s, std::string const& extension);

    std::string& Replace_File_Extension(std::string &s, std::string const& new_extension);
    std::string As_Replaced_Extension(std::string s, std::string const& new_extension);

    //changing the end of a string (assuming it's a directory name)
    std::string Get_Path_As_A_Number_Of_Directories_Back(std::string dir_name, unsigned int const& amount_back);
    std::string Get_Path_As_One_Directories_Back(std::string dir_name);
    std::string Get_Path_As_Two_Directories_Back(std::string dir_name);
    std::string Get_Path_As_Three_Directories_Back(std::string dir_name);
    
    std::string& Append_To_Front(std::string & str, std::string const& part);
    std::string& Append_To_Back(std::string & str, std::string const& part);

    std::string& Append_To_Front_Of_Each_Line(std::string & str, std::string const& part);
    std::string& Append_To_Back_Of_Each_Line(std::string & str, std::string const& part);

    std::string& Indent_Each_Line(std::string & str, int indent_amount);

std::string& Convert_Non_Digits_To_Spaces(std::string& s);

//strings and bools
void Falsify_Bool_If_Line_Is_Empty(std::string const& line, bool & b);
