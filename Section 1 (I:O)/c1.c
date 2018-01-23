#include <avr/io.h>

int main (void)
{
	unsigned char i;
	DDRA = 0xFF;//inisialisasi PORTA sebagai output
	DDRD = 0x00;//inisialisasi PORTD sebagai input
	SFIOR = 0 << PUD; // aktivasi resistor pull-up internal
	PORTA = 0xFF;
	while (1)
	{
		i=PIND;
		PORTA = i;
	}
	return 0;
} 
