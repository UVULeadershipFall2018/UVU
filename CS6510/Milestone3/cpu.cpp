//
//  cpu.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/22/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "cpu.hpp"
#include <iostream>

using namespace std;

//Increment the cpu clock and with each incrementation,
//if the gantt chart switch is given, it will print the status of each process

void Cpu::incrementClock(Queues* q, bool g) {
	clock++;
	list<Pcb> tempList = q->fetchProcesses();
	vector<Pcb> processList;
	copy(tempList.begin(),tempList.end(),back_inserter(processList));
	if(g){
		if(processList.size() > 0){
			cout << clock << ": ";
			for(int i = 0; i <= processList.size()-1 ; i++){
				cout << "PID: " << processList[i].pid << " State: " << processList[i].currentState << " - " << processList[i].filename << "     ";
			}
		}
		cout << endl;
	}
}

