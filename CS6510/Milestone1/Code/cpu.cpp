//
//  cpu.cpp
//  vm1
//
//  Created by TJ Nielsen on 9/2/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "cpu.hpp"

void Cpu::load(int i, int value){
	registers[i] = value;
	};

int Cpu::fetch(int i){
	return registers[i];
}

void Cpu::reset(){
	for(int i=0; i < 12; i++){
		registers[i] = 0;
	};
}

void Cpu::set_pc(int i) {
	pc = i;
};
