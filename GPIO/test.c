/*
 * test.c
 *
 * Created: 2022-06-17 오전 11:45:11
 *  Author: PKNU
 */ 

#define  F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
					//DDR은 출력과 입력을 할지 결정
	
	DDRA =0xFF;  //portA를 출력으로 설정 0b 1111 1111 0x => 16비트 123456789ABCDEF prot => 8비트   0x0F= 입력 +출력 0xFF=출력 +출력	
	DDRB =0xFF;
	DDRC =0xFF;
	DDRD =0xFF;
	DDRE =0xFF;
	DDRF =0xFF;
	DDRG =0xFF;
	

	while(1)
	{
		
PORTA=0xFF;	//PORTA의 각 비트에 5V 출력		PORTA는 출력에만 사용
		PORTB=0xFF;
		PORTC=0xFF;
		PORTD=0xFF;
		PORTE=0xFF;
		PORTF=0xFF;
		PORTG=0xFF;
		
		_delay_ms(1000);
		
		PORTA=0x00;	//PORTA의 각 비트에 5V 출력		PORTA는 출력에만 사용
		PORTB=0x00;
		PORTC=0x00;
		PORTD=0x00;
		PORTE=0x00;
		PORTF=0x00;
		PORTG=0x00;
		
		_delay_ms(1000);
	}
	return 0;
}