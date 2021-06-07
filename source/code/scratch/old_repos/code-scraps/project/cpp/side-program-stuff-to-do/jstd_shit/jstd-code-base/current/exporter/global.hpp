#pragma once
#include <string>
#include <vector>
#include <boost/filesystem.hpp>


extern unsigned long long include_gaurd_global;
extern unsigned long long pragma_unique_maker_global;

namespace constant{
	
	//file/directory location constants
	const std::string NAME_Of_ROOT_FOLDER_THAT_EXPORTER_SHOULD_RUN_IN = "jstd";
	const std::string EXPORT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT = "../jstd-export/raw/";
	const std::string BUILT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT = "../jstd-export/built/";
	const std::string PATH_TO_EXPRESSION_SOLVER = (boost::filesystem::current_path() /= "../exporter/exrex.py").string();
	const std::string PATH_TO_REGEX_COMPACTS = (boost::filesystem::current_path() /= "../exporter/regex_compacts/").string();
	
	//file location names
	const std::string CODE_FILE = "code.hpp";
	const std::string HEADER_HPPS_FILE = "header_hpps";
	const std::string SOURCE_HPPS_FILE = "source_hpps";
	const std::string THIS_PROGRAM_FILE = "exporter";
	
	//code file makers for pseudo library
	const std::string FUNCTION_PART_DELIMITER = "<----DELIM---->";
	const std::string START_OF_FUNCTION_MARKER = "<----------------------------START---------------------------->";
	const std::string END_OF_FUNCTION_MARKER = "<-----------------------------END----------------------------->";
	
	//used by pseudo library checker
	const std::vector<std::string> NEEDED_FILES_FOR_EACH_PSEUDO_SUB_DIRECTORY = {CODE_FILE,HEADER_HPPS_FILE,SOURCE_HPPS_FILE};
	const std::vector<std::string> NEEDED_FILES_FOR_PSEUDO_ROOT_DIRECTORY = {CODE_FILE,HEADER_HPPS_FILE,SOURCE_HPPS_FILE, THIS_PROGRAM_FILE};
}