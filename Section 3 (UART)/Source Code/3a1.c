#include<avr/io.h>
int main (void)
{
	//tentukan nilai baudrate yang sesuai dengan inisialisasi ini
	UCSRA=0x00;
	UCSRB=0x10;
	UCSRC=0x86;
	UBRRL = 47;
	
	while (1)
	{
		loop_until_bit_is_set(UCSRA,7);
		PORTA=UDR;
		UCSRA|=_BV(7);
	}

	return 0;
}
