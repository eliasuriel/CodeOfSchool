/* Generate 60Hz 33% PWM output
* TPM0 uses MCGFLLCLK which is 41.94 MHz.

* The prescaler is set to divide by 16.

* The modulo register is set to 43702 and the CnV

* register is set to 14568. See Example 3 for

* the calculations of these values.*/

#include "mbed.h"
#include <MKL25Z4.H>

int main (void) {
    SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
    PORTD->PCR[1] = 0x0400; /* PTD1 used by TPM0 */
    SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
    SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */

    TPM0->SC = 0; /* disable timer */
    /* edge-aligned, pulse high */
    TPM0->CONTROLS[1].CnSC = 0x20 | 0x08; 
    /* Set up modulo register for 60 kHz */
    TPM0->MOD = 43702; 
    TPM0->CONTROLS[1].CnV = 0; 
    /* 
      Use the following values in Cnv for the desired duty cycle
      Set up channel value at 0 for 0% dutycycle 
      Set up channel value at 10925 for 25% dutycycle
      Set up channel value at 21851 for 50% dutycycle
      Set up channel value at 32776 for 75% dutycycle
      Set up channel value at 43702 for 100% dutycycle
    */
    TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
    while (1) { } 
}
