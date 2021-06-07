#pragma once
#include "timer.hpp"

class Stat_Timer{
	
	
public:
	void Start_Timer();
	void End_Timer();
	double Duration_Of_Timer();
	
private:
	Timer timer;
	
};