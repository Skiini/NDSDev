/*
 * puyo.cpp
 *
 *  Created on: 16 Apr 2017
 *      Author: efarhan
 */

#include "puyo.h"




void initPuyo(Puyo *puyo, u8* gfx)
{

	puyo->sprite_gfx_mem = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);

	puyo->frame_gfx = (u8*)gfx;

	dmaCopy(puyoSpritePal, SPRITE_PALETTE, 512);

	u8* offset = puyo->frame_gfx + (2*puyo->color + puyo->shape) * 64*64;

	dmaCopy(offset, puyo->sprite_gfx_mem, 64*64);
}

void showPuyo(Puyo *puyo)
{

	oamRotateScale(&oamMain, 0, degreesToAngle(puyo->angle), intToFixed(1, 8), intToFixed(1, 8));
	oamSet(&oamMain, 0, puyo->x, puyo->y, 0, 0, SpriteSize_64x64, SpriteColorFormat_256Color,
				puyo->sprite_gfx_mem, 0, false, false, false, false, false);


}
