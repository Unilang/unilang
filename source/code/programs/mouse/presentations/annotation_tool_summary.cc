#include <iostream>
#include <string>
#include "code/utilities/peripheral/mouse/mouse_controller.hpp"
#include "code/utilities/program/call/lib.hpp"


//this was a presentation tool designed to show functionality of a GUI tool
//we keep it here as an example.  we'll consider generating this kind of movie code later
std::string build_geo_flag(Point size, Point p){
    std::string command;
    if (size.x >= 0){
        command += std::to_string(size.x);
    }
    command += "x";
    command += std::to_string(size.y);
    command += "+";
    command += std::to_string(p.x);
    command += "+";
    command += std::to_string(p.y);
    return command;
}

void create_transparent_presentation_text(Point size, Point p, std::string const& str){
    std::string command;
    command += "echo \"";
    command += str;
    command += "\"";
    command += " | ";
    command += "lemonbar ";
    command += "-p ";
    command += "-F#FF000000 ";
    command += "-B#00000000 ";
    command += "-g ";
    command += build_geo_flag(size,p);
    command += " -f ";
    command += "\"";
    command += "Arial Black-24";
    command += "\"";
    command += " &";
    std::cout << command << std::endl;
    
    system(command);
}

void create_presentation_text(Point size, Point p, std::string const& str, std::string const& bg_color, std::string const& fg_color){
    std::string command;
    command += "echo \"";
    command += str;
    command += "\"";
    command += " | ";
    command += "lemonbar ";
    command += "-p ";
    command += "-F#FF";
    command += fg_color;
    command += " ";
    command += "-B#FF";
    command += bg_color;
    command += " ";
    command += "-g ";
    command += build_geo_flag(size,p);
    command += " -f ";
    command += "\"";
    command += "Arial Black-24";
    command += "\"";
    command += " &";
    std::cout << command << std::endl;
    
    system(command);
}

std::string lemon_light_green(){
    return "C5E8A2";
}
std::string lemon_light_blue(){
    return "A2E8E6";
}
std::string lemon_light_pink(){
    return "E8A2C8";
}
std::string lemon_light_orange(){
    return "E8B9A2";
}
std::string lemon_light_yellow(){
    return "E2E8A2";
}
std::string lemon_light_gray(){
    return "B6BCC1";
}

std::string lemon_dark_pink(){
    return "6d3658";
}
std::string lemon_dark_orange(){
    return "6d5936";
}
std::string lemon_dark_yellow(){
    return "6d6836";
}
std::string lemon_dark_green(){
    return "3a6d36";
}
std::string lemon_dark_blue(){
    return "36586d";
}
std::string lemon_dark_purple(){
    return "542487";
}
std::string lemon_dark_gray(){
    return "56554b";
}

std::string lemon_white(){
    return "000000";
}
std::string lemon_black(){
    return "FFFFFF";
}

void remove_all_presentation_text(){
    system("pkill lemonbar");
}

void show_first_message(std::string const& str, std::string const& bg_color, std::string const& fg_color){
    Point size;
    //size.x = 600;
    size.x = -1;
    size.y = 40;
    Point p;
    p.x = 1200;
    p.y = 459;
    create_presentation_text(size,p,str,bg_color,fg_color);
}

