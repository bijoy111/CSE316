/*
 * GccApplication2.c
 *
 * Created: 12/21/2022 7:49:46 PM
 * Author : turjo
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int a[] = {1, 2, 4, 8, 16, 32, 64, 128};
int b[] = {0b00000000,
		   0b00011000,
		   0b00100100,
		   0b01000010,
		   0b01111110,
		   0b01000010,
		   0b01000010,
           0b01111110};


int main(void)
{
    /* Replace with your application code */
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	int idx = 0;
	
    while (1)
    {
		for (int i=0; i<=7; i++) {
			int msb = b[i] & 128;
			b[i] = b[i] << 1;
			b[i] = b[i] | (msb >> 7);
		}
		idx = 0;
		for (int i=0; i<250; i++) {
			PORTC = a[idx];
			PORTD = ~b[idx];
			idx++;
			idx = idx % 8;
			_delay_ms(4);
		}
		
    }
}

