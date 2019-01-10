/*
 * lcd_interface.c
 *
 * Created: 10.01.2019 00:27:28
 *  Author: ppisk
 */ 
#include "lcd_interface.h"


char* uint_to_char(uint8_t val)
{
	char * ret_val = NULL;
	if(val == 0)
	{
		ret_val = malloc(sizeof(char)*2);
		ret_val[0]='0';
		ret_val[1]='\0';
		return ret_val;
	}
	
	uint8_t val2 = val;
	uint8_t counter = 0;
	while (val2 > 0) { val2 = val2 / 10; counter++; } //zlicza ilosc cyfr w liczbie
	ret_val = malloc(sizeof(char)*(counter+1));
	
	if(ret_val == NULL)
		return NULL;
		
	for(int i=counter-1; i>=0; --i)
	{
		ret_val[i] = (val%10)+48;
		val = val/10;
	}
	ret_val[counter]='\0';
	return ret_val;
}

void free_char(char *val)
{
	if( val == NULL)
		return;

	free(val);
	val = NULL;
}

void send_uint8(uint8_t num, int h, int w)
{
	char *string = uint_to_char(num);
	
	lcd_goto(w-1, h-1);
	lcd_puttext(string);
	
	free(string);
}

void send_text(char *string, int h, int w)
{
	lcd_goto(w-1, h-1);

	lcd_puttext(string);
}

void send_clear()
{
	lcd_cls();
}