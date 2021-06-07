class
❪"utilities"❫
❪"systems"❫
❪"program_input"❫
⚯
❪"bulk_line_processor"❫
⚞⚟
◀public: static▶ void ☀Execute_Needed_Tasks(Program_Input const& input) ❰
  Bulk_Line_Processor::Process(input.options, Do);
❱

◀private: static▶ std::vector<std::string>& ☀Do(std::vector<std::string> & all) ❰

  auto macro_lines = Gather_Macro_Lines(all);
  Make_Padding_Adjustments(macro_lines);
  return all;
❱

◀private: static▶ std::vector<std::reference_wrapper<std::string>> ☀Gather_Macro_Lines(std::vector<std::string> & all) ❰
  std::vector<std::reference_wrapper<std::string>> found;
  
  std::vector<std::reference_wrapper<std::string>> view;
  for (auto & it: all){
    
    if (view.size() < 3){
        view.push_back(it);
    }
    else{
        Proccess_View(view,it,found);
    }
  }
  
  return found;
❱



◀private: static▶ void ☀Proccess_View(std::vector<std::reference_wrapper<std::string>> & view, std::string & it, std::vector<std::reference_wrapper<std::string>> & found) ❰

    if (Begins_With(view[0].get(),"#ifndef ")){
        if (Begins_With(view[1].get(),"#define ")){
            if (Begins_With(view[2].get(),"#endif")){
                found.push_back(view[1].get());
            }
        }
    }
    
    //perform view shift
    view[0] = view[1];
    view[1] = view[2];
    view[2] = it;
❱

◀private: static▶ void ☀Make_Padding_Adjustments(std::vector<std::reference_wrapper<std::string>> & found) ❰

  int max_length = 0;
  
  //had to change all the indexes from 1 to 0, not sure how this ever worked before as 1.
  //oh 1 when you split by spaces, because the macros have a space after the #define which is captured
  
  //squeeze spaces
  for (auto &it: found){
        Squeeze_Away_Spaces(it.get());
  }
  
  //find max:
  for (auto it: found){
    auto splits = As_Split_Macro_Line(it);
    if (splits[0].length() > max_length){
        max_length = splits[0].length();
    }
  }
  
      //std::cout << max_length << std::endl;
      
      //reformat strings based on max size:
      for (auto & it: found){
        auto splits = As_Split_Macro_Line(it);
        std::string temp = splits[0];
        for (int i = 0; i < max_length-temp.length(); ++i){
            splits[0]+= ' ';
        }
        
        //reprint splits
        std::string final = splits[0];
        for (int i =1; i < splits.size(); ++i){
            final += " ";
            final += splits[i];
        }
    
    it.get() = final;
  }
❱

◀private: static▶ std::vector<std::string> ☀As_Split_Macro_Line(std::string it)❰

  if (Contains_Substring(it,")")){
    
    //assume its a function macro
    return Convert_Pair_To_Two_Element_Vector(As_Trim_Element_Sides(Split_On_First_Instance_Of_Char(it,')')));
  }
    
    //assume its just a macro, and not a function macro
    return Convert_Pair_To_Two_Element_Vector(As_Trim_Element_Sides(Split_On_Second_Instance_Of_Char(it,' ')));

❱

◀private: static▶ std::pair<std::string,std::string>  ☀As_Trim_Element_Sides(std::pair<std::string,std::string> p)❰
  trim(p.first);
  trim(p.second);
  return p;
❱
