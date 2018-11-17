/*
 * ENGINE_uC.c
 *
 * Created: 16.11.2018 22:13:37
 * Author : ppisk
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
//#include <avr/interrupt.h>
//#include <avr/power.h>
#include "control_hd44780.h"

void timer_init()
{
	TCCR1A|=(1<<COM1A1); //stan 1 od 0 do zdarzenia CompareMatch
	OCR1AH=0x00;
	OCR1AL=128;
	TCCR1A|=(1<<WGM10);
	TCCR1B|=(1<<WGM12); //tryb fast PWM 8-bit
	TCCR1B|=(1<<CS10); //preskaler 1
	DDRB|=(1<<PB1); //pin OC1A (PB1) jest wyjsciem
}

void engine_init()
{
	DDRC|=((1<<PC4)|(1<<PC5)); //PC4, PC5 wyjscia
	PORTC&=(0<<PC4);
	PORTC|=(1<<PC5); //wybor kierunku obrotow silnika
	timer_init();
}


//funkcja zwarca podana liczbe jako lancuch, trzeba zwolnic pamiec gdy lancuch nie jest juz potrzebny
char* uint_to_char(uint8_t val) //dodac warunek gdy nie uda sie zaalokowac pamieci
{
	char * ret_val = NULL;
	if(val == 0)
	{
		ret_val = malloc(sizeof(char)*2);
		ret_val[0]='0';
		ret_val[1]='\0';
		return ret_val;
	}
	uint8_t val2 = val;
	uint8_t counter = 0;
	while (val2 > 0) { val2 = val2 / 10; counter++; } //zlicza ilosc cyfr w liczbie
	ret_val = malloc(sizeof(char)*(counter+1));
	
	for(int i=counter-1; i>=0; --i)
	{
		ret_val[i] = (val%10)+48;
		val = val/10;
	}
	ret_val[counter]='\0';
	return ret_val;
}

void free_char(char *val)
{
	free(val);
	val = NULL;
}

int main(void)
{
	//clock_prescale_set(clock_div_1);
	DDRD&=((0<<PD2)|(0<<PD3)); //PD2, PD3 wejœcia
	PORTD|=((1<<PD2)|(1<<PD3)); //PD2, PD3 podciagniecie do Vcc
	
	uint8_t rejestrOC1A = 255;
	uint8_t rejestrOC1Anew = 255;
	char *string = NULL;
	lcd_init();
    engine_init();
	
	
	lcd_cls();
	lcd_goto(0, 0);
	lcd_puttext("Wartosc OC1A:");
	lcd_goto(0, 1);
	string = uint_to_char(rejestrOC1Anew);
	lcd_puttext(string);
	free(string);
	while (1) 
    {
		if(rejestrOC1A != rejestrOC1Anew)
		{
			lcd_cls();
			lcd_goto(0, 0);
			lcd_puttext("Wartosc OC1A:");
			lcd_goto(0, 1);
			string = uint_to_char(rejestrOC1Anew);
			lcd_puttext(string);
			free(string);
			rejestrOC1A = rejestrOC1Anew;
		}
		
		if(!(PIND & (1<<PD2)))
		{
			rejestrOC1Anew++;
			OCR1AL = rejestrOC1Anew;
			_delay_ms(80);
			while(!(PIND & (1<<PD2))) {}
			_delay_ms(80);
		}
		
		if(!(PIND & (1<<PD3)))
		{
			rejestrOC1Anew--;
			OCR1AL = rejestrOC1Anew;
			_delay_ms(80);
			while(!(PIND & (1<<PD3))) {}
			_delay_ms(80);
		}
    }
}

