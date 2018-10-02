//
//  scheduler.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/26/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "scheduler.hpp"
using namespace std;

Scheduler::Scheduler(Queues* q, Cpu* clock, Memory* mem) {
	schedulerMem = mem;
	schedularQueues = q;
	
	// Check for memory overlap
	if(!q->checkForMemoryOverlap()){
		cout << endl << "Load address overlap exception." << endl;
		exit(1);
	}
	
	// Adjust queue based on arrival time
	q->sortReadyQueue();
	jobsPending = true;
	gantt = q->nextInReadyQueue()->g;
	while(jobsPending){
		jobsPending = false;
		clock->incrementClock(q, gantt);
		checkJobQueue(q, mem);
		checkReadyQueue(q);
		checkIOQueue(q, clock);
		checkWaitQueue(q);
	}
}

void Scheduler::checkReadyQueue(Queues* q) {
	if(q->sizeReadyQueue() > 0){
		if(q->sizeJobQueue() == 0) {
			q->pushJobQueue(q->popReadyQueue());
			jobsPending = true;
		}
	}
}

void Scheduler::checkJobQueue(Queues* q, Memory* mem) {
	Execute executer;
	if(q->sizeJobQueue() > 0){
		jobsPending = true;
		if(q->nextInJobQueue()->currentState == "stateTerminated") {
			q->pushTerminated(q->popJobQueue());
		}else if(q->nextInJobQueue()->forking){
			Pcb child = spawnChild(q->nextInJobQueue());
			q->nextInWaitQueue()->addForkedChildren(child);
		}else if(q->nextInJobQueue()->currentState == "stateWaitForIO"){
			q->pushIOQueue(q->popJobQueue());
		}else{
			executer.runInstruction(q->nextInJobQueue(), mem);
		}
	}
}

void Scheduler::checkIOQueue(Queues* q, Cpu* clock) {
	if(q->sizeIOQueue() > 0){
		int randomNum = rand() % 10;
		for(int i = 0; i<= randomNum; i++){
			clock->incrementClock(q, gantt);
		}
		q->pushJobQueue(q->popIOQueue());
	}
}

void Scheduler::checkWaitQueue(Queues* q) {
	if(q->sizeWaitQueue() > 0){
		if(q->nextInJobQueue()->currentState == "stateTerminated"){
			q->pushReadyQueue(q->popWaitQueue());
		}
	}
}

Pcb Scheduler::spawnChild(Pcb* p) {
	Pcb child = *p;
	child.forkedChild = true;
	child.pid = 0;
	child.currentState = "stateNew";
	child.forking = false;
	child.forkedParent = false;
	schedularQueues->pushWaitQueue(schedularQueues->popJobQueue());
	schedularQueues->pushReadyQueue(child);
	schedulerMem->loadMemoryFromFile(child.filename, schedularQueues->nextInReadyQueue(), 1000);
	p->currentState = "stateWaiting";
	cout << "Forking" << endl << "================" << endl << "Parent PCB:";
	p->printPcb();
	cout << "Child:";
	child.printPcb();
	return child;
}

