#include "stat_timer.hpp"
void Stat_Timer::Start_Timer(){
	timer.Start();
	return;
}
void Stat_Timer::End_Timer(){
	timer.End();
	return;
}
double Stat_Timer::Duration_Of_Timer(){
	return timer.Duration();
}