/*
 * puyo.h
 *
 *  Created on: 16 Apr 2017
 *      Author: efarhan
 */


#ifndef _PUYO_HEADER
#define _PUYO_HEADER

#include <nds.h>
#include <puyoSprite.h>
#include <physics.h>

typedef enum
{
	CIRCLE=0,
	SQUARE=1

} PuyoShape;

typedef enum
{
	GREEN=0,
	RED=1,
	BLUE=2
} PuyoColor;


typedef struct
{
	int x;
	int y;

	PuyoShape shape;
	PuyoColor color;

	u16* sprite_gfx_mem;
	u8*  frame_gfx;

	int angle;
} Puyo;



void initPuyo(Puyo *puyo, u8* gfx);
void showPuyo(Puyo *puyo);

#endif

