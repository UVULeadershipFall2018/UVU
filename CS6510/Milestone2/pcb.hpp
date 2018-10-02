//
//  pcb.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/23/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef pcb_hpp
#define pcb_hpp

#include <stdio.h>
#include <string>
#include "registers.hpp"
#include <vector>
#include <iostream>

struct Pcb {
	std::string currentState;
	char* mainMemoryStart;
	char* firstInstructionP;
	char* directives;
	int programSize = 0;
	int loadAddress = 0;
	int firstInstruction = 0;
	int directiveLength = 0;
	bool forking = false;
	bool forkedParent = false;
	bool forkedChild = false;
	std::vector<Pcb> children;
	Pcb() { };
	Registers reg;
	int pc = 0;
	int memoryBase = 0;
	int memoryLimit = 0;
	int arrivalTime = 0;
	bool v = true;
	bool g = false;
	std::string filename = "";
	int pid = 0;
	Pcb(int p, std::string f, std::string state, int at, bool verbose, bool gant) : pid(p),
													filename(f),
												    arrivalTime(at),
													currentState(state),
													v(verbose),
													g(gant){};
	void setMemoryLimit(int limit) { memoryLimit = limit; }
	void setMemoryBase(int base) { memoryBase = base; }
	int getProgramSize() { return programSize; }
	int getLoadAddress() { return loadAddress; }
	char* setMemPointer(int pc) { return mainMemoryStart + pc; }
	char* getMainMemoryStart() { return mainMemoryStart; }
	char* getFirstInstructionP() { return mainMemoryStart + firstInstruction; }
	int getFirstInstruction() { return firstInstruction; }
	int* directivePullInt(int offset) { return (int*)(directives + offset); }
	char* directivePullChar(int offset) { return (directives + offset); }
	void directivePushChar(int offset, char value) { *(directives + offset) = value; }
	void directivePushInt(int offset, int value) {*(directives + offset) = value; }
	int getDirectiveLength() { return directiveLength; }
	void printPcb();
	void printRegisters();
	void setForking(bool f) { forking = f; }
	void setForkedParent(bool f) { forkedParent = f; }
	void setForkedChild(bool f) { forkedChild = f; }
	void addForkedChildren(Pcb p) { children.push_back(p); }
	bool childRunning();
};
bool operator<(const Pcb &arrival1, const Pcb &arrival2);

#endif /* pcb_hpp */

