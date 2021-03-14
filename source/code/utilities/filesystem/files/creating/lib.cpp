#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/types/strings/transformers/stripping/lib.hpp"
#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"
#include <fstream>
#include "code/tools/reflexivity/comment/generated_comment_getter.hpp"

void Create_File_If_It_Doesnt_Exist(std::string const& path_to_file){
  if (!File_Exists(path_to_file)){
    Write_To_File(path_to_file,"");
  }
}
void Create_File_Even_If_The_Path_Doesnt_Exist(std::string const& path_to_file){
  auto path = Get_File_Path_Without_The_Filename(path_to_file);
  Create_Path_If_It_Doesnt_Already_Exist(path);
}
void Write_To_File(std::string path_to_file, std::string const& content)
{
	std::ofstream outfile(path_to_file);
	outfile << content;
    outfile.close();
}
void Write_To_File(std::string path_to_file, std::wstring const& content)
{
	std::wofstream outfile(path_to_file);
	outfile << content;
    outfile.close();
}
void Write_To_File_As_Wstring(std::string path_to_file, std::wstring const& content)
{
    std::wofstream outfile(path_to_file);
    outfile << content;
    outfile.close();
}

void Write_To_File_With_Auto_Gen_Comment(std::string const& path_to_file, Source_Language const& source_language, std::string const& content)
{
  std::string out_str;
  out_str += Generated_Comment_Getter::Get(source_language);
  out_str += "\n";
  out_str += content;
  Write_To_File(path_to_file,out_str);
}