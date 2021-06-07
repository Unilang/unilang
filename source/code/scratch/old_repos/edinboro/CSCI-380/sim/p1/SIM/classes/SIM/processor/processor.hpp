#pragma once
#include <iostream>
#include "instruction/instruction.hpp"
#include "op_code/op_code.hpp"
#include "address/address.hpp"
#include "process_signal/process_signal.hpp"

/*

*/

class Processor{

	public:

	//Constructors
	Processor();

	//Observers
	int next_instruction_index(void);
	int MAR(void);
	Instruction MBR(void);
	Process_Signal Signal(void);
	
	//Transformers
	void Execute(Instruction instruction);
	void Execute(Process_Signal signal, Instruction instruction);


	protected:
	private:

	//functions
	void Add(void);
	void Sub(void);
	void Ld(void);
	void St(void);
	void Br(void);
	void Cbr(void);
	void Halt(void);
	void Data(void);
	
	void Add(Instruction instruction);
	void Sub(Instruction instruction);
	void Ld(Instruction instruction);

	//data members
	int ac;
	int pc;
	OP_Code ir;
	Address mar;
	Instruction mbr;
	int tmpr;
	int cs_pc;
	
	Process_Signal process_signal;
	
	
	
	

};
