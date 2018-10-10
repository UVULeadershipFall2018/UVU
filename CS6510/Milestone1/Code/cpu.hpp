//
//  cpu.hpp
//  vm1
//
//  Created by TJ Nielsen on 9/2/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef cpu_hpp
#define cpu_hpp

#include <stdio.h>

class Cpu{
public:
	int zregister = 9;
	int registers[12] = {0};
	void load(int register, int value);
	void reset();
	void set_pc (int i);
	int fetch(int i);
	int pc;
	bool running;
};


#endif /* cpu_hpp */
