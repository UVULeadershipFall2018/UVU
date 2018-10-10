//
//  load.cpp
//  vm1
//
//  Created by TJ Nielsen on 8/29/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "memory.hpp"
#include "load.hpp"

using namespace std;

void Load::load_from_bin (std::string filename, Memory *mem, bool verbose) {
	ifstream in;
	in.clear();
	cout << std::endl << filename << std::endl;
	in.open(filename, ios::in | ios::binary);
	int byte_counter = 0;
	int instruction_counter = 0;
	int instruction_code = 0;
	int directive = 0;
	int junk;
	if(in.is_open())
	{
		in.read((char*)&program_size, sizeof(int));
		in.read((char*)&program_start, sizeof(int));
		in.read((char*)&load_address, sizeof(int));
		if(verbose) {
			cout << "Program Size: " << program_size << std::endl;
			cout << "Program Start: " << program_start << std::endl;
			cout << "Load address: " << load_address << std::endl;
		}
		//Todo: modify this to read in directives, but for how, it is just skipping directive if they are before the instructions
		if(program_start > 0) {
			while(byte_counter < program_start){
				in.read((char*)&mem->stack[directive], sizeof(int8));
				if(verbose) {
					cout << "Loading directive byte: " << int(mem->stack[directive]) << endl;
				}
				byte_counter++;
				directive++;
			};
		}
		while(in) {
			in.read((char*)&instruction_code, sizeof(char));
			instruction_counter++;
			switch(instruction_code) {
				case OP_BX:
					byte_counter += 6;
					mem->main_memory[instruction_counter][0] = instruction_code;
					in.read((char*)&mem->main_memory[instruction_counter][1], sizeof(char));
					in.read((char*)&junk, sizeof(int));
					if(verbose) {
						cout << "Op-code: " << instruction_code << std::endl;
						cout << "Storing: " << mem->main_memory[instruction_counter][1] << std::endl;
					};
					break;
				case OP_STR:
				case OP_MOV:
				case OP_STRB:
				case OP_LDR:
				case OP_LDRB:
				case OP_CMP:
				case OP_AND:
				case OP_ORR:
				case OP_EOR:
					byte_counter += 6;
					mem->main_memory[instruction_counter][0] = instruction_code;
					in.read((char*)&mem->main_memory[instruction_counter][1], sizeof(char));
					in.read((char*)&mem->main_memory[instruction_counter][2], sizeof(char));
					in.read((char*)&junk, sizeof(char));
					in.read((char*)&junk, sizeof(char));
					in.read((char*)&junk, sizeof(char));
					if(verbose) {
						cout << "Op-code: " << instruction_code << std::endl;
						cout << "Storing: " << mem->main_memory[instruction_counter][1] << ","
						<< mem->main_memory[instruction_counter][2] << std::endl;
					};
					break;
				case OP_B:
				case OP_BNE:
				case OP_BGT:
				case OP_BLT:
				case OP_BEQ:
				case OP_BL:
					byte_counter += 6;
					mem->main_memory[instruction_counter][0] = instruction_code;
					in.read((char*)&mem->main_memory[instruction_counter][1], sizeof(int));
					in.read((char*)&junk, sizeof(char));
					if(verbose) {
						cout << "Op-code: " << instruction_code << std::endl;
						cout << "Storing: " << mem->main_memory[instruction_counter][1] << std::endl;
					};
					break;
				case OP_ADD:
				case OP_SUB:
				case OP_MUL:
				case OP_DIV:
					byte_counter += 6;
					mem->main_memory[instruction_counter][0] = instruction_code;
					in.read((char*)&mem->main_memory[instruction_counter][1], sizeof(char));
					in.read((char*)&mem->main_memory[instruction_counter][2], sizeof(char));
					in.read((char*)&mem->main_memory[instruction_counter][3], sizeof(char));
					in.read((char*)&junk, sizeof(char));
					in.read((char*)&junk, sizeof(char));
					if(verbose) {
						cout << "Op-code: " << instruction_code << std::endl;
						cout << "Storing: " << mem->main_memory[instruction_counter][1] << ","
						<< mem->main_memory[instruction_counter][2] << ","
						<< mem->main_memory[instruction_counter][3] << std::endl;
					};
					break;
				case OP_SWI:
					byte_counter += 6;
					mem->main_memory[instruction_counter][0] = instruction_code;
					in.read((char*)&mem->main_memory[instruction_counter][1], sizeof(int));
					in.read((char*)&junk, sizeof(char));
					if(verbose) {
						cout << "Op-code: " << instruction_code << std::endl;
						cout << "Storing: " << mem->main_memory[instruction_counter][1] << std::endl;
					};
					break;
				case OP_ADR:
				case OP_MVI:
					byte_counter += 6;
					mem->main_memory[instruction_counter][0] = instruction_code;
					in.read((char*)&mem->main_memory[instruction_counter][1], sizeof(char));
					in.read((char*)&mem->main_memory[instruction_counter][2], sizeof(int));
					if(verbose) {
						cout << "Op-code: " << instruction_code << std::endl;
						cout << "Storing: " << mem->main_memory[instruction_counter][1] << ","
						<< mem->main_memory[instruction_counter][2] << std::endl;
					};
					break;
			}; //end switch
		};//end while
		mem->num_of_directives = directive;
		mem->num_of_instructions = instruction_counter;
		in.close();
	}; //end if open
}; //end load_from_bin
