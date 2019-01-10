/*
 * ENGINE_uC.c
 *
 * Created: 16.11.2018 22:13:37
 * Author : ppisk
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "lib/lcd_interface.h"
#include "lib/inits.h"


volatile uint8_t speed = 0;		//predkoœæ obrotu glowicy odczytana przez czujnik
volatile uint8_t oldspeed = 0;	//poprzednia predkoœæ obrotu g³owicy odczytana przez czujnik

volatile uint8_t keyCount[2];	//liczniki opóŸnienia dragania styków 
volatile uint8_t keyBuffer[2];	//bufory wartoœci pinów przycików
volatile bool keyFlag[2];		//aktualne flagi przycisków
volatile bool oldkeyFlag[2];	//stare flagi przycisków

volatile uint8_t count_tim=0;	//ilosæ obrotów lizona w aktualnej sekundzie



int main(void)
{
	uint8_t rejestrOC1A = 2;	//pocz¹tkowe wartoœci wype³nienia PWM
	uint8_t rejestrOC1Anew = 1;	//
	bool pin;					//zmienne do rpzechowywania watosci PINU podczas odczytu watroœci z czujnika
	bool oldpin=1;				//
	
	init_ports();
	lcd_init();
	init_engine();
	init_timer0(); //do przyciskow
	init_timer1(); //do silnika PWM
	init_timer2(); //RTC
	sei();
	
	while (1)
	{
		//aktualizacja danych na wyœwietlaczu
		if(rejestrOC1A != rejestrOC1Anew || oldspeed != speed)// 
		{
			send_clear();
			send_text("OC1A:", 1, 1);
			send_uint8(rejestrOC1Anew, 1, 8);
			send_text("speed:", 2, 1);
			send_uint8(speed, 2, 8);
			send_text("Hz", 2, 12);
			
			oldspeed = speed;
			rejestrOC1A = rejestrOC1Anew;
		}
		
		
		//przycisk1
		if(oldkeyFlag[0] == 1 && keyFlag[0] == 0)
		{
			rejestrOC1Anew++;
			OCR1AL = rejestrOC1Anew;
		}
		oldkeyFlag[0]=keyFlag[0];
		
		
		//przycisk2
		if(oldkeyFlag[1] == 1 && keyFlag[1] == 0)
		{
			rejestrOC1Anew--;
			OCR1AL = rejestrOC1Anew;
		}
		oldkeyFlag[1]=keyFlag[1];


		//czujnik
		pin = PIND&(1<<PD2);
		if(!pin && oldpin == true && pin == false )
		{
			oldpin = pin;
			++count_tim;
		}
		else if(oldpin == false && pin == true)
			oldpin = pin;
	}
}



//------interrupts-----

ISR(TIMER0_OVF_vect)
{
	uint8_t pin = PIND;
	
	//przycisk1
	if(keyCount == 0) //jesli nie liczy
	{
		keyCount[0] = 10; //zacznij liczenie
		keyBuffer[0] = pin & (1<<PD6); //zapis stanu pinu
	}
	else
	{
		--keyCount[0];
		if( keyBuffer[0] != (pin & (1<<PD6)) ) //jesli stan pinu sie zmienil
		{
			keyCount[0] = 10; //licz od poczatku
			keyBuffer[0] = pin & (1<<PD6); //aktualizacja wartosci
		}
		else if(keyCount[0] == 0) //liczenie zakonczone
		keyFlag[0] = pin&(1<<PD6);
	}
	
	//przycisk2
	if(keyCount == 0) //jesli nie liczy
	{
		keyCount[1] = 10; //zacznij liczenie
		keyBuffer[1] = pin & (1<<PD7); //zapis stanu pinu
	}
	else
	{
		--keyCount[1];
		if( keyBuffer[1] != (pin & (1<<PD7)) ) //jesli stan pinu sie zmienil
		{
			keyCount[1] = 10; //licz od poczatku
			keyBuffer[1] = pin & (1<<PD7); //aktualizacja wartosci
		}
		else if(keyCount[1] == 0) //liczenie zakonczone
		keyFlag[1] = pin&(1<<PD7);
	}
}

ISR(TIMER2_OVF_vect)
{
	speed = count_tim;
	count_tim =0;
}