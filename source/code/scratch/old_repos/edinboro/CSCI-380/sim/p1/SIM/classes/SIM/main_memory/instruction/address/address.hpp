#pragma once
#include <iostream>
/*

*/
class Address{

	public:

	//Constructors
	Address(std::string address);
	Address(unsigned int const& address = 0);

	//Observers

	friend std::ostream& operator << (std::ostream &out, Address const& address);
	Address& operator= (std::string number);
	Address& operator= (unsigned int const& number);
	operator unsigned int () const;

	//Transformers


	protected:
	private:

	//functions

	//data members
	unsigned int value; //change to boost_int

};
