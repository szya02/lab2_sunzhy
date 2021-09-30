/*
 * lab2 partD.c
 *
 * Created: 2021/9/28 13:26:46
 * Author : zheng
 */ 
#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)


#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "uart.h"

char String[25];

int edge = 0;
int period = 0;
int num = 0;
int a = 0;
void initialize()
{
	cli();
	DDRB &= ~(1<<DDB0);
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B |= (1<<CS12);
	TCCR1A &= ~(1<<WGM10);
	TCCR1A &= ~(1<<WGM11);
	TCCR1B &= ~(1<<WGM12);
	TCCR1B &= ~(1<<WGM13);
	TCCR1B &= ~(1<<ICES1);
	TIFR1 |= (1<<ICF1);
	TIMSK1 |= (1<<ICIE1);
	TIMSK1 |= (1<<TOIE1);
	sei();
}

ISR(TIMER1_CAPT_vect)
{
	period = ICR1 + num * 65536 - edge;
	edge = ICR1;
	num = 0;
	if (a)
	{
		if (period >= 469 && period <= 3125)
		{
			sprintf(String,"¡¤ %d\n", period);
			UART_putstring(String);
		} 
		else if (period >= 3125 && period <= 6250)
		{
			sprintf(String,"/ %d\n", period);
			UART_putstring(String);
		}
		TCCR1B ^= (1<<ICES1);
		a = 0;
	} 
	
	else
	{
		if (period >= 6250)
		{
			sprintf(String,"SPACE %d\n", period);
			UART_putstring(String);
		}
		TCCR1B ^= (1<<ICES1);
		a = 1;
	}
	
}

ISR(TIMER1_OVF_vect)
{
	num = num + 1;
}

int main(void)
{
    UART_init(BAUD_PRESCALER);
	initialize();
    while (1) 
    {
    }
}

