#include "mbed.h"
#include <MKL25Z4.h>
#include <string>

#define RS 0x04 /* PTA1 mask */
#define RW 0x10 /* PTA4 mask */
#define EN 0x20 /* PTA5 mask */

void delayMs(int n);
void delayUs(int n);

extern "C" void PORTA_IRQHandler(void);

char keypad_getkey(void);
void keypad_init(void);

void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);

void PWM_mode(int valor);

int main(void){

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

    PTB->PSOR = 0x02; /* turn off blue LED */
    LCD_init();
    keypad_init();

    LCD_command(1); //Clear
    LCD_command(0x80); //Set cursor at first line
    LCD_data('S');
    LCD_data('e');
    LCD_data('t');
    LCD_data(' ');
    LCD_data('i');
    LCD_data('n');
    LCD_data('p');
    LCD_data('u');
    LCD_data('t');
    LCD_data(' ');
    LCD_data('m');
    LCD_data('o');
    LCD_data('d');
    LCD_data('e');
    LCD_command(0xC0);
    LCD_data('1');
    LCD_data(':');
    LCD_data('M');
    LCD_data('a');
    LCD_data('n');
    LCD_data('u');
    LCD_data('a');
    LCD_data('l');
    LCD_data(' ');
    LCD_data('2');
    LCD_data(':');
    LCD_data('A');
    LCD_data('u');
    LCD_data('t');
    LCD_data('o');
    unsigned char key;
    int sel = 0;
    while(1){
        key = keypad_getkey();
        if (key==1){
            sel=1;
            break;
        }
    }
    delayMs(500);
    if (sel==1){
        LCD_command(1); //Clear
        LCD_command(0x80); //Set cursor at first line
        LCD_data('S');
        LCD_data('e');
        LCD_data('l');
        LCD_data('e');
        LCD_data('c');
        LCD_data('t');
        LCD_data(' ');
        LCD_data('S');
        LCD_data('p');
        LCD_data('e');
        LCD_data('e');
        LCD_data('d');
        LCD_command(0xC0);
        LCD_data('1');
        LCD_data(':');
        LCD_data('L');
        LCD_data(' ');
        LCD_data('2');
        LCD_data(':');
        LCD_data('M');
        LCD_data(' ');
        LCD_data('3');
        LCD_data(':');
        LCD_data('M');
        LCD_data('H');
        LCD_data(' ');
        LCD_data('4');
        LCD_data(':');
        LCD_data('H');
        unsigned char key1;
        while(1){
            key1 = keypad_getkey();

            if (key1 == 1){
                LCD_command(1); //Clear
                LCD_command(0x80); //Set cursor at first line
                LCD_data('M');
                LCD_data('o');
                LCD_data('d');
                LCD_data('e');
                LCD_data(' ');
                LCD_data('L');
                LCD_data('o');
                LCD_data('w');
                PWM_mode(32776);
            } 
            else if(key1 == 2){
                LCD_command(1); //Clear
                LCD_command(0x80); //Set cursor at first line
                LCD_data('M');
                LCD_data('o');
                LCD_data('d');
                LCD_data('e');
                LCD_data(' ');
                LCD_data('M');
                LCD_data('e');
                LCD_data('d');
                LCD_data('i');
                LCD_data('u');
                LCD_data('m');
                PWM_mode(21851);
            } 
            else if(key1 == 3){
                LCD_command(1); //Clear
                LCD_command(0x80); //Set cursor at first line
                LCD_data('M');
                LCD_data('o');
                LCD_data('d');
                LCD_data('e');
                LCD_data(' ');
                LCD_data('M');
                LCD_data('e');
                LCD_data('d');
                LCD_data('.');
                LCD_data(' ');
                LCD_data('H');
                LCD_data('i');
                LCD_data('g');
                LCD_data('h');
                PWM_mode(10925);
            }
            else if(key1 == 5){
                LCD_command(1); //Clear
                LCD_command(0x80); //Set cursor at first line
                LCD_data('M');
                LCD_data('o');
                LCD_data('d');
                LCD_data('e');
                LCD_data(' ');
                LCD_data('H');
                LCD_data('i');
                LCD_data('g');
                LCD_data('h');
                PWM_mode(0);
            }
        }
    }
}

void PWM_mode(int valor){
    SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
    PORTD->PCR[1] = 0x0400; /* PTE30 used by TPM0 */
    SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
    SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */

    TPM0->SC = 0; /* disable timer */
    /* edge-aligned, pulse high */
    TPM0->CONTROLS[1].CnSC = 0x20 | 0x08; 
    /* Set up modulo register for 60 kHz */
    TPM0->MOD = 43702; 
    TPM0->CONTROLS[1].CnV = valor; 
    /* Set up channel value for 33% dutycycle */
    TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
    /* 
      Use the following values in Cnv for the desired duty cycle
      Set up channel value at 0 for 0% dutycycle 
      Set up channel value at 10925 for 25% dutycycle
      Set up channel value at 21851 for 50% dutycycle
      Set up channel value at 32776 for 75% dutycycle
      Set up channel value at 43702 for 100% dutycycle
    */
    while(1){}
}

extern "C" void PORTA_IRQHandler(void) {
    LCD_command(1); //Clear
    LCD_command(0x80); //Set cursor at first line
    LCD_data('P');
    LCD_data('A');
    LCD_data('U');
    LCD_data('S');
    LCD_data('E');
    LCD_data('D');
    PWM_mode(43702);
}

