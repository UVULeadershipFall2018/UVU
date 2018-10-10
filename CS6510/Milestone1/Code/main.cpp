//
//  main.cpp
//  vm1
//
//  Created by TJ Nielsen on 8/29/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>
#include <string>
#include <sstream>
#include "load.hpp"
#include "memory.hpp"
#include "run.hpp"
#include "cpu.hpp"


int main(int argc, const char * argv[]) {
	bool verbose;
	Load loader;
	Run runner;
	Memory mem;
	Cpu processor;
	processor.reset(); //clear registers
	bool repeat = true;
	std::string input_stream;
	std::cout << "Welcome, please enter command <load|run|coredump|errordump -v (filename)> or 'q' to quit:" << std::endl;
	std::cout << "FILES AVAILABLE" << std::endl;
	std::cout << "CPUBound.osx" << std::endl;
	std::cout << "IOBound.osx" << std::endl;
	std::cout << "test_cases.osx" << std::endl;
	while(repeat){
		verbose = false;
		//Prompt

		std::cout << std::endl << "VM>";
		
		//Capture input in a single string and then split into an array
		getline (std::cin, input_stream);
		std::istringstream buf(input_stream);
		std::istream_iterator<std::string> beg(buf), end;
		std::vector<std::string> inputs(beg, end);
		
		//If single argument provided, check for 'q' to end, otherways display an error and ask for input again
		if(inputs.size() == 1){
			if(inputs[0] == "q"){
				repeat = false;
			}else{
				repeat = true;
				std::cout << "Invalid input, please enter a file name" << std::endl;
			}
		
		//If two arguments are provided, assuming verbose disabled
		}else if(inputs.size() == 2){
			if(inputs[0] == "load"){
				loader.load_from_bin(inputs[1], &mem, verbose);
			}else if(inputs[0] == "run"){
				runner.run_program(&processor, &mem, &loader, verbose);
			}else if(inputs[0] == "coredump"){
				loader.load_from_bin(inputs[1], &mem, false);
				std::cout << std::endl << "Directives" << std::endl;
				mem.directive_dump();
				std::cout << std::endl << std::endl << "Instructions" << std::endl;
				mem.mem_dump();
				std::cout << std::endl;
			}else if (inputs[0] == "errordump"){
				std::cout << std::endl << std::endl <<  "SPACE HOLDER FOR ERROR DUMP" << std::endl;
			}
		
		//If three arguements are provided, check that -v was provided, otherwise send error
		}else if(inputs.size() == 3){
			if(inputs[1] == "-v"){
				verbose = true;
				if(inputs[0] == "load"){
					loader.load_from_bin(inputs[2], &mem, verbose);
				}else if(inputs[0] == "run"){
					runner.run_program(&processor, &mem, &loader, verbose);
				}
			}else{
				std::cout << std::endl << "invalid switch: " << inputs[1] << std::endl;
				repeat = true;
			}
		
		//User didn't enter anything
		}else{
			std::cout << "Invalid number of arguments " << std::endl;
			repeat = true;
		}
	}
	return 0;
}


