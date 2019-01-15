#include "buff.h"


void buff_init(Buffer *buff, int size)
{
	buff->head = NULL;
	buff->tail = NULL;
	buff->size = size;
	buff->head = (BNode*)malloc(sizeof(BNode));
	BNode *node = buff->head;
	for (int i = 0; i < buff->size - 1; ++i)
	{
		node->next = (BNode*)malloc(sizeof(BNode));
		node = node->next;
	}
	node->next = buff->head;
	buff->tail = NULL;
}

RetVal get(Buffer *buff)
{
	RetVal ret;
	if (buff->tail == NULL)
	{
		ret.byte = 0x00;
		ret.retStatus = true;
	}
	else
	{
		ret.retStatus = false;
		ret.byte = buff->tail->byte;
		if (buff->tail == buff->head)
			buff->tail = NULL;
		else
			buff->tail = buff->tail->next;
	}
	return ret;
}

RetVal add(Buffer *buff, uint8_t val)
{
	RetVal ret;
	if (buff->tail == NULL)
	{
		buff->head->byte = val;
		buff->tail = buff->head;
		ret.retStatus = false;
	}
	else if (buff->head->next == buff->tail)
	{
		ret.retStatus = true;
	}
	else
	{
		buff->head = buff->head->next;
		buff->head->byte = val;
		ret.retStatus = false;
	}
	return ret;
}

void buff_destroy(Buffer *buff)
{
	if (buff->tail == NULL)
		return;
	BNode *node = NULL;
	while (buff->tail != buff->head)
	{
		node = buff->tail;
		buff->tail = buff->tail->next;
		free(node);
	}
	free(buff->head);
	buff->head = buff->tail = NULL;
	
}