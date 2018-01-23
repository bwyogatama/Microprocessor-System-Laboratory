#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

int main (void)
{
	DDRA = 0XFF;
	PORTA = 0XFF;
	while (1)
	{
		PORTA = 0b00110011;
		_delay_ms(500);
		PORTA = 0b11001100;
		_delay_ms(500);
	}
	return 0;
}


