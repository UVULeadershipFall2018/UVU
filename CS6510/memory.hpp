//
//  memory.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/15/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef memory_hpp
#define memory_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include "pcb.hpp"

class Memory {
private:
	
	int const maxSize = 5000;
	char* mainMemory = new char[maxSize];
	char* mainMemoryStart = mainMemory;
	
public:
	int getMax() { return maxSize; }
	char* getMemPointer() { return mainMemory; }
	int* fetchInt() { int* m = (int*)mainMemory ; mainMemory += 4; return m; }
	char* fetchByte() { char* m = mainMemory ; mainMemory += 1; return m; }
	void setMemPointer(char* memPointer) {mainMemory = memPointer;}
	void loadMemoryFromFile(std::string filename, Pcb* pcb);
	void loadMemoryFromFile(std::string filename, Pcb* pcb, int loadAddress);
	void resetMemPointer() {mainMemory = mainMemoryStart; }
	void freeMemory(Pcb* pcb);
};


#endif /* memory_hpp */
