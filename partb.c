/*
 * GccApplication3.c
 *
 * Created: 2021/9/28 10:27:20
 * Author : zheng
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB &= ~(1<<DDB0);
	DDRB |= (1<<DDB5);
    while (1) 
    {
		if (PINB & (1<<PINB0))
		{
			PORTB &= ~(1<<PORTB5);
		} 
		else
		{
			PORTB |= (1<<PORTB5);
		}
    }
}

