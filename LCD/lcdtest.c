/*
 * lcdtest.c
 *
 * Created: 2022-06-20 오후 2:54:50
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"
int main()
{
	Byte *str1 ="LCD TEST";
	Byte *str2 ="ATmaga 128";
	DDRA=0xFF;
	DDRG=0xFF;
	
	Lcd_Init();
	_delay_ms(300);
	Lcd_Clear();
	
	while(1)
	{
		Lcd_Pos(0,0); //위치 LCD 위쪽
		Lcd_STR(str1);//
		Lcd_Pos(1,0); //위치 LCD 밑에
		Lcd_STR(str2);
	}
	return 0;
}