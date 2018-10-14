//
//  scheduler.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/26/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef scheduler_hpp
#define scheduler_hpp

#include <stdio.h>
#include "execute.hpp"
#include "cpu.hpp"
#include "memory.hpp"
#include "queues.hpp"



class Scheduler {
	enum modes {
		fifo,
		round_robin
	};
	modes mode = fifo;
	Queues* schedularQueues;
	Memory* schedulerMem;
	bool jobsPending;
	bool gantt;
public:
	Scheduler(Queues* q, Cpu* clock, Memory* mem, int quantum1, int quantum2);
	void checkJobQueue(Queues* q, Memory* mem);
	void checkReadyQueue(Queues* q);
	void checkIOQueue(Queues* q, Cpu* clock);
	void checkWaitQueue(Queues* q);
	void shiftReadyToJob();
	void shiftJobToIO();
	void shiftJobToReady();
	void shiftJobToTerminate();
	void shiftIOToJob();
	Pcb spawnChild(Pcb* p);
};

#endif /* scheduler_hpp */
