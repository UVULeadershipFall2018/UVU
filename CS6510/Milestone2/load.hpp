//
//  load.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/13/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef load_hpp
#define load_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "cpu.hpp"
#include "queues.hpp"
#include "memory.hpp"

class Load {
	std::list<int> pidList;
public:
	Load() { pidList.push_back(100); }
	void loadProcess(bool gante, bool verbose, std::string filename, Cpu *clock, int arrivalTime,  Queues *queues, Memory *mem);
	int addPid();
};
#endif /* load_hpp */
