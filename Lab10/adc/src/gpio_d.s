# file: gpio_d.s
# author: Bethany Hull

.include "macros.inc"
.include "gpio_regs.inc"

SET_TARGET

.text             

FUNCTION gpio_d_init,global			// initialize all 16 bits of Port D to outputs
  push {lr}

  mov r0,#3					// send 3 as argument to rcc_gpio_enable function
  bl rcc_gpio_enable				// call rcc_gpio_enable
	
  ldr r3,=#GPIOD_BASE				// load r3 with base address of GPIO PORT D

  ldr r2,=#0x00000000				// load 0 into r2
  str r2,[r3,#GPIO_PUPDR]			// write 0 to GPIO Port D PUPD register
  str r2,[r3,#GPIO_OTYPER]			// write 0 to GPIO Port D TYPEregister
  str r2,[r3,#GPIO_ODR]				// write 0 to GPIO Port D output data register

  ldr r2,=#0x55555555				// set all 16 bits of port D to outputs
  str r2,[r3,#GPIO_MODER]	

  ldr r2,=#0xffffffff				// write 0xffffffff to Port D register

  pop {lr}

  bx lr
    
ENDFUNC gpio_d_init

FUNCTION gpio_d_put,global			// put a value out to the 16 bits of Port D outputs
  
  push {lr}

  ldr r3,=#GPIOD_BASE				// load r3 with base address of GPIO Port D

  str r0,[r3,#GPIO_ODR]				// write to (function argument) to GPIO Port D output

  pop {lr}

  bx lr

ENDFUNC gpio_d_put

FUNCTION gpio_d_get_current,global	// get the current state of the 16 port D outputs
  push {lr}

  ldr r3,=#GPIOD_BASE				// load r3 with the base address of GPIO Port D

  ldr r0,[r3,#GPIO_ODR]				// load r0 with GPIO Port D output data register

  pop {lr}

  bx lr

ENDFUNC gpio_d_get_current

.end
