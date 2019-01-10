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
funkcja konweruj¹ca zmienn¹ liczbowa uint8_t na ³añcuch zakowy
!nale¿y zwolniæ pamiêæ przydzielon¹ t¹ funkcjê, u¿ywaj¹c funkcji "void free_char(char *)"
@param	val		wartoœæ liczbowa do przekonwertowania
@return			wskaŸnik na przydzielon¹ pamiêæ dla przekonwertowanego ³añcucha znaków
*/
char* uint_to_char(uint8_t val);

/*
funkcja usuwaj¹ca przydzielon¹ pamieæ na ³añcuch znaków
@param	val		wskaŸnik na wartosæ do usuniecia przydzielonej pamieci
*/
void free_char(char *val);

/*
funkcja wysy³aj¹ca liczbe formatu uint8_t do wyswietlenia na ekran LCD
@param	num		wartoœæ do przes³ania
@param	h		wiersz na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
@param	w		pole w wierszu na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
*/
void send_uint8(uint8_t num, int h, int w);

/*
funkcja wysy³aj¹ca tekst do wyswietlenia na ekran LCD
@param	string	wartoœæ do przes³ania
@param	h		wiersz na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
@param	w		pole w wierszu na LCD (liczony od 1 a nie od 0 jak w bibliotece hd44780)
*/
void send_text(char *string, int h, int w);

/*
funkcja wysy³aj¹ca z¹danie wyczyszczenia ekranu  LCD
*/
void send_clear();


#endif /* LCD_INTERFACE_H_ */