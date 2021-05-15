#include "DxLib-wii.h"

#include <math.h>

//#ifndef IS_EMU
int x_offset = 80; // 80 + 480 + 80 = 640
int y_offset = 30; // 30 + 420 + 30 = 480
//#else
//int x_offset = 0; // 80 + 480 + 80 = 640
//int y_offset = 0; // 30 + 420 + 30 = 480
//#endif

extern int oto[151];
extern int sta,stb,stc,ls;

void my_callback()
{
    // VIDEO PART
    //#ifndef IS_EMU
    GRRLIB_Rectangle(0, 0, x_offset, 480, GetColor(0,0,0), 1); //LEFT BORDER
    GRRLIB_Rectangle(480+x_offset, 0, x_offset, 480, GetColor(0,0,0), 1); //RIGHTBORDER
    GRRLIB_Rectangle(0, 0, 640, y_offset, GetColor(0,0,0), 1); //TOP BORDER
    GRRLIB_Rectangle(0, 420+y_offset, 640, y_offset, GetColor(0,0,0), 1); //BOTTOM BORDER
	
	//GRRLIB_Printf(20, 20, tex_font, 0xFFFFFFFF, 1, "(%d) %d %d %d", ls, sta, stb, stc);
    //#endif
}

void debug(char* text){

	int key;
	
	while(1)
	{	
		PAD_ScanPads();
		WPAD_ScanPads();
		
		if(PAD_ButtonsDown(0) & PAD_BUTTON_START)
			break;
		
		if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)
			break;
				
		GRRLIB_Printf(240-8*20/2, 250, tex_font, 0xFFFFFFFF, 1, "TEXT: %s", text);
		GRRLIB_Render();
	}
}

void GRRLIB_Ellipse (const f32 x,  const f32 y,  const f32 radiusx, const f32 radiusy, const u32 color, const u8 filled)
{
	guVector v[36];
    u32 ncolor[36];
    u32 a;
    f32 ra;
    f32 G_DTOR = M_DTOR * 10;

    for (a = 0; a < 36; a++) {
        ra = a * G_DTOR;
        v[a].x = cos(ra) * radiusx + x + x_offset;
        v[a].y = sin(ra) * radiusy + y + y_offset;
        v[a].z = 0.0f;
        ncolor[a] = color;
    }

    if (!filled)  GRRLIB_GXEngine(v, ncolor, 36, GX_LINESTRIP);
    else          GRRLIB_GXEngine(v, ncolor, 36, GX_TRIANGLEFAN) ;
}

void DrawPixel(int a, int b, u32 color)
{
    GRRLIB_Plot(a + x_offset, b + y_offset, color);
}

void DrawLine(int a, int b, int c, int d, u32 color)
{
    GRRLIB_Line(a + x_offset, b + y_offset, c + x_offset, d + y_offset, color);
}

void DrawBox(int a, int b, int ac, int bd, u32 color, int filled)
{
    GRRLIB_Rectangle(a + x_offset, b + y_offset, ac-a, bd-b, color, filled);
}

GRRLIB_texImg* DerivationGraph(int SrcX, int SrcY, int Width, int Height, GRRLIB_texImg* SrcGraphHandle)
{
    GRRLIB_texImg* newTexture;
    
	newTexture = GRRLIB_CreateEmptyTexture(Width, Height);
	GRRLIB_CompoStart();
    GRRLIB_DrawPart(0, 0, SrcX, SrcY, Width, Height, SrcGraphHandle, 0, 1, 1, 0xFFFFFFFF);
    //GRRLIB_Screen2Texture(0, 0, newTexture, GX_TRUE);
	GRRLIB_CompoEnd(0, 0, newTexture);
	
	GRRLIB_SetHandle(newTexture,  newTexture->w/2, newTexture->h/2);
    
	return newTexture;
}

void DrawGraph(int x, int y, GRRLIB_texImg* GrHandle, int TransFlag)
{
    GRRLIB_DrawImg(x + x_offset, y + y_offset, GrHandle, 0, 1, 1, 0xFFFFFFFF);
}

void DrawTurnGraph(int x, int y, GRRLIB_texImg* GrHandle, int TransFlag)
{
    GRRLIB_DrawImg(x + x_offset, y + y_offset, GrHandle, 0, -1, 1, 0xFFFFFFFF); //Crashed once, no more
}

void drawimage(GRRLIB_texImg* mx, int a, int b)
{
	if(mirror==0)
		DrawGraph(a, b, mx, TRUE);

	if (mirror==1)
		DrawTurnGraph(a, b, mx, TRUE);
}

u32 GetColor(int r, int g, int b)
{
    return RGBA(r, g, b, 255);
}

void SetTransColor(int r, int g, int b){
}

void GetGraphSize(int grap, int* x , int* y){
}

void DrawString(int x, int y, const char *String, int Color)
{
	GRRLIB_Printf(x + x_offset, y + y_offset, tex_font, Color, 1, String);
}

int DrawFormatString(int x, int y, int Color, const char *FormatString, ... )
{
    int  size;
    char tmp[1024];

    va_list argp;
    va_start(argp, FormatString);
    size = vsprintf(tmp, FormatString, argp);
    va_end(argp);
	
	GRRLIB_Printf(x + x_offset, y + y_offset, tex_font, Color, 1, tmp);
	return 0;
}

int	ClearDrawScreen()
{
	return 0;
}

