/*
 * UART.c
 *
 * Created: 2022-06-21 오전 9:35:38
 * Author : PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>

void putch(unsigned char data){
   while((UCSR0A & 0x20) == 0);
   UDR0 = data;
   UCSR0A |= 0x20;
}

int main(void)
{
    unsigned char text[] = "Hello World\r\n";
   unsigned char i = 0;
   
   DDRE = 0xfe;
	//DDRD=0xfb;// 0B 1111 1011
   UCSR0A = 0x00;
   UCSR0B = 0x18;
   UCSR0C = 0x06;
   
   UBRR0H = 0x00;
   UBRR0L = 3;
   
    while (text[i] != '\0') 
    {
      putch(text[i++]);
    }
}
