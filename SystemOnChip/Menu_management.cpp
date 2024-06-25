#include <MKL25Z4.h>

#define RS 0x04 /* PTA2 Pin */
#define RW 0x10 /* PTA4 Pin */
#define EN 0x20 /* PTA5 Pin */

/*Functions*/
void delayMs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void); 

void delayUs(int n);
void keypad_init(void);
void LED_init(void);
char keypad_getkey(void);

/*Main function*/
int main(void){
	unsigned char key;
	keypad_init();
	LED_init();
	
	LCD_init();
	int menu = 0;
	while (menu == 0){
		LCD_command(1); /* clear display */
		delayMs(500);
		LCD_command(0x80); /* set cursor at first line */
		
		LCD_data('P'); 
		LCD_data('r');
		LCD_data('e');
		LCD_data('s');
		LCD_data('s');
		LCD_data(' ');
		LCD_data('B');
		LCD_data('u');
		LCD_data('t');
		LCD_data('t');
		LCD_data('o');
		LCD_data('n');
		delayMs(500);
		
		if(menu == 0){
			key = keypad_getkey();
			if (key == 1){
				menu = 1;
			} else 
			if(key == 2){
				menu = 2;
			} else 
			if(key == 3){
				menu = 3;
			}
		}
    	else if (menu == 1){
			PTB->PCOR = 0x40000; /* turn on red LED */
			LCD_command(1); /* clear display */
			delayMs(500);
			LCD_command(0x80); /* set cursor at first line */
			
			LCD_data('R'); 
			LCD_data('e');
			LCD_data('d');
			LCD_data(' ');
			LCD_data('L');
			LCD_data('e');
			LCD_data('d');
			LCD_data(' ');
			LCD_data('i');
			LCD_data('s');
			LCD_data(' ');
			LCD_data('o');
			LCD_data('n');
			LCD_data('!');
			delayMs(500);
			
			PTB->PSOR = 0x40000; /* turn off red LED */
			menu = 0;
		}
		else if (menu == 2){
			PTB->PCOR = 0x02; /* turn on blue LED */
			LCD_command(1); /* clear display */
			delayMs(500);
			LCD_command(0x80); /* set cursor at first line */
			
			LCD_data('B'); 
			LCD_data('l');
			LCD_data('u');
			LCD_data('e');
			LCD_data(' ');
			LCD_data('L');
			LCD_data('e');
			LCD_data('d');
			LCD_data(' ');
			LCD_data('i');
			LCD_data('s');
			LCD_data(' ');
			LCD_data('o');
			LCD_data('n');
			LCD_data('!');
			delayMs(500);
			PTB->PSOR = 0x02; /* turn off blue LED */
			menu = 0;
		}
		
		else if(menu == 3){
			PTB->PCOR = 0x80000; /* turn on green LED */
			LCD_command(1); /* clear display */
			delayMs(500);
			LCD_command(0x80); /* set cursor at first line */
			
			LCD_data('G'); 
			LCD_data('r');
			LCD_data('e');
			LCD_data('e');
			LCD_data('n');
			LCD_data(' ');
			LCD_data('L');
			LCD_data('e');
			LCD_data('d');
			LCD_data(' ');
			LCD_data('i');
			LCD_data('s');
			LCD_data(' ');
			LCD_data('o');
			LCD_data('n');
			LCD_data('!');
			delayMs(500);
			PTB->PSOR = 0x80000; /* turn off green LED */
			menu = 0;
		}
    }
}


/* initialize and configurates the LCD on the FRDM board */
void LCD_init(void)
{
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
delayMs(30); 

/* initialization sequence */
LCD_command(0x38);
delayMs(1);
LCD_command(0x01);/* Clear screen */ 

LCD_command(0x38);/* Set 8-bit data, 2-line, 5x7 font */
LCD_command(0x06);/* Move cursor right */
LCD_command(0x01);/* Clear screen, move cursor to home */
LCD_command(0x0F);}/* Turn on display, cursor blinking */

/* Initializes PortC that is connected to the keypad.*/
/* Pins as GPIO input pin with pullup enabled.*/

void keypad_init(void)
{
SIM->SCGC5 |= 0x0800;  /* enable clock to Port C */
PORTC->PCR[0] = 0x103; /* PTD0, GPIO, enable pullup*/
PORTC->PCR[1] = 0x103; /* PTD1, GPIO, enable pullup*/
PORTC->PCR[2] = 0x103; /* PTD2, GPIO, enable pullup*/
PORTC->PCR[3] = 0x103; /* PTD3, GPIO, enable pullup*/
PORTC->PCR[4] = 0x103; /* PTD4, GPIO, enable pullup*/
PORTC->PCR[5] = 0x103; /* PTD5, GPIO, enable pullup*/
PORTC->PCR[6] = 0x103; /* PTD6, GPIO, enable pullup*/
PORTC->PCR[7] = 0x103; /* PTD7, GPIO, enable pullup*/
PTD->PDDR = 0x0F; /* make PTD7-0 as input pins */
}

/* initialize all three LEDs on the FRDM board */
void LED_init(void)
{
SIM->SCGC5 |= 0x400; /* enable clock to Port B */
SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
PORTB->PCR[18] = 0x100; /* make PTB18 pin as GPIO */
PTB->PDDR |= 0x40000; /* make PTB18 as output pin */
PTB->PSOR |= 0x40000; /* turn off red LED */
PORTB->PCR[19] = 0x100; /* make PTB19 pin as GPIO */
PTB->PDDR |= 0x80000; /* make PTB19 as output pin */
PTB->PSOR |= 0x80000; /* turn off green LED */
PORTD->PCR[1] = 0x100; /* make PTD1 pin as GPIO */
PTD->PDDR |= 0x02; /* make PTD1 as output pin */
PTD->PSOR |= 0x02; /* turn off blue LED */
}


/* Sends command to the LCD*/
void LCD_command(unsigned char command)
{
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

/* Sends data to the LCD*/
void LCD_data(unsigned char data)
{

PTA->PSOR = RS; /* RS = 1, R/W = 0 */

PTA->PCOR = RW;

PTD->PDOR = data;

PTA->PSOR = EN; /* pulse E */

delayMs(0);
PTA->PCOR = EN;
delayMs(1);
}

/* Delay n milliseconds */
/* The CPU core clock is set to MCGFLLCLK at */ /*41.94 MHz in SystemInit(). */

void delayMs(int n) {
int i;
int j;
for(i = 0 ; i < n; i++)
for(j = 0 ; j < 7000; j++) { }
}

void delayUs(int n) {
int i;
int j;
for(i = 0 ; i < n; i++)
for(j = 0 ; j < 700; j++) { }
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