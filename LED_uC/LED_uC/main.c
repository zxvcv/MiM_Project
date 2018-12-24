/*
 * LED_uC.c
 *
 * Created: 28.10.2018 16:59:00
 * Author : zxvcv
 
 * Changed Fusebits:
 **zmiana jednostki taktuj¹cej procesor (na oscylator kwarcowy 16MHz)
 ***LOW.SUT_CKSEL:  Ext. Full-swing Crystal; Start_up time PWRDWN/RESET: 1K CK/14CK+ 65ms
 ***                EXTFSXTAL_1KCK_14CK_65MS
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include "buff.h"

#define LEDNO_MAX   15 //Liczba LEDow na taœmie
#define LEDNO_USE   10 //Liczba LEDow u¿ywanych



void WS2812B_init()
{
	DDRD|=_BV(PD4);     //Pin SCK jest wyjœciem - master mode
	UCSR0C=_BV(UMSEL01) | _BV(UMSEL00) | _BV(UCPHA0); // | _BV(UCPOL0); //Uart w trybie emulacji SPI
	UCSR0B=_BV(TXEN0);  //Potrzebujemy tylko MOSI
	UBRR0=2;
}

void WS2812B_UDR(uint8_t byte)
{
	while(!(UCSR0A & _BV(UDRE0)));  //Zaczekaj na miejsce w buforze
	UDR0 = byte;       //Umieœæ w nim dane do wys³ania
}

//najkrótszy reset to 20 ¿eby by³ sygna³ RESET o wystarczaj¹cej dlugosci
void WS2812B_reset(int length)
{
	for(int i=0; i<length; ++i)
		WS2812B_UDR(0x00);
}

void WS2812B_send_byte(uint8_t byte)
{
	uint8_t tmp=0x00;
	if(byte & 0x80) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x40) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wyœlij bity 7-6
	tmp=0x00;
	if(byte & 0x20) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x10) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wyœlij bity 5-4
	tmp=0x00;
	if(byte & 0x08) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x04) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wyœlij bity 3-2
	tmp=0x00;
	if(byte & 0x02) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x01) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wyœlij bity 1-0
}

void WS2812B_send_iLED(uint8_t R, uint8_t G, uint8_t B)
{
	WS2812B_send_byte(G);
	WS2812B_send_byte(R);
	WS2812B_send_byte(B);
}

//jeden transfer do 15 ledów to 180 wysylan pelnych buforów z UART
int main(void)
{
	clock_prescale_set(clock_div_1);
	WS2812B_init();    //Zainicjuj interfejs

	uint8_t colorG=255;
	uint8_t colorR=255;
	uint8_t colorB=255;

	WS2812B_reset(20);

	for(int i=0; i<LEDNO_MAX; ++i)
	{
		WS2812B_send_byte(0);
		WS2812B_send_byte(0);
		WS2812B_send_byte(0);
	}
	
	while(1)
	{
		for(int j=0; j<LEDNO_USE-1; ++j)
		{
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			for(int i=0; i<LEDNO_USE; ++i)
			{
				if(i==j)
					WS2812B_send_iLED(0, colorR, 0);
				else
					WS2812B_send_iLED(0, 0, 0);
			}
		}
		
		for(int j=LEDNO_USE-1; j>=1; --j)
		{
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			for(int i=0; i<LEDNO_USE; ++i)
			{
				if(i==j)
					WS2812B_send_iLED(0, colorR, 0);
				else
					WS2812B_send_iLED(0, 0, 0);
			}
		}
		
		for(int j=0; j<LEDNO_USE-1; ++j)
		{
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			for(int i=0; i<LEDNO_USE; ++i)
			{
				if(i==j)
					WS2812B_send_iLED(colorG, 0, 0);
				else
					WS2812B_send_iLED(0, 0, 0);
			}
		}
		
		for(int j=LEDNO_USE-1; j>=1; --j)
		{
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			for(int i=0; i<LEDNO_USE; ++i)
			{
				if(i==j)
					WS2812B_send_iLED(colorG, 0, 0);
				else
					WS2812B_send_iLED(0, 0, 0);
			}
		}
		
		for(int j=0; j<LEDNO_USE-1; ++j)
		{
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			for(int i=0; i<LEDNO_USE; ++i)
			{
				if(i==j)
					WS2812B_send_iLED(0, 0, colorB);
				else
					WS2812B_send_iLED(0, 0, 0);
			}
		}
		
		for(int j=LEDNO_USE-1; j>=1; --j)
		{
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			WS2812B_reset(180*100);
			for(int i=0; i<LEDNO_USE; ++i)
			{
				if(i==j)
					WS2812B_send_iLED(0, 0, colorB);
				else
					WS2812B_send_iLED(0, 0, 0);
			}
		}
	}
	
}