#pragma once
#include "global.hpp"
#include <string>
#include <iostream>
#include <thread>

struct Code_Info{
	
	
	//all data will be valid when the object is constructed
	Code_Info(std::string const& code_id, std::string const& suffix){
		
		
		Refresh_Data(code_id,suffix);
		int tries = 25;
		while (status != "0" && tries > 0){
			std::cerr << "code_info status was 0! UH OH! Wait 5 seconds and try again\n";
			--tries;
			std::this_thread::sleep_for(std::chrono::seconds(5));
			Refresh_Data(code_id,suffix);
		}
		
		if (tries <= 0){
			std::cerr << "we got stuck in an infinite \"check for ready\" state. the api is never going to tell us that the file is ready, so jus SKIP IT\n";
			skipped = true;
		}
		
	}
	
	private: void Refresh_Data(std::string const& code_id, std::string const& suffix){
		
		using namespace constant;
		
		//pull from the ideone api
		std::string statement = "python " + IDEONE_API_PULLER + " " + IDEONE_API_USERNAME + " " + IDEONE_API_PASSWORD + " " + code_id + " " + suffix + " >> /dev/null 2>&1";
		system((statement).c_str());
		
		//read all of the data in
		source_code = Get_Whole_File_As_String  ( DUMP_OF_SOURCE_CODE + "-"  +suffix );
		stdin       = Get_Whole_File_As_String  ( DUMP_OF_STDIN       + "-"  +suffix );
		stdout      = Get_Whole_File_As_String  ( DUMP_OF_STDOUT      + "-"  +suffix );
		stderr      = Get_Whole_File_As_String  ( DUMP_OF_STDERR      + "-"  +suffix );
		error       = Get_Whole_File_As_String  ( DUMP_OF_ERROR       + "-"  +suffix );
		status      =  Get_Whole_File_As_String ( DUMP_OF_STATUS      + "-"  +suffix );
		signal      = Get_Whole_File_As_String  ( DUMP_OF_SIGNAL      + "-"  +suffix );
		result      = Get_Whole_File_As_String  ( DUMP_OF_RESULT      + "-"  +suffix );
	}
	
	public:
	std::string source_code;
	std::string stdin;
	std::string stdout;
	std::string stderr;
	std::string error;
	std::string status;
	std::string signal;
	std::string result;
	bool skipped = false;
};
