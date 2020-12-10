/*
* Author: Bethany Hull
*/

#include "adc.h"
#include "seg7.h"
/* #include <Servo.h>  This is included in the servo online that you linked, used for writing the movement to the servo
*                      and reading the current angle.
*                      the function write() takes in a degree in which you want it to adjust to.
*                      the read() function will return a degree
*/
#include <math.h>

//Function Declarations
void gpio_d_init(void);
unsigned int SysTick_Config(unsigned int ticks);
unsigned int gpio_c_init(void);

// also add gpio get and put functions to write to and from switches

//# Defines

#define reload_value (1 << 23) - 1 /* Reload value is 20x10^-6 / 5.96 * 10^-9  */

#define LEDs_ODR_Base (0x40020C14) /* LEDs Port D ODR Address */

#define step_size 22.75

unsigned int *pLEDs = (unsigned int *)LEDs_ODR_Base; /* Create pointer to Port D - ODR Reg */

unsigned int counter = 1;
uint32_t val = 0;

unsigned int switch1 = 0; //switch to change from auto (0) to manual (0)
unsigned int switch2 = 0; //switch to change from left (0) to right  (0) in manual mode


void servoSetup()
{
  // xAxisServo.attach(9);  Only works with pins 9 and 10, attaches the servo
  // yAxisServo.attach(10);  Only works with pins 9 and 10, attaches the servo
}

int main()
{

  // Create a server object Servo myservo
  servoSetup(); // Sets up and attaches 2 serves on pins 9 and 10 -- Defined above
  adc_init();   // Initialize the ADC hardware
  seg7_init();  // Initialize the 7 segment display
  adc_start();  // Start adc

  /* set all the seven seg displays in order [0-9]*/
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
    // This will wait for adc to finish
    continue;
  }

  /* Once the ADC function finishes this will be the while loop that makes all the calls
  * and keeps the program continuously running
  */
  while (1)
  {
    //get the value of switch 1 and switch 2 using the gpio_c_get function
    //isolate the bit 0 and 1 to get the value of switch 1 and 2 and set
    //them to the "switch1" and "switch2" variables respectively.

    /* This will continually grab the value of the voltage by the user if it is manual mode */
    if (switch1 == 1) {
      val = adc_get();
    }
    

    /*
    * This will be the section that writes to the two servos. It will write no matter which mode.
    * The only difference will be which servo is active.  The options are Left, Right, or Both
    * 
    * The volt_to_degree() is a custom function we wrote down below to convert the ADC count to degrees
    * 
    * PSEUDO Code
    * if (switch for x axis is on) {
    *     xAxisServo.write(volt_to_deg(val));
    * 
    *   }
    * 
    * if (switch for y axis is on) {
    *   yAxisServo.write(volt_to_deg(val));
    * }
    * 
    * if (switch for both is on) {
    *   xAxisServo.write(volt_to_deg(val));
    *   yAxisServo.write(volt_to_deg(val));
    * 
    */

    /*
    *   The values for the voltage will be converted to a step in degrees
    *   and will be right to the four rightmost LEDS 0 and 1 will be the x axis, 2 and 3 will be the y axis
    *   this will be written in every pass of the while loop with a seg7_put(<LED num in hex>, <hexTo7 value from array> )
    *   These values with be calculated with a mod to isolate the tens and ones digit.
    *   Each axis will use 2 LEDS to right 00 to 90
    *   These values will all be written in the code above.
    */

    continue;
  }

  return 0;
}

void SysTick_Handler(void) //ISR - SysTick Interrupt Service Routine

{

  /*
  *  This next part will control
  * 
  */
  // if (switch1 == 0)
  // {
    // val = deg_to_volt(xAxisServo.read())
    //   if (val >= 2095 - step_size) {
    //     val -= step_size
    //   }else {
    //     val += step_size
    //   }

    
    
  // }
  
}

int volt_to_deg (int voltageValue) { // takes in a voltage value between 0 - 4095
  double percent = voltageValue / 4095.0
  double step = 180.0 / 100.0
  int val = round((percent * step) - 90)
return val
}

int deg_to_volt (int degreeValue) { // takes in a degree value between -90 and 90
  double percent = (degreeValue + 90) / 180.0
  double step = 4095.0 / 100.0
  int val = round(percent * step)
return val
}
