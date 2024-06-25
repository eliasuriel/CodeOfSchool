#include <MKL25Z4.h>

int main (void) {

SIM->SCGC5 |= 0x1000; /* enable clock to Port D */

PORTD->PCR[1] = 0x100; /* make PTD1 pin as GPIO */

PTD->PDDR |= 0x02; /* make PTD1 as output pin */

SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */

SIM->SOPT2 |= 0x03000000; 

TPM0->SC = 0; /* disable timer while configuring */
TPM0->SC = 0x02; /* prescaler /4 */
TPM0->MOD = 40960 - 1; /* modulo value */
TPM0->SC |= 0x80; /* clear TOF */
TPM0->SC |= 0x08; /* enable timer free-running mode*/

while (1) 
{
while((TPM0->SC & 0x80) == 0) { 
TPM0->SC |= 0x80; /* clear TOF */
PTD->PTOR = 0x02; /* toggle blue LED */} 
/* wait until the TOF is set */

}
}

