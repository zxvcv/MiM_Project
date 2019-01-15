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

#include "define.h"

#include <avr/io.h>
#include <avr/power.h>
#include <stdbool.h>
#include "lib/data_send.h"


int main(void)
{
	clock_prescale_set(clock_div_1);
	
	WS2812B_init();    //Zainicjuj interfejs
	
	DDRC|=(0<<PC1);
	PORTC|=(1<<PC1);

	int size = 16;
	int length = 4;
	uint8_t bg = 0;

	//const uint8_t cl1[] = { 202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202 };
	//const uint8_t cl2[] = { 160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160 };
	//const uint8_t cl3[] = { 226,226,226,226,226,226,226,226,226,226,226,226,226,226,226,226 };
	//const uint8_t cl4[] = { 154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,154 };
	//const uint8_t cl5[] = { 22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22 };
	const uint8_t cl6[] = { 26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26 };
		
	WS2812B_reset(20);
	//wygaszanie wszystkich ledów
	for(int i=0; i<LEDNO_MAX; ++i)
	{
		WS2812B_send_iLED(0, 0, 0);
	}

	//petla glowna
	while(1)
	{
		if(PINC&(1<<PC1)) //PC1 nie zwarty do masy
		{
			show_text_SC("AVR ATMEGA328P  ", 160, size, length, bg);
			show_text_SC("MIKROKONTROLERY ", 226, size, length, bg);
			show_text_SC("I MIKROPROCESORY", 226, size, length, bg);
			show_text_SC("PROJEKT:        ", 202, size, length, bg);
			show_text_MC("WYSWIETLACZ     ", cl6, size, length, bg);
			show_text_MC("         WIDMOWY", cl6, size, length, bg);
		}
		else
			show_picture(0);
	}
}