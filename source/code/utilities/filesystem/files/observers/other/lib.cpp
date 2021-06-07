#include "code/utilities/filesystem/files/observers/other/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <sys/stat.h>
#include <dirent.h>
#include <filesystem>

bool Regular_File_Exists_Recursively(std::string const& path, std::string const& match_name){
  for(auto iterEntry = std::filesystem::recursive_directory_iterator(path); iterEntry != std::filesystem::recursive_directory_iterator(); ++iterEntry ) {
      if (iterEntry->is_regular_file()) {
          const auto filenameStr = iterEntry->path().filename().string();
          if (filenameStr == match_name){
            return true;
          }
      }
  }
  return false;
}

std::string Get_File_That_Symbolic_Link_Points_To(std::string const& path_to_symbolic_link){
  return execute("readlink " + path_to_symbolic_link);
}

bool Folder_Has_C_Or_CPP_File(std::string folder_name){
  auto f1 = Get_Regular_Files_Of_Path_With_The_File_Extension("c",folder_name);
  auto f2 = Get_Regular_Files_Of_Path_With_The_File_Extension("cpp",folder_name);
  return !f1.empty() || !f2.empty();
}

bool Files_Are_The_Same(const std::string& path_to_file1, const std::string& path_to_file2) {
  std::ifstream f1(path_to_file1, std::ifstream::binary|std::ifstream::ate);
  std::ifstream f2(path_to_file2, std::ifstream::binary|std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    return false; //file problem
  }

  if (f1.tellg() != f2.tellg()) {
    return false; //size mismatch
  }

  //seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}

std::string Type_Of_File(std::string const& path){
  return execute("file -L -b -z -N " + path);
}

bool Is_A_Dynamic_Executable_According_to_Ldd(std::string const& path)
{
  auto results = execute_and_get_back_stdout_only("ldd " + path);
  trim(results);
  
  return results == "not a dynamic executable";
  
}

std::optional<std::time_t> Last_Modification_Time_If_File_Exists(std::string path_to_file){
  
  //starts out with no time, because we don't know if the file exists
  std::optional<std::time_t> potential_time;
  
  //if the file exists, we derive the last modification time
  if (File_Exists(path_to_file)){
    struct stat fileInfo;
    lstat(path_to_file.c_str(), &fileInfo);
    potential_time = fileInfo.st_mtime;
  }
  
  //return an optional modification time
  return potential_time;
}

std::string Instances_Of_Double_Semicolon(std::string const& filename){
  return execute(std::string("ag ';(\\s)+;' -G ") + filename);
}