/*
 * PWM.c
 *
 * Created: 2022-06-22 오후 4:24:23
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	
	unsigned char Light=0;
	
	DDRB= 0x10;		//PORTB 5번을 출력으로 설정
	
	TCCR0= 0x76; // (1 << WGM00) | (1 << COM01) | (1 << COM00) | (1 << CS02) (1 << CS01) (0 << CS00) 255
				
	TCNT0=0x00;
	
	while(1)
	{
		
		for(Light=0;Light<255;Light++)
		{
			
			OCR0=Light;
			_delay_ms(5);
		}
		for(Light=255;0<Light;Light--)
		{
			
			OCR0 = Light;
			_delay_ms(5);
		}
	}
}