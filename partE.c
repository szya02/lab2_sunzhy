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
#include <string.h>

#include "uart.h"

char String[25];
char code[6];
char ary1[]={".-"};
char ary2[]={"-..."};
char ary3[]={"-.-."};
char ary4[]={"-.."};
char ary5[]={"."};
char ary6[]={"..-."};
char ary7[]={"--."};
char ary8[]={"...."};
char ary9[]={".."};
char ary10[]={".---"};
char ary11[]={"-.-"};
char ary12[]={".-.."};
char ary13[]={"--"};
char ary14[]={"-."};
char ary15[]={"---"};
char ary16[]={".--."};
char ary17[]={"--.-"};
char ary18[]={".-."};
char ary19[]={"..."};
char ary20[]={"-"};
char ary21[]={"..-"};
char ary22[]={"...-"};
char ary23[]={".--"};
char ary24[]={"-..-"};
char ary25[]={"-.--"};
char ary26[]={"--.."};
char ary27[]={".----"};
char ary28[]={"..---"};
char ary29[]={"...--"};
char ary30[]={"....-"};
char ary31[]={"....."};
char ary32[]={"-...."};
char ary33[]={"--..."};
char ary34[]={"---.."};
char ary35[]={"----."};
char ary36[]={"-----"};

int edge = 0;
int period = 0;
int num = 0;
int a = 0;

void match()
{
	if (strcmp(code,ary1) == 0)
	{
		sprintf(String,"A");
		UART_putstring(String);
	} 
	else if (strcmp(code,ary2) == 0)
	{
		sprintf(String,"B");
		UART_putstring(String);
	}
	else if (strcmp(code,ary3) == 0)
	{
		sprintf(String,"C");
		UART_putstring(String);
	}
	else if (strcmp(code,ary4) == 0)
	{
		sprintf(String,"D");
		UART_putstring(String);
	}
	else if (strcmp(code,ary5) == 0)
	{
		sprintf(String,"E");
		UART_putstring(String);
	}
	else if (strcmp(code,ary6) == 0)
	{
		sprintf(String,"F");
		UART_putstring(String);
	}
	else if (strcmp(code,ary7) == 0)
	{
		sprintf(String,"G");
		UART_putstring(String);
	}
	else if (strcmp(code,ary8) == 0)
	{
		sprintf(String,"H");
		UART_putstring(String);
	}
	else if (strcmp(code,ary9) == 0)
	{
		sprintf(String,"I");
		UART_putstring(String);
	}
	else if (strcmp(code,ary10) == 0)
	{
		sprintf(String,"J");
		UART_putstring(String);
	}
	else if (strcmp(code,ary11) == 0)
	{
		sprintf(String,"K");
		UART_putstring(String);
	}
	else if (strcmp(code,ary12) == 0)
	{
		sprintf(String,"L");
		UART_putstring(String);
	}
	else if (strcmp(code,ary13) == 0)
	{
		sprintf(String,"M");
		UART_putstring(String);
	}
	else if (strcmp(code,ary14) == 0)
	{
		sprintf(String,"N");
		UART_putstring(String);
	}
	else if (strcmp(code,ary15) == 0)
	{
		sprintf(String,"O");
		UART_putstring(String);
	}
	else if (strcmp(code,ary16) == 0)
	{
		sprintf(String,"P");
		UART_putstring(String);
	}
	else if (strcmp(code,ary17) == 0)
	{
		sprintf(String,"Q");
		UART_putstring(String);
	}
	else if (strcmp(code,ary18) == 0)
	{
		sprintf(String,"R");
		UART_putstring(String);
	}
	else if (strcmp(code,ary19) == 0)
	{
		sprintf(String,"S");
		UART_putstring(String);
	}
	else if (strcmp(code,ary20) == 0)
	{
		sprintf(String,"T");
		UART_putstring(String);
	}
	else if (strcmp(code,ary21) == 0)
	{
		sprintf(String,"U");
		UART_putstring(String);
	}
	else if (strcmp(code,ary22) == 0)
	{
		sprintf(String,"V");
		UART_putstring(String);
	}
	else if (strcmp(code,ary23) == 0)
	{
		sprintf(String,"W");
		UART_putstring(String);
	}
	else if (strcmp(code,ary24) == 0)
	{
		sprintf(String,"X");
		UART_putstring(String);
	}
	else if (strcmp(code,ary25) == 0)
	{
		sprintf(String,"Y");
		UART_putstring(String);
	}
	else if (strcmp(code,ary26) == 0)
	{
		sprintf(String,"Z");
		UART_putstring(String);
	}
	else if (strcmp(code,ary27) == 0)
	{
		sprintf(String,"1");
		UART_putstring(String);
	}
	else if (strcmp(code,ary28) == 0)
	{
		sprintf(String,"2");
		UART_putstring(String);
	}
	else if (strcmp(code,ary29) == 0)
	{
		sprintf(String,"3");
		UART_putstring(String);
	}
	else if (strcmp(code,ary30) == 0)
	{
		sprintf(String,"4");
		UART_putstring(String);
	}
	else if (strcmp(code,ary31) == 0)
	{
		sprintf(String,"5");
		UART_putstring(String);
	}
	else if (strcmp(code,ary32) == 0)
	{
		sprintf(String,"6");
		UART_putstring(String);
	}
	else if (strcmp(code,ary33) == 0)
	{
		sprintf(String,"7");
		UART_putstring(String);
	}
	else if (strcmp(code,ary34) == 0)
	{
		sprintf(String,"8");
		UART_putstring(String);
	}
	else if (strcmp(code,ary35) == 0)
	{
		sprintf(String,"9");
		UART_putstring(String);
	}
	else if (strcmp(code,ary36) == 0)
	{
		sprintf(String,"0");
		UART_putstring(String);
	}
}

void initialize()
{
	cli();
	DDRB &= ~(1<<DDB0);
	DDRB |= (1<<DDB5);
	PORTB &= ~(1<<PORTB5);
	DDRB |= (1<<DDB4);
	PORTB &= ~(1<<PORTB4);
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
			sprintf(String,".");
			UART_putstring(String);
			strcat(code,".");
			PORTB |= (1<<PORTB5);
			_delay_ms(50);
			PORTB &= ~(1<<PORTB5);
		} 
		else if (period >= 3125 && period <= 6250)
		{
			sprintf(String,"-");
			UART_putstring(String);
			strcat(code,"-");
			PORTB |= (1<<PORTB4);
			_delay_ms(50);
			PORTB &= ~(1<<PORTB4);
		}
		TCCR1B ^= (1<<ICES1);
		a = 0;
	} 
	
	else
	{
		
		if (period >= 12500)
		{
			sprintf(String,"SPACE \n");
			UART_putstring(String);
			match();
			strcpy(code,"");
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