int DrawRotaGraph(int x, int y, double ExRate, double Angle, GRRLIB_texImg* GrHandle, int TransFlag)
{
    //GRRLIB_DrawImg(x + x_offset, y + y_offset, GrHandle, 0, -1, 1, 0xFFFFFFFF); //Crashed once, no more
	//GRRLIB_DrawImg(x + x_offset /* -GrHandle->w*0.5 */, y+ y_offset /* + GrHandle->h*/, GrHandle, 0, 1, -1, 0xFFFFFFFF); //TEST
    //GRRLIB_DrawImg(x + x_offset, y +y_offset, GrHandle, 180, 1, 1, 0xFFFFFFFF);
	GRRLIB_DrawImg(x + x_offset -GrHandle->w*0.5, y + y_offset - GrHandle->h*0.5, GrHandle, 0, 1, -1, 0xFFFFFFFF); //TEST
	return 0;
}

void DrawOval( int x, int y, int rx, int ry, int Color, int FillFlag)
{
	GRRLIB_Ellipse (x, y, rx, ry, Color, FillFlag);
}

void SetFontThickness(int thickness)
{
}

void SetFontSize(int size)
{
}

int ChangeFontType(int FontType)
{
	return 0;
}

void DrawString(int x, int y, const char *String, int Color, int EdgeColor)
{
	GRRLIB_Printf(x + x_offset, y + y_offset, tex_font, Color, 1, String);
}

void WaitKey()
{
	int key;
	
	while(1)
	{
		WPAD_ScanPads();
		PAD_ScanPads();
		
		if(PAD_ButtonsDown(0))
			break;

		if(WPAD_ButtonsDown(0))
			break;
		
		//GRRLIB_Render();
		//VIDEO_Flush();
        //VIDEO_WaitVSync();
	}
}

int CheckHitKey(s32 key)
{
	return 0;
	
	#ifdef IS_EMU
		if(PAD_ButtonsDown(0) && key){
			debug("CANE");
			return 1;
		}
	#else 
		if(WPAD_ButtonsDown(0) && key){
			debug("POLLO");
			return 1;
		}
	#endif
	
	return 0;
}

void WaitTimer(int i)
{
	usleep(i);
}

int GetRand(int i)
{
	return (rand()% i);
}

void DxLib_End()
{	
	exit(0);
}

int GetNowCount(){
	
	// Doesn't work but I don't care
	struct timeval tv;
	struct timezone tz;
	struct tm *tm;

	gettimeofday(&tv, &tz);
	tm=localtime(&tv.tv_sec);
	return tv.tv_usec;
	//GetTickCount();
	//return 0;
}

void ChangeVolumeSoundMem(int vol, int a){
}

int CheckSoundMem(int idx)
{
	return 0;
}

void SetCreateSoundDataType(int sound)
{
}

int LoadSoundMem(string path)
{
	return 0;
}

void StopSoundMem(int idx)
{
	StopOgg();
}

void PlaySoundMem(int SoundHandle, int PlayType)
{
	char pollo[32];
	sprintf(pollo, "Audio not found: %d!", SoundHandle);
	
	s32 freeChannel = ASND_GetFirstUnusedVoice();
	
	//if(freeChannel == 0 || freeChannel == SND_INVALID)
	//	return;
	
	if(freeChannel <= 0)
		return;
	
	if(ASND_StatusVoice(freeChannel) != SND_UNUSED)
		return;

	
	switch(SoundHandle){
		case 1:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)jump_raw, jump_raw_size, 150, 150, NULL);
			break;
		case 3:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)brokbreak_raw, brokbreak_raw_size, 150, 150, NULL);
			break;
		case 4:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)coin_raw, coin_raw_size, 150, 150, NULL);
			break;
		case 5:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)humi_raw, humi_raw_size, 150, 150, NULL);
			break;
		case 6:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)koura_raw, koura_raw_size, 150, 150, NULL);
			break;
		case 7:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)dokan_raw, dokan_raw_size, 150, 150, NULL);
			break;
		case 8:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)brockkinoko_raw, dokan_raw_size, 150, 150, NULL);
			break;
		case 9:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)powerup_raw, powerup_raw_size, 150, 150, NULL);
			break;
		case 10:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)kirra_raw, kirra_raw_size, 150, 150, NULL);
			break;
		case 11:
			PlayOgg(goal_ogg, goal_ogg_size, 0, OGG_ONE_TIME);
			break;
		case 12:
			PlayOgg(death_ogg, death_ogg_size, 0, OGG_ONE_TIME);
			break;
		case 13:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)Pswitch_raw, Pswitch_raw_size, 150, 150, NULL);
			break;
		case 14:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)jumpBlock_raw, jumpBlock_raw_size, 150, 150, NULL);
			break;
		case 15:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)hintBlock_raw, hintBlock_raw_size, 150, 150, NULL);
			break;
		case 16:
			PlayOgg(four_clear_ogg, four_clear_ogg_size, 0, OGG_ONE_TIME);
			break;
		case 17:
			PlayOgg(allclear_ogg, allclear_ogg_size, 0, OGG_ONE_TIME);
			break;
		case 18:
			ASND_SetVoice(freeChannel, VOICE_MONO_16BIT, 16000, 0, (void *)tekifire_raw, tekifire_raw_size, 150, 150, NULL);
			break;
		case 100:
			PlayOgg(field_ogg, field_ogg_size, 0, OGG_INFINITE_TIME);
			break;
		case 103:
			PlayOgg(dungeon_ogg, dungeon_ogg_size, 0, OGG_INFINITE_TIME);
			break;
		case 104:
			PlayOgg(star4_ogg, star4_ogg_size, 0, OGG_INFINITE_TIME);
			break;
		case 105:
			PlayOgg(castle_ogg, castle_ogg_size, 0, OGG_INFINITE_TIME);
			break;
		case 106:
			PlayOgg(puyo_ogg, puyo_ogg_size, 0, OGG_INFINITE_TIME);
			break;
		default:
			debug(pollo);
	}	
}