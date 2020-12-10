/* 
* Author: Daniel Bogden 
*/

#define SysTick_BASE (0xE000E010) /*!< SysTick Base Address  */

struct SysTick_t *SysTick = (struct SysTick_t *)SysTick_BASE; /*!< SysTick Struct Pointer  */

struct SysTick_t
{
  /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  unsigned int CTRL;

  /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  unsigned int LOAD;

  /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  unsigned int VAL;

  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
  unsigned int SYST_CALIB;
};

unsigned int SysTick_Config(unsigned int ticks)
{

  /* set reload register */
  SysTick->LOAD = ticks - 1; /* set reload register - don't allow bigger than 2^24-1! */

  SysTick->VAL = 0; /* Load the SysTick Counter Value */

  SysTick->CTRL = 7; /* Clock source is processor clock, Enable SysTick IRQ, and enable SysTick Timer Counter */

  return (0); /* Function successful but we won't check */
}
