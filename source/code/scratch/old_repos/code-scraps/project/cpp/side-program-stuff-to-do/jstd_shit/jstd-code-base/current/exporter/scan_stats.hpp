#pragma once
#include "stat_timer.hpp"
#include <vector>
#include <string>

class Scan_Stats: public Stat_Timer{
	
	
public:
	
	//constructor
	Scan_Stats();
	
	//for warning stats
	
		//transformers
		void Record_Missing_File(std::string const& file);
		void Record_Not_Needed_File(std::string const& file);
		void Record_Duplicate_Header(std::string const& file, std::string const& header);
		void Record_Uneeded_Header(std::string const& file, std::string const& header);
		
		//observers
		std::vector<std::string> Get_Missing_Files();
		std::vector<std::string> Get_Not_Needed_Files();
		std::vector<std::pair<std::string,std::string>> Get_Duplicate_Headers();
		std::vector<std::pair<std::string,std::string>> Get_Uneeded_Headers();
	
	//for other stats
		
		//transformers
		void Store_If_Max_Depth(uint const& namespace_depth);
		
		//observers
		unsigned int Get_Max_Depth();

private:
	
	//warning stats
	std::vector<std::string> missing_files;
	std::vector<std::string> not_needed_files;
	std::vector<std::pair<std::string,std::string>> duplicated_headers;
	std::vector<std::pair<std::string,std::string>> uneeded_headers;
	
	//other stats
	uint max_namespace_depth; 

};
