//
//  readyQueue.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/25/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "queues.hpp"

using namespace std;

bool Queues::checkForMemoryOverlap() {
	if(readyQueue.size() > 1) {
		if(readyQueue[1].loadAddress > readyQueue[0].memoryLimit) { return true; }
		else if(readyQueue[1].memoryLimit < readyQueue[0].loadAddress) {return true; }
		else { return false; }
	}
	else { return true; }
};

void Queues::pushReadyQueue(Pcb p){
	p.currentState = "stateReady";
	readyQueue.push_back(p);
};

void Queues::pushJobQueue(Pcb p){
	p.currentState = "stateRunning";
	jobQueue.push_back(p);
};

void Queues::pushIOQueue(Pcb p){
	p.currentState = "stateWaitForIO";
	ioQueue.push_back(p);
}

void Queues::pushTerminated(Pcb p){
	p.currentState = "stateTerminated";
	terminated.push_back(p);
	
}

void Queues::pushWaitQueue(Pcb p){
	p.currentState = "stateWaitForChild";
	p.forking = false;
	waitQueue.push_back(p);
}

Pcb Queues::popReadyQueue(){
	Pcb p = readyQueue.back();
	readyQueue.pop_back();
	return p;
};

Pcb Queues::popIOQueue(){
	Pcb p = ioQueue.back();
	ioQueue.pop_back();
	return p;
}

Pcb Queues::popJobQueue(){
	Pcb p = jobQueue.back();
	jobQueue.pop_back();
	return p;
};

Pcb Queues::popWaitQueue(){
	Pcb p = waitQueue.back();
	waitQueue.pop_back();
	return p;
};

Pcb* Queues::nextInJobQueue(){
	return &jobQueue.back();
};

Pcb* Queues::nextInWaitQueue(){
	return &waitQueue.back();
};

Pcb* Queues::nextInReadyQueue(){
	return &readyQueue.back();
};

Pcb* Queues::nextInIOQueue(){
	return &ioQueue.back();
};

bool Queues::checkJobQueueState() {
	p = jobQueue.back();
	if(p.currentState == "stateTerminated") {
		jobQueue.pop_back();
		return false;
	}else { return true; }
}

std::vector<Pcb> Queues::fetchProcesses(){
	std::vector<Pcb> processList;
	if(sizeReadyQueue() > 0) {
		for(int i = 0; i <= readyQueue.size()-1; i++) {
			processList.push_back(readyQueue[i]);
		}
	}
	if(sizeJobQueue() > 0) {
		for(int i = 0; i <= jobQueue.size()-1; i++) {
			processList.push_back(jobQueue[i]);
		}
	}
	if(sizeIOQueue() > 0) {
		for(int i = 0; i <= ioQueue.size()-1; i++) {
			processList.push_back(ioQueue[i]);
		}
	}
	if(sizeWaitQueue() > 0) {
		for(int i = 0; i <= waitQueue.size()-1; i++) {
			processList.push_back(waitQueue[i]);
		}
	}
	return processList;
}

