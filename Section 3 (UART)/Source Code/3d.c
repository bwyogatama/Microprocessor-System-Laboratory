#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 7372800UL
#include <util/delay.h>

//program ISR
ISR(INT1_vect)
{
	//inisialisasi port
	DDRA = 0xFF;
	DDRC = 0x00;
	PORTC = 0xFF;
	SFIOR = 0<<PUD;
	char i, kar;
	
	//pemberian 5s untuk mengisi password pertama
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x01;
	_delay_ms(1000);
	PORTA = 0x03;
	_delay_ms(1000);
	PORTA = 0x07;
	_delay_ms(1000);
	PORTA = 0x0F;
	_delay_ms(1000);
	
	//nilai switch input setelah 5s
	i = PINC;
	
	//jika password match (1)
	if (i == 0x01)
	{
		//menyala sejenak
		PORTA = 0xFF;
		_delay_ms(500);
		
		//pindah ke mode counter
		init_tim();
		
		//penentuan nilai awal timer
		TCNT0 = 123;
		//penentuan nilai compare
		OCR0 = 127;
		//menanti compare match
		
		while(bit_is_clear(TIFR,OCF0))
		{
			if (TCNT0 == 123) {
				PORTA = 0x00;
			} else if (TCNT0 == 124) {
				PORTA = 0x01;
			} else if (TCNT0 == 125) {
				PORTA = 0x02;
			} else if (TCNT0 == 126) {
				PORTA = 0x03;
			} else if (TCNT0 == 127) {
				PORTA = 0x04;
			}
		}

		//meng-nol-kan flag
		TIFR|=_BV(OCF0);

		//pemberian 5s untuk mengisi password kedua
		PORTA = 0x00;
		_delay_ms(1000);
		PORTA = 0x01;
		_delay_ms(1000);
		PORTA = 0x03;
		_delay_ms(1000);
		PORTA = 0x07;
		_delay_ms(1000);
		PORTA = 0x0F;
		_delay_ms(1000);
		
		//nilai input keyboard setelah 5s
		kar = UDR;
		loop_until_bit_is_set(UCSRA,5);
		UDR = kar;
		
		//jika password match dengan "E"
		if (kar == 'E') {
			PORTA = 0xFF;
			_delay_ms(1000);
			PORTA = 0x00;
			_delay_ms(1000);
			PORTA = 0xFF;
			_delay_ms(1000);
			PORTA = 0x00;
			_delay_ms(1000);
		}
	}
}

void init_tim(void)
{
	//mode operasi dan sumber clock
	TCCR0=0b00000110;
	//overflow interrupt disable
	TIMSK=(0<<OCIE0);
}

void Init_Ext_Int(void)
{
	//register MCU, dengan 1 external input
	MCUCR=0x08;
	MCUCSR=0x00;
	GICR=0x80;
	GIFR=0x80;
}

//program IDLE
void RunningLED(void)
{
	unsigned int counter = 0;
	unsigned char j = 0x7F;
	unsigned char i = 0xFE;
	
	while(1)
	{
		if (counter < 7)
		{
			PORTA = i;
			_delay_ms(120);
			i = (i<<1)|(i>>7);
			counter += 1;
		}
		else
		{
			PORTA = j;
			_delay_ms(120);
			j = (j>>1)|(j<<7);
			counter += 1;
		}
	
		if (counter == 14)
		{
			counter = 0;
			i = 0xFE;
			j = 0x7F;
		}
	}
}

//program utama
int main(void)
{
	DDRA = 0xFF;
	Init_Ext_Int();
	sei();
	
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRL=47;
	
	while(1)
	{
		RunningLED();
	}
	
	return 0;
}
