#pragma once
namespace constants{
	
	//simulator constants
	constexpr const unsigned short VERSION_NUMBER{1};
	
	//memory constants
	constexpr const unsigned short MAIN_MEMORY_SIZE{256};
	constexpr const unsigned short ADDRESS_BIT_SIZE{8};
	constexpr const unsigned short OP_CODE_BIT_SIZE{8};
	constexpr const unsigned short INSTRUCTION_BIT_SIZE{ADDRESS_BIT_SIZE + OP_CODE_BIT_SIZE};
	
	//register constants
	constexpr const unsigned short AC_BIT_SIZE{16};
	constexpr const unsigned short PC_BIT_SIZE{8};
	constexpr const unsigned short IR_BIT_SIZE{8};
	constexpr const unsigned short MAR_BIT_SIZE{8};
	constexpr const unsigned short MBR_BIT_SIZE{16};
	constexpr const unsigned short TMPR_BIT_SIZE{16};
	constexpr const unsigned short PSW_BIT_SIZE{16};
	
	//dump memory constants
	constexpr const unsigned short OP_CODE_SET_WIDTH{13};
	constexpr const unsigned short ADDRESS_SET_WIDTH{5};
	constexpr const unsigned short MEMORY_INDEX_WIDTH{5};
	constexpr const unsigned short TOP_NEWLINE_COUNT{2};
	constexpr const unsigned short BOTTOM_NEWLINE_COUNT{2};
	

}
