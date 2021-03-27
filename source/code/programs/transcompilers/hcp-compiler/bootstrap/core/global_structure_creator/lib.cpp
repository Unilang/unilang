#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/global_structure_creator/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/header_validator/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/unicode_parser_symbols/lib.hpp"
#include "code/utilities/types/strings/transformers/stripping/lib.hpp"
#include "code/utilities/types/wstrings/transformers/other/lib.hpp"
#include "code/utilities/types/strings/transformers/other/lib.hpp"
#include "code/utilities/language_basic/multiple_relational_comparing/lib.hpp"
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include <iostream>
#include <fstream>










//constructor and create function
Global_Structure_Creator::Global_Structure_Creator(std::string const& hcp_file)
: line_number(2) //we start at 2 because we read in the file_type (class / global)
, char_number(0)

{
    file_name = Get_File_Name_From_File_Path(hcp_file);
    path_to_file_name = hcp_file;
    current_state = Structure_State::EXPECTING_HEADER_INCLUDE;
}

Class_Structure Global_Structure_Creator::Create(std::wifstream & infile, std::wstring const& file_type){

    Class_Structure structure;
    structure.Add_File_Type(file_type);
    structure.Set_File_Name(file_name);
    structure.Set_Path_To_File_Name(path_to_file_name);
    
    
    while (EOF != Set_Next_Char(infile,structure)) {

        if (c != L'ļ'){
            Process_Character(structure);
        }else{
            //handle escape character sequence
            if(infile){
                Set_Next_Char(infile,structure);
                Handle_Escaped_Character(structure);
            }else{
                Output_Compilation_Failure_Message(L"You shouldn't end your file with an escape character that is not escaping anything.");
            }

        }
    }

    infile.close();
    return structure;
}


//create implementation






wchar_t Global_Structure_Creator::Set_Next_Char(std::wifstream & infile,Class_Structure & structure){
    c = infile.get();
    if (c == L'\n'){
        ++line_number;
        char_number = 0;
    }else{
        ++char_number;
    }
    
    //add to structure variable if we are in a certain state
    switch (current_state){
        case Structure_State::IN_INHERITANCE:
        case Structure_State::IN_HPP_ONLY:
        case Structure_State::IN_CPP_ONLY:
        case Structure_State::IN_FUNCTION_BODY:
        case Structure_State::EXPECTING_ANYTHING:
        case Structure_State::IN_DATA_MEMBER:
        structure.Add_To_After_Headers_Portion(c);
        break;
        default:;
    }
    

    return c;
}

void Global_Structure_Creator::Process_Character(Class_Structure & structure){

    switch (current_state){
        case Structure_State::EXPECTING_HEADER_INCLUDE: Process_Character_Expecting_Header_Include(structure); break;
        case Structure_State::EXPECTING_SOURCE_INCLUDE: Process_Character_Expecting_Source_Include(structure); break;
        case Structure_State::EXPECTING_ANYTHING:       Process_Character_Expecting_Anything(structure);       break;
        case Structure_State::IN_HEADER_INCLUDE:        Process_Character_In_Header_Include(structure);        break;
        case Structure_State::IN_SOURCE_INCLUDE:        Process_Character_In_Source_Include(structure);        break;
        case Structure_State::IN_HPP_ONLY:              Process_Character_In_HPP_Only(structure);              break;
        case Structure_State::IN_CPP_ONLY:              Process_Character_In_CPP_Only(structure);              break;
        case Structure_State::IN_FUNCTION_BODY:         Process_Character_In_Function_Body(structure);         break;
        default: Output_Compilation_Failure_Message(L"Class_Structure has reached an unexpected state while deciding how to handle a character");
    }

    return;
}

