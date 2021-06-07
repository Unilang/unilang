#pragma once
#include "program_options.hpp"
#include "function.hpp"
#include "timer.hpp"
#include "export_stats.hpp"
#include <boost/filesystem.hpp>
#include <vector>
#include <string>

class Exporter{
	
public:
	static void Export(Program_Options const& program_options);
	
private:
	
	//functional decomposition of public Export function
	
	static void Perform_Timed_Export(Program_Options const& program_options);
		static void Perform_Export(Program_Options const& program_options, Export_Stats & stats);
			static void Start_The_Library_Conversion(Program_Options const& program_options, boost::filesystem::path const& exported_library, Export_Stats & stats);
				static void Convert_Directory_And_All_Sub_Directories(Program_Options const& program_options, boost::filesystem::path const& exported_library, Export_Stats & stats,std::vector<std::string> & namespace_stack);                                //recursive
					static void Make_Header_And_Source_File_For_Current_Namespace(Program_Options const& program_options, boost::filesystem::path const&exported_library, Export_Stats & stats,  std::vector<std::string> const& namespace_stack);                                                             // |
						static void Include_And_Use_Sub_Headers(Program_Options const& program_options,std::ofstream & header,std::vector<std::string> const& namespace_stack);                                                                          // |
						static void Export_Library_Functionality(Program_Options const& program_options,std::ofstream & header, std::ofstream & source, Export_Stats & stats,std::vector<std::string> const& namespace_stack);                                                                              // |
							static void Print_Functions(Program_Options const& program_options,std::ofstream & header,std::ofstream & source,std::vector<std::string> const& function_block, Export_Stats & stats,std::vector<std::string> const& namespace_stack);                                         // |
								static Function Get_Function(std::vector<std::string> const& function_block);                                                                                  // |
									static void Get_Attribute_Part(Function & function, std::vector<std::string>::const_iterator & it);
									static void Get_Template_Part(Function & function, std::vector<std::string>::const_iterator & it);                                                         // |
									static void Get_Parameters_Part(Function & function, std::vector<std::string>::const_iterator & it);                                                       // |
									static void Get_Regex_Part(Function & function, std::vector<std::string>::const_iterator & it);                                                            // |
									static void Get_Definition_Part(Function & function, std::vector<std::string>::const_iterator & it);  // |
									static void Get_Raw_Adds_Part(Function & function, std::vector<std::string>::const_iterator & it);
									static void Get_Raw_Deletes_Part(Function & function, std::vector<std::string>::const_iterator & it);
									static void Get_Function_Base_Part(Function & function, std::vector<std::string>::const_iterator & it);
								static std::vector<std::string> Get_Results_Of_Regular_Expression_Solver(std::string & regular_expression);  
									static void Resolve_Regular_Expression_Compacts(std::string & regular_expression);
										static std::string Resolve_Compact(std::string const& compact, bool const& empty);
								static void Convert_To_Needed_Function_Formats(Program_Options const& program_options,std::vector<std::string>& vec);                                                                                 // |
									static std::string As_Lowercase_Underscore_Form(std::string const& original);                                                                              // |
									static std::string As_Uppercase_Underscore_Form(std::string const& original);                                                                              // |
									static std::string As_Uppercase_Camelcase_Form(std::string const& original);                                                                               // |
									static std::string As_Lowercase_Camelcase_Form(std::string const& original);                                                                               // |
					static void Convert_All_The_Sub_Files(Program_Options const& program_options,boost::filesystem::path exported_library, Export_Stats & stats,  std::vector<std::string> & namespace_stack);                                                // .
		static void Output_Additional_Logging_Information(Timer const& timer);
		
};