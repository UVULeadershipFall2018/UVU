//
//  execute.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/26/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "execute.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

void Execute::runInstruction(Pcb* pcb, Memory* mem) {
	char argChar1;
	char argChar2;
	char argChar3;
	char garbChar1;
	int argInt1;
	int argInt2;
	if(pcb->reg.fetchReg(7) < pcb->reg.fetchReg(8)){
		argChar1 = 0;
		argChar2 = 0;
		argChar3 = 0;
		argInt1 = 0;
		argInt2 = 0;
		mem->setMemPointer(pcb->mainMemoryStart + pcb->reg.fetchReg(11));
		char instruction_code = *(mem->fetchByte());
		pcb->reg.setReg(11, (pcb->reg.fetchReg(11)+6));
		switch(instruction_code) {
			case OP_BX:
				argChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OB_BX: " << static_cast<unsigned>(argChar1);
				}
				pcb->reg.setReg(11, pcb->reg.fetchReg(argChar1) + pcb->firstInstruction - pcb->directiveLength);
				break;
			case OP_STR:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_STR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
					cout << endl << "Storing: " << pcb->reg.fetchReg(argChar1) << " in memory location: " << pcb->reg.fetchReg(argChar2);
				}
				pcb->directivePushInt(pcb->reg.fetchReg(argChar2), pcb->reg.fetchReg(argChar1));
				break;
			case OP_MOV:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_MOV: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << pcb->reg.fetchReg(argChar2);
				}
				pcb->reg.setReg(argChar1, pcb->reg.fetchReg(argChar2));
				break;
			case OP_STRB:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_STR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
					cout << endl << "Storing: " << pcb->reg.fetchReg(argChar1) << " in memory location: " << pcb->reg.fetchReg(argChar2);
				}
				pcb->directivePushChar(pcb->reg.fetchReg(argChar2), pcb->reg.fetchReg(argChar1));
				break;
			case OP_LDR:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_LDR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
					cout << endl << "Storing: " << *pcb->directivePullInt(pcb->reg.fetchReg(argChar2)) << " in: R" << static_cast<unsigned>(argChar1);
				}
				pcb->reg.setReg(argChar1,  *pcb->directivePullInt(pcb->reg.fetchReg(argChar2)));
				break;
			case OP_LDRB:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_LDR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2);
					cout << endl << "Storing: " << static_cast<unsigned>(*pcb->directivePullChar(pcb->reg.fetchReg(argChar2))) << " in: R" << static_cast<unsigned>(argChar1);
				}
				pcb->reg.setReg(argChar1,  *pcb->directivePullChar(pcb->reg.fetchReg(argChar2)));
				break;
			case OP_CMP:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_CMP: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
					cout << endl << "CMP of " << pcb->reg.fetchReg(argChar1) << " and " << pcb->reg.fetchReg(argChar2) << " is " << (pcb->reg.fetchReg(argChar1)==pcb->reg.fetchReg(argChar2));
				}
				if(pcb->reg.fetchReg(argChar1)^pcb->reg.fetchReg(argChar2)){
					pcb->reg.setReg(9,1);
				}else {
					pcb->reg.setReg(9, 0);
				}
				break;
			case OP_AND:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_AND: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
					cout << endl << "AND of " << pcb->reg.fetchReg(argChar1) << " and " << pcb->reg.fetchReg(argChar2) << " is " << (pcb->reg.fetchReg(argChar1)&pcb->reg.fetchReg(argChar2));
				}
				pcb->reg.setReg(9, (pcb->reg.fetchReg(argChar1)&pcb->reg.fetchReg(argChar2)));
				break;
			case OP_ORR:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_ORR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
					cout << endl << "OR of " << pcb->reg.fetchReg(argChar1) << " and " << pcb->reg.fetchReg(argChar2) << " is " << (pcb->reg.fetchReg(argChar1)|pcb->reg.fetchReg(argChar2));
				}
				pcb->reg.setReg(9, (pcb->reg.fetchReg(argChar1)|pcb->reg.fetchReg(argChar2)));
				break;
			case OP_EOR:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_EOR: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2) << ", " << static_cast<unsigned>(argChar3);
					cout << endl << "XOR of " << pcb->reg.fetchReg(argChar1) << " and " << pcb->reg.fetchReg(argChar2) << " is " << (pcb->reg.fetchReg(argChar1)^pcb->reg.fetchReg(argChar2));
				}
				pcb->reg.setReg(9, (pcb->reg.fetchReg(argChar1)^pcb->reg.fetchReg(argChar2)));
				break;
			case OP_B:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_B: " << argInt1;
				}
					pcb->reg.setReg(11, argInt1 + pcb->firstInstruction - pcb->directiveLength);
				break;
			case OP_BNE:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_BNE: " << argInt1;
				}
				if(pcb->reg.fetchReg(9)!= 0){
					pcb->reg.setReg(11, argInt1 + pcb->firstInstruction - pcb->directiveLength);
				}
				break;
			case OP_BGT:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_BGT: " << argInt1;
				}
				if(pcb->reg.fetchReg(9) > 0){
					pcb->reg.setReg(11, argInt1 + pcb->firstInstruction - pcb->directiveLength);
				}
				break;
			case OP_BLT:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_BLT: " << argInt1;
				}
				if(pcb->reg.fetchReg(9) < 0){
					pcb->reg.setReg(11, argInt1 + pcb->firstInstruction - pcb->directiveLength);
				}
				break;
			case OP_BEQ:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_BEQ: " << argInt1;
				}
				if(pcb->reg.fetchReg(9) == 0){
					pcb->reg.setReg(11, argInt1 + pcb->firstInstruction - pcb->directiveLength);
				}
				break;
			case OP_BL:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_BL: " << argInt1;
				}
				pcb->reg.setReg(5, pcb->reg.fetchReg(11));
				pcb->reg.setReg(11, argInt1 + pcb->firstInstruction - pcb->directiveLength);
				break;
			case OP_ADD:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
