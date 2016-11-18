/*
 * Dosya    : 18F4520_RF433_RX_TX.c
 * Yazar    : Expkits - www.expkits.com
 * Uygulama : RF433 UART Uygulamas�
 * S�r�m    : v1.0
 * Tarih    : 05.04.2013
 * MCU      : PIC18F4520
 * Kristal  : 20Mhz
 * Kit      : EX8
 * A��klama : RF433 RX ve TX mod�ller kullan�larak veri aktar�m�n�n sa�lanmas�d�r.
 *            D7 butonuna bas�ld��� zaman TX mod�l �zerinden sinyal g�nderilir.
 *            G�nderilen sinyal RX mod�l taraf�ndan al�narak UART RX interrupt� tetiklenir.
 *            Okunan veride 'X' yani 0x58 de�erine rastlanm�� ise D0 Ledi o anki durumuna
 *            g�re a��l�r yada kapan�r. D1 ledi RX mod�l� sinyal ald��� s�rece ileti�imin s�rd���n�
 *            g�sterecek �ekilde 1sn aral�klarla yan�p s�nen bir ikaz ����� durumundad�r.
 *            Haberle�me kesilirse s�necektir.
 *
 * Uyar�lar : CCS v4 ile derlenmi�tir.
 *            EX8 Kullan�c�lar�;
 *            - SWDIP7 �zerindeki RX ve TX (SW1-2) anahtarlar�n� ON konumuna almal�d�r.
 *            - SWDIP8 �zerinde sadece PORTD anahtar� (SW4) ON konumunda olmal�d�r.
 *            - Bu kod RXN3-B Rev1.0 ve TXC1 Rev.01 mod�lleri ile test edilmi�tir.
 *            - Her iki mod�lde EX8 �zerine tak�lacakt�r.
 *            - Bu kod ile ayn� anda TX ve RX mod�ler test edilmektedir.
 *            - Mod�ller aras� fiziksel bir sinyal ba�lant�s� yoktur.
 *            - Mod�ller beslemeyi ortak kaynaktan al�r ancak veri iletimi havadan ger�ekle�ir.
 */

#include <18F4520.h>
#device adc=16
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES HS                       //High speed Osc (> 4mhz FOR PCM/PCH) (>10mhz for PCD)
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used FOR I/O
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#use delay(clock=20000000)
#use rs232(baud=2000, rcv=PIN_C7, xmit=PIN_C6)
#include "EXLCD.C"

#int_rda
void serial_isr(){
   output_toggle(PIN_D1);
   if (getc()=='X')
   {
    output_toggle(PIN_D0);
   }
} 

void main()
{
   lcd_init () ;
   delay_ms (100) ;
   lcd_gotoxy(1, 1);
   printf(lcd_putc, "www.expkits.com  ");
   delay_ms(3000);
   WHILE (TRUE)
   {
        if (input(PIN_D7)==1) {
            lcd_gotoxy(1, 1);
            printf(lcd_putc, "Veri Gonderildi   ");
            putc(0x55);
            putc(0x55);
            putc(0x55);
            putc('X');
        } else {
            lcd_gotoxy(1, 1);
            printf(lcd_putc,"Bosta bekliyor.  ");
            putc(0x99);
            putc(0x99);
            putc(0x99);
        };
        delay_ms(500);
   }
}

