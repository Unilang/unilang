#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/structure/lib.hpp"









//setters
void Class_Structure::Add_Header_Include(std::wstring const& include_name){
    header_includes.emplace_back(include_name,true);
}
void Class_Structure::Add_Source_Include(std::wstring const& include_name){
    source_includes.emplace_back(include_name,true);
}
void Class_Structure::Append_To_Inheritance(wchar_t const& c){
    inheritance+=c;
}
void Class_Structure::Append_To_Inheritance(std::wstring const& str){
    inheritance+=str;
}
void Class_Structure::Append_To_HPP_Code(wchar_t const& c){
    hpp_code+=c;
}
void Class_Structure::Append_To_CPP_Code(wchar_t const& c){
    cpp_code+=c;
}
void Class_Structure::Append_To_Both_HPP_and_CPP(wchar_t const& c){
    hpp_code+=c;
    cpp_code+=c;
}
void Class_Structure::Append_To_HPP_Code(std::wstring const& str){
    hpp_code+=str;
}
void Class_Structure::Append_To_CPP_Code(std::wstring const& str){
    cpp_code+=str;
}
void Class_Structure::Append_To_Both_HPP_and_CPP(std::wstring const& str){
    hpp_code+=str;
    cpp_code+=str;
}
void Class_Structure::Add_To_After_Headers_Portion(wchar_t const& c){
    everything_after_headers += c;
}
void Class_Structure::Add_File_Type(std::wstring const& str){
    file_type = str;
}
void Class_Structure::Add_Data_Member(std::wstring const& str){
    data_members.push_back(str);
}
void Class_Structure::Set_File_Name(std::string const& str){
    file_name = str;
}
void Class_Structure::Set_Path_To_File_Name(std::string const& str){
    path_to_file_name = str;
}

//getters
std::string                               Class_Structure::File_Name()            const{return file_name;}
std::string                               Class_Structure::Path_To_File_Name()    const{return path_to_file_name;}
std::wstring                              Class_Structure::File_Type()            const{return file_type;}
std::vector<std::pair<std::wstring,bool>> Class_Structure::Header_Includes()      const{return header_includes;}
std::vector<std::pair<std::wstring,bool>> Class_Structure::Source_Includes()      const{return source_includes;}
std::wstring                              Class_Structure::Inheritance()          const{return inheritance;}
std::wstring                              Class_Structure::HPP_Code()             const{return hpp_code;}
std::wstring                              Class_Structure::CPP_Code()             const{return cpp_code;}
std::vector<std::wstring>                 Class_Structure::Data_Members()         const{return data_members;}




