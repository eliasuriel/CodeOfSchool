#include "mbed.h"
#include "MKL25Z4.h"
#include <string>
#include "iostream"
 
#define RS 0x04 /* PTA1 mask */
#define RW 0x10 /* PTA4 mask */
#define EN 0x20 /* PTA5 mask */
 
void ADC0_init(void);
 
extern "C" void PORTA_IRQHandler(void);
 
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCD_set(int n);
 
void delayMs(int n);
void delayUs(int n);
 
char keypad_getkey(void);
void keypad_init(void);
 
void fan_5s(void);
 
int main (void) {
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
    PORTE->PCR[5] &= ~PORT_PCR_MUX_MASK;
    PORTE->PCR[5] |= PORT_PCR_MUX(1);
    /* Setting as output pins */
    PTE->PDDR |= 0x0020;
 
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
 
    LCD_init(); //Configure the lcd
    keypad_init();
    ADC0_init();
    int result;
    float temperature;
    char buffer[16];
    int count;
 
    LCD_command(1); //Clear
    LCD_command(0x80); //Set cursor at first line
    LCD_data('S');
    LCD_data('e');
    LCD_data('t');
    LCD_data(' ');
    LCD_data('t');
    LCD_data('e');
    LCD_data('m');
    LCD_data('p');
    LCD_data('e');
    LCD_data('r');
    LCD_data('a');
    LCD_data('t');
    LCD_data('u');
    LCD_data('r');
    LCD_data('e');
 
    unsigned char key1;
    unsigned char key2;
    int sel = 0;
    int sel2 = 0;
    int value = 0;
    
    
 
    while(1){
        key1 = keypad_getkey();
        if(key1 == 1){
            sel = 1;
        }else 
        if(key1 == 2){
            sel = 2;
        }else 
        if(key1 == 3){
            sel = 3;
        }else
        if(key1 == 5){
            sel = 4;
        }else 
        if(key1 == 6){
            sel = 5;
        }else 
        if(key1 == 7){
            sel = 6;
        }else
        if(key1 == 9){
            sel = 7;
        }else 
        if(key1 == 10){
            sel = 8;
        }else
        if(key1 == 11){
            sel = 9;
        }
 
        if(sel!=0){
            break;
        }
    }
    delayMs(500);
 
    LCD_command(1);
    LCD_command(0x80); //Set cursor at first line
 
    std::string sel1_str = std::to_string(sel);;
    LCD_data(static_cast<unsigned char>(sel1_str[0]));
 
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
 
    std::string sel2_str = std::to_string(sel2);;
    LCD_data(static_cast<unsigned char>(sel2_str[0]));
 
    delayMs(100);
 
    LCD_command(1); //Clear
    LCD_command(0x80); //Set cursor at first line
    LCD_data('S');
    LCD_data('e');
    LCD_data('t');
    LCD_data(' ');
    LCD_data('t');
    LCD_data('o');
    LCD_data(' ');
    LCD_data(static_cast<unsigned char>(sel1_str[0]));
    LCD_data(static_cast<unsigned char>(sel2_str[0]));
 
    value = sel*10 + sel2;
    delayMs(3000);
 
    while (1) {
        
        ADC0->SC1[0] = 0; /* start conversion on channel 0 */
        while(!(ADC0->SC1[0] & 0x80)) { } /* wait for COCO */
        result = ADC0->R[0]; 
        /* read conversion result and clear COCO flag */
 
        temperature = result * 330.0 / 65536; 
        /* convert voltage to temperature */
 
        std::string Temp = std::to_string(temperature); 
        /* convert to string */
        LCD_set(temperature);
 
        /* send the string through UART0 for display */
        delayMs(1000);
        count = count + 1;
        if (count == 5){
            PTB->PDOR &= ~0x80000; /* turn on green LED */
            fan_5s();
            count = 0;
        }
        PTB->PDOR |= 0x80000; /* turn off green LED */
        
        while(temperature>value){
            PTE->PSOR = 0x0020; // Port E pin 5 = 0 (low)
            ADC0->SC1[0] = 0; /* start conversion on channel 0 */
            while(!(ADC0->SC1[0] & 0x80)) { } /* wait for COCO */
            result = ADC0->R[0]; 
            /* read conversion result and clear COCO flag */
 
            temperature = result * 330.0 / 65536; 
            /* convert voltage to temperature */
 
            std::string Temp = std::to_string(temperature); 
            /* convert to string */
            LCD_set(temperature);
 
            /* send the string through UART0 for display */
            delayMs(1000);
            if (temperature<value){
                break;
            }
        }
        PTE->PSOR = ~0x0020; // Port E pin 5 = 0 (low)
    } 
}
 
void fan_5s(void){
    /* Set pin high */
    PTE->PSOR = 0x0020; // Port E pin 16 = 1 (high)
    delayMs(5000);
    /* Set pin to low */
    PTE->PCOR = 0x0020; // Port E pin 0 = 0 (low)
}
 
void ADC0_init(void){
    SIM->SCGC5 |= 0x2000; /* clock to PORTE */
 
    PORTE->PCR[20] = 0; /* PTE20 analog input */ 
 
    SIM->SCGC6 |= 0x8000000; /* clock to ADC0 */
 
    ADC0->SC2 &= ~0x40; /* software trigger */
 
    ADC0->SC3 |= 0x07; /* 32 samples average */
 
    /* clock div by 4, long sample time, single ended 16 bit, bus clock */
 
    ADC0->CFG1 = 0x40 | 0x10 | 0x0C | 0x00;
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
 
void LCD_set(int n){
    LCD_command(1); //Clear
    LCD_command(0x80); //Set cursor at first line
    LCD_data('C');
    LCD_data('u');
    LCD_data('r');
    LCD_data('r');
    LCD_data('e');
    LCD_data('n');
    LCD_data('t');
    LCD_data(' ');
    LCD_data('t');
    LCD_data('e');
    LCD_data('m');
    LCD_data('p');
    LCD_data(':');
    LCD_data(' '); 
 
    std::string temp = std::to_string(n);
    unsigned char a_Test, b_Test, c_Test, d_Test;
    a_Test = static_cast<unsigned char>(temp[0]);
    b_Test = static_cast<unsigned char>(temp[1]);/*
    c_Test = static_cast<unsigned char>(temp[2]);
    d_Test = static_cast<unsigned char>(temp[3]);*/
    LCD_data(a_Test);
    LCD_data(b_Test);/*
    LCD_data(c_Test);
    LCD_data(d_Test);*/
    delayMs(100);
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
 
extern "C" void PORTA_IRQHandler(void) {
    unsigned char keyInt;
    while(1){
        PTE->PSOR = ~0x0020; // Port E pin 5 = 0 (low)
        int result;
        float temperature;
        char buffer[16];
 
        keyInt = keypad_getkey();
        ADC0->SC1[0] = 0; /* start conversion on channel 0 */
        while(!(ADC0->SC1[0] & 0x80)) { } /* wait for COCO */
        result = ADC0->R[0]; 
        /* read conversion result and clear COCO flag */
 
        temperature = result * 330.0 / 65536; 
        /* convert voltage to temperature */
 
        std::string Temp = std::to_string(temperature); 
        /* convert to string */
        LCD_set(temperature);
 
        /* send the string through UART0 for display */
        delayMs(1000);
 
        if(keyInt == 13){
            LCD_command(1);
            LCD_data('T');
            break;
        }
    }
    PORTA->ISFR = 0x00000002; /* clear interrupt flag */
}

