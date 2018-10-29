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

#define LED_NUM 15
#define F_CPU 16000000UL //na potrzeby debugowania tutaj

struct data_package {
	uint8_t G;
	uint8_t R;
	uint8_t B;
};

volatile uint8_t selected_table = 0;
volatile uint8_t number_of_sent_bits = 0;
volatile uint8_t number_of_set_diodes = 0;
volatile uint8_t tab[LED_NUM][3]={{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
								  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
								  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0}};






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
	UCSR0B|=_BV(TXEN0); //wlaczenie nadajnika
	
	uart_DATA_speed();
}

//_______________________

void send_RESET_WS2812B()
{
	uart_RESET_speed();
	//...
	uart_DATA_speed();
}


int main(void)
{
	clock_prescale_set(clock_div_1); //zmiana czestotliwosci taktowania procesora na 16MHz (preskaler zegara = 1)
    
	init_UART_MSPIM();
    while (1) 
    {
		
    }
}

/*
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>

//definicja LED1 (do którego pinu pod³¹czony LED1)
#define LED1 PC5

int main(void)
{
	clock_prescale_set(clock_div_1);
	//########### I/O ###########
	DDRC  |= (1<<LED1);//Ustawienie pinu diody jako wyjœcie
	//##########################
	
	while(1)//g³ówna pêtla programu
	{
		PORTC ^=(1<<LED1); //suma modulo 2 (XOR) stanu poprzedniego na porcie
		//czyli zmiana stanu pinu LED1 na przeciwny
		_delay_ms(500);
	}
}
*/