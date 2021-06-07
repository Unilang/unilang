#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "utilities.hpp"
#include "feed_reader.hpp"

class Puller {
	
	//tells the feed reader to update and download new files every so often
	public: static void Start_Task(Feed_Reader feed_reader);
	 
	 
};
