#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 7372800UL
#include <util/delay.h>

ISR(USART_RX_vect)
{
	unsigned char kar;

	kar = UDR;
	PORTA = kar;
	loop_until_bit_is_set(UCSRA,5);
	UDR = kar;
}

int main (void)
{
	UCSRA=0x00;
	UCSRB=0x98;
	UCSRC=0x86;
	UBRRL=47;
	sei();
	while(1)
	{
		if bit_is_set(UCSRA,3)
		{
			loop_until_bit_is_set(UCSRA,5);
		}
	}
	return 0;
}
