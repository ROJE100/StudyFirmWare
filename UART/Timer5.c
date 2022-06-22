/*
 * Timer5.c
 *
 * Created: 2022-06-21 오후 4:57:21
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char FND_DATA_TBL[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,
	0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E,
0X79,0X71,0X08,0X80};

volatile unsigned char time_s=0;				// 0.5초를 세는 변수
volatile unsigned char Time_STOP=0;				// 숫자 증가 및 정지시키는 변수

unsigned char timer0Cnt=0;

SIGNAL(TIMER2_COMP_vect)
{
	
	cli();
	OCR2 += 72;
	timer0Cnt++;
	if(timer0Cnt == 50)
	{
		
		if(Time_STOP ==0)
		{
			if(time_s >= 16)
			time_s=0;
			else
			time_s++;
		}
		timer0Cnt=0;
	}
	sei();
}
SIGNAL(INT4_vect)
{
	
	cli();
	if(Time_STOP ==0)
	Time_STOP =1;
	else
	Time_STOP = 0;
	
	sei();
}

int main()
{
	
	DDRA=0xFF;					// POTA를 출력
	DDRE=0x00;					// POTE를 입력
	TCCR2=0x05;					// 프리스케일러 1024
	OCR2=72;					// 0.01초 마다 한번씩 인터럽트 발생
	TIMSK =0x80;
	TIFR |=1 << OCF2;
	
	EICRB=0x03;					// 인터럽트 4를 상승엣지에서 동작하도록 설정
	EIMSK =0x10;				// 인터럽트 4를 허용
	EIFR=0x10;					// 인터럽트 4 플래그를 클리어
	
	sei();
	
	while(1)
	{
		PORTA=FND_DATA_TBL[time_s];	// 포트A에 FND Table 값 출력
	}
	return 0;
}
