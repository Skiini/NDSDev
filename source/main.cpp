/*---------------------------------------------------------------------------------

	$Id: main.cpp,v 1.13 2008-12-02 20:21:20 dovoto Exp $

	Simple console print demo
	-- dovoto


---------------------------------------------------------------------------------*/
#include <nds.h>

#include <stdio.h>

//ASSETS
#include <puyo.h>

enum {SCREEN_TOP = 0, SCREEN_BOTTOM = 192, SCREEN_LEFT = 0, SCREEN_RIGHT = 256};
	
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	touchPosition touchXY;

	Puyo puyo = {100,100, CIRCLE, BLUE };



	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_SPRITE);
	vramSetBankD(VRAM_D_SUB_SPRITE);

	oamInit(&oamMain, SpriteMapping_1D_128, false);
	oamInit(&oamSub, SpriteMapping_1D_128, false);


	initPuyo(&puyo, (u8*)puyoSpriteTiles);


 
	while(1) {

		swiWaitForVBlank();
		touchRead(&touchXY);
		scanKeys();

		int keys = keysHeld();


		if(keys)
		{
			if(keys & KEY_LEFT)
			{
				puyo.angle++;
			}
			if(keys & KEY_RIGHT)
			{
				puyo.angle--;
			}
		}



		showPuyo(&puyo);

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

	}

	return 0;
}
