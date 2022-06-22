/*
 * PWM2.c
 *
 * Created: 2022-06-22 오후 4:59:57
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int Light =0;
volatile unsigned char Light_flag =1;

int main()
{
	
	DDRB = 0x80;	// PORTB를 출력포트 1000 1000 B7
	DDRE= 0x00;		// 입력포트 E
	
	TCCR2 =0x62;	// 0110 0010 (1 << WGM20) | (1 << COM21) | (1 << CS21)
	TCNT2 = 0x00;
	
	EICRB= 0xFF;	// 1111 1111   EICRB는 INT4~7을 사용 EICTA는 INT0~INT3사용
	EIMSK = 0xF0;	// 1111 0000   INT4~7사용 EIMSK INT7 INT6.........INT1 INT0
	EIFR = 0xF0;	// 1111 0000   INT4~7 사용      INT7 INT6.........INT1 INT0
	
	sei();			// 전체 인터럽트 사용
	
	while(1)
	{
		
		if(Light_flag)
		{
			
			OCR2= Light;		// Light 값에 따라 밝기 제어
			Light_flag =0;
		}
	}
	
}

SIGNAL(INT4_vect)
{
	
	cli();
	Light = 0;
	Light_flag =1;
	sei();
}
SIGNAL(INT5_vect)
{
	
	cli();
	Light -=51;
	if(Light < 0)
	Light = 0;
	Light_flag = 1;
	sei();
}
SIGNAL(INT6_vect)
{
	
	cli();
	Light += 51;
	if(Light >255)
	Light =255;
	Light_flag =1;
	sei();
}
SIGNAL(INT7_vect)
{
	
	cli();
	Light =255;
	Light_flag =1;
	sei();
}