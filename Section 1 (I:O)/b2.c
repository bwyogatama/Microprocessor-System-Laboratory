#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

int main (void)
{
	DDRA = 0XFF;
	PORTA = 0XFF;
	while (1)
	{
		PORTA = 0b01110110;
		_delay_ms(500);
		PORTA = 0b01110111;
		_delay_ms(500);
	}
	return 0;
}



