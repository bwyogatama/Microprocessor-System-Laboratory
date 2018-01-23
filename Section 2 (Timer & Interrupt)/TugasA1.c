#include <avr/io.h>

void init_tim(void);
void Delay(void);

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
	init_tim();
	while (1) {
		PORTA = 0x0F;
		Delay();
		PORTA = 0xF0;
		Delay();
	}
	return 0;
}

void init_tim(void)
{
	// mode operasi CTC, sumber clock prescaller 256
	TCCR1A = 0;
	TCCR1B = 0b00001100;
	// overflow interrupt disable
	TIMSK |= (0<<TOIE1);
}

void Delay(void)
{
	// overflow interrupt enable
	TIMSK |= _BV(TOIE1);//(1<<TOIE1)
	// penentuan nilai awal timer
	TCNT1H = 0;
	TCNT1L = 0;
	// penentuan nilai compare untuk delay 1 detik
	OCR1AH = 0x70;
	OCR1AL = 0x80;
	// menunggu hingga compare match, nilai TCNT1 = OCR1A
	loop_until_bit_is_set(TIFR, OCF1A);
	// meng-nol-kan flag
	TIFR |= _BV(OCF1A);
	//overflow interrupt disable
	TIMSK |= _BV(TOIE1);
}