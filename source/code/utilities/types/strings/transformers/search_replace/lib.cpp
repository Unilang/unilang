#include "code/utilities/types/strings/transformers/search_replace/lib.hpp"
#include <algorithm>
#include <map>

std::string destroy_path_name_with_underscores(std::string path){

    path = string_replace_all(path,"/","_");
    path = string_replace_all(path,".","_");
    return path;
    
}
std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl){
    // handle error situations/trivial cases

    if (target.length() == 0 || src.length() == 0) {
        return src;
    }

    size_t idx = 0;

        idx = src.find( target, idx);

        src.replace( idx, target.length(), repl);
        idx += repl.length();

    return src;
}
std::string string_replace_all( std::string src, std::string const& target, std::string const& repl){

    if (target.length() == 0) {
        // searching for a match to the empty string will result in
        //  an infinite loop
        //  it might make sense to throw an exception for this case
        return src;
    }

    if (src.length() == 0) {
        return src;  // nothing to match against
    }

    size_t idx = 0;

    for (;;) {
        idx = src.find( target, idx);
        if (idx == std::string::npos)  break;

        src.replace( idx, target.length(), repl);
        idx += repl.length();
    }

    return src;
}

std::string& replace_spaces_with_plus( std::string & str){
    return replace_all(str,' ','+');
}
std::string& replace_spaces_with_underscore( std::string & str){
    return replace_all(str,' ','_');
}
std::string& replace_fwd_slash_with_space(std::string & str){
    return replace_all(str,'/',' ');
}
std::string& replace_space_with_fwd_slash(std::string & str){
    return replace_all(str,' ','/');
}

std::string& replace_all( std::string & src, char const& c1, char const& c2) {
    for (auto & it: src) {
        if (it ==  c1) {
            it = c2;
        }
    }

    return src;
}

std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str) {



     std::map<char,int> m;
    for (size_t i =0; i < str.size(); ++i) {
        if (!m.insert( std::pair<char,int>(str[i],0)).second) {
            str.erase(i, 1); --i;
        }
    }

    return str;
}