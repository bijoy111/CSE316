/*
 * GccApplication1.c
 *
 * Created: 12/13/2022 3:13:11 PM
 * Author : ASUS
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
int main(void)
{
    /* Replace with your application code */
	
	unsigned char c = 0b00010000;
	
	DDRB = 0xFF;
    while (1) 
    {
		
		PORTB = c;
		if(c == 1<<7) c =  0b00010000;
		else c <<=1;
		_delay_ms(1000);
		
		
    }
	return 0;

}


