//
//  run.cpp
//  vm1
//
//  Created by TJ Nielsen on 9/2/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include <iostream>
#include "run.hpp"
#include "memory.hpp"
#include "cpu.hpp"
#include "load.hpp"

using namespace std;
char mode_bit = 0;
char input;
char chars[4];

int Run::chars_to_int(Cpu *processor, Memory *mem, int i) {
	char* cstr = new char[4];
	cstr[0] = mem->stack[i];
	cstr[1] = mem->stack[i+1];
	cstr[2] = mem->stack[i+2];
	cstr[3] = mem->stack[i+3];
	int* intPtr = (int*)cstr;
	int Int32 = *intPtr;
	return Int32;
}

void Run::int_to_chars(Cpu *processor, Memory *mem, int i, int number) {
	union
	{
		unsigned int integer;
		unsigned char byte[4];
	} num;
	num.integer = number;
	mem->stack[i] = num.byte[0];
	mem->stack[i+1] = num.byte[1];
	mem->stack[i+2] = num.byte[2];
	mem->stack[i+3] = num.byte[3];
	
}

void Run::run_program(Cpu *processor, Memory *mem, Load *loader, bool verbose) {
	processor->set_pc(loader->program_start);
	int instruction = 0;
	processor->running = true;
	while(processor->running) {
		instruction++;
		processor->set_pc(processor->pc + 6);
		auto i = mem->main_memory[instruction];
		switch(i[0]) {
			case Load::OP_ADR:
				if(verbose){
					cout << endl << "ADR (Get address of label): " << i[2] << " and put address in R" << i[1] << endl;
				}
				processor->load(i[1], i[2]);
				break;
			case Load::OP_BX:
				if(verbose){
					cout << endl << "jumping to memory location stored in R" << i[1]
					<< endl;
				}
				instruction = (processor->registers[i[1]] - loader->program_start) / 6;
				break;
			case Load::OP_STR:
				if(verbose){
					cout << endl << "STR: " << processor->registers[i[1]]
					<< " in stack location: ["
					<< processor->registers[i[2]]
					<< "]" << endl;
				}
				Run::int_to_chars(processor, mem, processor->registers[i[2]], processor->registers[i[1]]);
				break;
			case Load::OP_MOV:
				if(verbose){
					cout << endl << "MOV: R" << i[1] << " = R" << i[2] << endl;
				}
				processor->registers[i[1]] = processor->registers[i[2]];
				break;
			case Load::OP_STRB:
				if(verbose){
					cout << endl << "STRB: Storing " << (processor->registers[i[1]])
					<< " in stack location: ["
					<< processor->registers[i[2]] << "]" << endl;
				}
				mem->stack[processor->registers[i[2]]] = (processor->registers[i[1]]); //Extract the fist byte of the int
				break;
			case Load::OP_LDR:
				if(verbose){
					cout << endl << "LDR: Loading int from stack location: ["
					<< processor->registers[i[2]]
					<< "] and storing in register R"
					<< i[1] << endl;
				}
				processor->registers[i[1]] = Run::chars_to_int(processor, mem, processor->registers[int(i[2])]);
				break;
			case Load::OP_LDRB:
			{
				if(verbose){
					cout << endl << "LDRB: Loading the first byte stored in stack location: ["
					<< processor->registers[i[2]]
					<< "] and storing in register R"
					<< i[1] << endl;
				}
				processor->registers[i[1]] = (mem->stack[processor->registers[i[2]]]);
				break;
			}
			case Load::OP_CMP:
				if(verbose){
					cout << endl << "CMP: Comparing " << processor->fetch(i[1]) << " and " << processor->fetch(i[2])
					<< " and storing in zregister." << endl;
				}
				processor->registers[9] = processor->fetch(i[1]) - processor->fetch(i[2]);
				break;
			case Load::OP_AND:
				if(verbose){
					cout << endl << "AND:  Performing an AND on " << processor->fetch(i[1]) << " and " << processor->fetch(i[2])
					<< " and storing in zregister." << endl;
				}
				processor->registers[9] = (processor->fetch(i[1])&processor->fetch(i[2]));
				break;
			case Load::OP_ORR:
				if(verbose){
					cout << endl << "OR:  Performing an OR on " << processor->fetch(i[1]) << " and " << processor->fetch(i[2])
					<< " and storing in zregister." << endl;
				}
				processor->registers[9] = (processor->fetch(i[1])|processor->fetch(i[2]));
				break;
			case Load::OP_EOR:
				if(verbose){
					cout << endl << "EOR:  Performing an XOR on " << processor->fetch(i[1]) << " and " << processor->fetch(i[2])
					<< " and storing in zregister." << endl;
				}
				processor->registers[9] = (processor->fetch(i[1])|processor->fetch(i[2]));
				break;
			case Load::OP_B:
				if(verbose){
					cout <<endl << "Jumping to PC: " << i[1] << "(instruction: " << instruction << ")" << endl;
				}
				instruction = (i[1] - loader->program_start) / 6;
				break;
			case Load::OP_BNE:
				if(processor->registers[9] != 0){
					instruction = (i[1] - loader->program_start) / 6;
					if(verbose){
						cout <<endl << "Jumping to PC: " << i[1] << "(instruction: " << instruction << ") because zregister(" << processor->registers[9] << ") is not 0.";
					}
				}else {
					if(verbose){
						cout <<endl << "Not jumping to PC: " << i[1] << " because zregister is = 0.";
					}
				}
				break;
			case Load::OP_BGT:
				if(processor->registers[9] > 0){
					instruction = (i[1] - loader->program_start) / 6;
					if(verbose){
						cout <<endl << "Jumping to PC: " << i[1] << "(instruction: " << instruction << ") because zregister(" << processor->registers[9] << ") is > 0.";
					}
				}else {
					if(verbose){
						cout <<endl << "Not jumping to PC: " << i[1] << " because zregister is not > 0.";
					}
				}
				break;
			case Load::OP_BLT:
				if(processor->registers[9] < 0){
					instruction = (i[1] - loader->program_start) / 6;
					if(verbose){
						cout <<endl << "Jumping to PC: " << i[1] << "(instruction: " << instruction << ") because zregister(" << processor->registers[9] << ") is < 0.";
					}
				}else {
					if(verbose){
						cout <<endl << "Not jumping to PC: " << i[1] << " because zregister is not < 0.";
					}
				}
				break;
			case Load::OP_BEQ:
				if(processor->registers[9] == 0){
					instruction = (i[1] - loader->program_start) / 6;
					if(verbose){
						cout <<endl << "Jumping to PC: " << i[1] << "(instruction: " << instruction << ") because zregister(" << processor->registers[9] << ") is = 0.";
					}
				}else {
					if(verbose) {
						cout <<endl << "Not jumping to PC: " << i[1] << " because zregister is not 0.";
					}
				}
				break;
			case Load::OP_BL:
				processor->load(5, instruction*6 + 6);
				if(verbose){
					cout <<endl << "Loading R5 with next PC: " << i[1] << "(instruction: " << instruction*6 + 6 << ")" << endl;
				}
				instruction = (i[1] - loader->program_start) / 6;
				if(verbose){
					cout <<endl << "Jumping to PC: " << i[1] << "(instruction: " << instruction << ")" << endl;
				}
				break;
			case Load::OP_ADD:
				processor->load(i[1], processor->registers[i[2]] + processor->registers[i[3]]);
				if(verbose){
					cout << endl << "ADD: R" << i[1] << " = R" << i[2] << " + R" << i[3] << endl;
				}
				break;
			case Load::OP_SUB:
				processor->load(i[1], processor->registers[i[2]] - processor->registers[i[3]]);
				if(verbose){
					cout << endl << "SUB: R" << i[1] << " = R" << i[2] << " - R" << i[3] << endl;
				}
				break;
			case Load::OP_MUL:
				processor->load(i[1], processor->registers[i[2]] * processor->registers[i[3]]);
				if(verbose){
					cout << endl << "MUL: R" << i[1] << " = R" << i[2] << " * R" << i[3] << endl;
				}
				break;
			case Load::OP_DIV:
				processor->load(i[1], processor->registers[i[2]] / processor->registers[i[3]]);
				if(verbose){
					cout << endl << "DIV: R" << i[1] << " = R" << i[2] << " / R" << i[3] << endl;
				}
				break;
			case Load::OP_SWI:
				if(verbose){
					cout << endl << "Entering kernel mode" << endl;
					mode_bit = 1;
				}
				switch(i[1]){
					case 1: cout << endl << "Input Register R1 = " << processor->fetch(1) << endl;
						cin >> input;
						if(verbose){
							cout << endl << "STR: " << input
							<< " in register R2"
							<< endl;
						}
						processor->registers[1] = char(input);
						break;
					case 2: cout << endl << "Output Register R2 = " << processor->fetch(2) << endl; break;
					case 3: processor->running = false; break;
				}
				break;
			case Load::OP_MVI:
				processor->registers[i[1]] = i[2];
				if(verbose){
					cout << endl << "MVI: R" << i[1] << " = " << i[2] << endl;
				}
				break;
		}
	}
}
