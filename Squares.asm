  NAME main
  PUBLIC __iar_program_start
  SECTION .data:CONST(2)
NUM DC16 0XFFFF,0XFFFF,0XFFFF
NUMEND DC32 0
LENGTH DC32 (NUMEND-NUM)/2
RESULT DS32 2
  PUBLIC __iar_program_start
  SECTION .intvec:CODE:NOROOT(2)
__iar_program_start
main
  LDR R0,LENGTH
  ADR R1,NUM
  MOV R8,#0
  MOV R9,#0
LOOP LDRH R4,[R1]
  UMULL R3,R7,R4,R4
  ADDS R8,R8,R3
  ADCCS R9,R9,R7
  ADD R1,R1,#2
  SUBS R0,R0,#1
  BNE LOOP
  STR R9,RESULT
  STR R8,RESULT+1
STOP B STOP
  END
  
