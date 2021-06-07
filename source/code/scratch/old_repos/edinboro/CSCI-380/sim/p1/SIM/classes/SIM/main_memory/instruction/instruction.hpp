#pragma once
#include <iostream>
#include "op_code/op_code.hpp"
#include "address/address.hpp"
/*

*/
class Instruction{

	public:

	//Constructors
	Instruction(void);
	Instruction(std::string op_code,std::string address);

	//Observers
	Address Get_Address(void) const;
	OP_Code Get_OP_Code(void) const;
	std::string Get_OP_String      (void) const;
	std::string Get_Address_String (void) const;


	bool Is_Empty(void)       const;

	friend std::ostream& operator << (std::ostream &out, Instruction const& instruction);

	//Transformers
	void Clear(void);
	void Set_Address(Address const& _address);
	void Set_OP_Code(OP_Code const& _op_code);


	protected:
	private:

	//functions

	//data members
	OP_Code op_code;
	Address address;

};
