//
//  execute.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/26/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef execute_hpp
#define execute_hpp

#include <stdio.h>
#include "memory.hpp"
#include "pcb.hpp"
#include "cpu.hpp"
#include "fork.hpp"

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

class Execute {
public:
	void runInstruction(Pcb* pcb, Memory* mainMemory);
};
#endif /* execute_hpp */
