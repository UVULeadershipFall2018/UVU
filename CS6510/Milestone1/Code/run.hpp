//
//  run.hpp
//  vm1
//
//  Created by TJ Nielsen on 9/2/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef run_hpp
#define run_hpp

#include "memory.hpp"
#include "cpu.hpp"
#include "load.hpp"
#include <stdio.h>

class Run {
public:
	void run_program (Cpu *processor, Memory *mem, Load *loader, bool verbose);
	int chars_to_int(Cpu *processor, Memory *mem, int i);
	void int_to_chars(Cpu *processor, Memory *mem, int i, int number);
};
#endif /* run_hpp */
