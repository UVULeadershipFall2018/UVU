//
//  load.hpp
//  vm1
//
//  Created by TJ Nielsen on 8/29/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef load_hpp
#define load_hpp
#include <vector>
#include "memory.hpp"

#include <stdio.h>

class Load {
public:
	
	static const int OP_ADR = 0;
	static const int OP_MOV = 1;
	static const int OP_STR = 2;
	static const int OP_STRB = 3;
	static const int OP_LDR = 4;
	static const int OP_LDRB = 5;
	static const int OP_BX = 6;
	static const int OP_B = 7;
	static const int OP_BNE = 8;
	static const int OP_BGT = 9;
	static const int OP_BLT = 10;
	static const int OP_BEQ = 11;
	static const int OP_CMP = 12;
	static const int OP_AND = 13;
	static const int OP_ORR = 14;
	static const int OP_EOR = 15;
	static const int OP_ADD = 16;
	static const int OP_SUB = 17;
	static const int OP_MUL = 18;
	static const int OP_DIV = 19;
	static const int OP_SWI = 20;
	static const int OP_BL = 21;
	static const int OP_MVI = 22;
	
	std::vector<char> memory;
	int program_size;
	int program_start;
	int load_address;
	void load_from_bin(std::string filename, Memory *mem, bool verbose);
	void decode (std::vector<char> contents);
	std::string filename;
};
#endif /* load_hpp */
