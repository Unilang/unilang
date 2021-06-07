#pragma once
#include <chrono>

class Timer{
	
public:
	void Start();
	void End();
	
	//call this after you've started and stoped the timer
	double Duration() const;
	
private:
	decltype(std::chrono::steady_clock::now()) start;
	decltype(std::chrono::steady_clock::now()) end;
	decltype(end - start) diff;
	
};