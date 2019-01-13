/*
 * LED_uC.c
 *
 * Created: 28.10.2018 16:59:00
 * Author : zxvcv
 
 * Changed Fusebits:
 **zmiana jednostki taktuj�cej procesor (na oscylator kwarcowy 16MHz)
 ***LOW.SUT_CKSEL:  Ext. Full-swing Crystal; Start_up time PWRDWN/RESET: 1K CK/14CK+ 65ms
 ***                EXTFSXTAL_1KCK_14CK_65MS
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/atomic.h>
#include <stdbool.h>
#include "colors.h" //tablica kolorow
#include "chars.h"  //tablica znakow
#include "prog1.h"  //tablica danych obrazka

extern const uint8_t __flash COLORS[256][3];
extern uint8_t TIMES[1];
extern uint8_t EEMEM DATA[4][10][10];
extern const bool __flash CHARS[44][5][10];

#define COLORS_NUM 256
#define PICTURES_NUM 4
#define LINE_NUM 10

#define LEDNO_MAX 15 //Liczba LEDow na ta�mie
#define LEDNO_USE 10 //Liczba LEDow u�ywanych

void WS2812B_init()
{
	DDRD|=_BV(PD4);     //Pin SCK jest wyj�ciem - master mode
	UCSR0C=_BV(UMSEL01) | _BV(UMSEL00) | _BV(UCPHA0); // | _BV(UCPOL0); //Uart w trybie emulacji SPI
	UCSR0B=_BV(TXEN0);//  //Potrzebujemy tylko MOSI, Przerwania pustego rejestru danych 
	UBRR0=2;
}

void WS2812B_UDR(uint8_t byte)
{
	while(!(UCSR0A & _BV(UDRE0)));  //Zaczekaj na miejsce w buforze
	UDR0 = byte;       //Umie�� w nim dane do wys�ania
}

//najkr�tszy reset to 0 �eby by� sygna� RESET o wystarczaj�cej dlugosci
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
	WS2812B_UDR(tmp);  //Wy�lij bity 7-6
	tmp=0x00;
	if(byte & 0x20) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x10) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 5-4
	tmp=0x00;
	if(byte & 0x08) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x04) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 3-2
	tmp=0x00;
	if(byte & 0x02) tmp=0b11100000; else tmp=0b10000000;
	if(byte & 0x01) tmp|=0b00001110; else tmp|=0b00001000;
	WS2812B_UDR(tmp);  //Wy�lij bity 1-0
}

void WS2812B_send_iLED(uint8_t R, uint8_t G, uint8_t B)
{
	WS2812B_send_byte(G);
	WS2812B_send_byte(R);
	WS2812B_send_byte(B);
}

void show_picture(uint8_t bg)
{
	uint8_t bgcl = bg; //kolor t�a

	for(int n=0; n<20; ++n) //od�wierzanie 20Hz (po wykonaniu tej petli minie 1s)
	{
		for(int i=0; i<PICTURES_NUM; ++i)
		{
			//matryca
			for(int j=0; j<LINE_NUM; ++j) //ustawienie wszystkich LED�w matrycy
			{
				WS2812B_reset(20); //reset
				for(int k=0; k<LEDNO_USE; ++k) //ustawienie wszystkich LED�w w linii
				{
					uint8_t val = eeprom_read_byte((*(*(DATA + i)+j)+k));
					WS2812B_send_iLED(COLORS[val][0], COLORS[val][1], COLORS[val][2]); //ustawianie pojednyczego LEDa
				}
			}
			//przerwa
			for(int j=0; j<20; ++j)
			{
				WS2812B_reset(20); //reset
				for(int k=0; k<LEDNO_USE; ++k) //ustawienie wszystkich LED�w w linii
					WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
			}
		}
	}

}

void show_text(const char string[], const uint8_t cl[], int size, int lenght, uint8_t bg)
{
	uint8_t bgcl = 0; //kolor t�a
	
	int chars_showed = 0;
	int char_num = 16;
	int znak;

	while(chars_showed < size-1)
	{
		for(int del=0; del<lenght; ++del)
		{
			for(int j=0; j<20; ++j) //od�wierzanie 20Hz (po wykonaniu tej petli minie 1s)
			{
				for(int chr=chars_showed+char_num-1;  chr >= chars_showed; --chr) //wyswietlanie wszystkich znak�w
				{
					if (string[chr] >= 48 && string[chr] <= 90 && chr <= size)
					znak = string[chr] - 48;
					else
					znak = 43;
					
					//wyswietlenie znaku
					for(int line=0; line<5; ++line) //ustawienie wszystkich pask�w LEDu w znaku
					{
						WS2812B_reset(20); //reset
						for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LED�w w linii
						{
							if(CHARS[znak][line][led] == true)
							WS2812B_send_iLED(COLORS[cl[chr]][0], COLORS[cl[chr]][1], COLORS[cl[chr]][2]); //ustawianie pojednyczego LEDa
							else
							WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
						}
					}
					for(int line=0; line<2; ++line) //wyswietlenie przerwy miedzy znakami 2 diod
					{
						WS2812B_reset(20); //reset
						for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LED�w w linii
						WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
					}
					
				}
				//1 pasek bia�y i przerwa 7 pask�w zeby w sumie bylo 120 pask�w
				WS2812B_reset(20); //reset
				for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LED�w w linii
				WS2812B_send_iLED(COLORS[15][0], COLORS[15][1], COLORS[15][2]); //ustawianie pojednyczego LEDa
				for(int line=0; line<7; ++line) //wyswietlenie przerwy miedzy znakami 2 diod
				{
					WS2812B_reset(20); //reset
					for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LED�w w linii
					WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
				}
			}
		}
		
		chars_showed+=char_num;
	}
}

//jeden transfer do 15 led�w to 180 wysylan pelnych bufor�w z UART
int main(void)
{
	clock_prescale_set(clock_div_1);
	
	WS2812B_init();    //Zainicjuj interfejs
	
	DDRC|=(0<<PC1);
	PORTC|=(1<<PC1);

	int size = 16;
	int length = 4;
	uint8_t bg = 0;
	//const char string[] = "POZDRAWIAM CIEPLUTKO";
	//const char string1[] = "AVR ATMEGA328P ";
	const uint8_t cl1[] = { 202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202 };
	//const char string2[] = "MIKROKONTROLERY ";
	const uint8_t cl2[] = { 160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160 };
	//const char string3[] = "I MIKROPROCESORY";
	const uint8_t cl3[] = { 226,226,226,226,226,226,226,226,226,226,226,226,226,226,226,226 };
	//const char string4[] = "PROJEKT:        ";
	const uint8_t cl4[] = { 154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,154 };
	//const char string5[] = "WYSWIETLACZ     ";
	const uint8_t cl5[] = { 22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22 };
	//const char string6[] = "WIDMOWY         ";
	const uint8_t cl6[] = { 26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26 };
		
	WS2812B_reset(20);
	//wygaszanie wszystkich led�w
	for(int i=0; i<LEDNO_MAX; ++i)
	{
		WS2812B_send_iLED(0, 0, 0);
	}

	//wyswietlanie danych
	while(1)
	{
		if(PINC&(1<<PC1)) //PC1 nie zwarty do masy
		{
			show_text("AVR ATMEGA328P  ", cl1, size, length, bg);
			show_text("MIKROKONTROLERY ", cl2, size, length, bg);
			show_text("I MIKROPROCESORY", cl3, size, length, bg);
			show_text("PROJEKT:        ", cl4, size, length, bg);
			show_text("WYSWIETLACZ     ", cl5, size, length, bg);
			show_text("WIDMOWY         ", cl6, size, length, bg);
		}
		else
			show_picture(0);
	}
}