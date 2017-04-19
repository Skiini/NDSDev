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
	int frame = 0;
	const int puyo_length = 4;
	Puyo puyo [puyo_length]= {
			{0,96, SQUARE, RED, PUYO64 },
			{124,96, SQUARE, RED, PUYO64 },
			{100,100, CIRCLE, GREEN, PUYO32 },
			{32,50, SQUARE, BLUE, PUYO32 }
	};

	consoleDemoInit();



	videoSetMode(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_SPRITE);

	vramSetBankF(VRAM_F_LCD);


	dmaCopy(puyoSpritePal, VRAM_F_EXT_SPR_PALETTE[0], puyoSpritePalLen);
	dmaCopy(smallPuyoSpritePal, VRAM_F_EXT_SPR_PALETTE[1], smallPuyoSpritePalLen);

	// set vram to ex palette
	vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);

	oamInit(&oamMain, SpriteMapping_1D_128, true);
	oamInit(&oamSub, SpriteMapping_1D_128, false);

	for(int i = 0; i<puyo_length;i++)
	{
		init_puyo(&(puyo[i]), i);
	}

	iprintf("Hello SAE Institute\n");
	iprintf("\x1b[32mNDS DEV IS AWESOME\n");
 
	while(1) {

		swiWaitForVBlank();
		touchRead(&touchXY);
		scanKeys();

		int keys = keysHeld();

		int delta_angle = 0;
		if(keys)
		{
			if(keys & KEY_LEFT)
			{
				delta_angle++;
			}
			else if(keys & KEY_RIGHT)
			{
				delta_angle--;
			}
		}

		for(int i = 0; i<puyo_length;i++)
		{
			puyo[i].angle += delta_angle;
			animate_puyo(&(puyo[i]));
		}

		for(int i = 0; i<puyo_length;i++)
		{
			show_puyo(&(puyo[i]));
		}

		iprintf("\x1b[10;0HFrame = %d",frame);
		iprintf("\x1b[16;0HTouch x = %04X, %04X\n", touchXY.rawx, touchXY.px);
		iprintf("Touch y = %04X, %04X\n", touchXY.rawy, touchXY.py);

		frame++;
		swiWaitForVBlank();
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

	}

	return 0;
}
