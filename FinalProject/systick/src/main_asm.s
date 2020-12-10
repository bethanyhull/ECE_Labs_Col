// file: main_asm.s
// author: arlen planting

    .syntax unified
    .thumb
    .file	"main_asm.s"

.include "src/periph_regs.inc"

    .data
    
    .align 2
MYTICK: .word 0

/*
	function: main
*/
    .text
    .align	2
    .global	main
    .thumb_func
    .type	main, %function
  
main:

  push {r4,r5,r6,r7,lr}

  bl SetSysClock

  bl gpio_d_init

  ldr r0,=#(1<<24)-1
  
  bl SysTick_Config

  halt:  // do nothing but loop

    nop

    b halt

all_done:

  pop {r4,r5,r6,r7,lr}
  
  bx lr

/*
	function:		SysTick_Handler
	C prototype: 	
*/
    .align	2
    .global	SysTick_Handler
    .thumb_func
    .type	SysTick_Handler, %function
  
SysTick_Handler:

  push {r5,r6,r7,lr}
  
  ldr r7,=GPIOD_BASE   //toggle Port D pin 15 LED

  ldr r6,[r7,GPIO_ODR]
  ldr r5,=#(1<<15)
  eor r6,r5
  str r6,[r7,GPIO_ODR]
  
  pop {r5,r6,r7,lr}  
  
  bx lr
  
  .end
