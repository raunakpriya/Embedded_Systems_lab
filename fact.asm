  NAME main
  PUBLIC __iar_program_start
  SECTION .intvec:CODE:NOROOT(2)
__iar_program_start
main
  mov r0,#10
  mov r1,r0
loop subs r1,r1,#1
  mulne r2,r0,r1
  mov r0,r2
  bne loop
stop b stop
  end
  
