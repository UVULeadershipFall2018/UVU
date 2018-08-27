class memory(object):
    def initialize_mem(self, head, size):
        self.mem = ['' for i in range(head, size)]
        self.program_counter = 0

    def write_mem(self, data):
        self.mem[self.addr_pointer] = data
        self.program_counter += 1

    def read_mem(self, addr):
        self.program_counter += 1
        return self.mem[addr]

    def get_program_counter(self):
        return self.program_counter

    def set_program_counter(self, pc):
        self.program_counter = pc

    def fetch_6bytes(self):
        self.current_instruction = []
        for i in range(1, 6):
            self.current_instruction.append(self.read_mem(self.program_counter))
            self.program_counter += 1