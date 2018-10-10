//
//  memory.cpp
//  vm1
//
//  Created by TJ Nielsen on 8/31/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include <iostream>
#include "memory.hpp"
#include "load.hpp"

using namespace std;

void Memory::load_directive(int x, char value) {
	stack[x] = value;
};

void Memory::mem_dump() {
	for(int instruction = 0; instruction < num_of_instructions;  instruction++){
		cout << endl << "Instruction ";
		for(int argument = 0; argument < 6; argument++) {
			cout << " : " << main_memory[instruction][argument];
		};
	};
}

void Memory::directive_dump() {
	for(int directive = 0; directive < num_of_directives;  directive++){
		cout << endl << "Directive ";
		cout << " : " << int(stack[directive]);
	};
}
