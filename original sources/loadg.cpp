#include "DxLib.h"

void end();

extern int ma,t,tt;
extern int grap[161][8],mgrap[51];
int x1;
extern int oto[151];

extern int anx[160],any[160];
extern int ne[40],nf[40];

void loadg(void){

for (t=0;t<7;t++){
mgrap[t]=0;
}

/*
for (t=0;t<161;t++){
for (tt=0;tt<8;tt++){
grap[t][tt]=0;
}}
*/

//ma-=100;//mb==5000;
//end();


//�摜�ǂݍ���

// ���ߐF��ύX
SetTransColor( 9*16+9 , 255 , 255 ) ;

//�v���C���[
mgrap[0] = LoadGraph( "res/player.png" ) ;
//�u���b�N
mgrap[1] = LoadGraph( "res/brock.png" ) ;
//�A�C�e��
mgrap[2] = LoadGraph( "res/item.png" ) ;
//�G
mgrap[3] = LoadGraph( "res/teki.png" ) ;
//�w�i
mgrap[4] = LoadGraph( "res/haikei.png" ) ;
//�u���b�N2
mgrap[5] = LoadGraph( "res/brock2.png" ) ;
//���܂�
mgrap[6] = LoadGraph( "res/omake.png" ) ;
//���܂�2
mgrap[7] = LoadGraph( "res/omake2.png" ) ;
//�^�C�g��
mgrap[30] = LoadGraph( "res/syobon3.PNG" ) ;


//�v���C���[�ǂݍ���
grap[40][0] = DerivationGraph( 0, 0, 30, 36, mgrap[0]) ;
grap[0][0] = DerivationGraph( 31*4, 0, 30, 36, mgrap[0]) ;
grap[1][0] = DerivationGraph( 31*1, 0, 30, 36, mgrap[0]) ;
grap[2][0] = DerivationGraph( 31*2, 0, 30, 36, mgrap[0]) ;
grap[3][0] = DerivationGraph( 31*3, 0, 30, 36, mgrap[0]) ;
grap[41][0] = DerivationGraph( 50, 0, 51, 73, mgrap[6]) ;

x1=1;
//�u���b�N�ǂݍ���
for (t=0;t<=6;t++){
grap[t][x1] = DerivationGraph( 33*t, 0, 30, 30, mgrap[x1]) ;
grap[t+30][x1] = DerivationGraph( 33*t, 33, 30, 30, mgrap[x1]) ;
grap[t+60][x1] = DerivationGraph( 33*t, 66, 30, 30, mgrap[x1]) ;
grap[t+90][x1] = DerivationGraph( 33*t, 99, 30, 30, mgrap[x1]) ;
}
grap[8][x1] = DerivationGraph( 33*7, 0, 30, 30, mgrap[x1]) ;
grap[16][x1] = DerivationGraph( 33*6, 0, 24, 27, mgrap[2]);
grap[10][x1] = DerivationGraph( 33*9, 0, 30, 30, mgrap[x1]) ;
grap[40][x1] = DerivationGraph( 33*9, 33, 30, 30, mgrap[x1]) ;
grap[70][x1] = DerivationGraph( 33*9, 66, 30, 30, mgrap[x1]) ;
grap[100][x1] = DerivationGraph( 33*9, 99, 30, 30, mgrap[x1]) ;
//�u���b�N�ǂݍ���2
x1=5;
for (t=0;t<=6;t++){
grap[t][x1] = DerivationGraph( 33*t, 0, 30, 30, mgrap[x1]) ;
}
grap[10][5] = DerivationGraph( 33*1, 33, 30, 30, mgrap[x1]) ;
grap[11][5] = DerivationGraph( 33*2, 33, 30, 30, mgrap[x1]) ;
grap[12][5] = DerivationGraph( 33*0, 66, 30, 30, mgrap[x1]) ;
grap[13][5] = DerivationGraph( 33*1, 66, 30, 30, mgrap[x1]) ;
grap[14][5] = DerivationGraph( 33*2, 66, 30, 30, mgrap[x1]) ;

//�A�C�e���ǂݍ���
x1=2;
for (t=0;t<=5;t++){
grap[t][x1] = DerivationGraph( 33*t, 0, 30, 30, mgrap[x1]) ;
}

//�G�L�����ǂݍ���
x1=3;
grap[0][x1] = DerivationGraph( 33*0, 0, 30, 30, mgrap[x1]) ;
grap[1][x1] = DerivationGraph( 33*1, 0, 30, 43, mgrap[x1]) ;
grap[2][x1] = DerivationGraph( 33*2, 0, 30, 30, mgrap[x1]) ;
grap[3][x1] = DerivationGraph( 33*3, 0, 30, 44, mgrap[x1]) ;
grap[4][x1] = DerivationGraph( 33*4, 0, 33, 35, mgrap[x1]);
grap[5][x1] = DerivationGraph( 0, 0, 37, 55, mgrap[7]) ;
grap[6][x1] = DerivationGraph( 38*2, 0, 36, 50, mgrap[7]);
grap[150][x1] = DerivationGraph( 38*2+37*2, 0, 36, 50, mgrap[7]);
grap[7][x1] = DerivationGraph( 33*6+1, 0, 32, 32, mgrap[x1]);
grap[8][x1] = DerivationGraph( 38*2+37*3, 0, 37, 47, mgrap[7]);
grap[151][x1] = DerivationGraph( 38*3+37*3, 0, 37, 47, mgrap[7]);
grap[9][x1] = DerivationGraph( 33*7+1, 0, 26, 30, mgrap[x1]);
grap[10][x1] = DerivationGraph( 214, 0, 46, 16, mgrap[6]);

//�������[
grap[30][x1] = DerivationGraph( 0,56, 30, 36, mgrap[7]);
grap[155][x1] = DerivationGraph( 31*3,56, 30, 36, mgrap[7]);
grap[31][x1] = DerivationGraph( 50, 74, 49, 79, mgrap[6]) ;


grap[80][x1] = DerivationGraph( 151, 31, 70, 40, mgrap[4]);
grap[81][x1] = DerivationGraph( 151, 72, 70, 40, mgrap[4]);
grap[130][x1] = DerivationGraph( 151+71, 72, 70, 40, mgrap[4]);
grap[82][x1] = DerivationGraph( 33*1, 0, 30, 30, mgrap[5]);
grap[83][x1] = DerivationGraph( 0, 0, 49, 48, mgrap[6]);
grap[84][x1] = DerivationGraph( 33*5+1, 0, 30, 30, mgrap[x1]);
grap[86][x1] = DerivationGraph( 102, 66, 49, 59, mgrap[6]);
grap[152][x1] = DerivationGraph( 152, 66, 49, 59, mgrap[6]);

grap[90][x1] = DerivationGraph( 102, 0, 64, 63, mgrap[6]);

grap[100][x1] = DerivationGraph( 33*1, 0, 30, 30, mgrap[2]) ;
grap[101][x1] = DerivationGraph( 33*7, 0, 30, 30, mgrap[2]) ;
grap[102][x1] = DerivationGraph( 33*3, 0, 30, 30, mgrap[2]) ;

//grap[104][x1] = DerivationGraph( 33*2, 0, 30, 30, mgrap[5]) ;
grap[105][x1] = DerivationGraph( 33*5, 0, 30, 30, mgrap[2]) ;
grap[110][x1] = DerivationGraph( 33*4, 0, 30, 30, mgrap[2]) ;


//�w�i�ǂݍ���
x1=4;
grap[0][x1] = DerivationGraph( 0, 0, 150, 90, mgrap[x1]) ;
grap[1][x1] = DerivationGraph( 151, 0, 65, 29, mgrap[x1]) ;
grap[2][x1] = DerivationGraph( 151, 31, 70, 40, mgrap[x1]) ;
grap[3][x1] = DerivationGraph( 0, 91, 100, 90, mgrap[x1]) ;
grap[4][x1] = DerivationGraph( 151, 113, 51, 29,mgrap[x1]) ;
grap[5][x1] = DerivationGraph( 222, 0, 28, 60,mgrap[x1]) ;
grap[6][x1] = DerivationGraph( 151, 143, 90, 40,mgrap[x1]);
grap[30][x1] = DerivationGraph( 293, 0, 149, 90, mgrap[x1]) ;
grap[31][x1] = DerivationGraph( 293, 92, 64, 29, mgrap[x1]) ;

//���ԃt���O
grap[20][x1] = DerivationGraph( 40, 182, 40, 60, mgrap[x1]) ;


//�O��
x1=5;
grap[0][x1] = DerivationGraph( 167, 0, 45, 45, mgrap[6]) ;









//�G�T�C�Y����
//int GrHandle=0;
x1=3;
for (t=0;t<=140;t++){
GetGraphSize(grap[t][x1] ,&anx[t] ,&any[t]);
anx[t]*=100;any[t]*=100;
}
anx[79]=120*100;any[79]=15*100;
anx[85]=25*100;any[85]=30*10*100;

//�w�i�T�C�Y����
x1=4;
for (t=0;t<40;t++){
GetGraphSize(grap[t][x1] ,&ne[t] ,&nf[t]);
//ne[t]*=100;nf[t]*=100;
}

/*
anx[0]=30;any[0]=30;
anx[1]=30;any[1]=43;
anx[2]=30;any[2]=30;
anx[3]=30;any[3]=44;
*/









//wav�ǂݍ���
//try{
//oto[2] = LoadSoundMem( "SE/1.wav" ) ;
SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMPRESS);
oto[100]=LoadSoundMem( "BGM/field.wav" ) ;
ChangeVolumeSoundMem(50, oto[100]);
oto[103]=LoadSoundMem( "BGM/dungeon.wav" ) ;
ChangeVolumeSoundMem(50, oto[103]);
oto[104]=LoadSoundMem( "BGM/star4.wav");
oto[105]=LoadSoundMem( "BGM/castle.wav");
ChangeVolumeSoundMem(50, oto[105]);
oto[106]=LoadSoundMem( "BGM/puyo.wav");
oto[107]=LoadSoundMem( "BGM/last.wav");
ChangeVolumeSoundMem(50, oto[107]);

SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);
oto[1] = LoadSoundMem( "SE/jump.wav" );
//oto[2] = LoadSoundMem("SE/brockcoin.wav");
oto[3] = LoadSoundMem("SE/brockbreak.wav");
oto[4] = LoadSoundMem("SE/coin.wav");
oto[5] = LoadSoundMem("SE/humi.wav");
oto[6] = LoadSoundMem("SE/koura.wav");
oto[7] = LoadSoundMem("SE/dokan.wav");
oto[8] = LoadSoundMem("SE/brockkinoko.wav");
oto[9] = LoadSoundMem("SE/powerup.wav");
oto[10] = LoadSoundMem("SE/kirra.wav");
oto[11] = LoadSoundMem("SE/goal.wav");
oto[12] = LoadSoundMem("SE/death.wav");
oto[13] = LoadSoundMem("SE/Pswitch.wav");
oto[14] = LoadSoundMem("SE/jumpBlock.wav");
oto[15] = LoadSoundMem("SE/hintBlock.wav");
oto[16] = LoadSoundMem("SE/4-clear.wav");
oto[17] = LoadSoundMem("SE/allclear.wav");
oto[18] = LoadSoundMem("SE/tekifire.wav");

//}catch( int num){end();}


x1=40;
ChangeVolumeSoundMem( 255 * x1 / 100, oto[103] ) ;


//���[�v�ݒ�-20000-20�b
//SetLoopPosSoundMem( 1,oto[104]) ;
//SetLoopSamplePosSoundMem(44100,oto[104]);
//SetLoopSamplePosSoundMem(22050,oto[104]);





}