/*
 * lcd_interface.h
 *
 * Created: 10.01.2019 00:27:13
 *  Author: ppisk
 */ 

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include <stdlib.h>
#include "control_hd44780.h"

/*
funkcja konweruj�ca zmienn� liczbowa uint8_t na �a�cuch zakowy
!nale�y zwolni� pami�� przydzielon� t� funkcj�, u�ywaj�c funkcji "void free_char(char *)"
@param	val		warto�� liczbowa do przekonwertowania
@return			wska�nik na przydzielon� pami�� dla przekonwertowanego �a�cucha znak�w
*/
char* uint_to_char(uint8_t val);

/*
funkcja usuwaj�ca przydzielon� pamie� na �a�cuch znak�w
@param	val		wska�nik na wartos� do usuniecia przydzielonej pamieci
*/
void free_char(char *val);

/*
funkcja wysy�aj�ca liczbe formatu uint8_t do wyswietlenia na ekran LCD
@param	num		warto�� do przes�ania
@param	h		wiersz na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
@param	w		pole w wierszu na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
*/
void send_uint8(uint8_t num, int h, int w);

/*
funkcja wysy�aj�ca tekst do wyswietlenia na ekran LCD
@param	string	warto�� do przes�ania
@param	h		wiersz na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
@param	w		pole w wierszu na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
*/
void send_text(char *string, int h, int w);

/*
funkcja wysy�aj�ca z�danie wyczyszczenia ekranu  LCD
*/
void send_clear();


#endif /* LCD_INTERFACE_H_ */