#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 7372800UL
#include <util/delay.h>

ISR(USART_RX_vect)
{
	unsigned char kar, i;
	char kal1[]=" 13213006 ";
	char kal2[]=" 13213062 ";
	
	kar = UDR;
	PORTA = kar;
	
	if (kar == '1')
	{
		for (i=0;kal1[i]!='\0';++i)
		{
				loop_until_bit_is_set(UCSRA,5);
				UDR=kal1[i];
		}
	}
	else if (kar == '2')
	{
		for (i=0;kal2[i]!='\0';++i)
		{
				loop_until_bit_is_set(UCSRA,5);
				UDR=kal2[i];
		}
	}
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
