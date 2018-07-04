/*
 * bluetooth.c
 *
 * Created: 08-08-2017 06:55:42 PM
 * Author : drishti
 */  

#include <avr/io.h>
#include <avr/interrupt.h>
#include "USART_128.h"

#define F_CPU 8000000UL

#include <util/delay.h>
int main(void)
{
	DDRB |= 0xFF;  //set pin of register as output

	USART_Init(103,1);
	sei();
	
	USART_InterruptEnable(1); //use 1st usart out of two
	while (1)
	{
		USART_Transmitchar('Z',1);
		PORTB =0x00;
	}
}
ISR(USART1_RX_vect)
{
	unsigned char r_data;
	r_data=USART_Receive(1);
	if (r_data=='U')
	{
		USART_Transmitchar('U',1);
		//PORTB|=0b00001000;
		PORTB |= 1<< PINB0;
		_delay_ms(50);
		//PORTB &= ~(1<< PINB0);
		
	}
	else if(r_data=='R')
	{
		USART_Transmitchar('R',1);
		//PORTB=0b00000100;
		PORTB |= 1<< PINB2;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	else if(r_data=='L')
	{
		USART_Transmitchar('L',1);
		//PORTB |=0b00000010;
		PORTB |= 1<< PINB3;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	else if(r_data=='D')
	{
		USART_Transmitchar('D',1);
		//PORTB=0b00000001;
		PORTB |= 1<< PINB1;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	else if(r_data=='T')
	{
		USART_Transmitchar('T',1);
		//PORTB=0b00010000;
		PORTB |= 1<< PINB4;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	else if(r_data=='C')
	{
		USART_Transmitchar('C',1);
		//PORTB=0b00100000;
		PORTB |= 1<< PINB6;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	else if(r_data=='X')
	{
		USART_Transmitchar('X',1);
		//PORTB=0b01000000;
		PORTB |= 1<< PINB5;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	else if(r_data=='S')
	{
		USART_Transmitchar('S',1);
		//PORTB=0b10000000;
		PORTB |= 1<< PINB7;
		_delay_ms(50);
		//PORTB &= ~(1<<PINB1);
	}
	
	else
	{
		USART_Transmitchar('N',1);
		_delay_ms(50);
	}
}
