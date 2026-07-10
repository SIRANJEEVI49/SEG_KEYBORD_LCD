/*
 * File:   SEG_KEYPAD_LCD.c
 * Author: admin
 *
 * Created on April 4, 2026, 11:37 AM
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 20000000
/*#define RS RC0
#define EN RC1
#define D4 RC2
#define D5 RC3
#define D6 RC4
#define D7 RC5 */

// 8 BIT LCD
#define RS RA0
#define EN RA2
#define RW RA1
void lcd_init();
void delay(unsigned int t)
{
    while(t--);
}
void enable()
{
    EN = 1;
    __delay_ms(10);
    EN = 0;
    __delay_ms(10);
}
/*void lcd_4bit(unsigned char data)
{
    D4 = (data & 0X01)?1:0;
    D5 = (data & 0X02)?1:0;
    D6 = (data & 0X04)?1:0;
    D7 = (data & 0X08)?1:0;
    enable();  
}*/
void command(unsigned char cmd)
{
    RS = 0;
    PORTD = cmd;
   // lcd_4bit(cmd >> 4); // UPPER NIPPLE
   // lcd_4bit(cmd);
   // __delay_ms(5);
    enable();
}
void data(unsigned char d)
{
    RS = 1;
    PORTD = d;
    //lcd_4bit(d >> 4);
    //lcd_4bit(d);
    enable();
    __delay_ms(5);
    RE1 = 1;
}
void lcd_init()
{
   // RC6 = RC7 = 0;
   //  command(0x02); // carriage value    4 bit LCD
   // command(0x28); //4 bit LCD   
    command(0x38); // 8 bit LCD
    command(0x0C); // display on
    command(0x01); //clear screen
    command(0X80); // 1 row
}
void string(const char *str)
{
    while(*str)
    {
        data(*str++);
    }
}
void keypad()
{
    RB0 = 1; RB1 = RB2 = RB3 = 0;
    if(RB4 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 1");
        __delay_ms(100);
        }
    if(RB5 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 2");
        __delay_ms(100);
       
        }
    if(RB6 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 3");
        __delay_ms(100);
        }
    if(RB7 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 4");
        __delay_ms(100);
        }
    RB1 = 1;
    RB0 = RB2 = RB3 = 0;
    if(RB4 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 5");
        __delay_ms(100);
        }
    if(RB5 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 6");
        __delay_ms(100);
        }
    if(RB6 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 7");
        __delay_ms(100);
        }
    if(RB7 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 8");
        __delay_ms(100);
        }
    RB2 = 1;
    RB0 = RB1 = RB3 = 0;
    if(RB4 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 9");
        __delay_ms(100);
        }
    if(RB5 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 10");
        __delay_ms(100);
        }
    if(RB6 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 11");
        __delay_ms(100);
        }
    if(RB7 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 12");
        __delay_ms(100);
        }
    RB3 = 1;
    RB0 = RB2 = RB1 = 0;
    if(RB4 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 13");
        __delay_ms(100); 
        }
    if(RB5 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 14");
        __delay_ms(100);
        }
    if(RB6 == 1)
        {
        command(0X80);
        command(0x01);
        string("switch 15");
        __delay_ms(100);
        }
    if(RB7 == 1)
     {
        command(0X80);
        command(0x01);
        string("switch 16");
        __delay_ms(100);
     }
}
void main(void)
{
    PORTA = PORTD = PORTB = PORTC = 0X00;
    TRISA = TRISD = 0X00;
    TRISB = 0X0F;  
    TRISC = 0X00;
    PORTE = TRISE = 0X00;
    ANSEL = ANSELH = 0X00;
    RW = 0;
   // RD6 = RD7 = 0;
    int i,arr[10] = {0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
    lcd_init();
    char str[10] = {"READY"};
    command(0x01);
    string(&str);
    delay(100);
    while(1)
    {
        // SEGMENT
       /* for(i = 0; i<10; i++)
        {
            RA0 = RA1 = RA2 = RA3 = 1;
            PORTD = arr[i];
            __delay_ms(200);
        }*/
        keypad();
        __delay_ms(10);
        
      /*  RB0 = 1;
        RB1 = RB2 = RB3 = 0;  
        if(RB4 == 1)
        {
            command(0x01);
            command(0x80);
            string("switch 1");
            delay(1000);
           // command(0x01);
        }
        if(RB5 == 1)
        {
            command(0x01);
            command(0x80);
            string("switch 2");
            delay(1000);
           // command(0x01);
        }*/
    }
    return;
}
