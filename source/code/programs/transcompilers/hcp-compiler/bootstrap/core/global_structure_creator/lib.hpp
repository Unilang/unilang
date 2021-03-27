#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/structure/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/structure_state/lib.hpp"

class Global_Structure_Creator{










public:
//constructor and create function
Global_Structure_Creator(std::string const& hcp_file)
;

Class_Structure Create(std::wifstream & infile, std::wstring const& file_type);


//create implementation
private:





wchar_t Set_Next_Char(std::wifstream & infile,Class_Structure & structure);

void Process_Character(Class_Structure & structure);

void Process_Character_Expecting_Header_Include(Class_Structure & structure);
void Process_Character_Expecting_Source_Include(Class_Structure & structure);
void Process_Character_In_Header_Include(Class_Structure & structure);
void Process_Character_In_Source_Include(Class_Structure & structure);
void Process_Character_Expecting_Anything(Class_Structure & structure);
void Process_Character_In_HPP_Only(Class_Structure & structure);
void Process_Character_In_CPP_Only(Class_Structure & structure);
void Process_Character_In_Function_Body(Class_Structure & structure);
void Handle_Escaped_Character(Class_Structure & structure);
void Attempt_To_Print_Escape_Char_To_File(Class_Structure & structure);

//utility
void Error_On_These_Other_Characters(std::wstring const& doing, std::vector<wchar_t> others);
void Output_Compilation_Failure_Message(std::wstring const& message);


//data members
std::string file_name;
std::string path_to_file_name;
Structure_State current_state;
std::wstring include_name_temp;
std::wstring data_member_name_temp;
wchar_t c;
unsigned int line_number;
unsigned int char_number;

};