#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "feed_reader.hpp"

class Thread_Starter {
	
	//runs all of the threaded tasks (the "main" function no longer does anything, and is just in a constant loop)
	public: static void Run_The_Never_Ending_Threads(std::vector<Feed_Reader> const& feed_readers);
	
};
