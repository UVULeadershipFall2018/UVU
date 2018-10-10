//
//  memory.hpp
//  vm1
//
//  Created by TJ Nielsen on 8/31/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef memory_hpp
#define memory_hpp

#include <stdio.h>
typedef int8_t int8;
typedef int32_t int32;

class Memory{
public:
	int num_of_instructions = 0;
	int num_of_directives = 0;
	int main_memory[100][100] = { };
	int8 stack[100] = {0};
	void load_directive(int x, char value);
	void mem_dump();
	void directive_dump();
};


#endif /* memory_hpp */
