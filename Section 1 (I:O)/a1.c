#include <avr/io.h>

int main (void)
{
	DDRA = 0XFF ; //inisialisasi PORTA sebagai OUTPUT
	PORTA = (1 << PA6) | (1 << PA4) | (1 << PA2) | (1 << PA0); // nilai OUTPUT
	return 0;
}
