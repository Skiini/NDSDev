/*
 * fury.h
 *
 *  Created on: Mar 23, 2017
 *      Author: efarhan
 */

#ifndef INCLUDE_FURY_H_
#define INCLUDE_FURY_H_

#include <nds.h>
#include "furySprite.h"

enum FuryAnimState
{
	IDLE=0,
	JUMP=1,
	WALK=2
};


#define FURY_FRAMES_PER_ANIM 5

typedef struct
{
	int x;
	int y;

	u16* sprite_gfx_mem;
	u8*  frame_gfx;

	int state;
	int anim_frame;

	bool hFlip;
}Fury;



void initFury(Fury *sprite, u8* gfx);
void animateFury(Fury *sprite);
void showFury(Fury *sprite);

#endif /* INCLUDE_FURY_H_ */
