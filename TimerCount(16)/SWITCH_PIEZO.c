﻿/*
 * SWITCH_PIEZO.c
 *
 * Created: 2022-06-23 오전 10:10:59
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned int DoReMi[8] ={523,587,659,698,783,880,987,1046};
volatile unsigned char sound_flag=1;



int main()
{
	
	DDRE=0x08;				// 포트E PE3를 출력 나머지는 입력포트로 설정한다.
							// Buzzer를 PE3에 연결
	
	TCCR3A =0x00;			// TCCR1일때는 A만 가지고 모드를 결정 TCCR2~3일때는 A,B둘다 가지고 모드를 결정
	TCCR3B=0x19;			// 0001 1001 (1 << WGM33) | (1 << WGM32) | (1 << CS30)	
	
	TCCR3C=0x00;			
	TCNT3=0x0000;
	EICRB=0xFF;				//1111 1111 INT4~7 사용 
	EIMSK=0xF0;				//1111 0000 INT4~7 사용
	EIFR=0xF0;				//1111 0000 INT4~7 사용
	sei();
	while(1)
	{
		
		_delay_ms(500);
		TCCR3A=0x00;
		sound_flag=0;
	}
}
SIGNAL(INT4_vect)
{
	
	cli();
	ICR3=F_CPU/DoReMi[0]/6;
	TCCR3A = 0x40;			// 0100 0000 (1 << COM3C0)
	sound_flag=1;
	sei();
}
SIGNAL(INT5_vect)
{
	
	cli();
	ICR3=F_CPU/DoReMi[1]/6;
	TCCR3A=0x40;			// 0000 0000 (1 << COM3C0)
	sound_flag=1;
	sei();
}
SIGNAL(INT6_vect)
{
	
	cli();
	ICR3=F_CPU/DoReMi[2]/6;
	TCCR3A= 0x40;			// 0000 0100 (1 << COM3C0)
	sound_flag=1;
	sei();
}
SIGNAL(INT7_vect)
{
	
	cli();
	ICR3=F_CPU/DoReMi[3]/6;
	TCCR3A=0x40;			// 0000 0100 (1 << COM3C0)
	sound_flag=1;
	sei();
}
