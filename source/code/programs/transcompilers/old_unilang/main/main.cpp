#include <locale>
#include <iostream>

//This is a boilerplate main that I think is nice to have in every program I write.  
//No matter how small a program is, it inevitably grows,
//Its nice to have these facilities pre-implemented.
//Some may think this a bulky addon for every application.
//I think compilers are pretty good, and this fits my design principals.
//previously generated, but put in place when switching to mono repo

//decelerations
void Setup_And_Run_Program_Wrapped_In_Generated_Exception_Catcher(int const argc, char** const argv);
void Setup_And_Run_Program(int const argc, char** const argv);
Composed_Program_Options Convert_Raw_Program_Options_Into_Composed_Structures(int const argc, char** const argv);
Program_Input Get_Verified_Program_Input(int const argc, char** const argv);
void Set_Up_Locale();

//definitions
int main(int const argc, char** const argv) {
    
    //sets up, runs program, and directs all uncaught exceptions to a generated root exception handler
    Setup_And_Run_Program_Wrapped_In_Generated_Exception_Catcher(argc,argv);
    //exit successfully (assuming we didn't bail out)
    return EXIT_SUCCESS;
}

void Setup_And_Run_Program_Wrapped_In_Generated_Exception_Catcher(int const argc, char** const argv){
    
    //setup and run program
    //direct any uncaught exceptions to the root exception handler
    try{Setup_And_Run_Program(argc,argv);}
    catch(...){Root_Exception_Handler::Handle_Exceptions();}
}

void Setup_And_Run_Program(int const argc, char** const argv){
    
    //setup the locale and facets
    Set_Up_Locale();
    
    auto verified_program_input = Get_Verified_Program_Input(argc,argv);
    
    //execute all the needed tasks based on the program option flags
    Task_Executer::Execute_Needed_Tasks(verified_program_input);
}
Composed_Program_Options Convert_Raw_Program_Options_Into_Composed_Structures(int const argc, char** const argv){

    //create a program options object from out of boost
    auto program_options = Program_Options_Creator::Create(argc, argv);
    
    //let the user compose those parsed values into sub structs
    auto composed_program_options = Program_Options_Composer::Compose(program_options);
    
    //return composed version of program options
    return composed_program_options;
}
Program_Input Get_Verified_Program_Input(int const argc, char** const argv){
  
    //get program options from command line
    auto composed_program_options = Convert_Raw_Program_Options_Into_Composed_Structures(argc,argv);
    
    //get root settings
    auto settings = Root_Settings_Getter::Get();
    
    //create and verify the program input
    Program_Input program_input{settings,composed_program_options};
    Program_Input_Validator::Validate(program_input);
  
  return program_input;
}

void Set_Up_Locale(){
    
    //Unicode please
    std::locale::global(std::locale("en_US.UTF-8"));
    
    //in case we print money or something
    std::cout.imbue(std::locale("en_US.utf8"));
}