void Global_Structure_Creator::Process_Character_Expecting_Header_Include(Class_Structure & structure){

    if (c == L'❪'){current_state=Structure_State::IN_HEADER_INCLUDE;}
    else if(c == L'⚯'){current_state=Structure_State::EXPECTING_SOURCE_INCLUDE;}
    else{
        Error_On_These_Other_Characters(L"while expecting header include",{L'❫',L'☀',L'◈',L'◀',L'▶',L'◖',L'◗',L'❰',L'❱'});
        structure.Append_To_Both_HPP_and_CPP(c);
    }

    return;
}
void Global_Structure_Creator::Process_Character_Expecting_Source_Include(Class_Structure & structure){

    if (c == L'❪'){current_state=Structure_State::IN_SOURCE_INCLUDE;}
    else{
        Error_On_These_Other_Characters(L"while expecting a source include",{L'❫',L'⚯',L'☀',L'◈',L'◀',L'▶',L'◖',L'◗',L'❰',L'❱'});
        structure.Append_To_Both_HPP_and_CPP(c);
    }

    return;
}
void Global_Structure_Creator::Process_Character_In_Header_Include(Class_Structure & structure){

    if (c == L'❫'){
        
        //validate the header name before we add it
        Header_Validator::Validate(file_name,include_name_temp,true);
        
        current_state=Structure_State::EXPECTING_HEADER_INCLUDE;
        structure.Add_Header_Include(include_name_temp);
        include_name_temp.clear();
    }else{
        Error_On_These_Other_Characters(L"while in a header include block",{L'❪',L'⚯',L'☀',L'◈',L'◀',L'▶',L'◖',L'◗',L'❰',L'❱'});
        include_name_temp+= c;
    }

    return;
}
void Global_Structure_Creator::Process_Character_In_Source_Include(Class_Structure & structure){

    if (c == L'❫'){
        
        //validate the header name before we add it
        Header_Validator::Validate(file_name,include_name_temp,false);
        
        current_state=Structure_State::EXPECTING_SOURCE_INCLUDE;
        structure.Add_Source_Include(include_name_temp);
        include_name_temp.clear();
    }else{
        Error_On_These_Other_Characters(L"in a source include block",{L'❪',L'⚯',L'☀',L'◈',L'◀',L'▶',L'◖',L'◗',L'❰',L'❱'});
        include_name_temp+= c;
    }

    return;
}
void Global_Structure_Creator::Process_Character_Expecting_Anything(Class_Structure & structure){

    if(c == L'◀'){
        current_state=Structure_State::IN_HPP_ONLY;
    }else if(c == L'◖'){
        current_state=Structure_State::IN_CPP_ONLY;

    }else if(c == L'☀'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name)) + "::";
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_CPP_Code(wstr);

    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_Both_HPP_and_CPP(wstr);
    }else if(c == L'❰'){
        current_state=Structure_State::IN_FUNCTION_BODY;
        structure.Append_To_HPP_Code(';');
        structure.Append_To_CPP_Code('{');
    }else{
        Error_On_These_Other_Characters(L"while not in a Unicode block",{L'❪',L'❫',L'⚯',L'▶',L'◗',L'❱'});
        structure.Append_To_Both_HPP_and_CPP(c);
    }

    return;
}
void Global_Structure_Creator::Process_Character_In_HPP_Only(Class_Structure & structure){

    if (c == L'▶'){
        current_state=Structure_State::EXPECTING_ANYTHING;
    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_HPP_Code(wstr);
    }else{
        Error_On_These_Other_Characters(L"while in hpp only block",{L'❪',L'❫',L'⚯',L'☀',L'◀',L'◖',L'◗',L'❰',L'❱'});
        structure.Append_To_HPP_Code(c);
    }

    return;
}
void Global_Structure_Creator::Process_Character_In_CPP_Only(Class_Structure & structure){

    if (c == L'◗'){
        current_state=Structure_State::EXPECTING_ANYTHING;
    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_CPP_Code(wstr);
    }else{
        Error_On_These_Other_Characters(L"while in cpp only block",{L'❪',L'❫',L'⚯',L'☀',L'◀',L'▶',L'◖',L'❰',L'❱'});
        structure.Append_To_CPP_Code(c);
    }

    return;
}
void Global_Structure_Creator::Process_Character_In_Function_Body(Class_Structure & structure){

    if(c == L'❱'){
        current_state=Structure_State::EXPECTING_ANYTHING;
        structure.Append_To_CPP_Code('}');
    }else{
        Error_On_These_Other_Characters(L"while in header a include block",{L'❪',L'❫',L'⚯',L'☀',L'◈',L'◀',L'▶',L'◖',L'◗',L'❰'});
        structure.Append_To_CPP_Code(c);
    }
    return;
}
void Global_Structure_Creator::Handle_Escaped_Character(Class_Structure & structure){


    //error if we are escaping a character that does not need to be escaped
    if (c != All_Of(L'❪',L'❫',L'⚯',L'☀',L'◈',L'◀',L'▶',L'◖',L'◗',L'❰',L'❱',L'ļ')){
        Output_Compilation_Failure_Message(L"There is no reason to escape this character");
    }else{
        
        //decide whether to print the escape character
        Attempt_To_Print_Escape_Char_To_File(structure);
    }

    return;
}
void Global_Structure_Creator::Attempt_To_Print_Escape_Char_To_File(Class_Structure & structure){
    
        
    switch (current_state){
        case Structure_State::EXPECTING_ANYTHING: structure.Append_To_Both_HPP_and_CPP(c); break;
        case Structure_State::IN_HPP_ONLY:        structure.Append_To_HPP_Code(c);         break;
        case Structure_State::IN_CPP_ONLY:        structure.Append_To_CPP_Code(c);         break;
        case Structure_State::IN_FUNCTION_BODY:   structure.Append_To_CPP_Code(c);         break;
        default: Output_Compilation_Failure_Message(L"It does not make sense to escape a Unicode character here");
    }
}

//utility
void Global_Structure_Creator::Error_On_These_Other_Characters(std::wstring const& doing, std::vector<wchar_t> others){

    for (auto const& it: others){
        if (c == it){
            
            std::wstring message;
            message += L"got an unexpected special character(";
            message += it; //stack overflow question (maybe we should pass in a wstring instead of std::vector<wchar_t>)
            message += L") ";
            message += doing;
            Output_Compilation_Failure_Message(message);
        }
    }

    return;
}
void Global_Structure_Creator::Output_Compilation_Failure_Message(std::wstring const& message){
    std::cerr << file_name << ":" << line_number << ":" << char_number << ": ";
    std::wcerr << message << '\n';
    exit(EXIT_FAILURE);
    return;
}


