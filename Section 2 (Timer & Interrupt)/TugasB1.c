#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 7372800UL //8Mhz
#include <util/delay.h>

void init_tim(void);

int main(void)
{
	init_tim();
	DDRA = 0xFF;
	while (1)
	{
	// penentuan nilai awal timer
	TCNT0 = 123;
	// penentuan nilai compare
	OCR0 = 124;
	// menanti compare match
	while (bit_is_clear(TIFR, OCF0))
	{
		PORTA = 0b10101010;
	}
	// meng-nol-kan flag
	TIFR |= _BV(OCF0);
	PORTA = 0b01010101;
	_delay_ms(500);
	}
	return 0;
}

void init_tim(void)
{
	// mode operasi dan sumber clock
	TCCR0 = 0b00000110;
	// overflow interrupt disable
	TIMSK = (0<<OCIE0);
}