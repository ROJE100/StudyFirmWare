/*
 * leftright.c
 *
 * Created: 2022-06-20 오전 11:41:50
 *  Author: PKNU
 */ 
#define F_CPU 7432800UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Time_STOP=0;

unsigned char FND_DATA_TBL []={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x08,0x80};
unsigned char cnt=0;

SIGNAL(INT4_vect)
{
	
	cli();
	Time_STOP =1;
	cnt =0;
	sei();
}
SIGNAL(INT6_vect)
{
	
	cli();
	Time_STOP =0;
	sei();
}
int main()
{
	DDRA=0xFF;
	DDRE=0x00;
	
	EICRB=0x32;		// INT4~7까지 영역  ISC40 ISC41 ISC50 ISC51 || ISC60 ISC61 ISC70 ISC81
					//					 1	    2	  4	    8 합2    1     2     4     8 합3
	EIMSK=0x50;     //					 INT4=1 INT5=2 INT6=4 INT7=8  >> INT4,INT6 >> 합 5
	EIFR=0x50;		//					 INT4=1 INT5=2 INT6=4 INT7=8  >> INT4,INT6 >> 합 5
	sei();
	
	while(1)
	{
		PORTA=FND_DATA_TBL[cnt];
		if(Time_STOP ==0)
		{
			
			cnt++;
			if(cnt>17) cnt=0;
		}
		_delay_ms(1000);
	}
	
}