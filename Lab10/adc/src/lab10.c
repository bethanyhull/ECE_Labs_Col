//"#include" statements for ADC and 7 segment function prototype declarations go here
#include "adc.h"
#include "seg7.h"

// gpio_d_init() prototype declaration goes here!
void gpio_d_init(void);

int main(void)
{
  adc_init();               // Initialize the ADC hardware
  seg7_init ();             // Initialize the 7 segment display
  gpio_d_init();            // Initialize the GPIO Port D as outputs (output(15-0) = off)
  unsigned char segData[16] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x2, 0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0e};                
                                // set up array of 7 segment data to display decimal digits 
  while(1) {
    uint32_t q = 0;             // Initialize any variables needed
    
    adc_start();                // Start ADC
    
    while (!adc_done()) {
      q = q +1;
                                // Wait in a tight loop for ADC conversion to finish
    }
    uint32_t val = adc_get();   // ADC is done; get ADC value (12 bits right justified)
  
                                // Use ADC value (0 - ???) to write 7 seg display
                                
                                // call seg7_put() for each digit in 7 segment display
                          
                                
  seg7_put (0x7, 0x00);  // HEX7 is always blank

  int dig6 = floor(((val - (val % 1366)) / 1366) * .000732421875);
  seg7_put (0x6, segData[dig6]);  // HEX6 is volts

int dig6 = floor((((val % 1366) - (val % 137)) / 137) * .000732421875);
  seg7_put (0x6, segData[dig6]);  // HEX5 is tenths of volts

int dig6 = floor((((val % 137) - (val % 14)) / 14) * .000732421875);
  seg7_put (0x6, segData[dig6]); // HEX4 is hundredths of volts

  int dig3 = (val - (val % 1000))/1000;
  seg7_put (0x3, segData[dig3]);  // HEX3 is thousands digit of decimal ADC count                             
                                
  int dig2 = ((val % 1000) - (val % 100))/100;
  seg7_put (0x2, segData[dig2]); // HEX2 is hundreds digit of decimal ADC count
                                
  int dig1 = ((val % 100) - (val % 10))/10;
  seg7_put (0x1, segData[dig1]); // HEX1 is tens digit of decimal ADC count                              
                                
  int dig0 = ((val % 10) - (val % 1))/1;
  seg7_put (0x0, segData[dig0]); // HEX0 is ones digit of decimal ADC count                            
  }

  return 0;                     // main function always returns 0 to indicate success
}
