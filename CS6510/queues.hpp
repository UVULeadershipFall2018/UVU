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
#include "pbq.hpp"
#include "pcb.hpp"


class Queues {
	std::vector<Pcb> readyQueue;
	std::vector<Pcb> jobQueue;
	std::vector<Pcb> ioQueue;
	std::vector<Pcb> waitQueue;
	std::vector<Pcb> terminated;
	Pcb p;
	Pbq readyQueue0;
	Pbq readyQueue1;
	Pbq readyQueue2;
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
	std::list<Pcb> fetchProcesses();
	void pushJobQueue(Pcb p);
	Pcb popJobQueue();
	long sizeReadyQueue() { return readyQueue0.queueSize() + readyQueue1.queueSize() + readyQueue2.queueSize(); }
	long sizeJobQueue() { return jobQueue.size(); }
	long sizeIOQueue() { return ioQueue.size(); }
	long sizeWaitQueue() { return waitQueue.size(); }
	bool checkJobQueueState();
	void adjustPbq();
	void setQuantums(int quantum1, int quantum2);
	
	
};

#endif /* readyQueue_hpp */
