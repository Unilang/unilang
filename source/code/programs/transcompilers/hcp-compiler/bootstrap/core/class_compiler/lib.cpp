#include <iostream>
#include <string>
#include <fstream>
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/class_compiler/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/strings/observers/path/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/wstrings/transformers/trimming/lib.hpp"
#include "code/utilities/types/wstrings/transformers/other/lib.hpp"
#include "code/utilities/types/converters/lib.hpp"








 void Class_Compiler::Compile_HCP_File(Class_Structure const& structure, std::string const& directory,  bool const& utility_functions){

    //use the structure to print the cpp and hpp versions of the file
	
	std::string header_name = As_Removed_Suffix(structure.Path_To_File_Name())+ ".hpp";
	std::string source_name = As_Removed_Suffix(structure.Path_To_File_Name()) + ".cpp";

	  if (!directory.empty()){
		header_name = directory + "/" + Get_File_Name(header_name);
		source_name = directory + "/" + Get_File_Name(source_name);
	}

    //std::cout << structure.Path_To_File_Name() << std::endl;
    //std::cout << header_name << std::endl;
    //std::cout << source_name << std::endl;

    std::wofstream hpp_stream(header_name);
    std::wofstream cpp_stream(source_name);
    
    auto str = As_Removed_Suffix(structure.File_Name());
    std::wstring wstr(str.begin(),str.end());
    cpp_stream << "#include " << '"' << wstr << ".hpp" << '"' << '\n';
    hpp_stream << "#pragma once\n";
    Print_Include_Files(hpp_stream,structure.Header_Includes());
    Print_Include_Files(cpp_stream,structure.Source_Includes());
    hpp_stream << '\n';
    cpp_stream << '\n';

    //dump hpp code wrapped in class name
    Dump_HPP(hpp_stream,structure,structure.File_Name(),utility_functions);

    //dump cpp
    cpp_stream << structure.CPP_Code();
    auto suf_removed = As_Removed_Suffix(structure.File_Name());
    auto class_name = as_wstring(Make_Capital_And_Underscored_In_User_Type_Format(suf_removed));
    
    //add the json exporting function
    if (utility_functions){
    cpp_stream << "//functions added automatically by hcp-compiler\n";
    
        //json function implementation
        
        //class name function implementation
        cpp_stream << "std::string Class_Name(" <<  class_name << " const& class_object){\n";
        cpp_stream << "\treturn \"" <<  class_name << "\";\n}";
        
        //As YAML String
        cpp_stream << "std::string As_YAML_String(" <<  class_name << " const& class_object){\n";
        cpp_stream << "\tstd::string yaml_str;\n";
        cpp_stream << "\treturn yaml_str;\n}";
        
        //As XML String
        cpp_stream << "std::string As_XML_String(" <<  class_name << " const& class_object){\n";
        cpp_stream << "\tstd::string xml_str;\n";
        cpp_stream << "\treturn xml_str;\n}";
    }
}

 void Class_Compiler::Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes){

    for (auto it: includes){
        if (it.second){
            outfile << "#include ";
            if (Begins_And_Ends_With(it.first,L'"')){
                outfile << As_Last_Char_Removed(it.first) << ".hpp\"";
            }else{
                outfile << "<" << it.first << ">";
            }
            outfile << '\n';
        }
    }
}

 void Class_Compiler::Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file, bool const& utility_functions){
    auto str = Make_Capital_And_Underscored_In_User_Type_Format(As_Removed_Suffix(hcp_file));
    std::wstring wstr(str.begin(),str.end());
    outfile << "class " << wstr;
    if (!structure.Inheritance().empty()){
        outfile << ": " << structure.Inheritance();
    }
    outfile << "{\n";

    //dump
    outfile << structure.HPP_Code();
    
    if (utility_functions){
      outfile << "//functions added automatically by hcp-compiler\n";
      outfile << "public:\n";
      outfile << "\tfriend  std::string Class_Name(" <<  wstr << " const& class_object);\n";
      outfile << "\tfriend  std::string As_YAML_String(" <<  wstr << " const& class_object);\n";
      outfile << "\tfriend  std::string As_XML_String(" <<  wstr << " const& class_object);\n";
      
      outfile << "private:\n";
      outfile << "friend class boost::serialization::access;\n";
      outfile << "template<class Archive>\n";
      outfile << "void serialize(Archive & ar, const unsigned int version){\n";
      for (auto const& data_member: structure.Data_Members()){
          outfile << "\tar & " << data_member << ";\n";
      }
      outfile << "}\n";
      
      
      // outfile << "public:\n";
      // outfile << "NLOHMANN_DEFINE_TYPE_INTRUSIVE(";
      // outfile << Get_As_Comma_Seperated_String(structure.Data_Members());
      // outfile << ")";
    }
    
    outfile << "};";
    
}

