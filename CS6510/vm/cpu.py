class cpu(object):
    def intitialize_cpu(self):
        self.registers = ['' for i in range(0,11)]
        self.program_counter = 0
        self.instruction_register = 0
        self.running = True

    def fetch(self, index):
        self.instruction_register = self.instruction_register[index]

    def load(self, index, value):
        self.registers[index] = value