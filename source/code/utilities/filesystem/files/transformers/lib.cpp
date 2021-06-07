#include "code/utilities/filesystem/files/transformers/lib.hpp"
#include "code/utilities/streams/filestreams/lib.hpp"
#include "code/utilities/output/printers/lib.hpp"
#include "code/utilities/types/strings/transformers/reverse/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/types/general/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/vectors/transformers/lib.hpp"
#include "code/utilities/types/strings/observers/path/lib.hpp"

//general functions for general files
void Transform_Each_Line_Of_File_With_Function(std::string const& path_to_file, std::function<std::string& (std::string &)> const& func){
        auto lines = Read_Each_Line_Of_File_Into_Vector(path_to_file);
        for (auto & line: lines){
          func(line); 
        }
        Print_Each_Element_To_A_File_On_A_Seperate_Line(lines,path_to_file);
}
void Transform_File_Lines_In_Bulk_With_Function(std::string const& path_to_file, std::function<std::vector<std::string>& (std::vector<std::string> &)> const& func){
        auto lines = Read_Each_Line_Of_File_Into_Vector(path_to_file);
        func(lines);
        Print_Each_Element_To_A_File_On_A_Seperate_Line(lines,path_to_file);
}


//specific functions for general files
void Reverse_Each_Line_From_File(std::string const& path_to_file){
  
  auto lines = Read_Each_Line_Of_File_Into_Vector(path_to_file);
  for (auto & line: lines){
      Reverse(line);
  }
  Print_Each_Element_To_A_File_On_A_Seperate_Line_With_No_Newline_After_The_Last_Line(lines,path_to_file);
}

void Rename_Preprocessor_Include_Directive_To_Match_File_Name(std::string path_to_file){
  
  //remove the slash if it starts with one
  if (Begins_With(path_to_file,"/")){
    path_to_file.erase(0,1);
  }
  auto file_name = As_Removed_Suffix(Get_File_Name(path_to_file));
  
  auto lines = Read_Each_Line_Of_File_Into_Vector(path_to_file);
  bool ifndef_found = false;
  for (auto & line: lines){
    
    //handle first #ifndef line
    if (Begins_With(As_Trimmed(line),"#ifndef")){
      if (!ifndef_found){
        line = "#ifndef " + file_name + "H";
        ifndef_found = true;
      }
    }
    
    //handle first #define line
    else if(Begins_With(As_Trimmed(line),"#define")){
      if (ifndef_found){
        line = "#define " + file_name + "H";
        break;
      }
    }
    
  }
  
  Print_Each_Element_To_A_File_On_A_Seperate_Line_With_No_Newline_After_The_Last_Line(lines,path_to_file);
}

void Make_The_File_Have_A_Single_Blank_Line_At_The_Bottom(std::string path_to_file){
  
  //remove the slash if it starts with one
  if (Begins_With(path_to_file,"/")){
    path_to_file.erase(0,1);
  }
  
   auto lines = Read_Each_Line_Of_File_Into_Vector(path_to_file);
   Remove_Last_Elements_That_Are_Whitespace_Elements(lines);
   lines.emplace_back();
  Print_Each_Element_To_A_File_On_A_Seperate_Line_With_No_Newline_After_The_Last_Line(lines,path_to_file); 
}

//dealing with file types
void Turn_Symbolic_Linked_File_Into_Regular_File(std::string const& path_to_file){
        auto i = execute("readlink " + path_to_file);
        execute_quietly("rm -rf " + path_to_file);
        execute_quietly("cp -rf " + As_All_Chars_Removed_From_Back_Until_Char_Is_Seen(path_to_file,'/') + i + " " + path_to_file);
}

void Append_To_File(std::string const& path, std::string const& str){
  std::ofstream out;
  out.open(path, std::ios_base::app);
  out << str;
  out.close();
}

void Add_Newline_If_File_Does_Not_End_With_Newline(std::string const& path){
  execute_quietly(std::string("tail -c1 ") + path + " | read -r _ || echo >> " + path);
}