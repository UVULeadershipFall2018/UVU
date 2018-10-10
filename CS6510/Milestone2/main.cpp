//
//  main.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/13/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>
#include <string>
#include <stdlib.h>     /* stoi */
#include <sstream>
#include <iostream>
#include "memory.hpp"
#include "process.hpp"
#include "load.hpp"
#include "registers.hpp"
#include "decode.hpp"
#include <string>
#include "cpu.hpp"
#include "queues.hpp"
#include "scheduler.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	Cpu clock;
	Load loader;
	Queues queues;
	Memory mem;
	bool running = true;
	bool v = false;
	bool g = false;
	while(running) {
		
		char input_string[200], *p;
		string fullInputString;
		vector<string> arguments;
		cout << endl << endl << "VM>";
		cin.getline(input_string, 200);
		p = strtok(input_string, " ");
		if(p){
			arguments.push_back(p);
			p = strtok(NULL, " ");
		}else {
			arguments.push_back(" ");
			;
		}
		int i = 0;
		bool executing = false;
		
		//Split input into tokens seperated by spaces, an array of arguments
		while (p != NULL) {
			i++;
			arguments.push_back(p);
			p = strtok(NULL, " ");
		}
		
		//Switch checks for the number of arguments provided to decide what to check for
		switch(i){
			//One argument, check for 'q' otherwise, invalid argument
			case(0):
				if(arguments[0] == "q") { running = false; }
				else { cout << "Invalid argument, press q to quit" << endl; }
				executing = false;
				break;
				
			//Two arguments, should be command and filename, no verbose
			case(1):
				if(arguments[0] == "execute"){
					//mem.loadMemoryFromFile(arguments[1]);
					loader.loadProcess(g, v, arguments[1], &clock, 0, &queues, &mem);
				}
				executing = true;
				break;
				
			//Three arguments
			//execute -v <filename> or
			//osx <asm> <load address>
			//execute <filename> <arrival time>
			case(2):
				if(arguments[1] == "-v"){ v = true; g = false; }
				if(arguments[1] == "-g"){ v = false; g = true; }
				if(arguments[0] == "execute"){
					if(arguments[1] != "-v" and arguments[1] != "-g") {
						loader.loadProcess(g, v, arguments[1], &clock, stoi(arguments[2]), &queues, &mem);
						executing = true;
					}else{
					loader.loadProcess(g, v, arguments[2], &clock, 0, &queues, &mem);
					executing = true;
					}
				}
				else if(arguments[0] == "osx"){
					fullInputString = "./" + arguments[0] + " " + arguments[1] + " " + arguments[2];
					const char *command = fullInputString.c_str();
					system(command);
					executing = false;
				}
				break;
			//Five arguments, expecting execute <filename> <arrival time> <filename> <arrival time>
			case(4):
				loader.loadProcess(g, v, arguments[1], &clock, stoi(arguments[2]), &queues, &mem);
				loader.loadProcess(g, v, arguments[3], &clock, stoi(arguments[4]), &queues, &mem);
				executing = true;
				break;
				
			//Six arguments, expecting execute  (-v|-g)  <filename> <arrival time> <filename> <arrival time>
			case(5):
				if(arguments[1] == "-v"){ v = true; g = false; }
				if(arguments[1] == "-g"){ v = false; g = true; }
				loader.loadProcess(g, v, arguments[2], &clock, stoi(arguments[3]), &queues, &mem);
				loader.loadProcess(g, v, arguments[4], &clock, stoi(arguments[5]), &queues, &mem);
				executing = true;
				break;
			
			//Seven arguments, expecting execute <filename> <arrival time> <filename> <arrival time> <filename> <arrival time>
			case(6):
				
				loader.loadProcess(g, v, arguments[1], &clock, stoi(arguments[2]), &queues, &mem);
				loader.loadProcess(g, v, arguments[3], &clock, stoi(arguments[4]), &queues, &mem);
				loader.loadProcess(g, v, arguments[5], &clock, stoi(arguments[6]), &queues, &mem);
				executing = true;
				break;
				
			//Eight arguments, expecting execute (-v|-g) <filename> <arrival time> <filename> <arrival time> <filename> <arrival time>
			case(7):
				if(arguments[1] == "-v"){ v = true; g = false; }
				if(arguments[1] == "-g"){ v = false; g = true; }
				loader.loadProcess(g, v, arguments[2], &clock, stoi(arguments[3]), &queues, &mem);
				loader.loadProcess(g, v, arguments[4], &clock, stoi(arguments[5]), &queues, &mem);
				loader.loadProcess(g, v, arguments[6], &clock, stoi(arguments[7]), &queues, &mem);
				executing = true;
				break;
			default:
				cout << endl << "Invalid input" << endl;
				break;
		}
		if(executing){
			Scheduler sched(&queues, &clock, &mem);
			cout << endl << "Finished Program, cleaning up" << endl;
		}
	}
	return 0;
}
