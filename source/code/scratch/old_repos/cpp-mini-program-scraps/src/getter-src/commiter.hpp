#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "utilities.hpp"

class Commiter {
	
	//automatically pushes the code base onto github.
	//it will make a pull before it does,  but it assumes no merge conflicts will occur.
	//if merge conflicts do occur, this thread task will probably break. I mean, I dunno what
	//will happen.  It will probably just not actually do the commit, but will still try again later... who knowws
	public: static void Start_Task();
};
