/*
 * WS2812B.c
 *
 * Created: 13.01.2019 21:53:59
 *  Author: ppisk
 */ 

#include "WS2812B.h"


void WS2812B_init()
{
	DDRD|=_BV(PD4);     //Pin SCK jest wyjœciem - master mode
	UCSR0C=_BV(UMSEL01) | _BV(UMSEL00) | _BV(UCPHA0); // | _BV(UCPOL0); //Uart w trybie emulacji SPI
	UCSR0B=_BV(TXEN0);  //Potrzebujemy tylko MOSI, Przerwania pustego rejestru danych
	UBRR0=2;
}


void WS2812B_UDR(uint8_t byte)
{
	while(!(UCSR0A & _BV(UDRE0)));  //Zaczekaj na miejsce w buforze
	UDR0 = byte;       //Umieœæ w nim dane do wys³ania
}


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