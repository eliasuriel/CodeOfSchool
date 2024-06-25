#include "mbed.h"
#include <MKL25Z4.h>

void delayMs(int n);

int main(void)
{
__disable_irq(); /* disable all IRQs */
SIM->SCGC5 |= 0x400; /* enable clock to Port B */
SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
PORTB->PCR[18] = 0x100; /* make PTB18 pin as GPIO */
PORTB->PCR[19] = 0x100; /* make PTB19 pin as GPIO */
PTB->PDDR |= 0xC0000; /* make PTB18-19 as output pin */
PORTD->PCR[1] = 0x100; /* make PTD1 pin as GPIO */
PTD->PDDR |= 0x02; /* make PTD1 as output pin */
PTB->PDOR |= 0xC0000; /* turn off red/green LEDs */
PTD->PDOR |= 0x02; /* turn off blue LED */
SIM->SCGC5 |= 0x200; /* enable clock to Port A */

/* configure PTA1 for interrupt */
PORTA->PCR[1] |= 0x00100; /* make it GPIO */
PORTA->PCR[1] |= 0x00003; /* enable pull-up */
PTA->PDDR &= ~0x0002; /* make pin input */
PORTA->PCR[1] &= ~0xF0000; /* clear interrupt selection */
PORTA->PCR[1] |= 0xA0000; /* enable falling edge INT */

/* configure PTA2 for interrupt*/
PORTA->PCR[2] |= 0x00100; /* make it GPIO */
PORTA->PCR[2] |= 0x00003; /* enable pull-up */
PTA->PDDR &= ~0x0004; /* make pin input */
PORTA->PCR[2] &= ~0xF0000; /* clear interrupt selection */
PORTA->PCR[2] |= 0xA0000; /* enable falling edge INT */
NVIC->ISER[0] |= 0x40000000; /* enable INT30 (bit 30 of ISER[0]) */
__enable_irq(); /* global enable IRQs */

//Lineas para inicializar el TMP0
SIM->SCGC6 |= 0x01000000; // enable clock to TPM0
SIM->SOPT2 |= 0x01000000; // use 32.768 kHz clock
TPM0->SC = 0; // disable timer while configuring
TPM0->SC = 0x02; // prescaler 4
TPM0->MOD = 0x2000; // modulo 8192
TPM0->SC |= 0x80; // clear TOF
TPM0->SC |= 0x08; // enable timer free-running mode
//Aquí acaba el TMP0



/* toggle the red LED continuously */
while(1) {
PTB->PTOR |= 0x40000; /* toggle red LED */
delayMs(500); } }

void PORTA_IRQHandler(void) {
    int i;
    while (PORTA->ISFR & 0x00000006) {
        if (PORTA->ISFR & 0x00000002) {
            /* toggle green LED (PTB19) three times */
            for (i = 0; i < 3; i++) {
                PTB->PDOR &= ~0x80000; /* turn on green LED */
                delayMs(500);
                PTB->PDOR |= 0x80000; /* turn off green LED */
                delayMs(500);
            }
            PORTA->ISFR = 0x00000002; /* clear interrupt flag */
        }

        if (PORTA->ISFR & 0x00000004) {
            /* toggle blue LED (PTD1) three times */
            for (i = 0; i < 3; i++) {
                PTD->PDOR &= ~0x02; /* turn on blue LED */
                delayMs(500);
                PTD->PDOR |= 0x02; /* turn off blue LED */
                delayMs(500);
            }
            PORTA->ISFR = 0x00000004; /* clear interrupt flag */ 
        } 
    } 
}

/* Delay n milliseconds */
void delayMs(int n){
    int i;
    for (i = 0; i<n;i++){
        while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
        TPM0->SC |= 0x80; // clear TOF
    }
}