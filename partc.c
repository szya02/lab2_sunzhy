/*
 * GccApplication1.c
 *
 * Created: 2021/9/28 12:05:25
 * Author : zheng
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void initialize()
{
	cli();
	DDRB &= ~(1<<DDB0);
	DDRB |= (1<<DDB5);
	PORTB &= ~(1<<PORTB5);
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<ICES1);
	TIFR1 |= (1<<ICF1);
	TIMSK1 |= (1<<ICIE1);
	sei();
}

ISR(TIMER1_CAPT_vect)
{
	PORTB ^= (1<<PORTB5);
	TCCR1B ^= (1<<ICES1);
}

int main(void)
{
    initialize();
    while (1) 
    {
    }
}

