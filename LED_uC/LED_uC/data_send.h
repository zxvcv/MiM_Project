/*
 * data_send.h
 *
 * Created: 13.01.2019 22:05:08
 *  Author: ppisk
 */ 


#ifndef DATA_SEND_H_
#define DATA_SEND_H_

#include <avr/io.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include "colors.h" //tablica kolorow
#include "chars.h"  //tablica znakow
#include "prog1.h"  //tablica danych obrazka

#define COLORS_NUM 256
#define PICTURES_NUM 4
#define LINE_NUM 10

#define LEDNO_MAX 15 //Liczba LEDow na taœmie
#define LEDNO_USE 10 //Liczba LEDow u¿ywanych

extern const uint8_t __flash COLORS[256][3];
//extern uint8_t TIMES[1];
extern uint8_t EEMEM DATA[4][10][10];
extern const bool __flash CHARS[44][5][10];


void show_picture(uint8_t bg);


void show_text(const char string[], const uint8_t cl[], int size, int lenght, uint8_t bg)


#endif /* DATA_SEND_H_ */