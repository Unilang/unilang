#pragma once

enum class Find_By_Method
{ID,CLASS,TAG
};


struct Find_By_Step{
	Find_By_Method method;
	std::string value;

    Find_By_Step(Find_By_Method method_in, std::string value_in):
	method(method_in),
	value(value_in)
	{	}
};