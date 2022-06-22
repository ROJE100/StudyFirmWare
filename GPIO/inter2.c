///*
 //* inter2.c
 //*
 //* Created: 2022-06-20 오전 10:40:21
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7432800UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//
//volatile unsigned char exchange=0;
//
//SIGNAL (INT4_vect)
//{
	//
	//exchange = ~exchange;  // exchange 0 인터텁트 실행이 1로 바뀌는 것을 다시 0으로 바꿈
//}
//
//int main()
//{
	//
	//DDRE=0x00;
	//DDRA=0xff;
	//EIMSK = 1 << INT4;
	//EICRB = (1 << ISC41) | (1 << ISC40);
	//sei();
	//
	//while(1)
	//{
		//if(exchange)
		//{
		//exchange++;
		//_delay_ms(300);
		//PORTA=exchange; 
		//}
		//
		//else PORTA=0x00;
		//
	//}
	//return 0;
//}