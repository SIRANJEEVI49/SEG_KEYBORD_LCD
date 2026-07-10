//2 BUTTON USING ON 7 SEGMENT first button 0-9 forward and reverse
/*
 * File:   button_inc_dec.c
 * Author: admin
 *
 * Created on March 16, 2026, 10:40 AM
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
void delay(unsigned long int t)
{
    while(t--);
}
void main(void)
{
    int i,count = 0,count1 = 10;
    int arr[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
    PORTD = PORTB = PORTA = 0X00;
    TRISB = 0X03; TRISD = TRISA = 0X00;
    ANSEL = ANSELH = 0X00;
    while(1)
    {
        if(RB0 == 0)
        {
        for(i = 0; i< 10; i++)
         {
            RA0 = 1;
            RA1 = RA2 = RA3 = 0;
            PORTD = arr[i];
            __delay_ms(100);
          //  RB0 = 1;
         }
        }
        if(RB1 == 0)
        {
           for(i = 10; 0<i;i--)
            {
                RA1 = 1;
                RA0 = RA2 = RA3 = 0;
                PORTD = arr[i];
                __delay_ms(100);
             //   RB1 = 1;
            }
        //}
      /*  if(RB1 == 1)
        {
            count1--;
            while(RB1 == 1);
        }

        for(i = 10; i>count1;i--)
        {
            RA1 = 1;
            RA0 = RA2 = RA3 = 0;
            PORTD = arr[count1];
            delay(1000);
        }*/
    }
    return;
}