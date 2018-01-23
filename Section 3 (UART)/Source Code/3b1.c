#include <avr/io.h>

int main(void)
{
	UCSRA=0x00;
	UCSRB=0x08;
	UCSRC=0x86;
	UBRRL=47;
			
	char kal[]=" Prakikum Sistem Mikroprosesor ";
	unsigned char i=0;
	
	for (i=0;kal[i]!='\0';++i)
	{
		loop_until_bit_is_set(UCSRA,5);
		UDR=kal[i];
	}
	return 0;
}
