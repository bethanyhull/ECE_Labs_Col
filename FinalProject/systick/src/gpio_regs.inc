# file: gpio_regs.inc
# author: Daniel Bogden

// Section establishes addresses for GPIO
.equ GPIOA_BASE,0X40020000
.equ GPIOB_BASE,0x40020400
.equ GPIOC_BASE,0X40020800
.equ GPIOD_BASE,0x40020C00
.equ GPIOE_BASE,0x40021000
	
.equ GPIO_MODER,0x00
.equ GPIO_OTYPER,0x04
.equ GPIO_OSPEEDR,0X08
.equ GPIO_PUPDR,0x0C
.equ GPIO_IDR,0x10
.equ GPIO_ODR,0x14
.equ GPIO_BSRR,0x18
.equ GPIO_LCKR,0x1C
.equ GPIO_AFRL,0x20
.equ GPIO_AFRH,0x24
