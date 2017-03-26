/*
 * fury.h
 *
 *  Created on: Mar 23, 2017
 *      Author: efarhan
 */

#ifndef INCLUDE_NORMAN_H_
#define INCLUDE_NORMAN_H_

#include <nds.h>
#include "normanSprite.h"

enum NormanAnimState
{
	IDLE=0,
	WALK=1,
	JUMP=2,

};


#define FURY_FRAMES_PER_ANIM 7

typedef struct
{
	int x;
	int y;

	u16* sprite_gfx_mem;
	u8*  frame_gfx;

	int state;
	int anim_frame;

	bool hFlip;
}Norman;



void initNorman(Norman *sprite, u8* gfx);
void animateNorman(Norman *sprite);
void showNorman(Norman *sprite);

#endif /* INCLUDE_NORMAN_H_ */
