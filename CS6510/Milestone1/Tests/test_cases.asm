INDEX	.WORD 1
		.WORD 2
		.WORD 3
		MVI R3 2        ;Intialize R3 with int 1
		MVI R4 6        ;Intialize R4 with int 1 
		MVI R5 16
		MVI R0 28
LABEL1	ADD R2 R3 R4    ;Add 
		SWI 2
		SUB R2 R5 R4    ;Subtract
		SWI 2
		MUL R2 R3 R4    ;Multiplication
		SWI 2
		DIV R2 R0 R3    ;Division
		SWI 2
		MOV R2 R5		;MOV
		SWI 2
		MVI R2 18		;MVI
		SWI 2
		ADR R2 LABEL1	;ADR
		SWI 2
		MVI R0 10000
		STR R0 [R2]		;STR
		LDR R2 [R2]		;LDR
		SWI 2 
		STRB R0 [R3]	;STRB
		LDRB R2 [R3]	;LDRB
		SWI 2
		B JUMP1
		SWI 3 
JUMP1	BL JUMP2	
		SWI 3
JUMP2	MOV R2 R5
		SWI 2
		ADR R2 JUMP3
		BX R2
		SWI 3
JUMP3	MVI R3 2
		MVI R4 2
		MVI R5 3
		CMP R3 R5
		BNE JUMP4
		SWI 3
JUMP4	CMP R3 R4
		BEQ JUMP5
		SWI 3
JUMP5	CMP R5 R3
		BGT JUMP6
		SWI 3
JUMP6	CMP R3 R5
		BLT JUMP7
JUMP7	SWI 3

