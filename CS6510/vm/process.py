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

    def decode(self, instruction):

    def __init__(self):
        return 0

    def do_ADR(self):
        print("do_ADR")

    def do_MOV(self):
        print("do_MOV")

    def do_STR(self):
        print("do_STR")

    def do_STRB(self):
        print("do_STRB")

    def do_LDR(self):
        print("do_LDR")

    def do_LDRB(self):
        print("do_LDRB")

    def do_BX(self):
        print("do_BX")

    def do_B(self):
        print("do_B")

    def do_BNE(self):
        print("do_BNE")

    def do_BGT(self):
        print("do_BGT")

    def do_BLT(self):
        print("do_BLT")

    def do_BEQ(self):
        print("do_BEQ")

    def do_CMP(self):
        print("do_CMP")

    def do_AND(self):
        print("do_AND")

    def do_ORR(self):
        print("do_ORR")

    def do_EOR(self):
        print("do_EOR")

    def do_ADD(self):
        print("do_ADD")

    def do_SUB(self):
        print("do_SUB")

    def do_MUL(self):
        print("do_MUL")

    def do_DIV(self):
        print("do_DIV")

    def do_SWI(self):
        print("do_SWI")

    def do_BL(self):
        print("do_BL")

    def do_MVI(self):
        print("do_MVI")
