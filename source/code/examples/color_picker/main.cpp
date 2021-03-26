#include <iostream>
#include "code/utilities/program/wrappers/zenity/color_picker/color_picker.hpp"
#include "code/utilities/program/wrappers/zenity/color_picker/color_picker_settings.hpp"

int main(){
    Color_Picker_Settings c_settings;
    auto new_color = Color_Picker::Select_Color(c_settings);
    std::cout << new_color.r << " " << new_color.g << " " << new_color.b << std::endl;
}