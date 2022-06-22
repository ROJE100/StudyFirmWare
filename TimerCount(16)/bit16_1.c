/*
 * _16bit.c
 *
 * Created: 2022-06-22 오전 10:20:08
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL		//1초에 256 >> 7372800/256 = 28800
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer1Cnt=0;

int main()
{
	
	DDRC=0x0F;
	
	TCCR1A=0x00;			//(0 << WGMn0)									 0000 0000
	TCCR1B=0x01;			//(1 << CS12)									 0000 0001
	
	TCNT1=36736;				//클럭수(28800) + TCNT값(36736) = 2의 16승
	TIMSK =0x04;			//(1 << TOIE1)					                 0000 0100
	TIFR |=1 << TOV1;
	
	sei();
	
	while(1)
	{
		
		PORTC =LED_Data;
	}
	return 0;
}
SIGNAL(TIMER1_OVF_vect)
{
	
	cli();
	
	//timer1Cnt++;
	//
	//if(timer1Cnt == 127)
	//{
		
		LED_Data++;
		
		if(LED_Data>0x0F)
		LED_Data=0;
		TCNT1=36736
		//timer1Cnt=0;
	//}
	sei();
}