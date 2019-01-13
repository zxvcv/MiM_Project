/*
 * prog1.h
 *
 * Created: 28.12.2018 01:08:27
 *  Author: ppisk
 */ 


#ifndef PROG1_H_
#define PROG1_H_

#include <avr/eeprom.h>

uint8_t TIMES[1] = {
						4, //  0
					};
					
//      obrazy linie ledy
uint8_t EEMEM DATA[4][10][10] = {
						 //   0    1    2    3    4    5    6    7    8    9
						{	{   0,   0,   3,   3,   3,   3,   3,   3,   0,   0 },		// 0
							{   0,   3,  11,  11,  11,  11,  11,  11,   3,   0 },		// 1
							{   3,  11,  11,  11,  11,  11,   8,  11,  11,   3 },		// 2
							{   3,  11,  11,   8,   8,  11,  11,   8,  11,   3 },		// 3
							{   3,  11,  11,  11,  11,  11,  11,   8,  11,   3 },		// 4
							{   3,  11,  11,  11,  11,  11,  11,   8,  11,   3 },		// 5
							{   3,  11,  11,   8,   8,  11,  11,   8,  11,   3 },		// 6
							{   3,  11,  11,  11,  11,  11,   8,  11,  11,   3 },		// 7
							{   0,   3,  11,  11,  11,  11,  11,  11,   3,   0 },		// 8
							{   0,   0,   3,   3,   3,   3,   3,   3,   0,   0 }		// 9
																					},		// -obraz 0
						{	{   0,   0,   3,   8,   3,   3,   3,   3,   0,   0 },		// 0
							{   0,   3,  11,   8,  11,  11,  11,  11,   3,   0 },		// 1
							{   3,  11,  11,   8,   8,  11,   8,  11,  11,   3 },		// 2
							{   3,  11,  11,   8,   8,  11,  11,   8,  11,   3 },		// 3
							{   3,  11,  11,   8,  11,  11,  11,   8,  11,   3 },		// 4
							{   3,  11,  11,   8,  11,  11,  11,   8,  11,   3 },		// 5
							{   3,  11,  11,   8,   8,  11,  11,   8,  11,   3 },		// 6
							{   3,  11,  11,   8,   8,  11,   8,  11,  11,   3 },		// 7
							{   0,   3,  11,   8,  11,  11,  11,  11,   3,   0 },		// 8
							{   0,   0,   3,   8,   3,   3,   3,   3,   0,   0 }		// 9
																					},		// -obraz 1
						{	{   0,   0,   1,   1,   1,   1,   1,   1,   0,   0 },		// 0
							{   0,   1, 175, 175, 175, 175, 175, 175,   1,   0 },		// 1
							{   1, 175, 175,   8, 175, 175, 175,   8, 175,   1 },		// 2
							{   1, 175, 175, 175,   8, 175, 175,   8, 175,   1 },		// 3
							{   1, 175, 175, 175, 175, 175, 175,   8, 175,   1 },		// 4
							{   1, 175, 175, 175, 175, 175, 175,   8, 175,   1 },		// 5
							{   1, 175, 175, 175,   8, 175, 175,   8, 175,   1 },		// 6
							{   1, 175, 175,   8, 175, 175, 175,   8, 175,   1 },		// 7
							{   0,   1, 175, 175, 175, 175, 175, 175,   1,   0 },		// 8
							{   0,   0,   1,   1,   1,   1,   1,   1,   0,   0 }		// 9
																					},		// -obraz 2
						{	{   0,   0,   2,   2,   2,   2,   2,   2,   0,   0 },		// 0
							{   0,   2,  85,  85,  85,  85,  85,  85,   2,   0 },		// 1
							{   2,  85,  85,  85,  85,  85,  85,   8,  85,   2 },		// 2
							{   2,  85,  85,   8,   8,  85,  85,   8,  85,   2 },		// 3
							{   2,  85,  85,  85,  85,  85,  85,   8,  85,   2 },		// 4
							{   2,  85,  85,  85,  85,  85,  85,   8,  85,   2 },		// 5
							{   2,  85,  85,   8,   8,  85,  85,   8,  85,   2 },		// 6
							{   2,  85,  85,  85,  85,  85,  85,   8,  85,   2 },		// 7
							{   0,   2,  85,  85,  85,  85,  85,  85,   2,   0 },		// 8
							{   0,   0,   2,   2,   2,   2,   2,   2,   0,   0 }		// 9
																					}		// -obraz 3
					};

#endif /* PROG1_H_ */