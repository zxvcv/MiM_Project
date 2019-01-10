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
inicjalizacja port�w IO
*/
void init_ports();

/*
inicjalizacja timera0, do obslugi przycisk�w
*/
void init_timer0();

/*
inicjalizacja timera1, dzia�aj�cego tylko sprz�towo, generuj�cego sygna� PWM dla silnika DC
*/
void init_timer1();

/*
inicjalizacja timera2, do obslugi RTC
*/
void init_timer2();

/*
inicjalizacja element�w potrzebnych do obslugi silnika - porty
*/
void init_engine();


#endif /* INIT_AND_INTERRUPTS_H_ */