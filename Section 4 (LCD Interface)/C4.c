#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "lcd_lib.h"
//Strings stored in AVR Flash memory
const uint8_t LCDtombol1[] PROGMEM="Percobaan LCD\0";

int main(void)
{
	static int count = 0;
	int x = 0;
	LCDinit();//init LCD bit, dual line, cursor right
	LCDclr();//clears LCD
	DDRA=0xFF;
	PORTA=0x00;
	DDRD=0x00;
	PORTD=0x0F;
	SFIOR=(0<<PUD);
	LCDGotoXY(0, 0);
	CopyStringtoLCD(LCDtombol1, 0, 0);
	LCDGotoXY(0, 1);
	while(1)//loop demos
	{
		
		if (count >= 4) {
			x++;
			LCDshiftRight(2);
			LCDGotoXY(2*x, 0);
			CopyStringtoLCD(LCDtombol1, 2*x, 0);			
			LCDGotoXY(x*count, 1);
			count = 0;

		}
		
		
		for (int i = 0x10; i != 0;) {
			DDRD = i;
			_delay_ms(1);

			if (bit_is_clear(PIND,0)) {
				if (i == 0x10)
				LCDsendChar('1');
				else if (i == 0x20)
				LCDsendChar('4');
				else if (i == 0x40)
				LCDsendChar('7');
				else if (i == 0x80)
		
				_delay_ms(200);
				count++;
			}

			if (bit_is_clear(PIND,1)) {
				if (i == 0x10)
				LCDsendChar('2');
				else if (i == 0x20)
				LCDsendChar('5');
				else if (i == 0x40)
				LCDsendChar('8');
				else if (i == 0x80)
				LCDsendChar('0');
				_delay_ms(200);
			
				count++;
			}

			if (bit_is_clear(PIND,2)) {
				if (i == 0x10)
				LCDsendChar('3');
				else if (i == 0x20)
				LCDsendChar('6');
				else if (i == 0x40)
				LCDsendChar('9');
				else if (i == 0x80)
				LCDsendChar('#');
				_delay_ms(200);
			
				count++;
			}

			if (bit_is_clear(PIND,3)) {
				if (i == 0x10)
				LCDsendChar('A');
				else if (i == 0x20)
				LCDsendChar('B');
				else if (i == 0x40)
				LCDsendChar('C');
				else if (i == 0x80)
				LCDsendChar('D');
				_delay_ms(200);
				count++;
			}

			i=(i<<1);
		}

		
	}
	return 0;
}
