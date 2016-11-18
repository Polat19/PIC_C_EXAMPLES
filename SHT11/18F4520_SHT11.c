/*
 * Dosya    : 18F4520_SHT11.c
 * Yazar    : Expkits - www.expkits.com
 * Uygulama : SHT11 Sensor Uygulamasi
 * S�r�m    : v1.0
 * Tarih    : 05.04.2013
 * MCU      : PIC18F4520
 * Kristal  : 20Mhz (MCU FOSC 20Mhz)
 * Kit      : EX8
 * A��klama : Sensirion SHT1x sensorlerini okuyarak LCD ekranda sicaklik ve nem
 *            bilgisi gosterir.
 * Uyar�    : CCS v4 ile derlenmi�tir.
 *            EX8 Kullan�c�lar� i�in;
 *            - Sens�r� geli�tirme kitine takarken besleme voltaj�n�n do�ru
 *              oldu�undan emin olunuz. Aksi halde sens�r zarar g�rebilir.
 *            - SWDIP7 SDA SCK (SW3-4) ON komununda olmal�d�r.
 *            - PULL U/D anahtarlar�ndan C3 ve C4 anahtarlar� ON konumuna al�narak
 *              SDA ve SCK hatlar� lojik 1 seviyesine �ekilmelidir.
 *
 * SHT Driver :http://www.ccsinfo.com/forum/viewtopic.php?t=28564
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

#define sht_data_pin   PIN_C4
#define sht_clk_pin    PIN_C3

#include <sht75.c>
#include "EXLCD.C"

void main()
{
 float restemp, truehumid;
 lcd_init();
 sht_init();

 while(TRUE)
 {
  sht_rd (restemp, truehumid);
  lcd_gotoxy(1,1);
  printf(lcd_putc, "Temp : %3.1f %cC   ", restemp, 223);
  printf(lcd_putc, "\nRH   : %3.1f %%   ", truehumid);
  delay_ms(500);        //delay 500 ms between reading to prevent self heating of sensor
 }
}
