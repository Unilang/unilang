#pragma once
#include <string>
#include <vector>
#include <utility>

class Class_Structure{






public:

//setters
void Add_Header_Include(std::wstring const& include_name);
void Add_Source_Include(std::wstring const& include_name);
void Append_To_Inheritance(wchar_t const& c);
void Append_To_Inheritance(std::wstring const& str);
void Append_To_HPP_Code(wchar_t const& c);
void Append_To_CPP_Code(wchar_t const& c);
void Append_To_Both_HPP_and_CPP(wchar_t const& c);
void Append_To_HPP_Code(std::wstring const& str);
void Append_To_CPP_Code(std::wstring const& str);
void Append_To_Both_HPP_and_CPP(std::wstring const& str);
void Add_To_After_Headers_Portion(wchar_t const& c);
void Add_File_Type(std::wstring const& str);
void Add_Data_Member(std::wstring const& str);
void Set_File_Name(std::string const& str);
void Set_Path_To_File_Name(std::string const& str);

//getters
std::string                               File_Name()            const;
std::string                               Path_To_File_Name()    const;
std::wstring                              File_Type()            const;
std::vector<std::pair<std::wstring,bool>> Header_Includes()      const;
std::vector<std::pair<std::wstring,bool>> Source_Includes()      const;
std::wstring                              Inheritance()          const;
std::wstring                              HPP_Code()             const;
std::wstring                              CPP_Code()             const;
std::vector<std::wstring>                 Data_Members()         const;


 
//◀private:▶ well.. I want the optimizer to tweak these
//should probably make the optimizer a friend

    std::string file_name;
    std::string path_to_file_name;
    std::wstring file_type;
    std::vector<std::pair<std::wstring,bool>> header_includes;
    std::vector<std::pair<std::wstring,bool>> source_includes;
    std::wstring inheritance;
    std::wstring hpp_code;
    std::wstring cpp_code;
    std::vector<std::wstring> data_members;
    
    //useful for the optimizer. it starts with the character that starts the inheritance
    //because of the way the parser works.  This character is eaten while expecting source include
    //apart from this character, we don't want to store any character observed in the "expecting source" state
    //why? because the optimizer can derive that data later from it's vector variables that hold includes
    std::wstring everything_after_headers = L"⚞";


};