/*
 * GccApplication3.c
 *
 * Created: 11-08-2017 08:56:52 PM
 * Author : saurabh
 */ 

#include <avr/io.h>


#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "USART_32.h"
#include <avr/sfr_defs.h>


#include "PS2.h"

//#define BAUD 12				//set after at commands mode
//#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)


enum {select, leftStick, rightStick, start, up, right, down, left}; //3rd byte from ps2 controller
enum {leftFront2, rightFront2, leftFront1, rightFront1, triangle_up, circle_right, cross_down, square_left}; // 4th byte from ps2 controller

enum left;
uint8_t x,y;

int isPressed(uint8_t dataByte, uint8_t dataBit)
 {
	return ((dataByte & (1 << dataBit)) ? 1 : 0);
}



int main(void)
{
	USART_Init(103); //baud rate 4800
	
	//USART_Transmitchar('A');
	//USART_Transmitchar(0x0D);
	_delay_us(50);
	init_PS2();				//function to initialize spi
	_delay_us(2000);
	//initialise usart

	
	//USART_Transmitchar('M');
	//USART_Receive();
	while (1)
	{
		//USART_Transmitchar('B');
		//USART_Receive();
		//	USART_Transmitchar(0x0D);
		scan_PS2();
		_delay_us(500);
		
		x=~data_array[3];
		y=~data_array[4];
		//USART_Transmitchar('A');
		//USART_TransmitBinary(x);
		if (isPressed(x,up))	//x refers to the array which will be in terms of 000x 0000 if switch corresponding to up is pressed and up refers to enum
		{
			
			USART_Transmitchar('U');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
			//USART_Receive();
		}
		else if (isPressed(x,right))	//x refers to the array which will be in terms of 000x 0000 if switch corresponding to up is pressed and up refers to enum
		{
			
			USART_Transmitchar('R');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
			//USART_Receive();
		}
		else if (isPressed(x,left))	//x refers to the array which will be in terms of 000x 0000 if switch corresponding to up is pressed and up refers to enum
		{
			
			USART_Transmitchar('L');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
			//USART_Receive();
		}
		else if (isPressed(x,down))	//x refers to the array which will be in terms of 000x 0000 if switch corresponding to up is pressed and up refers to enum
		{
			
			USART_Transmitchar('D');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
			//USART_Receive();
		}
		if (isPressed(y,triangle_up))
		{
			USART_Transmitchar('T');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
		}
		else if (isPressed(y,circle_right))
		{
			USART_Transmitchar('C');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
		}
		else if (isPressed(y,cross_down))
		{
			USART_Transmitchar('X');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
		}
		else if (isPressed(y,square_left))
		{
			USART_Transmitchar('S');
			//_delay_us(50);
			//USART_Transmitchar(0x0D);
		}
		/*else
		{
			USART_Transmitchar('e');
			_delay_us(50);
			//USART_Transmitchar(0x0D);
		}*/
	}
}




