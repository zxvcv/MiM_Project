/*
biblioteka tworzaca i obslugujaca bufor pierscieniowy dla danych uint8_t

dodajemy na glowe, usuwany z ogona
*/

#include <avr/io.h>
//#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BNode{
	uint8_t byte;
	struct BNode *next;
} BNode;

typedef struct Buffer{
	BNode *head;
	BNode *tail;
	int size;
} Buffer;

typedef struct RetVal{
	bool retStatus;
	uint8_t byte;
} RetVal;

//funkcja inicjalizujaca bufor pierscieniowy do dzialania
void buff_init(Buffer *buff, int size);

//funkcja do pobierania warotosci z bufora
RetVal get(Buffer *buff);

//funkcja do dodawania wartosci do bufora
RetVal add(Buffer *buff, uint8_t val);

//funkcja do zwalniania pamieci zajmowanej przez bufor
void buff_destroy(Buffer *buff);


