#pragma once
#include "program_options.hpp"
#include "warn_machine.hpp"
#include "scan_stats.hpp"
#include <vector>
#include <string>
#include <utility>

class Scanner{
	
public:
	Scanner()=delete;
	static void Scan(Program_Options const& program_options);
	
private:
	
	//functional decomposition of public Scan function
	
	static void Perform_Timed_Scan(Program_Options const& program_options);
		static void Perform_Scan(Program_Options const& program_options);
			static void Start_The_Library_Scan(Program_Options const& program_options);
				static void Make_Sure_The_Necessary_Files_Are_Present_At_Root(Program_Options const& program_options, Warn_Machine & warn_machine);
				static void Make_Sure_No_Extra_Files_Exist_At_Root(Program_Options const& program_options, Warn_Machine & warn_machine);
				//static void Check_Header_Files(Program_Options const& program_options, Warn_Machine & warn_machine);
				//static void Check_Code_File(Program_Options const& program_options, Warn_Machine & warn_machine);
				static void Scan_Directory_And_All_Sub_Directories(Program_Options const& program_options,Warn_Machine & warn_machine);
					static void Make_Sure_The_Necessary_Files_Are_Present_In_Subfolder(Program_Options const& program_options, Warn_Machine & warn_machine);
					static void Make_Sure_No_Extra_Files_Exist_In_Subfolder(Program_Options const& program_options, Warn_Machine & warn_machine);
					static void Check_Header_Files(Program_Options const& program_options, Warn_Machine & warn_machine);
						static void Complain_About_Header_Duplicates(Program_Options const& program_options, Warn_Machine & warn_machine, std::vector<std::string> const& header_lines,std::string const& file_name);
						static void Complain_About_Source_Duplicates(Program_Options const& program_options, Warn_Machine & warn_machine, std::vector<std::string> const& header_lines, std::vector<std::string> const& source_lines,std::string const& file_name);
					static void Check_Code_File(Program_Options const& program_options, Warn_Machine & warn_machine);
					static void Scan_All_The_Sub_Files(Program_Options const& program_options, Warn_Machine & warn_machine);
					
					static void Trigger_Possible_Exit(Program_Options const& program_options, Warn_Machine & warn_machine,std::string const& str);
					
					static void Fix_Warnings(Program_Options const& program_options);
						static bool Prompt_To_Add_File(std::string const& it);
						static bool Prompt_To_Delete_File(std::string const& it);
						static bool Prompt_To_Delete_Duplicate_Header(std::pair<std::string,std::string> const& it);
						static bool Prompt_To_Delete_Uneeded_Header(std::pair<std::string,std::string> const& it);
						static bool Prompt();
						static void Remove_Dups_From_Header(std::pair<std::string,std::string> const& it);
						static void Remove_Uneeded_From_Header(std::pair<std::string,std::string> const& it);
					
	//data
	static Scan_Stats stats;
	

	
};