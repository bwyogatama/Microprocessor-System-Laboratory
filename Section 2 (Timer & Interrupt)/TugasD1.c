#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>
#include <avr/interrupt.h>


void Init_Ext_Int(void);

ISR(INT0_vect)
{
	unsigned char i = 0x01, n;
	for (n=0;n<8;++n) 
	{
		PORTA = i;
		_delay_ms(250);
		i = (i<<1) | (i>>7);
	}
}

int main(void)
{
	Init_Ext_Int();
	sei();
	DDRA = 0xFF;
	while (1) 
	{
		PORTA = 0b10101010;
		_delay_ms(500);
		PORTA = 0b01010101;
		_delay_ms(500);
	}
	return 0;
}

void Init_Ext_Int(void)
{
	MCUCR = 0x02;
	MCUCSR = 0x00;
	GICR = 0x40;
	GIFR = 0x40;
}
