//
//  cpu.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/22/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef cpu_hpp
#define cpu_hpp

#include <string>
#include <vector>
#include <list>
#include "pcb.hpp"
#include "queues.hpp"
#include <stdio.h>

class Cpu {
	private:
	int clock = 0;
	public:
	bool ready = true;
	int fetchClock() { return clock; }
	void incrementClock(Queues* q, bool g);
};
#endif /* cpu_hpp */
