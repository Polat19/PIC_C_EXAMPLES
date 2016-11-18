/*
 * Dosya    : 18F4520_Joystick.c
 * Yazar    : Expkits - www.expkits.com
 * Uygulama : Joystick Test Uygulamas�
 * S�r�m    : v1.0
 * Tarih    : 05.04.2013
 * MCU      : PIC18F4520
 * Kristal  : 20Mhz
 * Kit      : EX8
 * A��klama : Ama� joystick versinin LCD ekranda g�r�nt�lenmesidir.
 * Uyar�    : CCS v4 ile derlenmi�tir.
 *            EX8 i�in;
 *            - Jumper J13 BUTTON PULL (UP) konumunda olmal�d�r.
 *            - Jumper J6 (PORTA-E PULL U/D yan�nda) (D)own pozisyonuna al�nacak.
 *            - PULL U/D SW SWDIP1(PORTA-E) SW5 (A3) ON konumuna al�nacak.
 *            - J5 (PORTA-E ��k��lar) �zerindeki E2 ��k���ndan GND'ye 4.7K diren�
 *              ba�lanmas� gereklidir. Bu i�lem direkt ZIF soket �zerinden bir diren�
 *              ile de yap�labilir. ZIF �zerinde GND ve E2 birbirine daha yak�nd�r.
 */


#include <18F4520.h>
#device adc=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)

#use delay(clock=20000000)

#include "EXLCD.C"
#define JOY_UP PIN_E0
#define JOY_DOWN PIN_A2
#define JOY_LEFT PIN_E1
#define JOY_RIGHT PIN_E2
#define JOY_ENTER PIN_A3
#define JOY_ESC PIN_A4


void main()
{
    setup_adc_ports (NO_ANALOGS);
    setup_adc (ADC_OFF);
    lcd_init();
    delay_ms (100);
    output_low (PIN_B7); // Buzzer kapal�.

    while (TRUE)
    {
        printf (lcd_putc, "\fJoystick Demo");
        lcd_gotoxy (1, 2);

        if (input (JOY_UP) == 1)
        {
            printf (lcd_putc, " UST");
        }

        if (input (JOY_DOWN) == 1)
        {
            printf (lcd_putc, " ALT");
        }

        if (input (JOY_RIGHT) == 1)
        {
            printf (lcd_putc, " SAG");
        }

        if (input (JOY_LEFT) == 1)
        {
            printf (lcd_putc, " SOL");
        }

        if (input (JOY_ENTER) == 1)
        {
            printf (lcd_putc, " ENTER");
        }

        if (input (JOY_ESC) == 1)
        {
            printf (lcd_putc, " ESC");
        }

        delay_ms (250);
    }
}
