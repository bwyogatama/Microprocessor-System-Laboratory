#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>
#include <avr/interrupt.h>


void Init_Ext_Int(void);

ISR(INT0_vect)
{
	PORTA = 0x99;
	_delay_ms(500);
	PORTA = 0x66;
	_delay_ms(500);
}

ISR(INT1_vect)
{
	PORTA = 0x46;
	_delay_ms(500);
	PORTA = 0x47;
	_delay_ms(500);
}

int main(void)
{
	Init_Ext_Int();
	sei();
	DDRA = 0xFF;
	while (1) 
	{
		PORTA = 0xFF;
		_delay_ms(500);
		PORTA = 0x00;
		_delay_ms(500);
	}
	return 0;
}

void Init_Ext_Int(void)
{
	MCUCR = 0x0A;
	MCUCSR = 0x00;
	GICR = 0xC0;
	GIFR = 0xC0;
}