//
//  decode.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/16/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.


#include "decode.hpp"
#include "memory.hpp"
#include "process.hpp"
#include "cpu.hpp"
#include "registers.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "pcb.hpp"

using namespace std;

Decode::Decode(Memory* mem, Process* proc, Cpu* clock, Registers* reg, bool v, Pcb* pcb) {
//	vector<int*> args;
//	reg->setReg(6, proc->getLoadAddress());
//	reg->setReg(10, mem->getMax());
//	reg->setReg(11, proc->getFirstInstruction());
//	reg->setReg(7, proc->getFirstInstruction());
//	reg->setReg(8, proc->getLimit());
//	char argChar1;
//	char argChar2;
//	char argChar3;
//	char garbChar1;
//	int argInt1;
//	int argInt2;
//	mem->setPC(pcb->getFirstInstructionP());
//	proc->setRunning(true);
//	while(reg->fetchReg(7) < reg->fetchReg(8) && proc->isRunning()){
//		argChar1 = 0;
//		argChar2 = 0;
//		argChar3 = 0;
//		argInt1 = 0;
//		argInt2 = 0;
//		clock->incrementClock(pcb);
//		char instruction_code = *(mem->fetchByte());
//		reg->setReg(11, (reg->fetchReg(11)+6));
//		switch(instruction_code) {
//			case OP_BX:
//				argChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OB_BX: " << static_cast<unsigned>(argChar1);
//				}
//				mem->setPC(mem->getFirstInstructionP() + (reg->fetchReg(argChar1) - mem->getDirectiveLength()));
//				break;
//			case OP_STR:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_STR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
//					cout << endl << "Storing: " << reg->fetchReg(argChar1) << " in memory location: " << reg->fetchReg(argChar2);
//				}
//				mem->directivePushInt(reg->fetchReg(argChar2), reg->fetchReg(argChar1));
//				break;
//			case OP_MOV:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_MOV: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
//					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << reg->fetchReg(argChar2);
//				}
//				reg->setReg(argChar1, reg->fetchReg(argChar2));
//				break;
//			case OP_STRB:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_STR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
//					cout << endl << "Storing: " << reg->fetchReg(argChar1) << " in memory location: " << reg->fetchReg(argChar2);
//				}
//				mem->directivePushChar(reg->fetchReg(argChar2), reg->fetchReg(argChar1));
//				break;
//			case OP_LDR:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_LDR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
//					cout << endl << "Storing: " << *mem->directivePullInt(reg->fetchReg(argChar2)) << " in: R" << static_cast<unsigned>(argChar1);
//				}
//				reg->setReg(argChar1,  *mem->directivePullInt(reg->fetchReg(argChar2)));
//				break;
//			case OP_LDRB:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_LDR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
//					cout << endl << "Storing: " << static_cast<unsigned>(*mem->directivePullChar(reg->fetchReg(argChar2))) << " in: R" << static_cast<unsigned>(argChar1);
//				}
//				reg->setReg(argChar1,  *mem->directivePullChar(reg->fetchReg(argChar2)));
//				break;
//			case OP_CMP:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_CMP: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "CMP of " << reg->fetchReg(argChar1) << " and " << reg->fetchReg(argChar2) << " is " << (reg->fetchReg(argChar1)==reg->fetchReg(argChar2));
//				}
//				if(reg->fetchReg(argChar1)^reg->fetchReg(argChar2)){
//					reg->setReg(9,1);
//				}else {
//					reg->setReg(9, 0);
//				}
//				break;
//			case OP_AND:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_AND: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "AND of " << reg->fetchReg(argChar1) << " and " << reg->fetchReg(argChar2) << " is " << (reg->fetchReg(argChar1)&reg->fetchReg(argChar2));
//				}
//				reg->setReg(9, (reg->fetchReg(argChar1)&reg->fetchReg(argChar2)));
//				break;
//			case OP_ORR:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_ORR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "OR of " << reg->fetchReg(argChar1) << " and " << reg->fetchReg(argChar2) << " is " << (reg->fetchReg(argChar1)|reg->fetchReg(argChar2));
//				}
//				reg->setReg(9, (reg->fetchReg(argChar1)|reg->fetchReg(argChar2)));
//				break;
//			case OP_EOR:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_EOR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "XOR of " << reg->fetchReg(argChar1) << " and " << reg->fetchReg(argChar2) << " is " << (reg->fetchReg(argChar1)^reg->fetchReg(argChar2));
//				}
//				reg->setReg(9, (reg->fetchReg(argChar1)^reg->fetchReg(argChar2)));
//				break;
//			case OP_B:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_B: " << argInt1;
//				}
//				mem->setPC(mem->getFirstInstructionP() + (argInt1 - mem->getDirectiveLength()));
//				break;
//			case OP_BNE:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_BNE: " << argInt1;
//				}
//				if(reg->fetchReg(9)!= 0){
//					mem->setPC(mem->getFirstInstructionP() + (argInt1 - mem->getDirectiveLength()));
//				}
//				break;
//			case OP_BGT:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_BGT: " << argInt1;
//				}
//				if(reg->fetchReg(9) > 0){
//					mem->setPC(mem->getFirstInstructionP() + (argInt1 - mem->getDirectiveLength()));
//				}
//				break;
//			case OP_BLT:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_BLT: " << argInt1;
//				}
//				if(reg->fetchReg(9) < 0){
//					mem->setPC(mem->getFirstInstructionP() + (argInt1 - mem->getDirectiveLength()));
//				}
//				break;
//			case OP_BEQ:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_BEQ: " << argInt1;
//				}
//				if(reg->fetchReg(9) == 0){
//					mem->setPC(mem->getFirstInstructionP() + (argInt1 - mem->getDirectiveLength()));
//				}
//				break;
//			case OP_BL:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_BL: " << argInt1;
//				}
//				reg->setReg(5, reg->fetchReg(11));
//				mem->setPC(mem->getFirstInstructionP() + (argInt1 - mem->getDirectiveLength()));
//				break;
//			case OP_ADD:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_ADD: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << reg->fetchReg(argChar2) <<  " + "  << reg->fetchReg(argChar3) << " = " <<  (reg->fetchReg(argChar2) + reg->fetchReg(argChar3));
//				}
//				reg->setReg(argChar1, (reg->fetchReg(argChar2) + reg->fetchReg(argChar3)));
//				break;
//			case OP_SUB:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_SUB: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << reg->fetchReg(argChar2) <<  " - "  << reg->fetchReg(argChar3) << " = " <<  (reg->fetchReg(argChar2) - reg->fetchReg(argChar3));
//				}
//				reg->setReg(argChar1, (reg->fetchReg(argChar2) - reg->fetchReg(argChar3)));
//				break;
//			case OP_MUL:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_MUL: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << reg->fetchReg(argChar2) <<  " * "  << reg->fetchReg(argChar3) << " = " <<  (reg->fetchReg(argChar2) * reg->fetchReg(argChar3));
//				}
//				reg->setReg(argChar1, (reg->fetchReg(argChar2) * reg->fetchReg(argChar3)));
//				break;
//			case OP_DIV:
//				argChar1 = *mem->fetchByte();
//				argChar2 = *mem->fetchByte();
//				argChar3 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_SUB: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
//					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << reg->fetchReg(argChar2) <<  " / "  << reg->fetchReg(argChar3) << " = " <<  (reg->fetchReg(argChar2) / reg->fetchReg(argChar3));
//				}
//				reg->setReg(argChar1, (reg->fetchReg(argChar2) / reg->fetchReg(argChar3)));
//				break;
//			case OP_SWI:
//				argInt1 = *mem->fetchInt();
//				garbChar1 = *mem->fetchByte();
//				if(v){
//					cout << endl << "OP_SWI: " << argInt1;
//					switch(argInt1) {
//						case 1:
//							break;
//						case 2:
//							cout << endl << "R2 = " << reg->fetchReg(2);
//							break;
//						case 3:
//							proc->setRunning(false);
//							cout << endl;
//							break;
//					}
//				}
//				break;
//			case OP_ADR:
//				argChar1 = *mem->fetchByte();
//				argInt1 = *mem->fetchInt();
//				reg->setReg(argChar1, argInt1);
//				if(v){
//					cout << endl << "OP_ADR: " << static_cast<unsigned>(argChar1) << ", " << argInt1;
//					cout << endl << "Storing: " << argInt1 << " in: R" << static_cast<unsigned>(argChar1);
//				}
//				break;
//			case OP_MVI:
//				argChar1 = *mem->fetchByte();
//				argInt1 = *mem->fetchInt();
//				if(v){
//					cout << endl << "OP_MVI: " << static_cast<unsigned>(argChar1) << ", " << argInt1;
//					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to: " << argInt1;
//				}
//				reg->setReg(argChar1, argInt1);
//				break;
//		}; //end switch
//	};//end while
}; //end constructor

