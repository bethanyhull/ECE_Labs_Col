//"#include" statements for ADC and 7 segment function prototype declarations go here
// gpio_d_init() prototype declaration goes here!

int main(void)
{
                                // Initialize the ADC hardware
                                // Initialize the 7 segment display
                                // Initialize the GPIO Port D as outputs (output(15-0) = off)
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
                               
                                
                                // HEX7 is always blank
                                // HEX6 is volts
                                // HEX5 is tenths of volts
                                // HEX4 is hundredths of volts
                                
                                // HEX3 is thousands digit of decimal ADC count
                                // HEX2 is hundreds digit of decimal ADC count
                                // HEX1 is tens digit of decimal ADC count
                                // HEX0 is ones digit of decimal ADC count
                                
                                
  }

  return 0;                     // main function always returns 0 to indicate success
}
