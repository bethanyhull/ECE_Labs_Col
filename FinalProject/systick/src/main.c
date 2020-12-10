/*
* Author: Daniel Bogden
*/

//Function Declarations
void gpio_d_init(void);
unsigned int SysTick_Config(unsigned int ticks);

//# Defines
#define reload_value (1 << 23) - 1 /* System Timer reload value */
#define LEDs_ODR_Base (0x40020C14) /* LEDs Port D ODR Address */

unsigned int *pLEDs = (unsigned int *)LEDs_ODR_Base; /* Create pointer to Port D - ODR Reg */

unsigned int counter = 1;

int main()
{

  //set system clock
  SetSysClock();

  //initialize Port D (LEDs)
  gpio_d_init();

  //configure SysTick System Timer
  SysTick_Config(reload_value);

  //loop forever
  while (1)
  {
    continue;
  }

  return 0;
}

void SysTick_Handler(void) //ISR - SysTick Interrupt Service Routine

{
  //toggle Port D - LED 15
  // *pLEDs ^= (1 << 15);

  /* Light up LEDs 0 through 15, once all on turn them off and repeat. */
  if (counter > 15)
  {
    counter = 0;
    *pLEDs = 0;
  }
  else
  {
    *pLEDs |= (1 << counter);
    counter++;
  }
}
