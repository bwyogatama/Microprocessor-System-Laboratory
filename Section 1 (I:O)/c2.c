#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

int main (void)
{
	unsigned char masukan; //variabel penampung input dari switch
	unsigned char i = 0XFE;//inisialisasi i
	DDRA = 0xFF;
	DDRD = 0x00;
	SFIOR = 0 << PUD;
	PORTA = 0xFF;
	while (1)
	{
		masukan = PIND;
		if (masukan == 0b01110110) //saat input nim 118
		{	
			PORTA = 0b01110110;
			_delay_ms(500);
			PORTA = 0b01110111;
			_delay_ms(500);
		}
		else if (masukan == 0b01110111) //saat input nim 119
		{
			while (i != 0b01111111 && masukan == 0b01110111)
			{
				PORTA = i;
				_delay_ms(120);
				i = (i<<1) | (i>>7);
			}
			while (i != 0b11111110 && masukan == 0b01110111)
			{
				PORTA = i;
				_delay_ms(120);
				i = (i>>1) | (i<<7);
			}
		else //saat input lainnya
		{
			PORTA = 0b00001101;
		}
	}
	return 0;
}