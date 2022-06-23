/*
 * motor1.c
 *
 * Created: 2022-06-23 오후 3:08:33
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	
	DDRB=0x20;					// 0010 0000 MOTOR1_EN를 출력 포트로 설정
	DDRD =0xF0;					// 1111 0000 STEP 0~STEP 3을 출력 포트로 설정
	
	PORTB &= ~0x20;				// M1 Disable, DC 모터 정지
	
	while(1)
	{
		
		PORTD =0x10;			// 1 step
		_delay_ms(500);
		PORTD =0x20;			// 2 step
		_delay_ms(500);
		PORTD =0x40;			// 3 step
		_delay_ms(500);
		PORTD = 0x80;			// 4 step
		_delay_ms(500);
	}
}