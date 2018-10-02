//
//  pcb.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/23/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "pcb.hpp"

using namespace std;

void Pcb::printPcb() {
	cout << endl << "PCB for: " << filename;
	cout << endl << "====================================";
	cout << endl << "PID: " << pid;
	cout << endl << "Arrival Time: " << arrivalTime;
	cout << endl << "Current State: " << currentState << endl;
	cout << endl << "Main Memory" << endl << "-----------";
	cout << endl << "Load Address: " << loadAddress;
	cout << endl << "Program Size: " << programSize;
	cout << endl << "First Instruction: " << firstInstruction;
	cout << endl << "PC: " << reg.fetchReg(11);
	cout << endl << "Registers" << endl << "---------";
	for(int r=0; r <= 12; r++) {
		cout << endl << "	R" << r << ": " << reg.fetchReg(r);
	}
	cout << endl << endl;
}

bool Pcb::childRunning() {
	bool running = false;
	for(int i = 0; i <= children.size()-1; i++){
		if(children[i].currentState != "stateTerminated"){
			running = true;
		}
	}
	return running;
};

void Pcb::printRegisters() {
	cout << endl << endl << "Registers" << endl << "==============" << endl;
	for(int i=0; i<=11; i++) {
		cout << "R" << i << ": " << reg.fetchReg(i) << endl;
	}
	cout << endl << "==============" << endl << endl;
}

bool operator <(const Pcb &arrival1, const Pcb &arrival2){
	return arrival1.arrivalTime > arrival2.arrivalTime;
}


