from __future__ import print_function
import sys
from memory import memory
from process import process
from cpu import cpu
from input_output import io
from program import program
from cmd import Cmd

verbose = False
stack = []
register = ()
HEAD_LENGTH = 12

def main():

    in_cmd = True
    while(in_cmd):
        input = raw_input("VM:>")
        if "-v" in input:
            verbose = True
            input = input.split(' ')[0] + input.split(' ')[2]
        if "load" in input and len(input.split):
            in_cmd_filename = True
            while (in_cmd_filename):
                filename_input = raw_input("VM:Filename:>")
                mem = memory(0, 500)
                f = io(filename_input)
                program(f.data, mem)
                cpu_obj = cpu()
                cpu_obj.initialize()
                mem.set_program_counter(mem.mem[4] + HEAD_LENGTH)
        elif input == r"run":
            while cpu_obj.running:
                cpu_obj.print_registers()
                mem.fetch_6bytes()
                proc = process()
                proc.decode(mem, cpu_obj)
        elif input == "q":
            exit(0)


if __name__ == '__main__':
    main()