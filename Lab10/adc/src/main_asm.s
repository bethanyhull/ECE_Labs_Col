# file: main_asm.s

.include "macros.inc"

  SET_TARGET

  .text

  FUNCTION main,global

    push {r4,r5,r6,r7,lr}

    ldr  r4,=0x11223344
    ldr  r5,=0x55667788
    add  r2,r4,r5

    all_done:
    
    pop {r4,r5,r6,r7,lr}

    bx lr
  
  ENDFUNC main

  .data

  .end
