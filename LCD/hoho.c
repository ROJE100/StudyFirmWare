/*
 * 구구단.c
 *
 * Created: 2022-06-20 오후 4:01:46
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Lcd.h"


int main()
{
	//unsigned char arr[50] ={};
	DDRA=0xFF;
	DDRG=0x0F;
	unsigned char buf[16]={};
	
	Lcd_Init();
	
	Lcd_Clear();
	
	while(1)
	{
		for(int i=2;i<10;i++)
		{
			for(int j=1;j<10;j++)
			{
				Lcd_Clear();  //앞에 있는 쓰레기 값을 정리하는 역활
				Lcd_Pos(0,0); //위치 LCD 위쪽
				sprintf(buf,"%d * %d = %d",i,j,i*j);	
				
				Lcd_STR(buf);//
				_delay_ms(1000);
			}
		}	
	}
	return 0;
	
} 
