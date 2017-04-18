/*
 * puyo.cpp
 *
 *  Created on: 16 Apr 2017
 *      Author: efarhan
 */

#include "puyo.h"




void init_puyo(Puyo *puyo, int sprite_index)
{

	puyo->sprite_index = sprite_index;


	switch (puyo->size_format)
	{
	case PUYO64:
		puyo->frame_gfx = (u8*)puyoSpriteTiles;
		puyo->sprite_gfx_mem = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);

		break;
	case PUYO32:

		puyo->frame_gfx = (u8*)smallPuyoSpriteTiles;
		puyo->sprite_gfx_mem = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

		break;
	}
}

void animate_puyo(Puyo *puyo)
{
	u8* offset;
	switch (puyo->size_format)
	{
	case PUYO64:


		offset = puyo->frame_gfx + (2*puyo->color + puyo->shape) * 64*64;
		dmaCopy(offset, puyo->sprite_gfx_mem, 64*64);
		break;
	case PUYO32:

		offset = puyo->frame_gfx + (2*puyo->color + puyo->shape) * 32 * 32;
		dmaCopy(offset, puyo->sprite_gfx_mem, 32*32);
		break;
	}
}

void show_puyo(Puyo *puyo)
{

	oamRotateScale(&oamMain, puyo->sprite_index, degreesToAngle(puyo->angle), intToFixed(1, 8), intToFixed(1, 8));
	switch (puyo->size_format)
	{
	case PUYO64:

		oamSet(&oamMain, puyo->sprite_index, puyo->x, puyo->y, 0, PUYO64, SpriteSize_64x64, SpriteColorFormat_256Color,
					puyo->sprite_gfx_mem, puyo->sprite_index, true, false, false, false, false);
		break;
	case PUYO32:

		oamSet(&oamMain, puyo->sprite_index, puyo->x, puyo->y, 0, PUYO32, SpriteSize_32x32, SpriteColorFormat_256Color,
				puyo->sprite_gfx_mem, puyo->sprite_index, true, false, false, false, false);
		break;
	}


}
