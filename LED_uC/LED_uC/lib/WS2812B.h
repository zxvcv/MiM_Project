/*
 * WS2812B.h
 *
 * Created: 13.01.2019 21:53:51
 *  Author: ppisk
 */ 


#ifndef WS2812B_H_
#define WS2812B_H_

#include "../define.h"
#include <avr/io.h>

/*
funkcja inicjalizujaca interfejs UART do sterowania diodami WS2812B
*/
void WS2812B_init();

/*
funkcja czekajaca na wolny bufor i wpisuj�ca do niego warto�c gdy jest wolny
@param	byte		bajt do wys�ania, dane do wpisania do bufora UART
*/
void WS2812B_UDR(uint8_t byte);

/*
funkcja wysy�aj�ca reset o podanej d�ugo�ci
!najkr�tszy reset musi trwa� 20, a wi�c musi byc wpisana warto�� length >= 20
@param	length		d�ugos� resetu
*/
void WS2812B_reset(int length);

/*
funkcja przeliczaj�ca i wysy�aj�ca bajt przez interfejs UART
@param	byte		bajt do wys�ania
*/
void WS2812B_send_byte(uint8_t byte);

/*
funkcja wysy�aj�ca dena do jednego leda (wszystkie 3 kolory)
@param	R		warto�� okre�laj�ca nat�enie �wwiat�a diody czerwonej
@param	G		warto�� okre�laj�ca nat�enie �wwiat�a diody zielonej
@param	B		warto�� okre�laj�ca nat�enie �wwiat�a diody niebieskiej
*/
void WS2812B_send_iLED(uint8_t R, uint8_t G, uint8_t B);


#endif /* WS2812B_H_ */