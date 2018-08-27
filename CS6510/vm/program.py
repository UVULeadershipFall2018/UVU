class program(object):
    def load_program(self, data, mem):
        for byte in data:
            mem.write_mem(byte)
        return mem