void delayMs(int n){
    int i;
    for (i = 0; i<n;i++){
        while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
        TPM0->SC |= 0x80; // clear TOF
    }
}

void delayUs(int n) {
    int i;
    for (i = 0; i<n;i++){
        while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
        TPM0->SC |= 0x80; // clear TOF
    }
}

void LCD_init(void){
    SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
    PORTD->PCR[0] = 0x100; /* make PTD0 pin as GPIO */
    PORTD->PCR[1] = 0x100; /* make PTD1 pin as GPIO */
    PORTD->PCR[2] = 0x100; /* make PTD2 pin as GPIO */
    PORTD->PCR[3] = 0x100; /* make PTD3 pin as GPIO */
    PORTD->PCR[4] = 0x100; /* make PTD4 pin as GPIO */
    PORTD->PCR[5] = 0x100; /* make PTD5 pin as GPIO */
    PORTD->PCR[6] = 0x100; /* make PTD6 pin as GPIO */
    PORTD->PCR[7] = 0x100; /* make PTD7 pin as GPIO */
    PTD->PDDR = 0xFF; /* make PTD7-0 as output pins */
    SIM->SCGC5 |= 0x0200; /* enable clock to Port A */
    PORTA->PCR[2] = 0x100; /* make PTA2 pin as GPIO */
    PORTA->PCR[4] = 0x100; /* make PTA4 pin as GPIO */
    PORTA->PCR[5] = 0x100; /* make PTA5 pin as GPIO */
    PTA->PDDR |= 0x34; /* make PTA5, 4, 2 as out pins*/
    delayMs(30); /* initialization sequence */
    LCD_command(0x38);
    delayMs(1);
    LCD_command(0x01);
    /* set 8-bit data, 2-line, 5x7 font */
    LCD_command(0x38);
    /* move cursor right */
    LCD_command(0x06); 
    /* clear screen, move cursor to home */
    LCD_command(0x01);
    /* turn on display, cursor blinking */
    LCD_command(0x0F);
}

void LCD_command(unsigned char command){
    PTA->PCOR = RS | RW; /* RS = 0, R/W = 0 */
    PTD->PDOR = command;
    PTA->PSOR = EN; /* pulse E */
    delayMs(0);
    PTA->PCOR = EN; 
    if (command < 4)
    delayMs(4); /* command 1 and 2 needs up to 1.64ms */
    else
    delayMs(1); /* all others 40 us */
}

void LCD_data(unsigned char data){
    PTA->PSOR = RS; /* RS = 1, R/W = 0 */
    PTA->PCOR = RW;
    PTD->PDOR = data;
    PTA->PSOR = EN; /* pulse E */
    delayMs(0);
    PTA->PCOR = EN;
    delayMs(1);
}

char keypad_getkey(void) {
    int row, col;
    const char row_select[] = {0x01, 0x02, 0x04, 0x08}; 
    /* one row is active */
    /* check to see any key pressed */

    PTC->PDDR |= 0x0F; /* enable all rows */
    PTC->PCOR = 0x0F;
    delayUs(2); /* wait for signal return */
    col = PTC-> PDIR & 0xF0; /* read all columns */
    PTC->PDDR = 0; /* disable all rows */
    if (col == 0xF0)
    return 0; /* no key pressed */

    /* If a key is pressed, we need find out which key.*/ 
    for (row = 0; row < 4; row++)
    { PTC->PDDR = 0; /* disable all rows */

    PTC->PDDR |= row_select[row]; /* enable one row */
    PTC->PCOR = row_select[row]; /* drive active row low*/

    delayUs(2); /* wait for signal to settle */
    col = PTC->PDIR & 0xF0; /* read all columns */

    if (col != 0xF0) break; 
    /* if one of the input is low, some key is pressed. */
    }

    PTC->PDDR = 0; /* disable all rows */

    if (row == 4)
    return 0; /* if we get here, no key is pressed */

    /* gets here when one of the rows has key pressed*/ 
    /*check which column it is*/

    if (col == 0xE0) return row * 4 + 1; /* key in column 0 */
    if (col == 0xD0) return row * 4 + 2; /* key in column 1 */
    if (col == 0xB0) return row * 4 + 3; /* key in column 2 */
    if (col == 0x70) return row * 4 + 4; /* key in column 3 */
    return 0; /* just to be safe */
}

void keypad_init(void){
    SIM->SCGC5 |= 0x0800;  /* enable clock to Port C */
    PORTC->PCR[0] = 0x103; /* PTD0, GPIO, enable pullup*/
    PORTC->PCR[1] = 0x103; /* PTD1, GPIO, enable pullup*/
    PORTC->PCR[2] = 0x103; /* PTD2, GPIO, enable pullup*/
    PORTC->PCR[3] = 0x103; /* PTD3, GPIO, enable pullup*/
    PORTC->PCR[4] = 0x103; /* PTD4, GPIO, enable pullup*/
    PORTC->PCR[5] = 0x103; /* PTD5, GPIO, enable pullup*/
    PORTC->PCR[6] = 0x103; /* PTD6, GPIO, enable pullup*/
    PORTC->PCR[7] = 0x103; /* PTD7, GPIO, enable pullup*/
    PTC->PDDR = 0x0F; /* make PTD7-0 as input pins */
}