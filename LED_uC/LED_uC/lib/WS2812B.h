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
funkcja czekajaca na wolny bufor i wpisuj¹ca do niego wartoœc gdy jest wolny
@param	byte		bajt do wys³ania, dane do wpisania do bufora UART
*/
void WS2812B_UDR(uint8_t byte);

/*
funkcja wysy³aj¹ca reset o podanej d³ugoœci
!najkrótszy reset musi trwaæ 20, a wiêc musi byc wpisana wartoœæ length >= 20
@param	length		d³ugosæ resetu
*/
void WS2812B_reset(int length);

/*
funkcja przeliczaj¹ca i wysy³aj¹ca bajt przez interfejs UART
@param	byte		bajt do wys³ania
*/
void WS2812B_send_byte(uint8_t byte);

/*
funkcja wysy³aj¹ca dena do jednego leda (wszystkie 3 kolory)
@param	R		wartoœæ okreœlaj¹ca natê¿enie œwwiat³a diody czerwonej
@param	G		wartoœæ okreœlaj¹ca natê¿enie œwwiat³a diody zielonej
@param	B		wartoœæ okreœlaj¹ca natê¿enie œwwiat³a diody niebieskiej
*/
void WS2812B_send_iLED(uint8_t R, uint8_t G, uint8_t B);


#endif /* WS2812B_H_ */