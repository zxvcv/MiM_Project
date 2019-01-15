/*
 * init.h
 *
 * Created: 10.01.2019 00:43:29
 *  Author: ppisk
 */ 

#ifndef INIT_AND_INTERRUPTS_H_
#define INIT_AND_INTERRUPTS_H_

#include <avr/io.h>

/*
inicjalizacja portów IO
*/
void init_ports();

/*
inicjalizacja timera0, do obslugi przycisków
*/
void init_timer0();

/*
inicjalizacja timera1, dzia³aj¹cego tylko sprzêtowo, generuj¹cego sygna³ PWM dla silnika DC
*/
void init_timer1();

/*
inicjalizacja timera2, do obslugi RTC
*/
void init_timer2();

/*
inicjalizacja elementów potrzebnych do obslugi silnika - porty
*/
void init_engine();


#endif /* INIT_AND_INTERRUPTS_H_ */