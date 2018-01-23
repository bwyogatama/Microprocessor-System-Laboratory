#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

int main(void)
{
  DDRA = 0xFF;
  PORTA = 0x00;
  DDRD = (1<<PD4) | (1<<PD5);
  SFIOR = (0<<PUD);
  
  while (1)
  {
    PORTD = (1<<PD4) | (0<<PD5);
    if (bit_is_clear(PIND, 0))
	  PORTA = 0b00000001;
	_delay_ms(50);
	if (bit_is_clear(PIND, 1))
	  PORTA = 0b00001111;
	_delay_ms(50);
	
	PORTD = (0<<PD4) | (1<<PD5);
    if (bit_is_clear(PIND, 0))
	  PORTA = 0b00000011;
	_delay_ms(50);
	if (bit_is_clear(PIND, 1))
	  PORTA = 0b00000111;
	_delay_ms(50);
  }
  return 0;
}
