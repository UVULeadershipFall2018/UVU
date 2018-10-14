//
//  pbq.hpp
//  VM-Milestone2
//
//  Created by TJ Nielsen on 10/13/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef pbq_hpp
#define pbq_hpp

#include <stdio.h>
#include <list>
#include "pcb.hpp"

struct Pbq {
	std::list<Pcb> queue;
	int priority = 0;
	int quantum = 0;
	void setQuantum(int q) { quantum = q; }
	void setPriority(int p) { priority = p; }
	void pushQueue(Pcb p) { p.currentState = "stateReady"; queue.push_back(p); }
	Pcb popQueue() { Pcb returnedPcb = queue.front(); queue.pop_front(); return returnedPcb; }
	long queueSize() { return queue.size(); }
};

#endif /* pbq_hpp */
