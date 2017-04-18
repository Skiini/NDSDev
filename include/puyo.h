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
#include <smallPuyoSprite.h>
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

typedef enum
{
	PUYO64=0,
	PUYO32=1
} PuyoSize;


typedef struct
{
	int x;
	int y;

	PuyoShape shape;
	PuyoColor color;
	PuyoSize size_format;

	int sprite_index;
	u16* sprite_gfx_mem;
	u8*  frame_gfx;

	int angle;
} Puyo;



void init_puyo(Puyo *puyo, int sprite_index);
void animate_puyo(Puyo *puyo);
void show_puyo(Puyo *puyo);

#endif

