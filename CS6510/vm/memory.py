class memory():
    def __init__(self, head, size):
        self.mem = ['' for i in range(head, size)]
        self.program_counter = 0
        self.HEADER_SIZE = 12

    def write_mem(self, data):
        self.mem[self.program_counter] = data
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
        for i in range(0, 6):
            self.current_instruction.append(self.read_mem(self.program_counter))