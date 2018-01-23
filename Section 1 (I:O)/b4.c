#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 7372800UL
#include <util/delay.h>

ISR(USART_RX_vect)
{
	char nim1[]=" 13213118 ";
	char nim2[]=" 13213119 ";
	unsigned char kar;
	unsigned char i;
	
	kar = UDR;
	PORTA = kar;
	
	if (kar == '1')
	{
		for (i=0;nim1[i]!='\0';i++)
			{
				loop_until_bit_is_set(UCSRA,5);
				UDR=nim1[i];
			}
	}
	else if (kar == '2')
	{
		for (i=0;nim2[i]!='\0';i++)
			{
				loop_until_bit_is_set(UCSRA,5);
				UDR=nim2[i];
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

