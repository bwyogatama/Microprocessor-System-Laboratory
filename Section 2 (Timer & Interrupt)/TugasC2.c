#include <avr/io.h>
#define F_CPU 7372800UL // 8MHz
#include <util/delay.h>
#include <avr/interrupt.h>


void init_int(void);
ISR(TIMER1_OVF_vect)
{
	PORTA = 0xFF;
	_delay_ms(200);
	TIFR = (1<<TOV1);
	TCNT1H = 0x8F;
	TCNT1L = 0x96;
}

int main(void)
{
	init_int();
	DDRA = 0xFF;
	while (1) {
		PORTA = 0b01010101;
		_delay_ms(100);
		PORTA = 0b10101010;
		_delay_ms(100);
		TIMSK = 0b000100;
	}
return 0;
}

void init_int(void)
{
	TIMSK = 0b000000;
	TCCR1B = 0b00000101; //prescaler 1024
	TCNT1H = 0xE3;
	TCNT1L = 0xE0;
	sei();
}