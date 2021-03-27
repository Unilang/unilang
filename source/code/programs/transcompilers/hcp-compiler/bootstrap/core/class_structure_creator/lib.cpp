#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/class_structure_creator/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/header_validator/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/unicode_parser_symbols/lib.hpp"
#include "code/utilities/types/strings/transformers/stripping/lib.hpp"
#include "code/utilities/types/wstrings/transformers/other/lib.hpp"
#include "code/utilities/types/strings/transformers/other/lib.hpp"
#include "code/utilities/language_basic/multiple_relational_comparing/lib.hpp"
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"





//constructor and create function
Class_Structure_Creator::Class_Structure_Creator(std::string const& hcp_file)
: line_number(2) //we start at 2 because we read in the file_type (class / global)
, char_number(0)

{
    file_name = Get_File_Name_From_File_Path(hcp_file);
    path_to_file_name = hcp_file;
    current_state = Structure_State::EXPECTING_HEADER_INCLUDE;
}

Class_Structure Class_Structure_Creator::Create(std::wifstream & infile, std::wstring const& file_type){

    Class_Structure structure;
    
    //some data based on the actual file
    structure.Add_File_Type(file_type);
    structure.Set_File_Name(file_name);
    structure.Set_Path_To_File_Name(path_to_file_name);
    
    //analyze each character at a time (we keep refreshing the data member "c"s value)
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






wchar_t Class_Structure_Creator::Set_Next_Char(std::wifstream & infile,Class_Structure & structure){
    c = infile.get();
    if (c == L'\n'){
        ++line_number;
        char_number = 0;
    }else{
        ++char_number;
    }
    
    //add to structure variable if we are in a certain state
    //this little addition is kind of hacky
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

void Class_Structure_Creator::Process_Character(Class_Structure & structure){

    switch (current_state){
        case Structure_State::EXPECTING_HEADER_INCLUDE: Process_Character_Expecting_Header_Include(structure); break;
        case Structure_State::EXPECTING_SOURCE_INCLUDE: Process_Character_Expecting_Source_Include(structure); break;
        case Structure_State::EXPECTING_ANYTHING:       Process_Character_Expecting_Anything(structure);       break;
        case Structure_State::IN_HEADER_INCLUDE:        Process_Character_In_Header_Include(structure);        break;
        case Structure_State::IN_SOURCE_INCLUDE:        Process_Character_In_Source_Include(structure);        break;
        case Structure_State::IN_INHERITANCE:           Process_Character_In_Inheritance(structure);           break;
        case Structure_State::IN_HPP_ONLY:              Process_Character_In_HPP_Only(structure);              break;
        case Structure_State::IN_CPP_ONLY:              Process_Character_In_CPP_Only(structure);              break;
        case Structure_State::IN_FUNCTION_BODY:         Process_Character_In_Function_Body(structure);         break;
        case Structure_State::IN_DATA_MEMBER:           Process_Character_In_Data_Member(structure);           break;
        default: Output_Compilation_Failure_Message(L"Class_Structure has reached an unexpected state while deciding how to handle a character");
    }

    return;
}

void Class_Structure_Creator::Process_Character_Expecting_Header_Include(Class_Structure & structure){

    if (c == L'❪'){current_state=Structure_State::IN_HEADER_INCLUDE;}
    else if(c == L'⚯'){current_state=Structure_State::EXPECTING_SOURCE_INCLUDE;}
    else{
        Error_On_Unicode_Parser_Symbol(L"while expecting header include");
        structure.Append_To_Both_HPP_and_CPP(c);
    }

    return;
}
void Class_Structure_Creator::Process_Character_Expecting_Source_Include(Class_Structure & structure){

    if (c == L'❪'){current_state=Structure_State::IN_SOURCE_INCLUDE;}
    else if(c == L'⚞'){current_state=Structure_State::IN_INHERITANCE;}
    else{
        Error_On_Unicode_Parser_Symbol(L"while expecting a source include");
        structure.Append_To_Both_HPP_and_CPP(c);
    }

    return;
}
void Class_Structure_Creator::Process_Character_In_Header_Include(Class_Structure & structure){

    if (c == L'❫'){
        
        //validate the header name before we add it
        Header_Validator::Validate(file_name,include_name_temp,true);
        
        current_state=Structure_State::EXPECTING_HEADER_INCLUDE;
        structure.Add_Header_Include(include_name_temp);
        include_name_temp.clear();
    }else{
        Error_On_Unicode_Parser_Symbol(L"while in a header include block");
        include_name_temp+= c;
    }

    return;
}
void Class_Structure_Creator::Process_Character_In_Source_Include(Class_Structure & structure){

    if (c == L'❫'){
        
        //validate the header name before we add it
        Header_Validator::Validate(file_name,include_name_temp,false);
        
        current_state=Structure_State::EXPECTING_SOURCE_INCLUDE;
        structure.Add_Source_Include(include_name_temp);
        include_name_temp.clear();
    }else{
        Error_On_Unicode_Parser_Symbol(L"in a source include block");
        include_name_temp+= c;
    }

    return;
}
void Class_Structure_Creator::Process_Character_In_Inheritance(Class_Structure & structure){

    if (c == L'⚟'){
        current_state=Structure_State::EXPECTING_ANYTHING;
    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_Inheritance(wstr);
    }
    else{
        Error_On_Unicode_Parser_Symbol(L"while in an inheritance block");
        structure.Append_To_Inheritance(c);
    }

    return;
}
void Class_Structure_Creator::Process_Character_Expecting_Anything(Class_Structure & structure){

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
        Error_On_Unicode_Parser_Symbol(L"while not in a Unicode block");
        structure.Append_To_Both_HPP_and_CPP(c);
    }

    return;
}
void Class_Structure_Creator::Process_Character_In_HPP_Only(Class_Structure & structure){

    if (c == L'▶'){
        current_state=Structure_State::EXPECTING_ANYTHING;
    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_HPP_Code(wstr);
    }else if(c == L'፠'){
        current_state=Structure_State::IN_DATA_MEMBER;
    }else{
        Error_On_Unicode_Parser_Symbol(L"while in hpp only block");
        structure.Append_To_HPP_Code(c);
    }

    return;
}
void Class_Structure_Creator::Process_Character_In_Data_Member(Class_Structure & structure){
    if (c == L'፠'){
        current_state=Structure_State::IN_HPP_ONLY;
        structure.Add_Data_Member(data_member_name_temp);
        structure.Append_To_HPP_Code(data_member_name_temp);
        data_member_name_temp.clear();
    }else{
        Error_On_Unicode_Parser_Symbol(L"while in a header include block");
        data_member_name_temp+= c;
    }
}
void Class_Structure_Creator::Process_Character_In_CPP_Only(Class_Structure & structure){

    if (c == L'◗'){
        current_state=Structure_State::EXPECTING_ANYTHING;
    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_CPP_Code(wstr);
    }else{
        Error_On_Unicode_Parser_Symbol(L"while in cpp only block");
        structure.Append_To_CPP_Code(c);
    }

    return;
}
void Class_Structure_Creator::Process_Character_In_Function_Body(Class_Structure & structure){

    if(c == L'❱'){
        current_state=Structure_State::EXPECTING_ANYTHING;
        structure.Append_To_CPP_Code('}');
    }else if(c == L'◈'){
        auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(file_name));
        std::wstring wstr(str.begin(),str.end());
        structure.Append_To_CPP_Code(wstr);
    }else{
        Error_On_Unicode_Parser_Symbol(L"while in header a include block");
        structure.Append_To_CPP_Code(c);
    }
    return;
}
void Class_Structure_Creator::Handle_Escaped_Character(Class_Structure & structure){


    //error if we are escaping a character that does not need to be escaped
    if (Looking_At_A_Unicode_Parser_Symbol()){
      
        //decide whether to print the escape character
        Attempt_To_Print_Escape_Char_To_File(structure);
  
    }else{
      
      Output_Compilation_Failure_Message(L"There is no reason to escape this character");
    }

    return;
}
void Class_Structure_Creator::Attempt_To_Print_Escape_Char_To_File(Class_Structure & structure){
    
        
    switch (current_state){
        case Structure_State::EXPECTING_ANYTHING: structure.Append_To_Both_HPP_and_CPP(c); break;
        case Structure_State::IN_HPP_ONLY:        structure.Append_To_HPP_Code(c);         break;
        case Structure_State::IN_CPP_ONLY:        structure.Append_To_CPP_Code(c);         break;
        case Structure_State::IN_FUNCTION_BODY:   structure.Append_To_CPP_Code(c);         break;
        default: Output_Compilation_Failure_Message(L"It does not make sense to escape a Unicode character here");
    }
}

//utility


bool Class_Structure_Creator::Looking_At_A_Unicode_Parser_Symbol(){
  return (c == Any_Of(ALL_UNICODE_PARSER_SYMBOLS));
}

void Class_Structure_Creator::Error_On_Unicode_Parser_Symbol(std::wstring const& doing){

    if (Looking_At_A_Unicode_Parser_Symbol()){
      std::wstring message;
      message += L"got an unexpected special character(";
      message += c; //stack overflow question (maybe we should pass in a wstring instead of std::vector<wchar_t>)
      message += L") ";
      message += doing;
      Output_Compilation_Failure_Message(message);
    }

    return;
}
void Class_Structure_Creator::Output_Compilation_Failure_Message(std::wstring const& message){

    for (auto const& it: file_name){
        std::wcerr << it;
    }
    std::wcerr << ":" << line_number << ":" << char_number << ": ";
    std::wcerr << message << std::endl;
    exit(EXIT_FAILURE);
    return;
}


