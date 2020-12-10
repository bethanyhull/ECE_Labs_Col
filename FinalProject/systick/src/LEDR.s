# file: LEDR.s
# author: Daniel Bogden

.include "macros.inc"

SET_TARGET

 .text

FUNCTION LEDR_Init,global

  push {lr}

  bl gpio_d_init				// Initialize GPIO Port D as output
  
  pop {lr}

  bx lr

ENDFUNC LEDR_Init


FUNCTION LEDR_Put_A,global

  push {lr}

  mov r1,r0					      // save return argument from get RUN
                          // previous values of LEDS in r1
  bl gpio_d_get_current		// Target Register wiill be r0

  mov r2,#0b1             // create 1 bit mask (lsb)
  and r1,r2	      				// isolate new bit 12 (just in case)
  lsl r1,#8				      	// de-normalize new bit 8
  lsl r2,#8					      // de-normalize mask to bit 8					
  mvn r2,r2        			  // invert mask for bit 12
  and r0,r2					      // clear tgarget bit 8
  orr r0,r1	      				// merge new bit 8 into Target

  bl gpio_d_put				    // write Target Reg. r0 to Port D

  pop {lr}

  bx lr

ENDFUNC LEDR_Put_A

FUNCTION LEDR_Put_B,global

  push {lr}

  mov r1,r0

  bl gpio_d_get_current

  ldr r2,=#(~(~0<<4))             // Creating a 4 bit mask
  and r1,r2                       // and the mask in r2 and the argument that was stored in r1
  lsl r1,#2                       // de-normalize bits of interest
  lsl r2,#2                       // de-normalize mask
  mvn r2,r2                       // mask inverse
  and r0,r2                       // bitwise AND the inverse mask and original argument
  orr r0,r1                       // bitwise OR the bits of interest and store in r0

  bl gpio_d_put

  pop {lr}
  bx lr

ENDFUNC LEDR_Put_B

// new
FUNCTION led_put_index, global 
  
  push {lr}
  
  mov r1,r0              //save return arguement from get_B (previous values of LED's) in r1
  
  bl gpio_d_get_current
  
  ldr r2,=#(~(~0<<3))   // 12-14 is 3 bit mask
  and r1,r2             // isolate new bits
  lsl r1,#12             // shift mask left 12 bits to normalize
  lsl r2,#12             // denormalize 3 bit mask to bits 12,13,14
  mvn r2,r2             // invert mask
  and r0,r2             // clear target bits using inverse
  orr r0,r1             // merge new bits into target
  
  bl gpio_d_put
  
  pop {lr}
  bx lr

ENDFUNC led_put_index

// new
FUNCTION led_put_segments, global

  push {lr}
  mov r1,r0              //save return arguement from get_B (previous values of LED's) in r1
  
  bl gpio_d_get_current
  
  ldr r2,=#(~(~0<<7))   // 0-6 is 7 bit mask
  and r1,r2             // isolate new bits
                        // shift mask is not needed since numbers begin at 0
  mvn r2,r2             // invert mask
  and r0,r2             // clear target bits using inverse
  orr r0,r1             // merge new bits into target
  
  bl gpio_d_put
  
  pop {lr}
  bx lr
  
ENDFUNC led_put_segments

.end












