RESULT  .WORD 0
ONE     .WORD 1
MAX     .WORD 100
MIN     .WORD 0
; This is a CPU bound program, it will increment (0...100)
RES   ADR R3 RESULT ; Get address of result
      ADR R5 MAX    ; Get Address of max
	  LDR R5 [R5]   ; Load R5 with 50
      ADR R0 MIN    ; Get address of min
	  LDR R0 [R0]   ; Load R0 with 0
	  MVI R2 0      ; Clear Result register
BEGIN ADR R1 ONE    ; Loop to incrementing from 0 to 100
INC   ADD R2 R2 R1  ; Increment result by 1
      STR R2 [R3]   ; Store value in result
      SWI 2
	  CMP R2 R5     ; Check if result == max (reg Z has the compare result)
	  BNE INC       ; Loop if not result != max
      SWI 98        ; Fork
      SWI 3			; End Program