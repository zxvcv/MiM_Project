/*
 * init.c
 *
 * Created: 10.01.2019 00:43:46
 *  Author: ppisk
 */ 

#include "inits.h"


void init_ports()
{
	//przyciski
	DDRD&=((0<<PD6)|(0<<PD7)); //PD2, PD3 wejœcia
	PORTD|=((1<<PD6)|(1<<PD7)); //PD2, PD3 podciagniecie do Vcc
	
	//czujnik obrotów (transoptor)
	DDRD|=(0<<PD2);
	PORTD|=(1<<PD2);
}

void init_timer0()
{
	TCCR0|=(1<<CS01); //8x prescaler, przerwanie OVF(overflow) co ok 2ms
	TIMSK|=(1<<TOIE0); //odblokowanie przerwan timera 0
}

void init_timer1()
{
	TCCR1A|=(1<<COM1A1); //stan 1 od 0 do zdarzenia CompareMatch
	OCR1AH=0x00;
	OCR1AL=1;
	TCCR1A|=(1<<WGM10);
	TCCR1B|=(1<<WGM12); //tryb fast PWM 8-bit
	TCCR1B|=(1<<CS10); //preskaler 1
	DDRB|=(1<<PB1); //pin OC1A (PB1) jest wyjsciem
}

void init_timer2()
{
	ASSR|=(1<<AS2); //taktowanie asynchroniczne timera
	TCNT2=0x00;
	TCCR2=(1<<CS22) | (1<<CS20); //preskaler 128, przerwanie co 1s
	while(ASSR&0x07); //czekanie na uaktualnienie timera (trzeba przy trybie asynchronicznym)
	TIMSK|=(1<<TOIE2); //odblokowanie przerwañ timera
	
}

void init_engine()
{
	DDRC|=((1<<PC4)|(1<<PC5)); //PC4, PC5 wyjscia
	PORTC&=(0<<PC4);
	PORTC|=(1<<PC5); //wybor kierunku obrotow silnika
}