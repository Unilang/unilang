#pragma once
#include <string>
#include <vector>
#include <thread>
#include <iostream>

//these all need reworked through the other two methods of spawining processes

std::vector<std::string> Get_Each_Line_Of_Shell_Command(std::string const& command);

//runs in the shell and gives you back the results (stdout and stderr)
std::string exec(std::string const& cmd);
std::string exec(const char* cmd);
std::string execute(std::string const& cmd);
std::string execute(const char* cmd);

std::string print_and_execute(std::string const& cmd);

//runs in the shell and gives you back one of the streams (stdout or stderr)
std::string execute_and_get_back_stdout_only(std::string const& cmd);
std::string execute_and_get_back_stdout_only(const char* cmd);
std::string execute_and_get_back_stderr_only(std::string const& cmd);
std::string execute_and_get_back_stderr_only(const char* cmd);

void execute_to_file(std::string const& cmd, std::string const& file);

//runs in the shell and gives you back nothing (sends all the streams into dev/null/)
void exec_quietly(std::string const& cmd);
void exec_quietly(const char* cmd);
void execute_quietly(std::string const& cmd);
void execute_quietly(const char* cmd);
void no_hup_execute_quietly_in_background(std::string const& cmd);

int Execute_Quietly_But_Report_Stderr_When_Nonzero(std::string const& cmd);
void Execute_Quietly_But_Report_Stderr_And_Exit_When_Nonzero(std::string const& cmd);

//runs in the shell and gives you back the return code (nothing is silenced)
int system(std::string const& cmd); //nice override for already existing C++ system(char*)
int Get_Return_Value_Of_Running(std::string const& cmd);
int Get_Return_Value_Of_Running(const char* cmd);

//runs in the shell and gives you back the return code (stdout or stderr is silenced)
int Silence_Stdout_And_Get_Return_Value_Of_Running(std::string const& cmd);
int Silence_Stdout_And_Get_Return_Value_Of_Running(const char* cmd);
int Silence_Stderr_And_Get_Return_Value_Of_Running(std::string const& cmd);
int Silence_Stderr_And_Get_Return_Value_Of_Running(const char* cmd);

//runs in the shell and gives you back the return code (all streams silenced)
int Silence_Output_And_Get_Return_Value_Of_Running(std::string const& cmd);
int Silence_Output_And_Get_Return_Value_Of_Running(const char* cmd);

bool Successful_Run_Of_Command(const char* cmd);          //all silenced
bool Successful_Run_Of_Command(std::string const& cmd);   //all silenced
bool Unsuccessful_Run_Of_Command(const char* cmd);        //all silenced
bool Unsuccessful_Run_Of_Command(std::string const& cmd); //all silenced
