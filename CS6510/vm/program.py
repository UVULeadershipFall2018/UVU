class program(object):
    def __init__(self, data, mem):
        for byte in data:
            mem.write_mem(byte)