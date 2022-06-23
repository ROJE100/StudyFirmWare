/*
 * PIEZO_KEYBOARD.c
 *
 * Created: 2022-06-23 오전 11:25:37
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>

	

unsigned int DoReMi[8] ={523,587,659,698,783,880,987,1046};
	
//void putch(unsigned char data)
//{
	//while((UCSR0A & 0x20)==0);			// 전송준비가 될때까지 대기
	//UDR0 =data;							// 데이터를 UDR0에 쓰면 전송
	//UCSR0A |= 0x20;						
//}

unsigned char getch()
{
	
	unsigned char data;				
	while((UCSR0A & 0x80)==0);			// 데이타를 받을때까지 대기
	data=UDR0;							// 수신된 데이터는 UDR0에 저장
	UCSR0A |= 0x80;
	return data;						// 읽어온 문자를 반환
}

int main()
{
	
	unsigned char RX_data =0;	// 도레미를 셀 카운트
	DDRE = 0xff;
	UCSR0A =0x00;
	UCSR0B =0x18;
	UCSR0C =0x06;
	UBRR0H =0x00;
	UBRR0L =0x03;
	
	DDRB = 0x80;
	
	// COM1C(1:0)=“10”, OC1C핀사용, WGM3(1:0)=“10”
	TCCR1A |= (1 << COM1C1) | (0 << COM1C0) | (1 << WGM31) | (0 << WGM30);
	
	// WGM3(3:2)=“11”, CS3(2:0)=“001” 1분주 사용
	TCCR1B |= (1 << WGM33) | (1 << WGM32) | (0 << CS32)| (0 << CS31)| (1 << CS30);
	
	TCCR1C = 0x00;
	
	// 타이머1 카운터 초기화
	TCNT1 =  0x0000;
	ICR3=F_CPU/DoReMi[0];
	while(1)
	{
		RX_data=getch();
		
		if((RX_data >= 0x30) && (RX_data <= 0x39))			// 1~9
		{
			
			ICR3=F_CPU/DoReMi[RX_data-0x30]/8;
			TCCR3A = 0x40;
			
		}
		
		
	}
	
}