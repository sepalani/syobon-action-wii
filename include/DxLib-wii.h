#ifndef DXLIB_WII_H
#define DXLIB_WII_H

#include <stdio.h>
#include <stdlib.h>
#include <grrlib.h>
#include <gccore.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <wiiuse/wpad.h>

//AUDIO
#include <asndlib.h>
#include <mp3player.h>
#include "oggplayer.h"
#include <field_ogg.h>
#include <dungeon_ogg.h>
#include <star4_ogg.h>
#include <castle_ogg.h>
#include <puyo_ogg.h>
#include <death_ogg.h>
#include <goal_ogg.h>
#include <four_clear_ogg.h>
#include <allclear_ogg.h>
#include <jump_raw.h>
#include <brokbreak_raw.h>
#include <coin_raw.h>
#include <humi_raw.h>
#include <koura_raw.h>
#include <dokan_raw.h>
#include <brockkinoko_raw.h>
#include <powerup_raw.h>
#include <kirra_raw.h>
#include <hintBlock_raw.h>
#include <tekifire_raw.h>
#include <Pswitch_raw.h>
#include <jumpBlock_raw.h>
#include <coin_intro_ogg.h>

#include <iostream>

#define DX_SOUNDDATATYPE_MEMPRESS   0
#define DX_SOUNDDATATYPE_MEMNOPRESS 0
#define DX_PLAYTYPE_LOOP            0
#define DX_PLAYTYPE_BACK			0

#define DX_FONTTYPE_NORMAL 0
#define DX_FONTTYPE_EDGE   1

//#define IS_EMU

#define PAD_INPUT_LEFT		WPAD_BUTTON_DOWN
#define PAD_INPUT_RIGHT		WPAD_BUTTON_2
#define PAD_INPUT_UP		WPAD_BUTTON_LEFT
#define PAD_INPUT_DOWN		WPAD_BUTTON_RIGHT
#define KEY_INPUT_RETURN    WPAD_BUTTON_PLUS
#define KEY_INPUT_SPACE		WPAD_BUTTON_1     // turbo

#define KEY_INPUT_O         789 //WPAD_BUTTON_HOME // suicide
#define KEY_INPUT_Z			WPAD_BUTTON_A     // jump
#define KEY_INPUT_F1		123 //WPAD_BUTTON_MINUS
#define KEY_INPUT_1			456 //WPAD_BUTTON_HOME  // used button

#define byte int

using namespace std;

extern GRRLIB_texImg *tex_font;
extern int mirror;

/*
	screen size 480x420
	tile size	33x33 (but often they are 30x30 with empty bg)

	main variable -> main_
	oto			music array (> 100 is bgm, < 100 are sfx)
	mmuki		direction?
	actaon[x]	frame of the player?
	main_ = 10   game running
	main_ = 100  title screen
	nokori 		lives
	maintm		sort of frame counter (if you press space it is increased by 2)
	
*/

void my_callback();
void debug(char* text);
void GRRLIB_Ellipse (const f32 x,  const f32 y,  const f32 radiusx, const f32 radiusy, const u32 color, const u8 filled);

// GFX
int LoadGraph(string path); // was int
GRRLIB_texImg* DerivationGraph(int SrcX, int SrcY, int Width, int Height, GRRLIB_texImg* SrcGraphHandle);
void SetTransColor(int r, int g, int b);
u32 GetColor(int r, int g, int b); //DWORD
int	ClearDrawScreen();
void GetGraphSize(int grap, int* x , int* y);
int DrawRotaGraph(int x, int y, double ExRate, double Angle, GRRLIB_texImg* GrHandle, int TransFlag);
void DrawBox(int a, int b, int ac, int bd, u32 color, int filled);
void DrawOval(int x, int y, int rx, int ry, int Color, int FillFlag);
void DrawGraph(int x, int y, GRRLIB_texImg* GrHandle, int TransFlag);
void DrawTurnGraph(int x, int y, GRRLIB_texImg* GrHandle, int TransFlag);
void DrawLine(int a, int b, int c, int d, u32 color);
void DrawPixel(int x, int y, int Color);
void DrawString(int x, int y, const char *String, int Color);

// AUDIO
void SetCreateSoundDataType(int sound);
int LoadSoundMem(string path);
void ChangeVolumeSoundMem(int vol, int a);
void PlaySoundMem( int SoundHandle, int PlayType);
void StopSoundMem(int idx);
int CheckSoundMem(int idx);

// TEXT
int DrawFormatString( int x, int y, int Color, const char *FormatString, ... );
int ChangeFontType(int FontType);
void SetFontThickness(int thickness);
void SetFontSize(int size);

// OTHER
void WaitKey();
int CheckHitKey(int KeyCode);
int GetNowCount();
int CheckHitKey(int KeyCode );
void WaitTimer(int interval);
void DxLib_End();
int GetRand(int RandMax);

#endif