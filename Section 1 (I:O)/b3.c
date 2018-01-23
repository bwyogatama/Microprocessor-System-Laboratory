#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

int main (void)
{
	unsigned char i=0xFE;
	DDRA = 0xFF;
	PORTA = i;
	while (1)
	{
		PORTA = i;
		_delay_ms(120);
		i = (i<<1) | (i>>7);
	}
	return 0;
}



