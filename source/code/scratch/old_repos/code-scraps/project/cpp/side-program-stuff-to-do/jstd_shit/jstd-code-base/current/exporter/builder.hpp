#pragma once
#include "program_options.hpp"
#include "build_stats.hpp"
#include <boost/filesystem.hpp>
#include <vector>
#include <string>

class Builder{
	
public:
	static void Build(Program_Options const& program_options);
private:
	
	static void Perform_Timed_Builds(Program_Options const& program_options);
		static void Perform_Builds(Program_Options const& program_options, Build_Stats & stats);
			static void Start_The_Builds(Program_Options const& program_options, boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
				static void Build_Pre_Compiled_Header(boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
					static void Build_Header_That_Is_Looked_For_But_Doesnt_Need_Included_In_Code_But_Needs_To_Be_Specified_In_Command_Line(std::string const& file_name);
					static void Build_Libraries(boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
						static std::string Get_Directory_Of_File(std::string const& path);
						static std::string Get_Just_File_Name(std::string const& path);
						static std::string Convert_To_Suitable_File_Name(std::string str,boost::filesystem::path const& built_library);
};