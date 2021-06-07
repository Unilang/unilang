#include "timer.hpp"

void Timer::Start(){
	start = std::chrono::steady_clock::now();
	return;
}

void Timer::End(){
	end = std::chrono::steady_clock::now();
	diff = end - start;
	return;
}

double Timer::Duration() const{
	return std::chrono::duration <double, std::milli> (diff).count()/1000;
}