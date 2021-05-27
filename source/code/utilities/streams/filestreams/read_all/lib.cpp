#include "code/utilities/streams/filestreams/read_all/lib.hpp"
#include "code/utilities/types/strings/observers/front_back/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/strings/observers/splitting/lib.hpp"
#include "code/utilities/types/converters/lib.hpp"
#include "code/utilities/types/vectors/converters/lib.hpp"
#include <streambuf>


//compied over to fix dep issue
std::vector<std::string> Get_Comma_Seperated_Values_From_File_Impl(std::string const& path_to_file){
  auto all = Read_Entire_File_Into_String(path_to_file);
  auto parts = Split_Into_Parts_From_Comma(all);
  for (auto & it: parts){
    trim(it);
  }
  return parts;
}

std::string Read_Entire_File_Into_String(std::string const& file){
	std::ifstream t(file);
	return std::string((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
}
std::vector<std::uint8_t> Read_Entire_Binary_File_Into_Byte_Vec(std::string const& file)
{
    std::ifstream instream(file, std::ios::in | std::ios::binary);
    std::vector<std::uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());
    return data;
}
std::string Read_Entire_Binary_File_Into_String(std::string const& file){
	std::ifstream t(file, std::ios::in | std::ios::binary);
	return std::string((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
}

std::vector<char> ReadAllBytes(std::string const& file)
{
    std::ifstream ifs(file, std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char>  result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(&result[0], pos);

    return result;
}


std::wstring Read_Entire_File_Into_WString(std::string const& file){
	std::wifstream t(file);
	return std::wstring((std::istreambuf_iterator<wchar_t>(t)),std::istreambuf_iterator<wchar_t>());
}
std::vector<std::string> Read_Each_Line_Of_File_Into_Vector(std::string const& file){
	std::ifstream infile(file);
	std::string line;
	std::vector<std::string> lines;
	std::getline(infile, line);
	while (infile){
		lines.push_back(line);
		std::getline(infile, line);
	}
	infile.close();
	return lines;
}
std::unordered_set<std::string> Read_Each_Line_Of_File_Into_USet(std::string const& file){
	std::ifstream infile(file);
	std::string line;
	std::unordered_set<std::string> lines;
	std::getline(infile, line);
	while (infile){
		lines.insert(line);
		std::getline(infile, line);
	}
	infile.close();
	return lines;
}

std::vector<std::vector<std::string>> Read_Each_Line_Of_File_Into_Vector_Split_Chunks_By_Empty_Line(std::string const& file){

    std::string line;
	std::vector<std::string> parts;
	std::vector<std::vector<std::string>> all_lines;
	std::ifstream infile(file);
	
	std::getline(infile, line);
	while(infile){
	
	    if (!line.empty()){
	        parts.push_back(line);
	    }else{
	        all_lines.push_back(parts);
	        parts.clear();
	    }
	
	    std::getline(infile, line);
	}
	
	if (!parts.empty()){
	    all_lines.push_back(parts);
	}
	
	
	return all_lines;
}


std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file) {

	std::ifstream infile(file);
	std::string line;
	std::string part;
	std::vector<std::string> parts;
	std::vector<std::vector<std::string>> all_lines;
	std::getline(infile, line);
	while (infile) {

		//parse and store
		bool c_found = false;
		bool in_string = false;
		for (auto const& c: line) {

			//if we have a character or a space inside a string
			if (c != ' '  || in_string) {


				// record the start or end of a string
				if (c == '"') {
					if (in_string) {
						in_string = false;
					}else{
						in_string = true;
					}
				}else{

					//store the other non quote characters
					c_found = true;
					part += c;
				}

			}else{
				if (c_found) {
					parts.push_back(part);
					c_found = false;
					part.clear();
				}
			}
		}

		if (!part.empty()) {
			parts.push_back(part);
			c_found = false;
			part.clear();
		}

		all_lines.push_back(parts);
		parts.clear();


		std::getline(infile, line);
	}

	return all_lines;
}

std::vector<std::pair<char,int>> Get_Comma_Seperated_Values_From_File_Where_Each_Value_Is_A_Pair_Of_Char_Int(std::string const& file){
    auto strings = Get_Comma_Seperated_Values_From_File_Impl(file);
    auto result = Get_As_Each_Element_A_Char_And_Int(strings);
    return result;
}