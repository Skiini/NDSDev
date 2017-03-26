/*---------------------------------------------------------------------------------

	$Id: main.cpp,v 1.13 2008-12-02 20:21:20 dovoto Exp $

	Simple console print demo
	-- dovoto


---------------------------------------------------------------------------------*/
#include <nds.h>

#include <stdio.h>

//ASSETS
#include <fury.h>

enum {SCREEN_TOP = 0, SCREEN_BOTTOM = 192, SCREEN_LEFT = 0, SCREEN_RIGHT = 256};
	
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	touchPosition touchXY;

	Fury fury = {100,100};



		videoSetMode(MODE_0_2D);
		videoSetModeSub(MODE_0_2D);

		vramSetBankA(VRAM_A_MAIN_SPRITE);
		vramSetBankD(VRAM_D_SUB_SPRITE);

		oamInit(&oamMain, SpriteMapping_1D_128, false);
		oamInit(&oamSub, SpriteMapping_1D_128, false);


		initFury(&fury, (u8*)furySpriteTiles);



 
	while(1) {

		swiWaitForVBlank();
		touchRead(&touchXY);
		scanKeys();

		int keys = keysHeld();


		if(keys)
		{
			if(keys & KEY_LEFT)
			{
				fury.state = WALK;
				fury.hFlip = true;
				fury.anim_frame++;
			}
			if(keys & KEY_RIGHT)
			{
				fury.state = WALK;
				fury.hFlip = false;
				fury.anim_frame++;
			}
		}
		else
		{
			fury.state = IDLE;
			fury.anim_frame = 0;
		}

		animateFury(&fury);
		showFury(&fury);

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

	}

	return 0;
}
