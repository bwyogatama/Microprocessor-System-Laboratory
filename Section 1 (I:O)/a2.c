#include <avr/io.h>

int main (void)
{
	DDRA = 0XFF ; //inisialisasi PORTA sebagai OUTPUT
	PORTA = 0b00001101; // nilai OUTPUT 
	return 0;
}

