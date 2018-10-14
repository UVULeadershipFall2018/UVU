END .BYTE 'q'
; This program will loop until the user enters the END byte which is 'q'
           ADR R2 END   
           LDRB R3 [R2] 
START      SWI 1        
           CMP R3 R1
           BNE START    
           SWI 3