#pragma once

#include <boost/filesystem.hpp>

//utility
	
	//general system calling
	std::string exec(std::string const& cmd);
	std::string exec(const char* cmd);

	//filesystem stuff
	void Create_Path_If_It_Doesnt_Already_Exist(boost::filesystem::path const& path);
	std::string Current_Folder_Name(void);
	void Step_Into_Folder(std::string const folder_name);
	void Step_Out_Of_Folder(void);
	bool File_Exists(std::string const& filename);
	std::vector<std::string> Get_Dirs_Of_Path(std::string const& path);
	std::vector<std::string> Get_Files_Of_Path(std::string const& path);
	std::vector<std::string> Recursively_Get_All_Source_File_Paths_Of_Path(std::string const& path);
	void Shortify_Path(boost::filesystem::path & path);
	
	//string functions
	std::string& ltrim(std::string &s);
	std::string& rtrim(std::string &s);
	std::string&  trim(std::string &s);
	std::string& Squeeze_Away_Spaces(std::string &s);
	
	//vector functions
	template <typename T> void Sort_And_Remove_Duplicates(std::vector<T>& vec){
		std::sort(vec.begin(), vec.end());
		vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	
	}
	bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str);
	
	//color functions
	void Exit_With_Error_Message(std::string const& str);
	void Green_Message(std::string const& str);
	void Red_Message(std::string const& str);