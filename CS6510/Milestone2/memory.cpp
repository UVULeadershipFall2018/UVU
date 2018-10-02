//
//  memory.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/15/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "memory.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Memory::loadMemoryFromFile(std::string fileName, Pcb* pcb) {
	
	fstream inFile;
	inFile.open(fileName, ios::in | ios::binary);
	int programSize = 0;
	int loadAddress = 0;
	int firstInstruction = 0;
	resetMemPointer();
	if (inFile) {
		inFile.read((char*)&programSize, sizeof(int));
		inFile.read((char*)&firstInstruction, sizeof(int));
		inFile.read((char*)&loadAddress, sizeof(int));
		firstInstruction += loadAddress;
		pcb->mainMemoryStart = mainMemory;
		mainMemory += loadAddress;
		pcb->memoryLimit = loadAddress+programSize;
		pcb->directives = mainMemory;
		pcb->directiveLength = firstInstruction - loadAddress;
		pcb->firstInstructionP = mainMemory + pcb->directiveLength;
		pcb->programSize = programSize;
		pcb->firstInstruction = firstInstruction;
		pcb->loadAddress = loadAddress;
		pcb->reg.setReg(7, firstInstruction);
		pcb->reg.setReg(8, loadAddress+programSize);
		pcb->reg.setReg(10, firstInstruction);
		pcb->reg.setReg(11, firstInstruction);
		inFile.read(mainMemory, programSize);
		cout << endl << "Loaded " << programSize << " bytes of data into main memory from " << fileName << " starting at address " << loadAddress <<  endl;
		cout << endl << "Header Information: " << endl << "Program Size: " << programSize;
		cout << endl << "First Instruction Address: " << firstInstruction;
		cout << endl << "Load Address: " << loadAddress << endl;
	}else {
		cout << endl << "Unable to open file:" << fileName << endl;
	}
}

void Memory::loadMemoryFromFile(std::string fileName, Pcb* pcb, int loadAddress) {
	
	fstream inFile;
	inFile.open(fileName, ios::in | ios::binary);
	int programSize = 0;
	int firstInstruction = 0;
	int wrongLoadAddress = 0;
	pcb->reg.resetRegisters();
	resetMemPointer();
	if (inFile) {
		inFile.read((char*)&programSize, sizeof(int));
		inFile.read((char*)&firstInstruction, sizeof(int));
		inFile.read((char*)&wrongLoadAddress, sizeof(int));
		firstInstruction += loadAddress;
		pcb->mainMemoryStart = mainMemory;
		mainMemory += loadAddress;
		pcb->memoryLimit = loadAddress+programSize;
		pcb->directives = mainMemory;
		pcb->directiveLength = firstInstruction - loadAddress;
		pcb->firstInstructionP = mainMemory + pcb->directiveLength;
		pcb->programSize = programSize;
		pcb->firstInstruction = firstInstruction;
		pcb->loadAddress = loadAddress;
		pcb->reg.setReg(7, firstInstruction);
		pcb->reg.setReg(8, loadAddress+programSize);
		pcb->reg.setReg(10, firstInstruction);
		pcb->reg.setReg(11, firstInstruction);
		inFile.read(mainMemory, programSize);
		cout << endl << "Loaded " << programSize << " bytes of data into main memory from " << fileName << " starting at address " << loadAddress <<  endl;
		cout << endl << "Header Information: " << endl << "Program Size: " << programSize;
		cout << endl << "First Instruction Address: " << firstInstruction;
		cout << endl << "Load Address: " << loadAddress << endl;
	}else {
		cout << endl << "Unable to open file:" << fileName << endl;
	}
}

void Memory::freeMemory(Pcb* pcb){
	setMemPointer(pcb->mainMemoryStart + pcb->memoryBase);
	for(int i=pcb->memoryBase; i <= pcb->memoryLimit; i++){
		*mainMemory = 0;
		mainMemory += i;
	}
}
