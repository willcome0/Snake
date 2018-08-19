#ifndef __SNAKE_H
#define __SNAKE_H

#include "common.h" 

#define  POINT_SIZE		4

#define  SNAKE_X_MAX	OLED_X_MAX / POINT_SIZE
#define  SNAKE_Y_MAX	OLED_Y_MAX / POINT_SIZE

#define X	0
#define Y	1

#define MAX_LENGTH	100
#define Last(_index, _x) ((_index)<(_x) ? MAX_LENGTH-(_x)+(_index) : (_index)-(_x))

extern uint32_t g_RunTime;
extern uint8_t g_PointerCoor[MAX_LENGTH][2];

extern uint8_t g_Head[2];
extern uint8_t g_NowDirect;


enum Direction
{
	TurnUp 		= 1,
	TurnDown	= 2,
	TurnLeft	= 4,
	TurnRight	= 5,
	Up		= 1,
	Down	= 2,
	Left	= 4,
	Right	= 5
};



void Snake_Turn(void);
void Snake_ShowBody(uint8_t x, uint8_t y, uint8_t mode, uint8_t length);
void Snake_DrawPoint(uint8_t x, uint8_t y, uint8_t mode);









#endif
