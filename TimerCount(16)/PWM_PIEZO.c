/*
 * PWM_PIEZO.c
 *
 * Created: 2022-06-23 오전 9:32:29
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>

// 피아노 음계에 해당하는 PWM 주파수
unsigned int DoReMi[8]={523,587,659,698,783,880,987,1046};
	
	int main()
	{
		unsigned char piano=0;
		
		DDRB=0x80;	// PWM 출력 OCR1C
		
		TCCR1A |= 0x0A;		// 0000 1010 ( 1 << COM1C1) | (1 << WGM11)
		TCCR1B |= 0x19;		// 0001 1001 ( 1 << WGM13)  | (1 << WGM12) (CS10)
		TCCR1C =0x00;
		TCNT1 = 0x0000;
		
		while(1)
		{
			
			ICR1=F_CPU/DoReMi[piano];		// 버튼에 맞는 음향을 연주 >>메인클럭
			OCR1C = ICR1/7;					// 25% 듀티비(주파수) >> 이상으로 할시 소음으로 들림
			piano++;						// piano 변수 1증가
			if(8< piano) piano =0;			// piano가 9가 되면 초기화
			_delay_ms(1000);
		}
		
	}