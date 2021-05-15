//#include "DxLib.h"
#include "DxLib-wii.h"
//#include "main.h"
#include <font_png.h>
#include <player_png.h>
#include <brock_png.h>
#include <item_png.h>
#include <teki_png.h>
#include <haikei_png.h>
#include <brock2_png.h>
#include <omake_png.h>
#include <omake2_png.h>
#include <syobon3_png.h>

void end();

extern int ma,t,tt;
GRRLIB_texImg* grap[161][8];
GRRLIB_texImg* mgrap[51];
//extern int grap[161][8],mgrap[51];
int x1;
extern int oto[151];

extern int anx[160],any[160];
//SCO extern int ne[40],nf[40];
extern int ne[],nf[];

void freeResources()
{
	int t, x1;

	for(t=0;t< 161;t++)
	{
		for(x1=0; x1<8; x1++)
			grap[t][x1] = NULL;
	}
	
	for(t=0; t<51; t++)
		mgrap[t] = NULL;
}

void loadg(void){

	//audio
	for(t=0; t<150; t++)
	{
		oto[t] = t;
	}
	
	for(t=0;t< 161;t++)
	{
		for(x1=0; x1<8; x1++)
			grap[t][x1] = NULL;
	}
	
	for(t=0; t<51; t++)
		mgrap[t] = NULL;

	SetTransColor( 9*16+9 , 255 , 255 ) ;

	tex_font = GRRLIB_LoadTexture(font_png);
    GRRLIB_InitTileSet(tex_font, 8, 16, 32);
	
	
	GRRLIB_texImg* player_texture = GRRLIB_LoadTexture(player_png);   // mgrap[0] - player_texture
	GRRLIB_texImg* brock_texture = GRRLIB_LoadTexture(brock_png);     // mgrap[1] - brock_texture
	GRRLIB_texImg* item_texture = GRRLIB_LoadTexture(item_png);       // mgrap[2] - item_texture
	GRRLIB_texImg* teki_texture = GRRLIB_LoadTexture(teki_png);       // mgrap[3] - teki_texture
	GRRLIB_texImg* haikei_texture = GRRLIB_LoadTexture(haikei_png);   // mgrap[4] - haikei_texture
	GRRLIB_texImg* brock2_texture = GRRLIB_LoadTexture(brock2_png);   // mgrap[5] - brock2_texture
	GRRLIB_texImg* omake_texture = GRRLIB_LoadTexture(omake_png) ;    // mgrap[6] - omake_texture
	GRRLIB_texImg* omake2_texture = GRRLIB_LoadTexture(omake2_png);   // mgrap[7] - omake2_texture
	mgrap[30] = GRRLIB_LoadTexture(syobon3_png); 
	
	
	grap[40][0] = DerivationGraph( 0, 0, 28, 36, player_texture);
	grap[0][0] = DerivationGraph( 28*4, 0, 28, 36, player_texture);
	grap[1][0] = DerivationGraph( 28*1, 0, 28, 36, player_texture);
	grap[2][0] = DerivationGraph( 28*2, 0, 28, 36, player_texture);
	grap[3][0] = DerivationGraph( 28*3, 0, 28, 36, player_texture);	
	grap[41][0] = DerivationGraph( 48, 0, 48, 72, omake_texture);   // BIG CAT
	
	x1=1;
	for (t=0;t<=6;t++)
	{
		grap[t][x1] =    DerivationGraph( 32*t,  0, 32, 32, brock_texture); //0-6
		grap[t+30][x1] = DerivationGraph( 32*t, 32, 32, 32, brock_texture);
		grap[t+60][x1] = DerivationGraph( 32*t, 64, 32, 32, brock_texture);
		grap[t+90][x1] = DerivationGraph( 32*t, 96, 32, 32, brock_texture);
	}
	grap[8][x1]  = DerivationGraph( 32*7, 0,  32, 32, brock_texture);
	grap[16][x1] = DerivationGraph( 32*6, 0,  32, 32, item_texture); //mgrap[2] //JUMP THING
	grap[10][x1] = DerivationGraph( 32*9, 0,  32, 32, brock_texture);
	grap[40][x1] = DerivationGraph( 32*9, 32, 32, 32, brock_texture);
	grap[70][x1] = DerivationGraph( 32*9, 64, 32, 32, brock_texture);
	grap[100][x1]= DerivationGraph( 32*9, 96, 32, 32, brock_texture);
	
	x1=5;
	for (t=0;t<=6;t++)
	{
		grap[t][x1] = DerivationGraph(32*t, 0, 32, 32, brock2_texture) ;
	}
	grap[10][5] = DerivationGraph(32*1, 32, 32, 32, brock2_texture);
	grap[11][5] = DerivationGraph(32*2, 32, 32, 32, brock2_texture);
	grap[12][5] = DerivationGraph(32*0, 64, 32, 32, brock2_texture);
	grap[13][5] = DerivationGraph(32*1, 64, 32, 32, brock2_texture);
	grap[14][5] = DerivationGraph(32*2, 64, 32, 32, brock2_texture);
	
	x1=2;
	for (t=0;t<=5;t++)
	{
		grap[t][x1] = DerivationGraph( 32*t, 0, 32, 32, item_texture);
	}
	
	x1=3;
	grap[0][x1] = DerivationGraph( 32*0, 0, 32, 44, teki_texture); anx[0] = 30; any[0] = 30;
	grap[1][x1] = DerivationGraph( 32*1, 0, 32, 44, teki_texture); anx[1] = 30; any[1] = 43;
	grap[2][x1] = DerivationGraph( 32*2, 0, 32, 44, teki_texture); anx[2] = 30; any[2] = 30;
	grap[3][x1] = DerivationGraph( 32*3, 0, 32, 44, teki_texture); anx[3] = 30; any[3] = 44;
	grap[4][x1] = DerivationGraph( 32*4, 0, 32, 44, teki_texture); anx[4] = 33; any[4] = 35;
	grap[5][x1] = DerivationGraph( 0, 0, 36, 56, omake2_texture);  anx[5] = 37; any[5] = 55;  // BIG CAT FRONT
	grap[6][x1] = DerivationGraph( 72 /*38*2*/, 0, 36, 52, omake2_texture);         anx[6] = 36; any[6] = 50;  // ROBOT 1
	grap[150][x1] = DerivationGraph( 144, /*38*2+37*2*/ 0, 36, 52, omake2_texture); // anx[150] = 36; any[150] = 50; // ROBOT ARMS UP
	
	grap[7][x1] = DerivationGraph( 32*6, 0, 32, 44, teki_texture);                  anx[7] = 32; any[7] = 32; // SNOWBALL WITH MISSLE
	grap[8][x1] = DerivationGraph( /*38*2+37*3*/180, 0, 36, 48, omake2_texture);    anx[8] = 37; any[8] = 47;// GHOST HAPPY BLUE
	grap[151][x1] = DerivationGraph( /*38*3+37*3*/ 216, 0, 36, 48, omake2_texture); //anx[151] = 37; any[151] = 47;// GHOST NO CAP
	
	grap[9][x1] = DerivationGraph( 32*7, 0, 28, 32, teki_texture);     anx[9] = 26; any[9] = 30; // FIREBALL
	grap[10][x1] = DerivationGraph( 204, 0, 48, 16, omake_texture);    anx[10] = 46; any[10] = 16; // BOWSER FIRE
	
	grap[30][x1] = DerivationGraph( 0,  56, 28, 36, omake2_texture);   anx[30] = 30; any[30] = 36;// MINICAT
	grap[155][x1]= DerivationGraph( 28, 56, 28, 36, omake2_texture);  // anx[155] = 30; any[155] = 36;// CAT DEAD
	grap[31][x1] = DerivationGraph( 48, 72, 40, 80, omake_texture);    anx[31] = 49; any[31] = 79;// CHICKEN	
	
	// HALF WAY
	grap[80][x1] = DerivationGraph( 152, 32, 72, 40, haikei_texture);  anx[80] = 70; any[80] = 40; // CLOUD mgrap[4] = haikei_texture
	grap[81][x1] = DerivationGraph( 152, 72, 72, 40, haikei_texture);  anx[81] = 70; any[81] = 40; // MAD CLOUD
	grap[130][x1] = DerivationGraph( 224, 72, 72, 40, haikei_texture); anx[130] = 70; any[130] = 40;// MAD CLOUD INVERTED
	grap[82][x1] = DerivationGraph( 32*1, 0, 32, 32, brock2_texture);  anx[82] = 30; any[82] = 30;// INFO BLOCK
	grap[83][x1]    = DerivationGraph(0,  0, 48, 48, omake_texture);   anx[83] = 49; any[83] = 48;// BLOCK WITH SPINE
	grap[84][x1] = DerivationGraph( 32*5, 0, 32, 32, teki_texture);    anx[84] = 30; any[84] = 30;// ORANGE BALL
	grap[86][x1]   = DerivationGraph(96, 64, 48, 60, omake_texture);   anx[86] = 49; any[86] = 59;// PINK BLOCK HAPPY
	grap[152][x1] = DerivationGraph(144, 64, 48, 60, omake_texture);   //anx[152] = 49; any[152] = 59;// PINK BLOCK UNHAPPY
	
	grap[90][x1] = DerivationGraph(96, 0, 64, 64, omake_texture);      anx[90] = 64; any[90] = 63;// CLOUD
	
	grap[100][x1] = DerivationGraph( 32*1, 0, 32, 32, item_texture);   anx[100] = 30; any[100] = 30;
	grap[101][x1] = DerivationGraph( 32*7, 0, 32, 32, item_texture);   anx[101] = 30; any[101] = 30;
	grap[102][x1] = DerivationGraph( 32*3, 0, 32, 32, item_texture);   anx[102] = 30; any[102] = 30;

	//grap[104][x1] = DerivationGraph( 33*2, 0, 30, 30, mgrap[5]) ;
	grap[105][x1] = DerivationGraph( 32*5, 0, 32, 32, item_texture);   anx[105] = 30; any[105] = 30;
	grap[110][x1] = DerivationGraph( 32*4, 0, 32, 32, item_texture);   anx[110] = 30; any[110] = 30;

	x1=4;
	grap[0][x1] = DerivationGraph(0,     0, 152, 92, haikei_texture); ne[0] = 150; nf[0] = 90;// HILL
	grap[1][x1] = DerivationGraph(152,   0,  68, 32, haikei_texture); ne[1] = 65; nf[1] = 29;// GRASS
	grap[2][x1] = DerivationGraph(152,  32,  72, 40, haikei_texture); ne[2] = 70; nf[2] = 40;// CLOUD
	grap[3][x1] = DerivationGraph(0,    92, 100, 92, haikei_texture); ne[3] = 100; nf[3] = 90;// CASTLE
	grap[4][x1] = DerivationGraph(152, 112,  52, 32, haikei_texture); ne[4] = 51; nf[4] = 29;// SMALL CLOUD
	grap[5][x1] = DerivationGraph(224,   0,  28, 60, haikei_texture); ne[5] = 28; nf[5] = 60;// PINE
	grap[6][x1] = DerivationGraph(152, 144,  92, 40, haikei_texture); ne[6] = 90; nf[6] = 40;// LAVA
	
	
	//grap[30][x1] = DerivationGraph(293, 0, 149, 90, haikei_texture); ne[] = ; nf[] = ;// ???????
	//grap[31][x1] = DerivationGraph(293, 92, 64, 29, haikei_texture); ne[] = ; nf[] = ;// ?????
	grap[20][x1] = DerivationGraph(44, 184, 44, 64, haikei_texture); ne[20] = 40; nf[20] = 60;// FLAG WITH SIGNS

	x1=5;
	grap[0][x1] = DerivationGraph(160, 0, 44, 44, omake_texture); // YELLOW WOOD
	
	/* END LOADING TEXTURES */
	
	x1=3;
	for (t=0;t<=140;t++)
	{
		//GetGraphSize(grap[t][x1] ,&anx[t] ,&any[t]);
		anx[t]*=100;any[t]*=100;
	}

	anx[79] = 120*100; any[79] = 15*100;
	anx[85] = 25*100; any[85] = 30*10*100;

	x1=4;
	for(t=0;t<40;t++)
	{
		//GetGraphSize(grap[t][x1] ,&ne[t] ,&nf[t]);
	}
	
	x1=40; // IMPORTANT?

	ChangeVolumeSoundMem( 255 * x1 / 100, oto[103] ) ;

}

