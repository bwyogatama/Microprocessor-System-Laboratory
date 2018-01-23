#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "lcd_lib.h"

// strings stored in AVR Flash Memory
const uint8_t LCDtombol1[] PROGMEM="***Tekan Tombol Scanning Keypad***\0";

// delay 1s
void delay1s(void)
{
  uint8_t i;
  for (i=0; i<100; i++)
  {
    _delay_ms(10);
  }
}

int main(void)
{
  LCDinit(); // initialize LCD bit, dual line, cursor right
  LCDclr(); // clear LCD

  DDRA = 0xFF;
  PORTA = 0x00;
  DDRD = (1<<PD4) | (1<<PD5) | (1<<PC7) | (1<<PC6);
  SFIOR = (0<<PUD);
  
  delay1s();
  LCDGotoXY(0, 1);
  delay1s();
  
  while (1) // loop demos
  {
    CopyStringtoLCD(LCDtombol1, 0, 0);
	LCDshiftRight(1);
	
	PORTD = (1<<PD4) | (0<<PD5) | (1<<PC7) | (1<<PC6);
    if (bit_is_clear(PIND, 0))
	{
	  LCDclr();
	  LCDGotoXY(8, 1);
	  LCDsendChar('&');
	  delay1s();
	  LCDclr();
	}
	_delay_ms(50);
	
	if (bit_is_clear(PIND, 1))
	{
  	  LCDclr();
	  LCDGotoXY(8, 1);
	  LCDsendChar('a');
	  delay1s();
	  LCDclr();
	}
	_delay_ms(50);
	
	PORTD = (0<<PD4) | (1<<PD5) | (1<<PC7) | (1<<PC6);
    if (bit_is_clear(PIND, 0))
	{
	  LCDclr();
	  LCDGotoXY(8, 1);
	  LCDsendChar('5');
	  delay1s();
	  LCDclr();
	}
	_delay_ms(50);
	
	if (bit_is_clear(PIND, 1))
	{
  	  LCDclr();
	  LCDGotoXY(8, 1);
	  LCDsendChar('7');
	  delay1s();
	  LCDclr();
	}
	_delay_ms(50);
  }
  return 0;
}
