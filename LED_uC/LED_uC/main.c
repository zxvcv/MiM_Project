/*
 * LED_uC.c
 *
 * Created: 28.10.2018 16:59:00
 * Author : zxvcv
 
 * Changed Fusebits:
 **zmiana jednostki taktuj¹cej procesor (na oscylator kwarcowy 16MHz)
 ***LOW.SUT_CKSEL:  Ext. Full-swing Crystal; Start_up time PWRDWN/RESET: 1K CK/14CK+ 65ms
 ***                EXTFSXTAL_1KCK_14CK_65MS
 */ 

#include <avr/io.h>
#include <avr/power.h>
#include <avr/interrupt.h>

#define LED_NUM 15
#define F_CPU 16000000UL //na potrzeby debugowania tutaj


//licznik przepelnien timera który sygnalizuje czy nalezy przetwarzac tablice danych czy nie
//zwiekszany przy przepelnieniu licznika a zmniejszany po zakodowaniu i wypelnieniu danych do bufora programowego
volatile uint8_t tables_to_code_counter = 0;

//przedstawia dane ktore beda docelowo brane z jakiegos innego nosnika
volatile uint8_t tab[LED_NUM][3]={{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
								  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
								  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0}};


//_______________________

//wywiolywane po wyslaniu znaku przez nadajnik w efekcie czego zwolnilo sie miejsce w buforze USART
ISP(USART_UDRE_vect)
{
	UDR0 = byte; //Umieœæ w nim dane do wys³ania !!!!!!! tu ma byc bajt z bufora programowego
}

void place_in_progBuffor(uint8_t byte)
{
	//dodaje podany bajt do programowego bufora
}

//_______________________

//reset speed UART SPI 160k bods
static inline void uart_RESET_speed()
{
	UBRR0=49;
}

//data speed UART SPI ~2 666 666 bods
static inline void uart_DATA_speed()
{
	UBRR0=2;
}

//inicjalizacja interfejsu UART
void init_UART_MSPIM()
{
	DDRD|=_BV(PD4); //pin odpowiadaj¹cy pinowi XCK ustawiony jako wyjscie
	UCSR0C=_BV(UMSEL00)|_BV(UMSEL01)|~(_BV(UCPOL0))|_BV(UCPHA0)|~(_BV(UDORD0)); //tryb MSPIM interfejsu UART, 1 tryb emulacji SPI, transmisja od MSB
	
	//przerwania
	UCSR0B|=_BV(UDRIE0); //odblokowanie przerwania USART_UDRE_vect
	
	UCSR0B|=_BV(TXEN0); //wlaczenie nadajnika
	
	uart_DATA_speed();
}


void code_byte_for_WS2812B(uint8_t byte)
{	
	//bity 7 i 6
	uint8_t toSend = 0x00;
	if(byte & 0x80) toSend = 0b11100000; else toSend = 0b10000000;
	if(byte & 0x40) toSend |= 0b00001110; else toSend |= 0b00001000;
	place_in_progBuffor(toSend);
	
	//bity 5 i 4
	toSend = 0x00;
	if(byte & 0x20) toSend = 0b11100000; else toSend = 0b10000000;
	if(byte & 0x10) toSend |= 0b00001110; else toSend |= 0b00001000;
	place_in_progBuffor(toSend);
	
	//bity 3 i 2
	toSend = 0x00;
	if(byte & 0x08) toSend = 0b11100000; else toSend = 0b10000000;
	if(byte & 0x04) toSend |= 0b00001110; else toSend |= 0b00001000;
	place_in_progBuffor(toSend);
	
	//bity 1 i 0
	toSend = 0x00;
	if(byte & 0x02) toSend = 0b11100000; else toSend = 0b10000000;
	if(byte & 0x01) toSend |= 0b00001110; else toSend |= 0b00001000;
	place_in_progBuffor(toSend);
}

void code_line_of_LEDs()
{
	uint8_t bits_counter = 0;
	uint8_t diodes_counter = 0;
	
	for(uint8_t diodes_counter = 0; diodes_counter < LED_NUM; ++diodes_counter)
		for(uint8_t bits_counter = 0; bits_counter < 3; ++bits_counter)
			code_byte_for_WS2812B(tab[diodes_counter][bits_counter]);
	--tables_to_code_counter;
}

void send_RESET_WS2812B()
{
	uart_RESET_speed();
	while(!(UCSR0A & _BV(TXC0)));  //Zaczekaj az wszystkie dane w buforze programowym i sprzetowym UART zostana nadane
	UCSR0A|=_BV(TXC0);  //Skasuj flagê sygnalizuj¹c¹ nadanie ramki
	UDR0=0;             //Wyœlij impuls ujemny o czasie trwania >50 us
	while((UCSR0A & _BV(TXC0)) == 0);  //Zaczekaj na koniec sygna³u RESET        rownoznaczne while(!(UCSR0A & _BV(TXC0)));
	uart_DATA_speed();
}


int main(void)
{
	clock_prescale_set(clock_div_1); //zmiana czestotliwosci taktowania procesora na 16MHz (preskaler zegara = 1)
    
	init_UART_MSPIM();
	sei();
	
    while (1) 
    {
		if(tables_to_code_counter > 0)
			code_line_of_LEDs();
    }
}