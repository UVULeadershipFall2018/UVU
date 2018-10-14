//
//  process.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/15/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef process_hpp
#define process_hpp

#include <stdio.h>
#include <string>

class Process {
private:
	std::string fileName;
	int loadAddress;
	int programSize;
	int firstInstruction;
	int registers[12] = {0};
	bool running;
	
	
public:
	Process(int size, int instruction, int load) :programSize(size),
												firstInstruction(instruction),
												loadAddress(load){}
	std::string getFilename() { return fileName; }
	int getLimit() { return programSize+loadAddress; }
	int getFirstInstruction() { return firstInstruction; }
	int getLoadAddress() { return loadAddress; }
	void setFileName(std::string f) { fileName = f; }
	void setLoadAddress(int l) { loadAddress = l; }
	void setLimit(int s) { programSize = s; }
	void setFirstInstruction(int fi) { firstInstruction = fi; }
	void setRunning(bool r) { running  = r; }
	bool isRunning() { return running; }
	//State getState() { return currentState; }
	//void setState(State s) { currentState = s; }
	
	
};

#endif /* process_hpp */
