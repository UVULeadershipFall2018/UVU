//
//  registers.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/16/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef registers_hpp
#define registers_hpp

#include <stdio.h>

class Registers {
private:
	int r[12] = {0};
	
public:
	Registers() {
		
	}
	void setReg(int reg, int v) { r[reg] = v; }
	int fetchReg(int reg) { return r[reg]; }
	void resetRegisters() { for(int i=0;i<=11;i++){ r[i] = 0; } }
};

#endif /* registers_hpp */
