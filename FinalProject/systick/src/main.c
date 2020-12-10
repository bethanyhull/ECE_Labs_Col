/*
* Author: Bethany Hull
*/

#include "adc.h"
#include "seg7.h"

//Function Declarations
void gpio_d_init(void);
unsigned int SysTick_Config(unsigned int ticks);
unsigned int gpio_c_init(void);

// also add gpio get and put functions to write to and from switches

//# Defines

#define reload_value (1 << 23) - 1 /* Reload value is 20x10^-6 / 5.96 * 10^-9  */

#define LEDs_ODR_Base (0x40020C14) /* LEDs Port D ODR Address */

unsigned int *pLEDs = (unsigned int *)LEDs_ODR_Base; /* Create pointer to Port D - ODR Reg */

unsigned int counter = 1;

unsigned int switch1 = 0; //switch to change from auto (0) to manual (0)

int main()
{

  adc_init();  // Initialize the ADC hardware
  seg7_init(); // Initialize the 7 segment display
  adc_start(); // Start adc

  /* set all the seven seg displays in order*/
  int sevenSeg[11] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x2, 0x78, 0x0, 0x18};

  //set system clock
  SetSysClock();

  //initialize Port D (LEDs)
  gpio_d_init();

  //Initialize Port C (switches)
  gpio_c_init();

  //configure SysTick System Timer

  /* reload value = 20x10^-6 / 5.96 * 10^-9 */
  SysTick_Config(reload_value);

  while (!adc_done())
  {
    continue;
  }

  //loop forever
  while (1)
  {
    //get the value of switch 1 using the gpio_c_get function
    //isolate the bit 0 to get the value of switch 1 and set
    //it to the switch 1 variable

    /* This will continually grab the value of the voltage by the user if it is manual mode */
    uint32_t val = adc_get();

    /*
  *   
  * */

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
