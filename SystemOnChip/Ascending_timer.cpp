#include <MKL25Z4.h>
#include "iostream"
#include <string>

#define RS 0x04 /* PTA1 mask */
#define RW 0x10 /* PTA4 mask */
#define EN 0x20 /* PTA5 mask */

void delayMs(int n);
void delayUs(int n);
char keypad_getkey(void);
void keypad_init(void);
void LED_init(void);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);

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

int main(void){
    keypad_init();
    LED_init();
    LCD_init();

    LCD_command(1); /* clear display */
    delayMs(500);
    LCD_command(0x80); /* set cursor at first line */
    LCD_data('H');
    LCD_data('O');
    LCD_data('L'); /* write the word */
    LCD_data('A');
    delayMs(5000);
    LCD_command(1); //Clear
    LCD_command(0x80); //Set cursor at first line
    LCD_data('P');
    LCD_data('O');
    LCD_data('N'); /* write the word */
    LCD_data(' ');
    LCD_data('T');
    LCD_data('I');
    LCD_data('E');
    LCD_data('M'); /* write the word */
    LCD_data('P');
    LCD_data('O');
    LCD_data(':');

    unsigned char key1;
    unsigned char key2;
    int sel = 0;
    int sel2 = 0;
    int value = 0;

    while(1){
        key1 = keypad_getkey();
        if (key1 == 1){
            sel = 1;
        } else 
        if(key1 == 2){
            sel = 2;
        } else 
        if(key1 == 3){
            sel = 3;
        }else
        if (key1 == 5){
            sel = 4;
        } else 
        if(key1 == 6){
            sel = 5;
        } else 
        if(key1 == 7){
            sel = 6;
        }else
        if (key1 == 9){
            sel = 7;
        } else 
        if(key1 == 10){
            sel = 8;
        }
        if(key1 == 11){
            sel = 9;
        }
        if (sel!=0){
            break;
        }
    }
    delayMs(1000);
    while(1){
        key2 = keypad_getkey();
        if (key2 == 14){
            sel2 = 0;
        } else 
        if (key2 == 1){
            sel2 = 1;
        } else 
        if (key2 == 2){
            sel2 = 2;
        } else 
        if (key2 == 3){
            sel2 = 3;
        }else
        if (key2 == 5){
            sel2 = 4;
        } else 
        if (key2 == 6){
            sel2 = 5;
        } else 
        if (key2 == 7){
            sel2 = 6;
        }else
        if (key2 == 9){
            sel2 = 7;
        } else 
        if (key2 == 10){
            sel2 = 8;
        }else 
        if (key2 == 11){
            sel2 = 9;
        }else
        if(key2==13 || key2==15){
            sel2 = 100;
        }

        if (sel2!=0){
            if(sel2==100){
                sel2=0;
            }
            break;
        }
    }

    if (sel2 == 0){
        value = sel;
    }
    else{
        value = (sel*10)+sel2;
    }
    int d, u;
    while(value>=0){
        LCD_command(1); //Clear
        d = value/10;
        u = value%10;
        std::string temp_u = std::to_string(u);
        std::string temp_d = std::to_string(d);
        unsigned char u_Test;
        u_Test = static_cast<unsigned char>(temp_u[0]);
        unsigned char d_Test;
        d_Test = static_cast<unsigned char>(temp_d[0]);
        LCD_data(d_Test);
        LCD_data(u_Test);
        if(value==0){
            PTB->PCOR = 0x40000; /* turn on red LED */
        }
        value=value-1;
        delayMs(1000);
    } 
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

void delayMs(int n) {
    int i;
    SysTick->LOAD = 41940 - 1;
    SysTick->CTRL = 0x5; /* Enable the timer and choose sysclk as the clock source */
    for(i = 0; i < n; i++) {
    while((SysTick->CTRL & 0x10000) == 0)
    { }
    }
    SysTick->CTRL = 0; 
}
void delayUs(int n) {
    int i;
    SysTick->LOAD = 4194 - 1;
    SysTick->CTRL = 0x5; /* Enable the timer and choose sysclk as the clock source */

    for(i = 0; i < n; i++) {
    while((SysTick->CTRL & 0x10000) == 0)
    /* wait until the COUTN flag is set */
    { }
    }
    SysTick->CTRL = 0; 
    /* Stop the timer (Enable = 0) */
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

void LED_init(void){
    SIM->SCGC5 |= 0x400; /* enable clock to Port B */
    SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
    PORTB->PCR[18] = 0x100; /* make PTB18 pin as GPIO */
    PTB->PDDR |= 0x40000; /* make PTB18 as output pin */
    PTB->PSOR |= 0x40000; /* turn off red LED */
    PORTB->PCR[19] = 0x100; /* make PTB19 pin as GPIO */
    PTB->PDDR |= 0x80000; /* make PTB19 as output pin */
    PTB->PSOR |= 0x80000; /* turn off green LED */
    PORTB->PCR[10] = 0x100; /* make PTD1 pin as GPIO */
    PTD->PDDR |= 0x02; /* make PTD1 as output pin */
    PTD->PSOR |= 0x02; /* turn off blue LED */
}