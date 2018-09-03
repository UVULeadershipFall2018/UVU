
OP_ADR = 0
OP_MOV = 1
OP_STR = 2
OP_STRB = 3
OP_LDR = 4
OP_LDRB = 5
OP_BX = 6
OP_B = 7
OP_BNE = 8
OP_BGT = 9
OP_BLT = 10
OP_BEQ = 11
OP_CMP = 12
OP_AND = 13
OP_ORR = 14
OP_EOR = 15
OP_ADD = 16
OP_SUB = 17
OP_MUL = 18
OP_DIV = 19
OP_SWI = 20
OP_BL = 21
OP_MVI = 22

class process(object):
    def __init__(self):
        self.started = True

    def byte_join(self, byteArray):
            bytes(byteArray)

    def decode(self, mem, cpu):
        if mem.current_instruction[0] == OP_ADR:
            self.do_ADR(mem, cpu)
        elif mem.current_instruction[0] == OP_MOV:
            self.do_MOV(mem, cpu)
        elif mem.current_instruction[0] == OP_STR:
            self.do_STR(mem, cpu)
        elif mem.current_instruction[0] == OP_STRB:
            self.do_STRB(mem, cpu)
        elif mem.current_instruction[0] == OP_LDR:
            self.do_LDR(mem, cpu)
        elif mem.current_instruction[0] == OP_LDRB:
            self.do_LDRB(mem, cpu)
        elif mem.current_instruction[0] == OP_BX:
            self.do_BX(mem, cpu)
        elif mem.current_instruction[0] == OP_B:
            self.do_B(mem, cpu)
        elif mem.current_instruction[0] == OP_BNE:
            self.do_BNE(mem, cpu)
        elif mem.current_instruction[0] == OP_BGT:
            self.do_BGT(mem, cpu)
        elif mem.current_instruction[0] == OP_BLT:
            self.do_BLT(mem, cpu)
        elif mem.current_instruction[0] == OP_BEQ:
            self.do_BEQ(mem, cpu)
        elif mem.current_instruction[0] == OP_CMP:
            self.do_CMP(mem, cpu)
        elif mem.current_instruction[0] == OP_AND:
            self.do_AND(mem, cpu)
        elif mem.current_instruction[0] == OP_ORR:
            self.do_ORR(mem, cpu)
        elif mem.current_instruction[0] == OP_EOR:
            self.do_EOR(mem, cpu)
        elif mem.current_instruction[0] == OP_ADD:
            self.do_ADD(mem, cpu)
        elif mem.current_instruction[0] == OP_SUB:
            self.do_SUB(mem, cpu)
        elif mem.current_instruction[0] == OP_MUL:
            self.do_MUL(mem, cpu)
        elif mem.current_instruction[0] == OP_DIV:
            self.do_DIV(mem, cpu)
        elif mem.current_instruction[0] == OP_SWI:
            self.do_SWI(mem, cpu)
        elif mem.current_instruction[0] == OP_BL:
            self.do_BL(mem, cpu)
        elif mem.current_instruction[0] == OP_MVI:
            self.do_MVI(mem, cpu)

    def do_ADR(self, mem, cpu):
        print("ADR R%s <-- R%s ; Get address of label" % (mem.current_instruction[1], mem.current_instruction[2]))

    def do_MOV(self, mem, cpu):
        print("MOV R%s <-- R%s ; Load data from register" % (mem.current_instruction[1], mem.current_instruction[2]))
        cpu.load(mem.current_instruction[1], cpu.registers[mem.current_instruction[2]])

    def do_STR(self, mem, cpu):
        print("STR R%s <-- R%s ; Store word (int) using register indirect addressing" % (mem.current_instruction[2], mem.current_instruction[1]))

    def do_STRB(self, mem, cpu):
        print("do_STRB")

    def do_LDR(self, mem, cpu):
        print("do_LDR")

    def do_LDRB(self, mem, cpu):
        print("do_LDRB")

    def do_BX(self, mem, cpu):
        print("do_BX")

    def do_B(self, mem, cpu):
        print("do_B")

    def do_BNE(self, mem, cpu):
        print("do_BNE")

    def do_BGT(self, mem, cpu):
        print("BGT ; Jump to %s if Z register is greater than zero" % (mem.current_instruction[1] + mem.HEADER_SIZE))
        print("zregister: %s" % cpu.zregister)
        if cpu.zregister > 0:
            mem.program_counter = mem.current_instruction[1] + mem.HEADER_SIZE

    def do_BLT(self, mem, cpu):
        print("do_BLT")

    def do_BEQ(self, mem, cpu):
        print("do_BEQ")

    def do_CMP(self, mem, cpu):
        print("do_CMP")

    def do_AND(self, mem, cpu):
        print("do_AND")

    def do_ORR(self, mem, cpu):
        print("do_ORR")

    def do_EOR(self, mem, cpu):
        print("do_EOR")

    def do_ADD(self, mem, cpu):
        print("ADD R%s <-- R%s + R%s ; Add" % (mem.current_instruction[1], mem.current_instruction[2], mem.current_instruction[3]))
        cpu.load(mem.current_instruction[1], (cpu.registers[mem.current_instruction[2]] + cpu.registers[mem.current_instruction[3]]))

    def do_SUB(self, mem, cpu):
        print("SUB R%s <-- R%s - R%s ; Subtract" % (mem.current_instruction[1], mem.current_instruction[2], mem.current_instruction[3]))
        cpu.load(mem.current_instruction[1], (cpu.registers[mem.current_instruction[2]] - cpu.registers[mem.current_instruction[3]]))

    def do_MUL(self, mem, cpu):
        print("do_MUL")

    def do_DIV(self, mem, cpu):
        print("do_DIV")

    def do_SWI(self, mem, cpu):
        print("do_SWI")
        cpu.running = False

    def do_BL(self, mem, cpu):
        print("do_BL")

    def do_MVI(self, mem, cpu):
        print("MVI R%s <-- %s ; Load register with immediate value" % (mem.current_instruction[1], mem.current_instruction[2]))
        cpu.load(mem.current_instruction[1], mem.current_instruction[2])
