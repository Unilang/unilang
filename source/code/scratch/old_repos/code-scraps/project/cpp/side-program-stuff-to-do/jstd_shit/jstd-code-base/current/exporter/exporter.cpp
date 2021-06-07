#include "exporter.hpp"
#include "global.hpp"
#include "utilities.hpp"
#include <string>
#include <vector>
#include <fstream>

void Exporter::Export(Program_Options const& program_options){
	Perform_Timed_Export(program_options);
	return;
}

void Exporter::Perform_Timed_Export(Program_Options const& program_options){
	
	std::cout << "Exporting... "; std::cout.flush();
	
	//start recording the time 
	//it takes to perform the export
	Export_Stats stats; stats.Start_Timer();
	
		//perform the export
		Perform_Export(program_options,stats);
	
	//export is done.
	//stop the timer
	stats.End_Timer();
	
	//conversion is complete (The pseudo library now matches the exported library in terms of content)
	Green_Message("Success!\n");
	
	//after the successful conversion, output any other kind of desired results
	//Output_Additional_Logging_Information(timer);
	
	return;
}
	void Exporter::Perform_Export(Program_Options const& program_options, Export_Stats & stats){
		
		//set the root of where the exported library will be.
		auto exported_library = boost::filesystem::current_path()
		/= constant::EXPORT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT;
		
		//make sure the root of the exported library is there
		//and that the path to it, doesn't have any redirection.
		Create_Path_If_It_Doesnt_Already_Exist(exported_library);
		Shortify_Path(exported_library);
		
		//assuming the program is being run at the root of the pseudo library,
		//this function will export the complete working version of the actual library.
		//(it will only update/create parts of the library that aren't already done)
		//(it will also remove parts of the actual library, that are no longer in the pseudo library)
		Start_The_Library_Conversion(program_options, exported_library, stats);
		
		return;
	}
		void Exporter::Start_The_Library_Conversion(Program_Options const& program_options, boost::filesystem::path const& exported_library, Export_Stats & stats){
		
		//perform any checks needed before conversion/update occurs
		
		//perform the conversion / update
		std::vector<std::string> namespace_stack;
		Convert_Directory_And_All_Sub_Directories(program_options, exported_library,stats, namespace_stack);
		
		return;
	}
			void Exporter::Convert_Directory_And_All_Sub_Directories(Program_Options const& program_options, boost::filesystem::path const& exported_library, Export_Stats & stats,  std::vector<std::string> & namespace_stack){
		
		//if exported library node doesn't exist, make it
		Create_Path_If_It_Doesnt_Already_Exist(exported_library);
		
		//make the .cpp file and the .hpp file for the current namespace
		Make_Header_And_Source_File_For_Current_Namespace(program_options,exported_library,stats, namespace_stack);
		
		//recursively do this across all sub-directories
		Convert_All_The_Sub_Files(program_options,exported_library,stats,namespace_stack);
		
		return;
	}
				void Exporter::Make_Header_And_Source_File_For_Current_Namespace(Program_Options const& program_options,boost::filesystem::path const& exported_library, Export_Stats & stats,  std::vector<std::string> const& namespace_stack){
		
		//create header and source files
		std::ofstream header(exported_library.string() + "/" + Current_Folder_Name() + ".hpp");
		std::ofstream source(exported_library.string() + "/" + Current_Folder_Name() + ".cpp");
		
		//use pragma once or inclusion guards
		if (program_options.Inclusion_Guards()){
			header << "#ifndef JSTD_UNIQUE_INCLUSION_GUARD_" << include_gaurd_global << '\n';
			header << "#define JSTD_UNIQUE_INCLUSION_GUARD_" << include_gaurd_global << '\n';
			++include_gaurd_global;
		}else{
			header << "#pragma once\n";
		}
		
		//add other headers to the two files
		std::ifstream header_hpps(boost::filesystem::current_path().string() + "/" + constant::HEADER_HPPS_FILE);
		std::ifstream source_hpps(boost::filesystem::current_path().string() + "/" + constant::SOURCE_HPPS_FILE);
		std::string temp;
		
		std::getline(header_hpps,temp);
		while (header_hpps){
			header << temp <<'\n';
			std::getline(header_hpps,temp);
		}
		
		
		std::getline(source_hpps,temp);
		while (source_hpps){
			source << temp <<'\n';
			std::getline(source_hpps,temp);
		}
		
		//wrap with namespace stack
		source << "#include \"" << Current_Folder_Name() << ".hpp" << "\"\n";
		for (auto it: namespace_stack){source <<  "namespace " <<  it << "{\n";}
		
		
		//header << "namespace " << Current_Folder_Name() << "{\n";
		source << "namespace " << Current_Folder_Name() << "{\n";
		
			Include_And_Use_Sub_Headers(program_options,header,namespace_stack);
			Export_Library_Functionality(program_options,header,source,stats,namespace_stack);
			
		//header << "}\n";
		if (program_options.Inclusion_Guards()){
			header << "#endif\n";
		}
		header.close();
		source << "}\n";
		for (size_t i = 0; i < namespace_stack.size(); ++i){source <<  "}\n";}
		source.close();
		
		return;
	}
					void Exporter::Include_And_Use_Sub_Headers(Program_Options const& program_options,std::ofstream & header,std::vector<std::string> const& namespace_stack){
		
		//get all the directories of the pseudo library node
		auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());
		
		for (auto const& dir: dirs){
			header << "#include \"" << Current_Folder_Name() << "/" << dir << ".hpp\"\n";
			for (auto it: namespace_stack){header <<  "namespace " <<  it << "{\n";}
			header << "namespace " << Current_Folder_Name() << "{\n";
			header << "using namespace " << dir << ";\n";
			for (size_t i = 0; i < namespace_stack.size(); ++i){header <<  "}\n";}header << "}\n";
			
		}
		
		if (dirs.empty()){
			for (auto it: namespace_stack){header <<  "namespace " <<  it << "{\n";}
			header << "namespace " << Current_Folder_Name() << "{\n";
			for (size_t i = 0; i < namespace_stack.size(); ++i){header <<  "}\n";}header << "}\n";
		}
		
		//put special marker to deal with pragma once
		if (program_options.CPP11()){
			if (dirs.empty()){
				header << "//unique marker because of pragma once's behavior on similarly data filled files: " << boost::filesystem::current_path().string() << " (" << pragma_unique_maker_global << ")\n";
				++pragma_unique_maker_global;
			}
		}
		
		return;
	}
					void Exporter::Export_Library_Functionality(Program_Options const& program_options,std::ofstream & header, std::ofstream & source, Export_Stats & stats,std::vector<std::string> const& namespace_stack){
		
		std::ifstream code((boost::filesystem::current_path() /= "code.hpp").string());
		std::string line;
		std::vector<std::string> function_block;
		
		std::getline(code,line);
		while(code){
			if(line == constant::START_OF_FUNCTION_MARKER){
				std::getline(code,line);
				while(code && line != constant::END_OF_FUNCTION_MARKER){
					function_block.push_back(line);
					std::getline(code,line);
				}
				Print_Functions(program_options,header,source,function_block,stats,namespace_stack);
				function_block.clear();
			}
			
			std::getline(code,line);
		}
		return;
	}
						void Exporter::Print_Functions(Program_Options const& program_options,std::ofstream & header,std::ofstream & source,std::vector<std::string> const& function_block, Export_Stats & stats,std::vector<std::string> const& namespace_stack){
		
		
		//convert the function chunk into a use-able class
		Function function = Get_Function(function_block);
		
		//solve the regular expressions
		std::vector<std::string> function_names;
		std::vector<std::string> part;
		for (auto it: function.function_name_expressions){
			part = Get_Results_Of_Regular_Expression_Solver(it);
			function_names.insert( function_names.end(), part.begin(), part.end() ); //function_names += part;
		}
		
		
		//get rid of un-needed whitespce
		for (auto & it: function_names){
			trim(it);
			Squeeze_Away_Spaces(it);
		}
		
		//get all function case conventions
		Convert_To_Needed_Function_Formats(program_options,function_names);
		
		//sort and remove duplicates
		Sort_And_Remove_Duplicates(function_names); //<- should warn what the repeats were
		
		//record function amount
		if (!function_names.empty()){
			stats.Increment_Base_Function();
			stats.Increment_Function_Synonyms(function_names.size()-1);
		}
		
		for (auto it: namespace_stack){header <<  "namespace " <<  it << "{\n";}
		header << "namespace " << Current_Folder_Name() << "{\n";
		//output header functions
		for (auto & it: function_names){
			if (program_options.CPP11()){
				header << "auto " << it << "(" << function.get_paramater_list() << ")->" << function.return_type  << ";\n";
			}else{
				header << function.return_type << " " << it << "(" << function.get_paramater_list() << ");\n";
			}
		}
		for (size_t i = 0; i < namespace_stack.size(); ++i){header <<  "}\n";}header << "}\n";
		
		//for (auto it: namespace_stack){source <<  "namespace " <<  it << "{\n";}
		//source << "namespace " << Current_Folder_Name() << "{\n";
		//output source functions
		for (auto it = function_names.begin(); it != function_names.end(); ++it){
			
			if (program_options.CPP11()){
				source << "auto " << *it << "(" << function.get_paramater_list() << ")->" << function.return_type;
			}else{
				source << function.return_type << " " << *it << "(" << function.get_paramater_list() << ");";
			}
			
			if (it == function_names.begin()){
				for (auto line: function.definition){
					source << line << std::endl;
				}
			}else{
				source << "{ return " << function_names[0] << "(" << function.get_passed_in_values() << ");}\n";
			}
		}
		
		
		return;
	}
							Function Exporter::Get_Function(std::vector<std::string> const& function_block){
		
		std::vector<std::string>::const_iterator it = function_block.begin();
		Function function;
		Get_Attribute_Part(function,it);
		Get_Template_Part(function,it);
		Get_Parameters_Part(function,it);
		Get_Regex_Part(function,it);
		Get_Definition_Part(function,it);
		Get_Raw_Adds_Part(function,it);
		Get_Raw_Deletes_Part(function,it);
		Get_Function_Base_Part(function,it);
		
		return function;
	}
								void Exporter::Get_Attribute_Part(Function & function, std::vector<std::string>::const_iterator & it){
									
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.attributes.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Template_Part(Function & function, std::vector<std::string>::const_iterator & it){
		
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.template_statement.push_back(*it);
			++it;
		}
		++it;
		
		return;
	}
								void Exporter::Get_Parameters_Part(Function & function, std::vector<std::string>::const_iterator & it){
		
		function.return_type = *it;
		++it;
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.parameters.push_back(std::pair<std::string,std::string>(*(it),*(it+1)));
			it+=2;
		}
		++it;
		
		return;
	}
								void Exporter::Get_Regex_Part(Function & function, std::vector<std::string>::const_iterator & it){
		
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.function_name_expressions.push_back(*it);
			++it;
		}
		++it;
		
		return;
	}
								void Exporter::Get_Definition_Part(Function & function, std::vector<std::string>::const_iterator & it){
		
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.definition.push_back(*it);
			++it;
		}
		++it;
		
		return;
	}
								void Exporter::Get_Raw_Adds_Part(Function & function, std::vector<std::string>::const_iterator & it){
									
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.raw_adds.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Raw_Deletes_Part(Function & function, std::vector<std::string>::const_iterator & it){
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.raw_deletes.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Function_Base_Part(Function & function, std::vector<std::string>::const_iterator & it){
									function.function_base = *it;
									return;
								}
							std::vector<std::string> Exporter::Get_Results_Of_Regular_Expression_Solver(std::string & regular_expression){
	std::vector<std::string> results;
	Resolve_Regular_Expression_Compacts(regular_expression);
	std::string all = exec(constant::PATH_TO_EXPRESSION_SOLVER + " \"" + regular_expression + "\"");
	
	std::string temp;
	for (auto it: all){
		if (it != '\n'){
			temp+=it;
		}else{
			results.push_back(temp);
			temp = "";
		}
	}
	
	if (!temp.empty()){
		results.push_back(temp);
	}
	
	return results;
}
								void Exporter::Resolve_Regular_Expression_Compacts(std::string & regular_expression){
									std::string built;
									std::string temp;
									
									for (auto it = regular_expression.cbegin(); it != regular_expression.cend(); ++it){
										
										//for possible empty sets
										if (*it == '<'){
											++it;
											while (*it != '>'){
												temp+=*it;
												++it;
											}
											built+=Resolve_Compact(temp,true);
											temp.clear();
											
										}
										
										//for stationary sets
										else if (*it == '#'){
											++it;
											while (*it != '#'){
												temp+=*it;
												++it;
											}
											built+=Resolve_Compact(temp,false);
											temp.clear();
										}
										
										//for all other characters
										else{
											built+=*it;
										}
									}
									
									
									
									regular_expression = built;
									return;
								}
									std::string Exporter::Resolve_Compact(std::string const& compact, bool const& empty){
										
										std::ifstream infile(constant::PATH_TO_REGEX_COMPACTS + compact);
										std::string word;
										std::vector<std::string> words;
										std::string resolved = "(";
										
										std::getline(infile,word);
										while(infile){
											words.push_back(word);
										std::getline(infile,word);
										}
										
										for (auto it = words.begin(); it != words.end(); ++it){
											resolved+=*it;
											
											if (words.size() >1){
												if (it != words.end()-1){
													resolved+="|";
												}
											}
											
										}
										
										if (empty){
											resolved+="|";
										}
										resolved+=")";
										
										return resolved;
									}
							void Exporter::Convert_To_Needed_Function_Formats(Program_Options const& program_options,std::vector<std::string>& vec){
		
		std::vector<std::string> all;
		for (auto const& it: vec){
			
			if (program_options.Cases()[0]){
				all.push_back(As_Lowercase_Underscore_Form(it));
			}
			
			if (program_options.Cases()[1]){
				all.push_back(As_Uppercase_Underscore_Form(it));
			}
			
			if (program_options.Cases()[2]){
				all.push_back(As_Lowercase_Camelcase_Form(it));
			}
			
			if (program_options.Cases()[3]){
				all.push_back(As_Uppercase_Camelcase_Form(it));
			}
		}
		vec = all;
		return;
	}
								std::string Exporter::As_Lowercase_Underscore_Form(std::string const& original){
		std::string str;
		for (auto const& it: original){
			if (it == ' '){
				str+="_";
			}else{
				str+=it;
			}
		}
		
		return str;
	}
								std::string Exporter::As_Uppercase_Underscore_Form(std::string const& original){
		std::string str;
		bool was_space = true;
		for (auto const& it: original){
			if (it == ' '){
				str+="_";
				was_space = true;
			}else{
				if (was_space){
					str+=toupper(it);
					was_space = false;
				}
				else{
					str+=it;
				}
			}
		}
		
		return str;
	}
								std::string Exporter::As_Uppercase_Camelcase_Form(std::string const& original){
		std::string str;
		bool was_space = true;
		for (auto const& it: original){
			if (it == ' '){
				//str+="_";
				was_space = true;
			}else{
				if (was_space){
					str+=toupper(it);
					was_space = false;
				}
				else{
					str+=it;
				}
			}
		}
		
		return str;
	}
								std::string Exporter::As_Lowercase_Camelcase_Form(std::string const& original){
		std::string str;
		bool was_space = false;
		for (auto const& it: original){
			if (it == ' '){
				//str+="_";
				was_space = true;
			}else{
				if (was_space){
					str+=toupper(it);
					was_space = false;
				}
				else{
					str+=it;
				}
			}
		}
		
		return str;
	}
				void Exporter::Convert_All_The_Sub_Files(Program_Options const& program_options, boost::filesystem::path exported_library, Export_Stats & stats,  std::vector<std::string> & namespace_stack){
		
		//get all the directories of the pseudo library node
		auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());
		
		
		for (auto const& dir: dirs){
			namespace_stack.push_back(Current_Folder_Name());
			exported_library /= Current_Folder_Name();
			Step_Into_Folder(dir);
			
			Convert_Directory_And_All_Sub_Directories(program_options,exported_library,stats,namespace_stack);
			
			namespace_stack.pop_back();
			exported_library /= "../";
			Shortify_Path(exported_library);
			Step_Out_Of_Folder();
		}
		
		return;
	}
	void Exporter::Output_Additional_Logging_Information(Timer const& timer){
		std::cout << "The export took " << timer.Duration() << " seconds." << std::endl;
		return;
	}