//					pcb->printRegisters();
					cout << endl << "OP_ADD: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << pcb->reg.fetchReg(argChar2) <<  " + "  << pcb->reg.fetchReg(argChar3) << " = " <<  (pcb->reg.fetchReg(argChar2) + pcb->reg.fetchReg(argChar3));
				}
				pcb->reg.setReg(argChar1, (pcb->reg.fetchReg(argChar2) + pcb->reg.fetchReg(argChar3)));
				break;
			case OP_SUB:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_SUB: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << pcb->reg.fetchReg(argChar2) <<  " - "  << pcb->reg.fetchReg(argChar3) << " = " <<  (pcb->reg.fetchReg(argChar2) - pcb->reg.fetchReg(argChar3));
				}
				pcb->reg.setReg(argChar1, (pcb->reg.fetchReg(argChar2) - pcb->reg.fetchReg(argChar3)));
				break;
			case OP_MUL:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_MUL: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << pcb->reg.fetchReg(argChar2) <<  " * "  << pcb->reg.fetchReg(argChar3) << " = " <<  (pcb->reg.fetchReg(argChar2) * pcb->reg.fetchReg(argChar3));
				}
				pcb->reg.setReg(argChar1, (pcb->reg.fetchReg(argChar2) * pcb->reg.fetchReg(argChar3)));
				break;
			case OP_DIV:
				argChar1 = *mem->fetchByte();
				argChar2 = *mem->fetchByte();
				argChar3 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				garbChar1 = *mem->fetchByte();
				if(pcb->v){
					cout << endl << "OP_DIV: " << static_cast<unsigned>(argChar1) << ", " << static_cast<unsigned>(argChar2)<< ", " << static_cast<unsigned>(argChar3);
					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to " << pcb->reg.fetchReg(argChar2) <<  " / "  << pcb->reg.fetchReg(argChar3) << " = " <<  (pcb->reg.fetchReg(argChar2) / pcb->reg.fetchReg(argChar3));
				}
				pcb->reg.setReg(argChar1, (pcb->reg.fetchReg(argChar2) / pcb->reg.fetchReg(argChar3)));
				break;
			case OP_SWI:
				argInt1 = *mem->fetchInt();
				garbChar1 = *mem->fetchByte();
				switch(argInt1) {
					case 1:
						if(pcb->g){
							pcb->currentState = "stateWaitForIO";
							pcb->reg.setReg(1, 'q');
						}else {
						cout << endl << "Press 'q' to continue: ";
						char inp;
						cin.get(inp);
						pcb->reg.setReg(1, inp);
						}
						break;
					case 2:
						if(!pcb->g){
							cout << endl << "R2 = " << pcb->reg.fetchReg(2);
						}
						break;
					case 3:
						pcb->currentState = "stateTerminated";
						cout << endl;
						break;
					case 99:
						//Wait
						break;
					case 98:
						//Fork
						if(pcb->pid==0) {
							pcb->currentState = "stateTerminated";
						}else{
							Fork forker(pcb);
						}
						break;
				}
				break;
			case OP_ADR:
				argChar1 = *mem->fetchByte();
				argInt1 = *mem->fetchInt();
				if(pcb->v){
					cout << endl << "OP_ADR: " << static_cast<unsigned>(argChar1) << ", " << argInt1;
					cout << endl << "Storing: " << argInt1 << " in: R" << static_cast<unsigned>(argChar1);
				}
				pcb->reg.setReg(argChar1, argInt1);
				break;
			case OP_MVI:
				argChar1 = *mem->fetchByte();
				argInt1 = *mem->fetchInt();
				if(pcb->v){
					cout << endl << "OP_MVI: " << static_cast<unsigned>(argChar1) << ", " << argInt1;
					cout << endl << "Setting R" << static_cast<unsigned>(argChar1) << " to: " << argInt1;
				}
				pcb->reg.setReg(argChar1, argInt1);
				break;
		}; //end switch
	}
}
