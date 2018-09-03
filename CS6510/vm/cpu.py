class cpu(object):
    def __init__(self):
        self.registers = ['' for i in range(0, 11)]

    def initialize(self):
        self.program_counter = 0
        self.instruction_register = 0
        self.running = True

    def fetch(self, index):
        self.instruction_register = self.instruction_register[index]

    def load(self, index, value):
        self.registers[index] = value
        self.zregister = value

    def print_registers(self):
        i = 0
        for r in self.registers:
            print "R%s: %s" % (i, r)
            i += 1