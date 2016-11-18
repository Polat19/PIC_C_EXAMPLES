/*
 * Dosya    : 18F4520_Blink.c
 * Yazar    : Expkits - www.expkits.com
 * Uygulama : LED Test Uygulamas�
 * S�r�m    : v1.0
 * Tarih    : 05.04.2013
 * MCU      : PIC18F4520
 * Kristal  : 20Mhz
 * Kit      : EX8
 * A��klama : A0 ledini yak�p s�nd�r�r.
 * Uyar�    : CCS v4 ile derlenmi�tir.
 *            EX8 i�in;
 *			  -SWDIP8 �zerindeki PORTA-E anahtar� ON konumunda olmal�d�r.
 */
#include <18F4520.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)

#FUSES HS   // High speed crystal

#use delay(clock=20000000)

#define LED PIN_A0
#define DELAY 500

void main()
{
   //Example blinking LED program
   while(true)
   {
      output_low(LED);
      delay_ms(DELAY);
      output_high(LED);
      delay_ms(DELAY);
   }

}
