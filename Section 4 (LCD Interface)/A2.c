#include <avr/io.h>
#define F_CPU 7372800UL
#include <util/delay.h>

char angka;
char kodehex;
unsigned int SSegmen(int angka);

int main(void)
{
  DDRA = 0xFF;
  DDRD = 0XFF;
  int i,j;
  
  while (1)
  {
    for(i=5;i>0;i--)
    {
      for(j=0;j<500;j++)
      {
      	PORTD = (0<<PD7) | (1<<PD6);
        PORTA = SSegmen(i);
	    _delay_ms(1);
	    PORTD = (1<<PD7) | (0<<PD6);
        PORTA = SSegmen(0) | (1<<7);
  	    _delay_ms(1);
      }
    }
    
    for(i=0;i<3;i++)
    {
      for(j=0;j<250;j++)
      {
      	PORTD = (0<<PD7) | (1<<PD6);
        PORTA = 0xF1; // F.
	    _delay_ms(1);
	    PORTD = (1<<PD7) | (0<<PD6);
        PORTA = 0xF1; // F.
  	    _delay_ms(1);
      }

		PORTD = (0<<PD7) | (1<<PD6);
		PORTA = 0x00; // Mati
		_delay_ms(500);

    }
  }
  return 0;
}

unsigned int SSegmen(int angka)
{
  switch (angka)
  {
    case 0 :
	  kodehex = 0x3f;
	  break;
	case 1 :
	  kodehex = 0x06;
	  break;
	case 2 :
	  kodehex = 0x5b;
	  break;
	case 3 :
	  kodehex = 0x4f;
	  break;
	case 4 :
	  kodehex = 0x66;
	  break;
	case 5 :
	  kodehex = 0x6d;
	  break;
	case 6 :
	  kodehex = 0x7d;
	  break;
	case 7 :
	  kodehex = 0x07;
	  break;
	case 8 :
	  kodehex = 0x7f;
	  break;
	case 9 :
	  kodehex = 0x6f;
	  break;
  }
  return kodehex;
}
