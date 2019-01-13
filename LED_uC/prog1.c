void show_text(const char string[], const uint8_t cl[], int size)
{
	uint8_t bgcl = 0; //kolor tła
	
	int time = 10;
	int char_num = 16;
	int znak;


	for(int j=0; j<10; ++j) //odświerzanie 20Hz (po wykonaniu tej petli minie 0.5s)
	{
		for(int chr=char_num-1;  chr >= 0; --chr) //wyswietlanie wszystkich znaków
		{
			if (string[chr] >= 48 && string[chr] <= 90)
			znak = string[chr] - 48;
			else
			znak = 43;
				
			//wyswietlenie znaku
			for(int line=0; line<5; ++line) //ustawienie wszystkich pasków LEDu w znaku
			{
				WS2812B_reset(20); //reset
				for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
				{
					if(CHARS[znak][line][led] == true)
					WS2812B_send_iLED(COLORS[cl[chr]][0], COLORS[cl[chr]][1], COLORS[cl[chr]][2]); //ustawianie pojednyczego LEDa
					else
					WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
				}
			}
			for(int line=0; line<2; ++line) //wyswietlenie przerwy miedzy znakami 2 diod
			{
				WS2812B_reset(20); //reset
				for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
				WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
			}
				
		}
		//1 pasek biały i przerwa 7 pasków zeby w sumie bylo 120 pasków
		WS2812B_reset(20); //reset
		WS2812B_send_iLED(COLORS[15][0], COLORS[15][1], COLORS[15][2]); //ustawianie pojednyczego LEDa
		for(int line=0; line<7; ++line) //wyswietlenie przerwy miedzy znakami 2 diod
		{
			WS2812B_reset(20); //reset
			for(int led=0; led<LEDNO_USE; ++led) //ustawienie wszystkich LEDów w linii
			WS2812B_send_iLED(COLORS[bgcl][0], COLORS[bgcl][1], COLORS[bgcl][2]); //ustawianie pojednyczego LEDa
		}
	}
}