#include "scan_stats.hpp"
Scan_Stats::Scan_Stats()
: max_namespace_depth(0)
{}

//for warning stats
void Scan_Stats::Record_Missing_File(std::string const& file){
	missing_files.push_back(file);
	return;
}
void Scan_Stats::Record_Not_Needed_File(std::string const& file){
	not_needed_files.push_back(file);
	return;
}
void Scan_Stats::Record_Duplicate_Header(std::string const& file, std::string const& header){
	duplicated_headers.push_back(std::pair<std::string,std::string>(file,header));
	return;
}
void Scan_Stats::Record_Uneeded_Header(std::string const& file, std::string const& header){
	uneeded_headers.push_back(std::pair<std::string,std::string>(file,header));
	return;
}
std::vector<std::string> Scan_Stats::Get_Missing_Files(){
	return missing_files;
}
std::vector<std::string> Scan_Stats::Get_Not_Needed_Files(){
	return not_needed_files;
}
std::vector<std::pair<std::string,std::string>> Scan_Stats::Get_Duplicate_Headers(){
	return duplicated_headers;
}
std::vector<std::pair<std::string,std::string>> Scan_Stats::Get_Uneeded_Headers(){
	return uneeded_headers;
}

//for other stats
void Scan_Stats::Store_If_Max_Depth(uint const& namespace_depth){
	if (namespace_depth > max_namespace_depth){
		max_namespace_depth = namespace_depth;
	}
	return;
}
unsigned int Scan_Stats::Get_Max_Depth(){
	return max_namespace_depth;
}