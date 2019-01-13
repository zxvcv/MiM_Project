/*
 * data_send.c
 *
 * Created: 13.01.2019 22:04:58
 *  Author: ppisk
 */ 

#include "data_send.h"

void show_picture(uint8_t bg)
{
	uint8_t bgcl = bg; //kolor t³a

	for(int n=0; n<20; ++n) //odœwierzanie 20Hz (po wykonaniu tej petli minie 1s)
	{
		for(int i=0; i<PICTURES_NUM; ++i)
		{
			//matryca
			for(int j=0; j<LINE_NUM; ++j) //ustawienie wszystkich LEDów matrycy
			{
				WS2812B_reset(20); //reset
				for(int k=0; k<LEDNO_USE; ++k) //ustawienie wszystkich LEDów w linii
				{
					uint8_t val = eeprom_read_byte((*(*(DATA + i)+j)+k));
					WS2812B_send_iLED(COLORS[val][0], COLORS[val][1], COLORS[val][2]); //ustawianie pojednyczego LEDa
				}
			}
			//przerwa
			for(int j=0; j<20; ++j)
			{
				WS2812B_reset(20); //reset
				for(int k=0; k<LEDNO_USE; ++k) //ustawienie wszystkich LEDów w linii
				WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
			}
		}
	}

}

void show_text(const char string[], const uint8_t cl[], int size, int lenght, uint8_t bg)
{
	uint8_t bgcl = 0; //kolor t³a
	
	int chars_showed = 0;
	int char_num = 16;
	int znak;

	while(chars_showed < size-1)
	{
		for(int del=0; del<lenght; ++del)
		{
			for(int j=0; j<20; ++j) //odœwierzanie 20Hz (po wykonaniu tej petli minie 1s)
			{
				for(int chr=chars_showed+char_num-1;  chr >= chars_showed; --chr) //wyswietlanie wszystkich znaków
				{
					if (string[chr] >= 48 && string[chr] <= 90 && chr <= size)
					znak = string[chr] - 48;
					else
					znak = 43;
					
					//wyswietlenie znaku
					for(int line=0; line<5; ++line) //ustawienie wszystkich pasków LEDu w znaku
					{
						WS2812B_reset(20); //reset
						for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
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
						for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
						WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
					}
					
				}
				//1 pasek bia³y i przerwa 7 pasków zeby w sumie bylo 120 pasków
				WS2812B_reset(20); //reset
				for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
				WS2812B_send_iLED(COLORS[15][0], COLORS[15][1], COLORS[15][2]); //ustawianie pojednyczego LEDa
				for(int line=0; line<7; ++line) //wyswietlenie przerwy miedzy znakami 2 diod
				{
					WS2812B_reset(20); //reset
					for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
					WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
				}
			}
		}
		
		chars_showed+=char_num;
	}
}