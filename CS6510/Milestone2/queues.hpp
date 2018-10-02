//
//  readyQueue.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/25/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef queues_hpp
#define queues_hpp

#include <stdio.h>
#include <queue>
#include "pcb.hpp"

class Queues {
	std::vector<Pcb> readyQueue;
	std::vector<Pcb> jobQueue;
	std::vector<Pcb> ioQueue;
	std::vector<Pcb> waitQueue;
	std::vector<Pcb> terminated;
	Pcb p;
public:
	Queues() {};
	void pushReadyQueue(Pcb p);
	void pushWaitQueue(Pcb p);
	void pushIOQueue(Pcb p);
	void pushTerminated(Pcb p);
	void sortReadyQueue() { sort(readyQueue.begin(), readyQueue.end()); }
	bool checkForMemoryOverlap();
	Pcb popReadyQueue();
	Pcb popWaitQueue();
	Pcb popIOQueue();
	Pcb fetchReady(int i) { return readyQueue[i]; }
	Pcb fetchRunning(int i) { return jobQueue[i]; }
	Pcb* nextInJobQueue();
	Pcb* nextInWaitQueue();
	Pcb* nextInReadyQueue();
	Pcb* nextInIOQueue();
	std::vector<Pcb> fetchProcesses();
	void pushJobQueue(Pcb p);
	Pcb popJobQueue();
	long sizeReadyQueue() { return readyQueue.size(); }
	long sizeJobQueue() { return jobQueue.size(); }
	long sizeIOQueue() { return ioQueue.size(); }
	long sizeWaitQueue() { return waitQueue.size(); }
	bool checkJobQueueState();
	
	
};

#endif /* readyQueue_hpp */
