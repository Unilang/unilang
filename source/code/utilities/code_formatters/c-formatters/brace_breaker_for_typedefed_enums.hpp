class
❪"utilities"❫
❪"systems"❫
❪"program_input"❫
⚯
❪"line_processor"❫
⚞⚟
◀public: static▶ void ☀Execute_Needed_Tasks(Program_Input const& input) ❰
  Line_Processor::Process(input.options, Do);
❱

◀private: static▶ std::string& ☀Do(std::string & all) ❰

    //assumes:
    //<any number of spaces>typedef enum name {<any number of spaces>
    auto find = all;
    trim(find);

	const std::string prefix_to_find = "typedef enum ";
    const std::string suffix_to_find = "{";
    
    //target line
    if (Begins_With(find,prefix_to_find) && Ends_With(find,suffix_to_find)){
        
        
        Remove_Last_Char(find);
        rtrim(find);
        find+="\n";
        
        auto indent = Starts_With_How_Many_Spaces(all);
        Append_N_Times(find," ",indent);
        Append(find,suffix_to_find);
        
        all = find;
    }

    return all;
❱
