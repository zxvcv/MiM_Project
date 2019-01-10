/*
 * control_hd44780.h
 *
 * Created: 16.11.2018 22:32:00
 *  Author: ppisk
 */ 

#ifndef CONTROL_HD44780_H_
#define CONTROL_HD44780_H_

#include <stdbool.h>
#include <stdint.h>
#include "defines.h"
#include "hd44780.h"
#include <util/delay.h>

void lcd_init();

void lcd_putchar(char c);

void lcd_puttext(const char *txt);

void lcd_goto(uint8_t x, uint8_t y);

void lcd_cls();

#endif /* CONTROL_HD44780_H_ */