//create bar at the top
//echo "hello world" | ./lemonbar -p -F#FFFFFFFF -B#FF222222
int main(int argc, char** argv){

    show_first_message("Local Map Sim",lemon_white(),lemon_black());
    Sleep_For_N_Milliseconds(5000);
    Mouse_Controller controller;
    
    //click "Create Route"
    Point p;
    p.x = 675;
    p.y = 472;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("Load/Create Routes",lemon_dark_green(),lemon_white());
    
    //click "Name Box"
    p.x = 809;
    p.y = 573;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    // type into "Name Box"
    controller.type_something_at_presentation_speed("test route");
    
    
    //click add lane button multiple times
    p.x = 735;
    p.y = 598;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(290);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(280);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    
    //adjust submaps
    p.x = 691;
    p.y = 633;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    controller.type_something_at_presentation_speed("1");
    
    p.x = 691;
    p.y = 751;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    controller.type_something_at_presentation_speed("1");
    
    p.x = 691;
    p.y = 774;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    controller.type_something_at_presentation_speed("1");
    
    //set a lane length
    p.x = 749;
    p.y = 705;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //slide right
    p.x = 794;
    p.y = 705;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //click marking button
    p.x = 892;
    p.y = 574;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(250);
    controller.presentation_click();
    show_first_message("Apply Annotation Algos",lemon_dark_blue(),lemon_white());
    
    //toggle start marking
    p.x = 860;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(700);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //toggle end marking
    p.x = 1009;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(700);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //turn on Regeneration SLA
    p.x = 860;
    p.y = 994;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //hover over sla slider
    p.x = 1060;
    p.y = 994;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //slide left
    p.x = 1034;
    p.y = 994;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //slide right
    p.x = 1112;
    p.y = 994;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //close algorithm tab
    p.x = 1112;
    p.y = 771;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //click "Settings Tab"
    p.x = 753;
    p.y = 531;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //Enable "Event Markings"
    p.x = 1162;
    p.y = 641;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("View/Adjust Annotation Points",lemon_dark_yellow(),lemon_white());
    Sleep_For_N_Milliseconds(200);
    
    //Refocus Mark Route Window
    p.x = 1058;
    p.y = 719;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //Open Marker Placement
    p.x = 1058;
    p.y = 793;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //move to marker placement slider
    p.x = 970;
    p.y = 858;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //slide right
    p.x = 1070;
    p.y = 858;
    controller.drag_mouse(p,6000);
    
    //slide left
    p.x = 970;
    p.y = 858;
    controller.drag_mouse(p,6000);
    
    //slide right
    p.x = 1070;
    p.y = 858;
    controller.drag_mouse(p,6000);
    
    //slide left
    p.x = 1000;
    p.y = 858;
    controller.drag_mouse(p,6000);
    Sleep_For_N_Milliseconds(200);
    
    //click label box
    p.x = 1018;
    p.y = 880;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    // type into "Label Box"
    controller.type_something_at_presentation_speed("regenerate");
    
    //click "Apply"
    p.x = 1088;
    p.y = 880;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //switch to "Annotating Over a Route"
    p.x = 946;
    p.y = 746;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("Create Event Regions",lemon_dark_orange(),lemon_white());
    Sleep_For_N_Milliseconds(200);
    
    //get to end marker
    p.x = 1061;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //extend end marker
    p.x = 1150;
    p.y = 812;
    controller.drag_mouse(p,6000);
    
    //got to start marker
    p.x = 977;
    p.y = 812;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    
    //extend start marker
    p.x = 1041;
    p.y = 812;
    controller.drag_mouse(p,6000);
    
    //click label box
    p.x = 993;
    p.y = 832;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    // type into "Label Box"
    controller.type_something_at_presentation_speed("hotspot");
    
    //click "Apply"
    p.x = 1092;
    p.y = 832;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //close the mark route window
    p.x = 1352;
    p.y = 720;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //open Event View
    p.x = 1279;
    p.y = 753;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("Event Processing On Cycles",lemon_dark_gray(),lemon_white());
    Sleep_For_N_Milliseconds(200);
    
    //show The Event View
    p.x = 1160;
    p.y = 777;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(1000);
    
    //open Location
    p.x = 1240;
    p.y = 731;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("Simulate Speed/Lag",lemon_dark_green(),lemon_white());
    Sleep_For_N_Milliseconds(200);
    
    //show speed
    p.x = 1160;
    p.y = 892;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //close location
    p.x = 1240;
    p.y = 731;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    
    //open the Time
    p.x = 1179;
    p.y = 804;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    Sleep_For_N_Milliseconds(200);
    
    //make it faster
    p.x = 1191;
    p.y = 823;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    p.x = 1145;
    p.y = 823;
    controller.drag_mouse(p,30000);
    Sleep_For_N_Milliseconds(2500);
    
    //Open log
    p.x = 800;
    p.y = 529;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("Observe Events",lemon_dark_pink(),lemon_white());
    Sleep_For_N_Milliseconds(6000);
    
    
    //Open Profiler
    p.x = 854;
    p.y = 528;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    show_first_message("Reactive Profiling",lemon_dark_orange(),lemon_white());
    Sleep_For_N_Milliseconds(1000);
    
    //increase history
    p.x = 773;
    p.y = 735;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    p.x = 872;
    p.y = 735;
    controller.drag_mouse(p,10000);
    
    //auto scale
    p.x = 1278;
    p.y = 734;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    controller.presentation_click();
    
    //hover to see numbers
    p.x = 1020;
    p.y = 809;
    controller.move_mouse_at_presentation_speed(p);
    Sleep_For_N_Milliseconds(200);
    show_first_message("and much much more...",lemon_white(),lemon_black());
    
}