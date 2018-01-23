#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

char angka;
char kodehex;
unsigned int SSegmen(char angka);

int main(void)
{
  DDRA = 0xFF;
  DDRD = (1<<PD4) | (1<<PD5);
  SFIOR = (0<<PUD);
  
  // Keadaan awal
  PORTD = (0<<PD7) | (1<<PD6);
  PORTA = SSegmen('0');
  _delay_ms(1);
  PORTD = (1<<PD7) | (0<<PD6);
  PORTA = SSegmen('0');
  _delay_ms(1);
  while (1)
  {
    PORTD = (1<<PD4) | (0<<PD5);
	if (bit_is_clear(PIND, 0))
	{
      PORTA = SSegmen('1');
	  _delay_ms(1);
      PORTA = SSegmen('1');
  	  _delay_ms(1);
	}
	if (bit_is_clear(PIND, 1))
	{
      PORTA = SSegmen('4');
	  _delay_ms(1);
      PORTA = SSegmen('4');
  	  _delay_ms(1);
	}
	
	PORTD = (0<<PD4) | (1<<PD5);
    if (bit_is_clear(PIND, 0))
    {
	    PORTA = SSegmen('2');
	    _delay_ms(1);
        PORTA = SSegmen('2');
  	    _delay_ms(1);
	}
	if (bit_is_clear(PIND, 1))
	{
	    PORTA = SSegmen('3');
	    _delay_ms(1);
        PORTA = SSegmen('3');
  	    _delay_ms(1);
	}
  }
  return 0;
}

unsigned int SSegmen(char angka)
{
  switch (angka)
  {
    case '0' :
	  kodehex = 0x3f;
	  break;
	case '1' :
	  kodehex = 0x06;
	  break;
	case '2' :
	  kodehex = 0x5b;
	  break;
	case '3' :
	  kodehex = 0x4f;
	  break;
	case '4' :
	  kodehex = 0x66;
	  break;
	case '5' :
	  kodehex = 0x6d;
	  break;
	case '6' :
	  kodehex = 0x7d;
	  break;
	case '7' :
	  kodehex = 0x07;
	  break;
	case '8' :
	  kodehex = 0x7f;
	  break;
	case '9' :
	  kodehex = 0x6f;
	  break;
  }
  return kodehex;
}
