//
//  load.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/13/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "load.hpp"
#include <iostream>
#include <fstream>
#include "memory.hpp"
#include "process.hpp"
#include "registers.hpp"
#include "decode.hpp"
#include <string>
#include "cpu.hpp"
#include "pcb.hpp"
#include "queues.hpp"
#include <list>

using namespace std;

void Load::loadProcess(bool gant, bool verbose, string filename, Cpu *clock, int arrivalTime, Queues *queues, Memory *mem){
	int pid = Load::addPid();
	Registers reg;
	Pcb pcb(pid, filename, "stateNew", arrivalTime, verbose, gant);
	mem->loadMemoryFromFile(filename, &pcb);
	pcb.printPcb();
	queues->pushReadyQueue(pcb);
}
int Load::addPid() {
	int p = pidList.back();
	pidList.push_back(++p);
	return pidList.back();}


