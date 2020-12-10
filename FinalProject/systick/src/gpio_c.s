# file: gpio_c.s
# author: Daniel Bogden

.include "macros.inc"
.include "gpio_regs.inc"

SET_TARGET

.text             

FUNCTION gpio_c_init,global		// initialize the 16 bits of Port C to inputs
  push {lr}

  mov r0,#2				// send 2 as argument to rcc_gpio_enable function
  bl rcc_gpio_enable			// call rcc_gpio_enable
	
  ldr r3,=#GPIOC_BASE			// load r3 with base address of GPIO PORT C
	
  ldr r2,=#0x00000000			// load 0 into r2
  str r2,[r3,#GPIO_PUPDR]		// write 0 to GPIO Port C PUPD register
  str r2,[r3,#GPIO_MODER]		// write 0 to GPIO Port C MODE register
  str r2,[r3,#GPIO_OTYPER]		// write 0 to GPIO Port C TYPE register

  ldr r2,=#0xffffffff		        // write 0xfffffff to Port C SPEED register
  str r2,[r3,#GPIO_OSPEEDR]	

  pop {lr}

  bx lr
    
ENDFUNC gpio_c_init

FUNCTION gpio_c_get,global		// get the 16 bits of Port C inputs
  
  push {lr}

  ldr r3,=#GPIOC_BASE			// load r3 with base address of GPIO Port C
	
  ldr r0,[r3,#GPIO_IDR]			// load r0 (arg) with GPIO Port C input data register

  pop {lr}

  bx lr

ENDFUNC gpio_c_get

.end
