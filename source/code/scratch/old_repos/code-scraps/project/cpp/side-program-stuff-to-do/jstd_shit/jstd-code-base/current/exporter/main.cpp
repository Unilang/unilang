//RUN THIS PROGRAM AT THE ROOT OF THE PSEUDO LIBRARY.
//IT SHOULD GET BUILT THERE ANYWAY.
//EDIT: I added a check, to make sure that it was run in the correc directory.
//The only danger would be if you ran it in a different folder that happened to be
//named the same thing as the root pseudo library folder. So still be careful.
//tldr; cd to the folder where this is built and only run it there.

//STD STUFF
#include <cstdlib>

//globals
#include "global.hpp"

//utility functions
#include "utilities.hpp" //<-- this is the kind of stuff that the jstd fixes, ya know?

//my classes
#include "scanner.hpp"
#include "exporter.hpp"
#include "builder.hpp"
#include "documenter.hpp"
#include "program_options.hpp"

//function decelerations
void Make_Sure_Program_Is_Run_In_The_Correct_Directory();
void Run_Scan_If_Needed(Program_Options const& program_options);
void Run_Export_If_Needed(Program_Options const& program_options);
void Run_Builds_If_Needed(Program_Options const& program_options);
void Create_Documentation_If_Needed(Program_Options const& program_options);
	
int main(int argc, char** argv){
	
	//read in program options
	Program_Options program_options(argc,argv);
	
	//CHECK TO MAKE SURE THE PWD IN THE RIGHT DIRECTORY.
	//WE EXPECT THE PROGRAM TO BE RUN IN A SPECIFICALLY NAMED FOLDER.
	//immediately exit, if the program is run in the wrong directory.
	Make_Sure_Program_Is_Run_In_The_Correct_Directory();
	
	//scan the pseudo library if command line permits it
	Run_Scan_If_Needed(program_options);
	
	//export the library if command line permits it
	Run_Export_If_Needed(program_options);
	
	//build static/dynamic libraries for windows/linux if command line permits it
	Run_Builds_If_Needed(program_options);
	
	//export documentation if command line permits it
	Create_Documentation_If_Needed(program_options);
	
	//program completed successfully
	Green_Message("Everything finished successfully!\n");
	
	return EXIT_SUCCESS;
}

//functions
void Make_Sure_Program_Is_Run_In_The_Correct_Directory(){
	
	//as noted by the comment at the top, we need to make sure you run this program in the right directory.
	//We can do a decent job of this, by making sure that the program is at least being run in the
	//correctly named directory.  We'll just have to hope that correctly named directory, is indeed the correct directory.
	if (Current_Folder_Name() != constant::NAME_Of_ROOT_FOLDER_THAT_EXPORTER_SHOULD_RUN_IN){
		Exit_With_Error_Message("You are not running the exporter in the correct directory.\n");
	}
		
	return;
}
void Run_Scan_If_Needed(Program_Options const& program_options){

	//perform a scan on the pseudo library (assuming you want to)
	//and output information about its success or failures
	if (program_options.Scan()){
		Scanner::Scan(program_options);
	}
	
	return;
}
void Run_Export_If_Needed(Program_Options const& program_options){
	
	//perform the export to create the real library (assuming you want to)
	//and output information about its success or failures
	if (program_options.Export()){
		Exporter::Export(program_options);
	}
	
	return;
}
void Run_Builds_If_Needed(Program_Options const& program_options){
	
	//perform builds to create create static/dynamic versions of the real library
	//and output information about its success or failures
	if (program_options.Build()){
		Builder::Build(program_options);
	}
	
	return;
}
void Create_Documentation_If_Needed(Program_Options const& program_options){
	
	//create documentation if specified in the command line
	if (program_options.Documentation()){
		Documenter::Document(program_options);
	}
	
	return;
}


