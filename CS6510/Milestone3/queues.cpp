//
//  readyQueue.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/25/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "queues.hpp"

using namespace std;

void Queues::setQuantums(int quantum1, int quantum2) {
	// Create 3 priority based queues to use in ready queue
	readyQueue0.setQuantum(quantum1);
	readyQueue0.setPriority(0);
	readyQueue1.setQuantum(quantum2);
	readyQueue1.setPriority(1);
	readyQueue2.setQuantum(1000);
	readyQueue2.setPriority(2);
}
bool Queues::checkForMemoryOverlap() {
	if(readyQueue0.queueSize() > 1) {
		if(readyQueue0.queue.front().loadAddress > readyQueue0.queue.back().memoryLimit) { return true; }
		else if(readyQueue0.queue.front().memoryLimit < readyQueue0.queue.back().loadAddress) {return true; }
		else { return false; }
	}
	else { return true; }
};

void Queues::pushReadyQueue(Pcb p){
	p.currentState = "stateReady";
	switch(p.pbqNum){
		case(0):
			p.pbqQuantum = readyQueue0.quantum;
			readyQueue0.pushQueue(p);
			break;
		case(1):
			p.pbqQuantum = readyQueue1.quantum;
			readyQueue1.pushQueue(p);
			break;
		case(2):
			p.pbqQuantum = readyQueue2.quantum;
			readyQueue2.pushQueue(p);
			break;
	}
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
	if(readyQueue0.queueSize() > 0) {
		return readyQueue0.popQueue();
	}else if(readyQueue1.queueSize() > 0){
		return readyQueue1.popQueue();
	}else if(readyQueue2.queueSize() > 0){
		return readyQueue2.popQueue();
	}else{
		cout << endl << "All 3 queues are empty, terminating" << endl;
		exit(0);
	}
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
	if(readyQueue0.queueSize() > 0) {
		return &readyQueue0.queue.front();
	}else if(readyQueue1.queueSize() > 0){
		return &readyQueue1.queue.front();
	}else if(readyQueue2.queueSize() > 0){
		return &readyQueue2.queue.front();
	}else{
		cout << endl << "All 3 queues are empty, terminating" << endl;
		exit(0);
	}
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

std::list<Pcb> Queues::fetchProcesses(){
	std::list<Pcb> processList;
	if(sizeReadyQueue() > 0) {
		processList.assign(readyQueue0.queue.begin(), readyQueue0.queue.end());
		processList.assign(readyQueue1.queue.begin(), readyQueue1.queue.end());
		processList.assign(readyQueue2.queue.begin(), readyQueue2.queue.end());
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

void Queues::adjustPbq() {
	if(nextInJobQueue()->shiftingQueues and nextInJobQueue()->currentState != "stateTerminated"){
		nextInJobQueue()->shiftingQueues = false;
		switch(nextInJobQueue()->pbqNum) {
			case(0):
				cout << endl << "Entering medium priority queue" << endl;
				nextInJobQueue()->pbqNum = readyQueue1.priority;
				nextInJobQueue()->pbqQuantum = readyQueue0.quantum;
				nextInJobQueue()->pbqSessionIterations = 0;
				readyQueue1.pushQueue(popJobQueue());
				break;
			case(1):
				cout << endl << "Entering low priority queue" << endl;
				nextInJobQueue()->pbqNum = readyQueue2.priority;
				nextInJobQueue()->pbqQuantum = readyQueue2.quantum;
				nextInJobQueue()->pbqSessionIterations = 0;
				readyQueue2.pushQueue(popJobQueue());
				break;
			case(2):
				nextInJobQueue()->pbqQuantum = readyQueue2.quantum;
				nextInJobQueue()->pbqSessionIterations = 0;
				readyQueue2.pushQueue(popJobQueue());
				break;
		}
	}else if(nextInJobQueue()->nextRound and nextInJobQueue()->currentState != "stateTerminated"){
		nextInJobQueue()->nextRound = false;
		switch(nextInJobQueue()->pbqNum) {
			case(0):
				cout << endl << "Staying in high priority queue" << endl;
				nextInJobQueue()->pbqSessionIterations = 0;
				readyQueue0.pushQueue(popJobQueue());
				break;
			case(1):
				cout << endl << "Staying in medium priority queue" << endl;
				nextInJobQueue()->pbqSessionIterations = 0;
				readyQueue1.pushQueue(popJobQueue());
				break;
			case(2):
				cout << endl << "Staying in low priority queue" << endl;
				nextInJobQueue()->pbqSessionIterations = 0;
				readyQueue2.pushQueue(popJobQueue());
				break;
		}
		
	}
}
