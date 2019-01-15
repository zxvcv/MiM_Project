/*
 * data_send.h
 *
 * Created: 13.01.2019 22:05:08
 *  Author: ppisk
 */ 


#ifndef DATA_SEND_H_
#define DATA_SEND_H_

#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include "WS2812B.h"

#include "colors.h" //tablica kolorow
#include "chars.h"  //tablica znakow
#include "prog1.h"  //tablica danych obrazka


extern const uint8_t __flash COLORS[256][3];
extern const uint8_t EEMEM DATA[4][10][10];
extern const bool __flash CHARS[44][5][10];



void show_picture(uint8_t bg);


void show_text_MC(const char string[], const uint8_t cl[], int size, int lenght, uint8_t bg);


void show_text_SC(const char string[], const uint8_t cl, int size, int lenght, uint8_t bg);


#endif /* DATA_SEND_H_ */