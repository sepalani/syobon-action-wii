#include "main.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

//��ʃT�C�Y�ݒ�
SetGraphMode( fxmax/100 , fymax/100 , 16 ) ;
//
SetWindowIconID(127);
//�ő剻�̖h�~
ChangeWindowMode(TRUE ) ;
//�^�C�g���̕ύX
SetMainWindowText( "����ڂ�̃A�N�V����" ) ;
//applog����
SetOutApplicationLogValidFlag(false);


// �c�w���C�u��������������(�G���[���N�����璼���ɏI��)
if( DxLib_Init() == -1 )return -1 ;

// �_��ł�
//DrawPixel( 320 , 240 , 0xffff ) ;

// �L�[���͑҂�
//WaitKey();


//�S���[�h
loadg();

//�t�H���g
SetFontSize(16) ;
SetFontThickness(4) ;

//���[�v
//for (maint=0;maint<=2;maint++){
while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0){

maint=0;Mainprogram();
if (maint==3)break;
}



//�c�w���C�u�����g�p�̏I������
DxLib_End() ;				

// �\�t�g�̏I�� 
return 0 ;				
}



//���C���`��
void rpaint(){

//�_�u���o�b�t�@�����O
SetDrawScreen(DX_SCREEN_BACK);

ClearDrawScreen();

setcolor(0,0,0);
//if (stagecolor==1)setcolor(170,170,255);
if (stagecolor==1)setcolor(160,180,250);
if (stagecolor==2)setcolor(10,10,10);
if (stagecolor==3)setcolor(160,180,250);
if (stagecolor==4)setcolor(10,10,10);
if (stagecolor==5){
  setcolor(160,180,250);
  mrzimen = 1;
}else{
  mrzimen = 0;
}

fillrect(0,0,fxmax,fymax);


/*
//����������
setcolor(0,0,120);

xs[1]="";
char num_str[255];
sprintf_s(num_str, sizeof(num_str),"%d",mjumptm);

xs[3]=xs[1]+num_str;
str(xs[3],10,10);
*/


if (main==1 && zxon>=1){


//�w�i
for (t=0;t<nmax;t++){
xx[0]=na[t]-fx;xx[1]=nb[t]-fy;
xx[2]=ne[ntype[t]]*100;xx[3]=nf[ntype[t]]*100;
xx[2]=16000;xx[3]=16000;

if (xx[0]+xx[2]>=-10 && xx[0]<=fxmax && xx[1]+xx[3]>=-10 && xx[3]<=fymax){

if (ntype[t]!=3){
  if((ntype[t]==1 || ntype[t]==2) && stagecolor==5){
    drawimage(grap[ntype[t]+30][4],xx[0]/100,xx[1]/100);
  }else{
    drawimage(grap[ntype[t]][4],xx[0]/100,xx[1]/100);
  }
}
if (ntype[t]==3)
drawimage(grap[ntype[t]][4],xx[0]/100-5,xx[1]/100);

//51
if (ntype[t]==100){
DrawFormatString(xx[0]/100+fma,xx[1]/100+fmb,GetColor(255,255,255),"51");
}

if (ntype[t]==101)
DrawFormatString(xx[0]/100+fma,xx[1]/100+fmb,GetColor(255,255,255),"�Q�[���N���A�[");
if (ntype[t]==102)
DrawFormatString(xx[0]/100+fma,xx[1]/100+fmb,GetColor(255,255,255),"�v���C���Ă���Ă��肪�Ɓ[");

}}//t



//�O��
for (t=0;t<emax;t++){
xx[0]=ea[t]-fx;xx[1]=eb[t]-fy;
xx[2]=enobia[t]/100;xx[3]=enobib[t]/100;
if (xx[0]+xx[2]*100>=-10 && xx[1]<=fxmax && xx[1]+xx[3]*100>=-10-8000 && xx[3]<=fymax){

//�R�C��
if (egtype[t]==0)
drawimage(grap[0][2],xx[0]/100,xx[1]/100);

//�u���b�N�̔j��
if (egtype[t]==1){
if (stagecolor==1 || stagecolor==3 || stagecolor==5)setcolor(9*16,6*16,3*16);
if (stagecolor==2)setcolor(0,120,160);
if (stagecolor==4)setcolor(192,192,192);

fillarc(xx[0]/100,xx[1]/100,7,7);
setcolor(0,0,0);
drawarc(xx[0]/100,xx[1]/100,7,7);
}

//���t�g�̔j��
if (egtype[t]==2 || egtype[t]==3){
if (egtype[t]==3)mirror=1;
drawimage(grap[0][5],xx[0]/100,xx[1]/100);
mirror=0;
}

//�|�[��
if (egtype[t]==4){
setc1();
fillrect((xx[0])/100+10,(xx[1])/100, 10, xx[3]);
setc0();
drawrect((xx[0])/100+10,(xx[1])/100, 10, xx[3]);
setcolor(250,250,0);
fillarc((xx[0])/100+15-1,(xx[1])/100,10,10);
setc0();
drawarc((xx[0])/100+15-1,(xx[1])/100,10,10);
}//4

//if (egtype[t]==1){
//drawimage(image[0],xx[0]/100+fma+5,xx[1]/100+fmb+5,0,0,10,10);
//��������
//drawimage(image[2],xx[0]/100+fma,xx[1]/100+fmb,0,0,20,20);
//}
//if (egtype[t]==2)
//drawimage(image[11],xx[0]/100+fma,xx[1]/100+fmb,0,0,25,16);


}
/*
//
if (egtype[t]==100){
for (t3=0;t3<=2;t3++){ 
setcolor(60,60,60);
if (t3==2)setcolor(250,250,250);
t2=t3*2;if (t2==4)t2=1;
//str("�X�e�[�W  �N���A�[",xx[0]/100+t2+fx/100,xx[1]/100+t2+fy/100);
str("�X�e�[�W  �N���A�[",60+t2,90+t2);
}
}//100
*/
}






//���t�g
for (t=0;t<srmax;t++){
xx[0]=sra[t]-fx;xx[1]=srb[t]-fy;
if (xx[0]+src[t]>=-10 && xx[1]<=fxmax+12100 && src[t]/100>=1){
xx[2]=14;if (srsp[t]==1){xx[2]=12;}

if (srsp[t]<=9 || srsp[t]>=20){
setcolor(220,220,0);
if (srsp[t]==2 || srsp[t]==3){setcolor(0,220,0);}
if (srsp[t]==21){setcolor(180,180,180);}
fillrect((sra[t]-fx)/100,(srb[t]-fy)/100,src[t]/100,xx[2]);

setcolor(180,180,0);
if (srsp[t]==2 || srsp[t]==3){setcolor(0,180,0);}
if (srsp[t]==21){setcolor(150,150,150);}
drawrect((sra[t]-fx)/100,(srb[t]-fy)/100,src[t]/100,xx[2]);
}
else if (srsp[t]<=14){
if (src[t]>=5000){
setcolor(0,200,0);
fillrect((sra[t]-fx)/100,(srb[t]-fy)/100,src[t]/100,30);
setcolor(0,160,0);
drawrect((sra[t]-fx)/100,(srb[t]-fy)/100,src[t]/100,30);

setcolor(180,120,60);
fillrect((sra[t]-fx)/100+20,(srb[t]-fy)/100+30,src[t]/100-40,480);
setcolor(100,80,20);
drawrect((sra[t]-fx)/100+20,(srb[t]-fy)/100+30,src[t]/100-40,480);

}}
if (srsp[t]==15){
for (t2=0;t2<=2;t2++){
xx[6]=1+0;drawimage(grap[xx[6]][1],(sra[t]-fx)/100+t2*29,(srb[t]-fy)/100);
}
}//15



/*
if (srtype[t]==0){
setc1();
if (srgtype[t]==0){setcolor(200,120,0);}
if (srgtype[t]==1){setcolor(40,40,240);}
if (srgtype[t]>=2 && srgtype[t]<=6)setcolor(240,240,40);
if (srgtype[t]==7)setcolor(0,240,0);
fillrect(xx[0]/100+fma,xx[1]/100+fmb, src[t]/100, srd[t]/100);
setc0();
if (srgtype[t]==0){setcolor(160,80,0);}
if (srgtype[t]==1){setcolor(0,0,200);}
if (srgtype[t]>=2 && srgtype[t]<=6)setcolor(200,200,0);
if (srgtype[t]==7)setcolor(0,210,0);
drawrect(xx[0]/100+fma,xx[1]/100+0+fmb, src[t]/100, srd[t]/100);
}}

//(�g�Q)
if (srtype[t]==1 || srtype[t]==2){
if (srtype[t]==2)setre2();
//drawimage(image[6],xx[0]/100+fma,xx[1]/100+fmb,0,0,src[t]/100, srd[t]/100+2);

xx[20]=2000;
for (tt=0;tt<=src[t]/xx[20];tt++){
xx[6]=xx[20]/100;xx[7]=xx[20]/100;if (src[t]/xx[20]==tt){xx[7]=(src[t]%xx[20])/100;}
if (xx[6]<=0)xx[6]=1;if (xx[7]<=0)xx[7]=1;
//drawimage(im[0],xx[0]/100+fma+tt*(xx[6]),xx[1]/100+fmb,5,0,xx[7],10);
drawimage(image[6],xx[0]/100+fma+tt*(xx[6]),xx[1]/100+fmb,0,0,xx[7], srd[t]/100+2);
}

*/
}
//t=xx[21];//if (xx[22]>spmax)t=spmax+1;

//setno();
}//t












//�v���C���[�`��
setcolor(0,0,255);
//mirror=1;

if (mactp>=2000){mactp-=2000;if (mact==0){mact=1;}else{mact=0;}}
if (mmuki==0)mirror=1;

if (mtype!=200 && mtype!=1){
if (mzimen==1){
// �ǂ݂��񂾃O���t�B�b�N���g��`��
//DrawExtendGraph(ma/100,mb/100,ma/100+100,mb/100+100,grap[0][0], TRUE ) ;
if (mact==0)drawimage(grap[0][0],ma/100,mb/100);
if (mact==1)drawimage(grap[1][0],ma/100,mb/100);
}
if (mzimen==0){
drawimage(grap[2][0],ma/100,mb/100);
}
}
//���剻
else if (mtype==1){
drawimage(grap[41][0],ma/100,mb/100);
}

else if (mtype==200){
drawimage(grap[3][0],ma/100,mb/100);
}

mirror=0;

//drawrect(ma/100,mb/100,30,36);


//g.setFlipMode(Graphics.FLIP_NONE);
//}//muteki




//for (t=0;t<bmax;t++){DrawFormatString((ba[t]-fx)/100+40,(bb[t]-fy)/100,GetColor(250,250,250),"%d",t);}

//�G�L����
for (t=0;t<amax;t++){

xx[0]=aa[t]-fx;xx[1]=ab[t]-fy;
xx[2]=anobia[t]/100;xx[3]=anobib[t]/100;xx[14]=3000;xx[16]=0;
if (xx[0]+xx[2]*100>=-10-xx[14] && xx[1]<=fxmax+xx[14] && xx[1]+xx[3]*100>=-10 && xx[3]<=fymax){
//if (atype[t]>=100)amuki[t]=0;
if (amuki[t]==1){mirror=1;}
if (atype[t]==3 && axtype[t]==1){DrawRotaGraph(xx[0]/100+13,xx[1]/100+15, 1.0f ,pai/ 1 , grap[atype[t]][3], TRUE ) ;xx[16]=1;}
if (atype[t]==9 && ad[t]>=1){DrawRotaGraph(xx[0]/100+13,xx[1]/100+15, 1.0f ,pai/ 1 , grap[atype[t]][3], TRUE ) ;xx[16]=1;}
if (atype[t]>=100 && amuki[t]==1)mirror=0;

//tekikaki(atype[t]);

//if (atype[t]>=100)
//drawrect(xx[0]/100,xx[1]/100,30,30);


//DrawFormatString(xx[0]/100+40,xx[1]/100,GetColor(0,0,0),"%d",axzimen[t]);
//drawstring(grap[atype[t]][3],xx[0]/100,xx[1]/100);


//���C��
if (atype[t]<200 && xx[16]==0 && atype[t]!=6 && atype[t]!=79 && atype[t]!=86 && atype[t]!=30){
if (!((atype[t]==80 || atype[t]==81) && axtype[t]==1)){
drawimage(grap[atype[t]][3],xx[0]/100,xx[1]/100);
}}


//�f�t���O����
if (atype[t]==6){
if (atm[t]>=10 && atm[t]<=19 || atm[t]>=100 && atm[t]<=119 || atm[t]>=200){
drawimage(grap[150][3],xx[0]/100,xx[1]/100);
}else{
drawimage(grap[6][3],xx[0]/100,xx[1]/100);
}
}

//�������[
if (atype[t]==30){
if (axtype[t]==0)drawimage(grap[30][3],xx[0]/100,xx[1]/100);
if (axtype[t]==1)drawimage(grap[155][3],xx[0]/100,xx[1]/100);
}



//�X�e���X�_
if ((atype[t]==81) && axtype[t]==1){
drawimage(grap[130][3],xx[0]/100,xx[1]/100);
}

if (atype[t]==79){
setcolor(250,250,0);
fillrect(xx[0]/100,xx[1]/100,xx[2],xx[3]);
setc0();
drawrect(xx[0]/100,xx[1]/100,xx[2],xx[3]);
}

if (atype[t]==82){

if (axtype[t]==0){
xx[9]=0;if (stagecolor==2){xx[9]=30;}
if (stagecolor==4){xx[9]=60;}
if (stagecolor==5){xx[9]=90;}
xx[6]=5+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

if (axtype[t]==1){
xx[9]=0;if (stagecolor==2){xx[9]=30;}
if (stagecolor==4){xx[9]=60;}
if (stagecolor==5){xx[9]=90;}
xx[6]=4+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

if (axtype[t]==2){
drawimage(grap[1][5],xx[0]/100,xx[1]/100);
}

}
if (atype[t]==83){

if (axtype[t]==0){
xx[9]=0;if (stagecolor==2){xx[9]=30;}
if (stagecolor==4){xx[9]=60;}
if (stagecolor==5){xx[9]=90;}
xx[6]=5+xx[9];drawimage(grap[xx[6]][1],xx[0]/100+10,xx[1]/100+9);
}

if (axtype[t]==1){
xx[9]=0;if (stagecolor==2){xx[9]=30;}
if (stagecolor==4){xx[9]=60;}
if (stagecolor==5){xx[9]=90;}
xx[6]=4+xx[9];drawimage(grap[xx[6]][1],xx[0]/100+10,xx[1]/100+9);
}

}

//�U�|�[��
if (atype[t]==85){
setc1();
fillrect((xx[0])/100+10,(xx[1])/100, 10, xx[3]);
setc0();
drawrect((xx[0])/100+10,(xx[1])/100, 10, xx[3]);
setcolor(0,250,200);
fillarc((xx[0])/100+15-1,(xx[1])/100,10,10);
setc0();
drawarc((xx[0])/100+15-1,(xx[1])/100,10,10);

}//85


//�j���b�X��
if (atype[t]==86){
if (ma>=aa[t]-fx-mnobia-4000 && ma<=aa[t]-fx+anobia[t]+4000){
drawimage(grap[152][3],xx[0]/100,xx[1]/100);
}
else{
drawimage(grap[86][3],xx[0]/100,xx[1]/100);
}}




if (atype[t]==200)
drawimage(grap[0][3],xx[0]/100,xx[1]/100);


mirror=0;

}}



//�u���b�N�`��
for (t=0;t<tmax;t++){
xx[0]=ta[t]-fx;xx[1]=tb[t]-fy;
xx[2]=32;xx[3]=xx[2];
if (xx[0]+xx[2]*100>=-10 && xx[1]<=fxmax){

xx[9]=0;
if (stagecolor==2){xx[9]=30;}
if (stagecolor==4){xx[9]=60;}
if (stagecolor==5){xx[9]=90;}

if (ttype[t]<100){
xx[6]=ttype[t]+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

if(txtype[t] != 10){

if (ttype[t]==100 || ttype[t]==101 || ttype[t]==102 || ttype[t]==103 ||  ttype[t]==104 && txtype[t]==1 || ttype[t]==114 && txtype[t]==1 || ttype[t]==116){
xx[6]=2+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

if (ttype[t]==112 || ttype[t]==104 && txtype[t]==0 || ttype[t]==115 && txtype[t]==1){
xx[6]=1+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

if (ttype[t]==111 || ttype[t]==113 || ttype[t]==115 && txtype[t]==0 || ttype[t]==124){
xx[6]=3+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

}

if (ttype[t]==117 && txtype[t]==1){
drawimage(grap[4][5],xx[0]/100,xx[1]/100);
}

if (ttype[t]==117 && txtype[t]>=3){
drawimage(grap[3][5],xx[0]/100,xx[1]/100);
}

if (ttype[t]==115 && txtype[t]==3){
xx[6]=1+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
//xx[6]=5+xx[9];drawimage(grap[xx[6]][1],xx[0]/100,xx[1]/100);
}

//�W�����v��
if (ttype[t]==120 && txtype[t]!=1){
drawimage(grap[16][1],xx[0]/100+3,xx[1]/100+2);
}

//ON-OFF
if (ttype[t]==130)drawimage(grap[10][5],xx[0]/100,xx[1]/100);
if (ttype[t]==131)drawimage(grap[11][5],xx[0]/100,xx[1]/100);

if (ttype[t]==140)drawimage(grap[12][5],xx[0]/100,xx[1]/100);
if (ttype[t]==141)drawimage(grap[13][5],xx[0]/100,xx[1]/100);
if (ttype[t]==142)drawimage(grap[14][5],xx[0]/100,xx[1]/100);


if (ttype[t]==300 || ttype[t]==301)
drawimage(grap[1][5],xx[0]/100,xx[1]/100);

//P�X�C�b�`
if (ttype[t]==400){drawimage(grap[2][5],xx[0]/100,xx[1]/100);}

//�R�C��
if (ttype[t]==800){drawimage(grap[0][2],xx[0]/100+2,xx[1]/100+1);}

//if (stagecolor==1)t-=30;
}}










//�n��(��)//�y�ǂ�
for (t=0;t<smax;t++){
if (sa[t]-fx+sc[t]>=-10 && sa[t]-fx<=fxmax+1100){

if (stype[t]==0){
setcolor(40,200,40);
fillrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, sc[t]/100, sd[t]/100);
drawrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, sc[t]/100, sd[t]/100);
}
//�y��
if (stype[t]==1){
setcolor(0,230,0);
fillrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, sc[t]/100, sd[t]/100);
setc0();
drawrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, sc[t]/100, sd[t]/100);
}
//�y��(��)
if (stype[t]==2){
setcolor(0,230,0);
fillrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+1, sc[t]/100, sd[t]/100);
setc0();
drawline((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, (sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+sd[t]/100);
drawline((sa[t]-fx)/100+fma+sc[t]/100,(sb[t]-fy)/100+fmb, (sa[t]-fx)/100+fma+sc[t]/100,(sb[t]-fy)/100+fmb+sd[t]/100);
}

//�y��(��)
if (stype[t]==5){
setcolor(0,230,0);
fillrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+1, sc[t]/100, sd[t]/100);
setc0();
drawline((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, (sa[t]-fx)/100+fma+sc[t]/100,(sb[t]-fy)/100+fmb);
drawline((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+sd[t]/100, (sa[t]-fx)/100+fma+sc[t]/100,(sb[t]-fy)/100+fmb+sd[t]/100);
}


//�����Ă���u���b�N
if (stype[t]==51){
if (sxtype[t]==0){
for (t3=0;t3<=sc[t]/3000;t3++){
drawimage(grap[1][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb);
}}
if (sxtype[t]==1 || sxtype[t]==2){
for (t3=0;t3<=sc[t]/3000;t3++){
drawimage(grap[31][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb);
}}
if (sxtype[t]==3 || sxtype[t]==4){
for (t3=0;t3<=sc[t]/3000;t3++){for (t2=0;t2<=sd[t]/3000;t2++){
drawimage(grap[65][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+29*t2+fmb);
}}}

if (sxtype[t]==10){
for (t3=0;t3<=sc[t]/3000;t3++){
drawimage(grap[65][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb);
}}

}//51


//��������
if (stype[t]==52){
xx[29]=0;if (stagecolor==2){xx[29]=30;}
if (stagecolor==4){xx[29]=60;}
if (stagecolor==5){xx[29]=90;}

for (t3=0;t3<=sc[t]/3000;t3++){
if (sxtype[t]==0){
drawimage(grap[5+xx[29]][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb);
if (stagecolor!=4){drawimage(grap[6+xx[29]][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb+29);}
else{drawimage(grap[5+xx[29]][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb+29);}
}
if (sxtype[t]==1){
for (t2=0;t2<=sd[t]/3000;t2++){
drawimage(grap[1+xx[29]][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb+29*t2);
}}

if (sxtype[t]==2){
  for (t2=0;t2<=sd[t]/3000;t2++){
    drawimage(grap[5+xx[29]][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+fmb+29*t2);
  }
}

}}


//�X�e�[�W�g���b�v
if (trap==1){
if (stype[t]>=100 && stype[t]<=299){
if (stagecolor==1 || stagecolor==3 || stagecolor==5)setc0();
if (stagecolor==2 || stagecolor==4)setc1();
drawrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb, sc[t]/100, sd[t]/100);
}}

//�S�[��
if (stype[t]==300){
setc1();
fillrect((sa[t]-fx)/100+10,(sb[t]-fy)/100, 10, sd[t]/100-8);
setc0();
drawrect((sa[t]-fx)/100+10,(sb[t]-fy)/100, 10, sd[t]/100-8);
setcolor(250,250,0);
fillarc((sa[t]-fx)/100+15-1,(sb[t]-fy)/100,10,10);
setc0();
drawarc((sa[t]-fx)/100+15-1,(sb[t]-fy)/100,10,10);
}

//����
if (stype[t]==500){
drawimage(grap[20][4],(sa[t]-fx)/100,(sb[t]-fy)/100);
}
}}//t


//�`��㏑��(�y��)
for (t=0;t<smax;t++){
if (sa[t]-fx+sc[t]>=-10 && sa[t]-fx<=fxmax+1100){

//����y��(�E)
if (stype[t]==40){
setcolor(0,230,0);
fillrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+1, sc[t]/100, sd[t]/100);
setc0();
drawrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+1, sc[t]/100, sd[t]/100);
}

//�Ƃԓy��
if (stype[t]==50){
setcolor(0,230,0);
fillrect((sa[t]-fx)/100+fma+5,(sb[t]-fy)/100+fmb+30, 50, sd[t]/100-30);
setc0();
drawline((sa[t]-fx)/100+5+fma,(sb[t]-fy)/100+fmb+30, (sa[t]-fx)/100+fma+5,(sb[t]-fy)/100+fmb+sd[t]/100);
drawline((sa[t]-fx)/100+5+fma+50,(sb[t]-fy)/100+fmb+30, (sa[t]-fx)/100+fma+50+5,(sb[t]-fy)/100+fmb+sd[t]/100);

setcolor(0,230,0);
fillrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+1, 60, 30);
setc0();
drawrect((sa[t]-fx)/100+fma,(sb[t]-fy)/100+fmb+1, 60, 30);
}

//�n��(�u���b�N)
if (stype[t]==200){
for (t3=0;t3<=sc[t]/3000;t3++){for (t2=0;t2<=sd[t]/3000;t2++){
drawimage(grap[65][1],(sa[t]-fx)/100+fma+29*t3,(sb[t]-fy)/100+29*t2+fmb);
}}
}

}}//t





//�t�@�C�A�o�[
for (t=0;t<amax;t++){

xx[0]=aa[t]-fx;xx[1]=ab[t]-fy;
//xx[2]=anobia[t]/100;xx[3]=anobib[t]/100;
xx[14]=12000;xx[16]=0;
if (atype[t]==87 || atype[t]==88){
if (xx[0]+xx[2]*100>=-10-xx[14] && xx[1]<=fxmax+xx[14] && xx[1]+xx[3]*100>=-10 && xx[3]<=fymax){

for (tt=0;tt<=axtype[t]%100;tt++){
xx[26]=18;
xd[4]=tt*xx[26]*cos(atm[t]*pai/180/2);
xd[5]=tt*xx[26]*sin(atm[t]*pai/180/2);
xx[24]=(int)xd[4];
xx[25]=(int)xd[5];
setcolor(230,120,0);
xx[23]=8;
if (atype[t]==87){
  fillarc(xx[0]/100+xx[24],xx[1]/100+xx[25],xx[23],xx[23]);
  setcolor(0,0,0);
  drawarc(xx[0]/100+xx[24],xx[1]/100+xx[25],xx[23],xx[23]);
}else{
  fillarc(xx[0]/100-xx[24],xx[1]/100+xx[25],xx[23],xx[23]);
  setcolor(0,0,0);
  drawarc(xx[0]/100-xx[24],xx[1]/100+xx[25],xx[23],xx[23]);
}
}

}
}}







//�v���C���[�̃��b�Z�[�W
setc0();
if (mmsgtm>=1){
mmsgtm--;
xs[0]="";

if (mmsgtype==1)xs[0]="���A��������!!";
if (mmsgtype==2)xs[0]="�ł͖������c�c";
if (mmsgtype==3)xs[0]="�h������!!";
if (mmsgtype==10)xs[0]="�H�ׂ�ׂ��ł͂Ȃ�����!!";
if (mmsgtype==11)xs[0]="���͔R����j��!!";
if (mmsgtype==50)xs[0]="�̂��c�c�Ă���c�c";
if (mmsgtype==51)xs[0]="���[�܂�[!!";
if (mmsgtype==52)xs[0]="�����ɃI���^";
if (mmsgtype==53)xs[0]="�����A������!!";
if (mmsgtype==54)xs[0]="���΂͐ێ�800�x!!";
if (mmsgtype==55)xs[0]="�n��ƍ��̂������c�c";
//if (mmsgtype==56)xs[0]="";

//if (stagecolor<=1 || stagecolor==3)setc0();
//if (stagecolor==2)setc1();

//str(xs[0],(ma+mnobia+300)/100,mb/100);

setc0();
str(xs[0],(ma+mnobia+300)/100-1,mb/100-1);
str(xs[0],(ma+mnobia+300)/100+1,mb/100+1);
setc1();
str(xs[0],(ma+mnobia+300)/100,mb/100);

}//mmsgtm


//�G�L�����̃��b�Z�[�W
setc0();
for (t=0;t<amax;t++){
if (amsgtm[t]>=1){
amsgtm[t]--;//end();

xs[0]="";

//if (amsgtype[t]==1001)xs[0]="";
if (amsgtype[t]==1001)xs[0]="���b�t�[!!";
if (amsgtype[t]==1002)xs[0]="��?���������������?";
if (amsgtype[t]==1003)xs[0]="�M�l�̎��ɏꏊ�͂�����!";
if (amsgtype[t]==1004)xs[0]="��x�Ɖ�����Ȃ����낤";
if (amsgtype[t]==1005)xs[0]="���A�ŋ�!!";
if (amsgtype[t]==1006)xs[0]="�������₪��!!";
if (amsgtype[t]==1007)xs[0]="���Ɍ�ނ̓񕶎��͖���!!";
if (amsgtype[t]==1008)xs[0]="�n�b�n�@!!";

if (amsgtype[t]==1011)xs[0]="���b�t�[!!";
if (amsgtype[t]==1012)xs[0]="��?���������������?";
if (amsgtype[t]==1013)xs[0]="�M�l�̎��ɏꏊ�͂�����!";
if (amsgtype[t]==1014)xs[0]="�g�̒��m�炸���c�c";
if (amsgtype[t]==1015)xs[0]="���f����������";
if (amsgtype[t]==1016)xs[0]="���߂ł����z��";
if (amsgtype[t]==1017)xs[0]="����!!";
if (amsgtype[t]==1018)xs[0]="���d�ȁc�c";

if (amsgtype[t]==1021)xs[0]="���b�t�[!!";
if (amsgtype[t]==1022)xs[0]="��?���������������?";
if (amsgtype[t]==1023)xs[0]="��x�Ɖ�����Ȃ����낤";
if (amsgtype[t]==1024)xs[0]="�g�̒��m�炸���c�c";
if (amsgtype[t]==1025)xs[0]="�l�́c�c�����Ȃ�!!";
if (amsgtype[t]==1026)xs[0]="�M�l�Ɍ��؂��؂͖���";
if (amsgtype[t]==1027)xs[0]="�����ˁA�������ˁA���܂ōӂ���!!";
if (amsgtype[t]==1028)xs[0]="�C������!!";

if (amsgtype[t]==1031)xs[0]="���b�t�[!!";
if (amsgtype[t]==1032)xs[0]="��?���������������?";
if (amsgtype[t]==1033)xs[0]="�M�l�̎��ɏꏊ�͂�����!";
if (amsgtype[t]==1034)xs[0]="�g�̒��m�炸���c�c";
if (amsgtype[t]==1035)xs[0]="���f����������";
if (amsgtype[t]==1036)xs[0]="���߂ł����z��";
if (amsgtype[t]==1037)xs[0]="����!!";
if (amsgtype[t]==1038)xs[0]="���d�ȁc�c";

if (amsgtype[t]==15)xs[0]="�S��!!����āA���G!!";
if (amsgtype[t]==16)xs[0]="�ۍ��ŏ��Ă�Ƃł�?";
if (amsgtype[t]==17)xs[0]="�p���C!!";
if (amsgtype[t]==18)xs[0]="���Ǝ�����";
if (amsgtype[t]==20)xs[0]="Zzz";
if (amsgtype[t]==21)xs[0]="�N�A�N�}�[";
if (amsgtype[t]==24)xs[0]="?";
if (amsgtype[t]==25)xs[0]="�H�ׂ�ׂ��ł͂Ȃ�����!!";
if (amsgtype[t]==30)xs[0]="���߂�!!";
if (amsgtype[t]==31)xs[0]="�u���b�N�𕎂�����?";
if (amsgtype[t]==32)xs[0]="�V���L�[��";

if (amsgtype[t]==50)xs[0]="�g���C!!";
if (amsgtype[t]==85)xs[0]="���؂�ꂽ�Ƃł��v������?";
if (amsgtype[t]==86)xs[0]="�|�[���A�^�[�b�N!!";



//if (stagecolor<=1 || stagecolor==3)setc0();
//if (stagecolor==2)setc1();

if (amsgtype[t]!=31){
//str(xs[0],(aa[t]+anobia[t]+300-fx)/100,(ab[t]-fy)/100);
xx[5]=(aa[t]+anobia[t]+300-fx)/100;xx[6]=(ab[t]-fy)/100;
}
else{
xx[5]=(aa[t]+anobia[t]+300-fx)/100;xx[6]=(ab[t]-fy-800)/100;
}

//setc0();
//str(xs[0],xx[5]-1,xx[6]-1);str(xs[0],xx[5]+1,xx[6]+1);
ChangeFontType(DX_FONTTYPE_EDGE);
setc1();
str(xs[0],xx[5],xx[6]);
ChangeFontType(DX_FONTTYPE_NORMAL);


}//amsgtm
}//amax



//���b�Z�[�W�u���b�N
if (tmsgtm>0){
ttmsg();
if (tmsgtype==1){
xx[0]=1200;
tmsgy+=xx[0];
if (tmsgtm==1){tmsgtm=80000000;tmsgtype=2;}
}//1

else if (tmsgtype==2){
tmsgy=0;tmsgtype=3;tmsgtm=15+1;
}

else if (tmsgtype==3){
xx[0]=1200;
tmsgy+=xx[0];
if (tmsgtm==15)WaitKey();
if (tmsgtm==1){tmsgtm=0;tmsgtype=0;tmsgy=0;}
}//1

tmsgtm--;
}//tmsgtm


//���b�Z�[�W
if (mainmsgtype>=1){
setfont(20,4);
if (mainmsgtype==1){DrawFormatString(126,100,GetColor(255,255,255),"WELCOME TO OWATA ZONE");}
if (mainmsgtype==1){for (t2=0;t2<=2;t2++)DrawFormatString(88+t2*143,210,GetColor(255,255,255),"1");}
setfont(20,5);
}//mainmsgtype>=1


//��ʍ�
if (blacktm>0){
blacktm--;
fillrect(0,0,fxmax,fymax);
if (blacktm==0){
if (blackx==1){zxon=0;}
}

}//blacktm

//DrawFormatString(10,10,GetColor(255,255,255),"X �c %d",anobib[0]);

}//if (main==1){


if (main==2){

setcolor(255,255,255);
str("����E�v���C�Ɋւ�������X",240-13*20/2,xx[12]/100);
str("�X�e�[�W�P�@�v���C",240-9*20/2,xx[13]/100);
str("��y�@�]�`�y",240-6*20/2,xx[14]/100);
str("�X�e�[�W�Q�@�v���C",240-9*20/2,xx[15]/100);
str("�F�l�@willowlet ",240-8*20/2,xx[16]/100);
str("�X�e�[�W�R�@�v���C",240-9*20/2,xx[17]/100);
str("�F�l�@willowlet ",240-8*20/2,xx[18]/100);
str("�X�e�[�W�S�@�v���C",240-9*20/2,xx[19]/100);
str("�F�l�Q�@ann ",240-6*20/2,xx[20]/100);
str("������",240-3*20/2,xx[21]/100);
str("�s��y",240-3*20/2,xx[22]/100);
str("�r��y",240-3*20/2,xx[23]/100);
str("����Z�p��",240-6*20/2,xx[24]/100);
str("�j��y",240-3*20/2,xx[25]/100);
str("����L���v�`���E�ҏW�E�G���R�[�h",240-16*20/2,xx[26]/100);
str("willowlet ",240-5*20/2,xx[27]/100);
str("�v���O�����E�`��E�l�^�E����ҏW",240-16*20/2,xx[28]/100);
str("����",240-2*20/2,xx[29]/100);

str("�v���C���Ă��������@���肪�Ƃ��������܂����`",240-22*20/2,xx[30]/100);
}



if (main==10){

setc0();
fillrect(0,0,fxmax,fymax);

SetFontSize(16) ;
SetFontThickness(4) ;

drawimage(grap[0][0],190,190);
DrawFormatString(230,200,GetColor(255,255,255)," �~ %d",nokori);


}//if (main==10){


//�^�C�g��
if (main==100){

setcolor(160,180,250);
fillrect(0,0,fxmax,fymax);

drawimage(mgrap[30],240-380/2,60);

drawimage(grap[0][4],12*30,10*29-12);
drawimage(grap[1][4],6*30,12*29-12);

//�v���C���[
drawimage(grap[0][0],2*30,12*29-12-6);
for (t=0;t<=16;t++){
drawimage(grap[5][1],29*t,13*29-12);
drawimage(grap[6][1],29*t,14*29-12);
}


setcolor(0,0,0);
str("Enter�L�[������!!",240-8*20/2,250);

}//if (main==100){



//DrawFormatString(230,200,GetColor(255,255,255)," �~ %d,%d,%d",sta,stb,stc);

ScreenFlip();

}//rpaint()







//���C���v���O����
void Mainprogram(){

stime=long(GetNowCount());


if (ending==1)main=2;


//�L�[
key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


if (main==1 && tmsgtype==0){


if (zxon==0){
zxon=1;
mainmsgtype=0;

stagecolor=1;
ma=5600;mb=32000;mmuki=1;mhp=1;
mc=0;md=0;
mnobia=3000;mnobib=3600;

mtype=0;
//if (stc==1)end();

fx=0;fy=0;
fzx=0;
stageonoff=0;




//�`�[�^�[�}���@����
bgmchange(oto[100]);

stagecls();

stage();


//�����_���ɂ�����
if (over==1){
//for (t=0;t<;t++){na[t]=rand(300000);nb[t]=rand(3000);}
for (t=0;t<tmax;t++){if (rand(3)<=1){ta[t]=(rand(500)-1)*29*100;tb[t]=rand(14)*100*29-1200;ttype[t]=rand(142);if (ttype[t]>=9 && ttype[t]<=99){ttype[t]=rand(8);}txtype[t]=rand(4);}}
for (t=0;t<bmax;t++){if (rand(2)<=1){ba[t]=(rand(500)-1)*29*100;bb[t]=rand(15)*100*29-1200-3000;if (rand(6)==0){btype[t]=rand(9);}}}

srco=0;
t=srco;sra[t]=ma+fx;srb[t]=(13*29-12)*100;src[t]=30*100;srtype[t]=0;sracttype[t]=0;sre[t]=0;srsp[t]=0;srco++;

if (rand(4)==0)stagecolor=rand(5);
//if (rand(6)==0)bgmchange(oto[rand(6)+100]);
}



StopSoundMem(oto[0]);


//���C��BGM
PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP) ;
//PlayMusic("BGM/titerman.mp3",DX_PLAYTYPE_LOOP) ;


}//zxon

//xx[1]=rand(100);







//�v���C���[�̈ړ�
xx[0]=0;actaon[2]=0;actaon[3]=0;
if (mkeytm<=0){
if (( key & PAD_INPUT_LEFT) && keytm<=0){actaon[0]=-1;mmuki=0;actaon[4]=-1;}	
if (( key & PAD_INPUT_RIGHT) && keytm<=0){actaon[0]=1;mmuki=1;actaon[4]=1;}
if (key & PAD_INPUT_DOWN){actaon[3]=1;}
}

//if (CheckHitKey(KEY_INPUT_F1)==1){end();}
if (CheckHitKey(KEY_INPUT_F1)==1){main=100;}
//if (CheckHitKey(KEY_INPUT_Q)==1){mkeytm=0;}
if (CheckHitKey(KEY_INPUT_O)==1){if (mhp>=1)mhp=0;if (stc>=5){stc=0;stagepoint=0;}}


if (mkeytm<=0){
if (key & PAD_INPUT_UP || CheckHitKey(KEY_INPUT_Z)==1){//end();
if (actaon[1]==10){actaon[1]=1;xx[0]=1;}
actaon[2]=1;
}}

if (key & PAD_INPUT_UP || CheckHitKey(KEY_INPUT_Z)==1){
if (mjumptm==8 && md>=-900){
md=-1300;
//�_�b�V����
xx[22]=200;if (mc>=xx[22] || mc<=-xx[22]){md=-1400;}
xx[22]=600;if (mc>=xx[22] || mc<=-xx[22]){md=-1500;}
}
// && xx[0]==0 && md<=-10

//if (mjumptm==7 && md>=-900){}
if (xx[0]==0)actaon[1]=10;
}




//if (( key & PAD_INPUT_UP) && keytm<=0){actaon[0]=-1;mmuki=0;}	

//xx[0]=200;
//if (actaon[0]==-1){ma-=xx[0];}
//if (actaon[0]==1){ma+=xx[0];}


//�����ɂ��ړ�
xx[0]=40;xx[1]=700;xx[8]=500;xx[9]=700;
xx[12]=1;xx[13]=2;

//���ׂ�␳
if (mrzimen==1){xx[0]=20;xx[12]=9;xx[13]=10;}


//if (mzimen==0){xx[0]-=15;}
if (actaon[0]==-1){
if (!(mzimen==0 && mc<-xx[8])){
if (mc>=-xx[9]){mc-=xx[0];if (mc<-xx[9]){mc=-xx[9]-1;}}
if (mc<-xx[9] && atktm<=0)mc-=xx[0]/10;
}
if (mrzimen!=1){
if (mc>100 && mzimen==0){mc-=xx[0]*2/3;}
if (mc>100 && mzimen==1){mc-=xx[0];if (mzimen==1){mc-=xx[0]*1/2;}}actaon[0]=3;
mkasok+=1;
}}

if (actaon[0]==1){
if (!(mzimen==0 && mc>xx[8])){
if (mc<=xx[9]){mc+=xx[0];if (mc>xx[9]){mc=xx[9]+1;}}
if (mc>xx[9] && atktm<=0)mc+=xx[0]/10;
}
if (mrzimen!=1){
if (mc<-100 && mzimen==0){mc+=xx[0]*2/3;}
if (mc<-100 && mzimen==1){mc+=xx[0];if (mzimen==1){mc+=xx[0]*1/2;}}actaon[0]=3;mkasok+=1;
}}
if (actaon[0]==0 && mkasok>0){mkasok-=2;}if (mkasok>8){mkasok=8;}

//���ׂ�␳������
if (mzimen!=1)mrzimen=0;


//�W�����v
if (mjumptm>=0)mjumptm--;
if (actaon[1]==1 && mzimen==1){
mb-=400;md=-1200;mjumptm=10;

//PlaySound( "jump.mp3" , DX_PLAYTYPE_NORMAL ) ;

//PlayMusic( "SE/jump.mp3" , DX_PLAYTYPE_NORMAL ) ;

//PlaySoundMem( oto[1], DX_PLAYTYPE_NORMAL ) ;

//PlaySoundMem( oto[1], DX_PLAYTYPE_BACK) ;
ot(oto[1]);

/*
md=-1040;
xx[1]=600;if (mc>xx[1] || mc<=-xx[1]){md=-1400;}
xx[1]=7;xx[2]=400;
if (mkasok>xx[1] && (mc>xx[2] || mc<=-xx[2])){
md=-1600;
if (mc>=800 || mc<=-800){md=-1800;}
}
*/

mzimen=0;

}
if (actaon[1]<=9)actaon[1]=0;

//if (actaon[1]==1){my+=xx[1];actaon[1]=0;}

//}//���n


if (mmutekitm>=-1)mmutekitm--;


//HP���Ȃ��Ȃ����Ƃ�
if (mhp<=0 && mhp>=-9){
mkeytm=12;mhp=-20;mtype=200;mtm=0;ot(oto[12]);StopSoundMem(oto[0]);StopSoundMem(oto[11]);StopSoundMem(oto[16]);
}//mhp
//if (mhp<=-10){
if (mtype==200){
if (mtm<=11){mc=0;md=0;}
if (mtm==12){md=-1200;}
if (mtm>=12){mc=0;}
if (mtm>=100 || fast==1){zxon=0;main=10;mtm=0;mkeytm=0;nokori--;if (fast==1)mtype=0;}//mtm>=100
}//mtype==200




//�����ɂ�郏�[�v
if (mtype==2){
mtm++;

mkeytm=2;
md=-1500;
if (mb<=-6000){blackx=1;blacktm=20;stc+=5;stagerr=0;StopSoundMem(oto[0]);mtm=0;mtype=0;mkeytm=-1;}
}//2

//�W�����v��A�E�g
if (mtype==3){
md=-2400;
if (mb<=-6000){mb=-80000000;mhp=0;}
}


//mtype�ɂ�����I�Ȉړ�
if (mtype>=100){mtm++;

//���ʂ̓y��
if (mtype==100){
if (mxtype==0){
mc=0;md=0;t=28;
if (mtm<=16){mb+=240;mzz=100;}
if (mtm==17){mb=-80000000;}
if (mtm==23){sa[t]-=100;}
if (mtm>=44 && mtm<=60){
if (mtm%2==0)sa[t]+=200;
if (mtm%2==1)sa[t]-=200;
}
if (mtm>=61 && mtm<=77){
if (mtm%2==0)sa[t]+=400;
if (mtm%2==1)sa[t]-=400;
}
if (mtm>=78 && mtm<=78+16){
if (mtm%2==0)sa[t]+=600;
if (mtm%2==1)sa[t]-=600;
}
if (mtm>=110){sb[t]-=mzz;mzz+=80;if (mzz>1600)mzz=1600;}
if (mtm==160){mtype=0;mhp--;}

}

//�ӂ��Ƃ΂�
else if (mxtype==10){
mc=0;md=0;
if (mtm<=16){ma+=240;}//mzz=100;}
if (mtm==16)mb-=1100;
if (mtm==20)ot(oto[10]);

if (mtm>=24){ma-=2000;mmuki=0;}
if (mtm>=48){mtype=0;mhp--;}

}else{
mc=0;md=0;
if (mtm<=16 && mxtype!=3){mb+=240;}//mzz=100;}
if (mtm<=16 && mxtype==3){ma+=240;}
if (mtm==19 && mxtype==2){mhp=0;mtype=2000;mtm=0;mmsgtm=30;mmsgtype=51;}
if (mtm==19 && mxtype==5){mhp=0;mtype=2000;mtm=0;mmsgtm=30;mmsgtype=52;}
if (mtm==20){
if(mxtype == 6){
  stc += 10;
}else{
  stc++;
}
mb=-80000000;
mxtype=0;
blackx=1;
blacktm=20;
stagerr=0;StopSoundMem(oto[0]);
}}
}//00


if (mtype==300){
mkeytm=3;
if (mtm<=1){mc=0;md=0;}
if (mtm>=2 && mtm<=42){md=600;mmuki=1;}
if (mtm>43 && mtm<=108){mc=300;}
if (mtm==110){mb=-80000000;mc=0;}
if (mtm==250){
  stb++;stc=0;zxon=0;tyuukan=0;main=10;maintm=0;
}
}//mtype==300

if (mtype==301 || mtype==302){
  mkeytm=3;
  
  if (mtm<=1){mc=0;md=0;}
  
  if (mtm>=2 && (mtype==301 && mtm<=102 || mtype==302 && mtm<=60)){
    xx[5]=500;
    ma-=xx[5];fx+=xx[5];fzx+=xx[5];
  }

  if ((mtype==301 || mtype==302) && mtm>=2 && mtm<=100){
    mc=250;mmuki=1;
  }
  
  if (mtm==200){
    ot(oto[17]);
    if(mtype==301){
      na[nco]=117*29*100-1100;nb[nco]=4*29*100;ntype[nco]=101;nco++;if (nco>=nmax)nco=0;
      na[nco]=115*29*100-1100;nb[nco]=6*29*100;ntype[nco]=102;nco++;if (nco>=nmax)nco=0;
    }else{
      na[nco]=157*29*100-1100;nb[nco]=4*29*100;ntype[nco]=101;nco++;if (nco>=nmax)nco=0;
      na[nco]=155*29*100-1100;nb[nco]=6*29*100;ntype[nco]=102;nco++;if (nco>=nmax)nco=0;
    }
  }
//�X�^�b�t���[����

  if (mtm==440){
    if(mtype==301){
      ending = 1;
    }else{
      sta++;stb=1;stc=0;zxon=0;tyuukan=0;main=10;maintm=0;
    }
  }


/*
if (mtm<=1){mc=0;md=0;}
if (mtm>=2 && mtm<=42){md=600;mmuki=1;}
if (mtm>43 && mtm<=108){mc=300;}
if (mtm==110){mb=-80000000;mc=0;}
if (mtm==250)end();
*/
}//mtype==301

}//mtype>=100




//�ړ�
if (mkeytm>=1){mkeytm--;}//mc=0;}
ma+=mc;mb+=md;
if (mc<0)mactp+=(-mc);
if (mc>=0)mactp+=mc;

if (mtype<=9 || mtype==200 || mtype==300 || mtype==301 || mtype==302)md+=100;


//����ۂ̍ő�l
if (mtype==0){
xx[0]=800;xx[1]=1600;
if (mc>xx[0] && mc<xx[0]+200){mc=xx[0];}
if (mc>xx[0]+200){mc-=200;}
if (mc<-xx[0] && mc>-xx[0]-200){mc=-xx[0];}
if (mc<-xx[0]-200){mc+=200;}
if (md>xx[1]){md=xx[1];}
}

//�v���C���[
//�n�ʂ̖��C
if (mzimen==1 && actaon[0]!=3){
if ((mtype<=9) || mtype==300 || mtype==301 || mtype==302){
if (mrzimen==0){
xx[2]=30;xx[1]=60;xx[3]=30;
if (mc>=-xx[3] && mc<=xx[3]){mc=0;}
if (mc>=xx[2]){mc-=xx[1];}
if (mc<=-xx[2]){mc+=xx[1];}
}
if (mrzimen==1){
xx[2]=5;xx[1]=10;xx[3]=5;
if (mc>=-xx[3] && mc<=xx[3]){mc=0;}
if (mc>=xx[2]){mc-=xx[1];}
if (mc<=-xx[2]){mc+=xx[1];}
}
}}


//�n�ʔ��菉����
mzimen=0;

//��O
if (mtype<=9 && mhp>=1){
if (ma<100){ma=100;mc=0;}
if (ma+mnobia>fxmax){ma=fxmax-mnobia;mc=0;}
}
//if (mb>=42000){mb=42000;mzimen=1;}
if (mb>=38000 && mhp>=0 && stagecolor==4){mhp=-2;mmsgtm=30;mmsgtype=55;}
if (mb>=52000 && mhp>=0){mhp=-2;}






//�u���b�N
//1-��񂪁A�R�C���A�����A�y��A7-�B��

xx[15]=0;
for (t=0;t<tmax;t++){
xx[0]=200;xx[1]=3000;xx[2]=1000;xx[3]=3000;//xx[2]=1000
xx[8]=ta[t]-fx;xx[9]=tb[t]-fy;//xx[15]=0;
if (ta[t]-fx+xx[1]>=-10-xx[3] && ta[t]-fx<=fxmax+12000+xx[3]){
if (mtype!=200 && mtype!=1 && mtype!=2){
if (ttype[t]<1000 && ttype[t]!=800 && ttype[t]!=140 && ttype[t]!=141){// && ttype[t]!=5){

//if (!(mztm>=1 && mztype==1 && actaon[3]==1)){
if (!(mztype==1)){
xx[16]=0;xx[17]=0;

//��
if (ttype[t]!=7 && ttype[t]!=110 && !(ttype[t]==114)){
if (ma+mnobia>xx[8]+xx[0]*2+100 && ma<xx[8]+xx[1]-xx[0]*2-100 && mb+mnobib>xx[9] && mb+mnobib<xx[9]+xx[1] && md>=-100){
if (ttype[t]!=115 && ttype[t]!=400 && ttype[t]!=117 && ttype[t]!=118 && ttype[t]!=120){
mb=xx[9]-mnobib+100;md=0;mzimen=1;xx[16]=1;
}
else if (ttype[t]==115){
ot(oto[3]);
eyobi(ta[t]+1200,tb[t]+1200,300,-1000,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,-300,-1000,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,240,-1400,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,-240,-1400,0,160,1000,1000,1,120);
brockbreak(t);
}
//P�X�C�b�`
else if (ttype[t]==400){
md=0;ta[t]=-8000000;ot(oto[13]);
for (tt=0;tt<tmax;tt++){if (ttype[tt]!=7){ttype[tt]=800;}}
StopSoundMem(oto[0]);
}

//����+
else if (ttype[t]==117){
ot(oto[14]);
md=-1500;mtype=2;mtm=0;
if (txtype[t]>=2 && mtype==2){mtype=0;md=-1600;txtype[t]=3;}
if (txtype[t]==0)txtype[t]=1;
}

//�W�����v��
else if (ttype[t]==120){
//txtype[t]=0;
md=-2400;mtype=3;mtm=0;
}

}}
}//!


//sstr=""+mjumptm;
//�u���b�N����̓���ւ�
if (!(mztm>=1 && mztype==1)){
xx[21]=0;xx[22]=1;//xx[12]=0;
if (mzimen==1 || mjumptm>=10){xx[21]=3;xx[22]=0;}
for (t3=0;t3<=1;t3++){

//��
if (t3==xx[21] && mtype!=100 && ttype[t]!=117){// && xx[12]==0){
if (ma+mnobia>xx[8]+xx[0]*2+800 && ma<xx[8]+xx[1]-xx[0]*2-800 && mb>xx[9]-xx[0]*2 && mb<xx[9]+xx[1]-xx[0]*2 && md<=0){xx[16]=1;xx[17]=1;
mb=xx[9]+xx[1]+xx[0];if (md<0){md=-md*2/3;}//}
//����
if (ttype[t]==1 && mzimen==0){
ot(oto[3]);
eyobi(ta[t]+1200,tb[t]+1200,300,-1000,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,-300,-1000,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,240,-1400,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,-240,-1400,0,160,1000,1000,1,120);
brockbreak(t);
}
//�R�C��
if (ttype[t]==2 && mzimen==0){
ot(oto[4]);
eyobi(ta[t]+10,tb[t],0,-800,0,40,3000,3000,0,16);
ttype[t]=3;
}
//�B��
if (ttype[t]==7){
ot(oto[4]);
eyobi(ta[t]+10,tb[t],0,-800,0,40,3000,3000,0,16);
mb=xx[9]+xx[1]+xx[0];ttype[t]=3;if (md<0){md=-md*2/3;}
}
// �g�Q
if (ttype[t]==10){
  mmsgtm=30;
  mmsgtype=3;
  mhp--;
}
}}


//���E
if (t3==xx[22] && xx[15]==0){
if (ttype[t]!=7 && ttype[t]!=110 && ttype[t]!=117){
if (!(ttype[t]==114)){// && txtype[t]==1)){
if (ta[t]>=-20000){
//if (ma+mnobia>xx[8] && ma<xx[8]+xx[2] && mb+mnobib>xx[9]+xx[1]/2-xx[0] &&){
if (ma+mnobia>xx[8] && ma<xx[8]+xx[2] && mb+mnobib>xx[9]+xx[1]/2-xx[0] && mb<xx[9]+xx[2] && mc>=0){
ma=xx[8]-mnobia;mc=0;xx[16]=1;
//if (ttype[t]!=4){ma=xx[8]-mnobia;mc=0;xx[16]=1;}
//if (ttype[t]==4){ma=xx[8]-mnobia;mc=-mc*4/4;}
}
if (ma+mnobia>xx[8]+xx[2] && ma<xx[8]+xx[1] && mb+mnobib>xx[9]+xx[1]/2-xx[0] && mb<xx[9]+xx[2] && mc<=0){
ma=xx[8]+xx[1];mc=0;xx[16]=1;//end();
//if (ttype[t]!=4){ma=xx[8]+xx[1];mc=0;xx[16]=1;}
//if (ttype[t]==4){ma=xx[8]+xx[1];mc=-mc*4/4;}
}
}}}
}

}//t3
}//!

}// && ttype[t]<50

if (ttype[t]==800){
//if (xx[0]+xx[2]>=-xx[14] && xx[0]<=fxmax+xx[14] && xx[1]+xx[3]>=-10-9000 && xx[1]<=fymax+10000){
if (mb>xx[9]-xx[0]*2-2000 && mb<xx[9]+xx[1]-xx[0]*2+2000 && ma+mnobia>xx[8]-400 && ma<xx[8]+xx[1]){
ta[t]=-800000;ot(oto[4]);
}}

//���Ƃ��ăN���A
if (ttype[t]==140){
if (mb>xx[9]-xx[0]*2-2000 && mb<xx[9]+xx[1]-xx[0]*2+2000 && ma+mnobia>xx[8]-400 && ma<xx[8]+xx[1]){
ta[t]=-800000;//ot(oto[4]);
sracttype[20]=1;sron[20]=1;
StopSoundMem(oto[0]);mtype=301;mtm=0;ot(oto[16]);

}}


//����I
if (ttype[t]==100){//xx[9]+xx[1]+3000<mb && // && mb>xx[9]-xx[0]*2
if (mb>xx[9]-xx[0]*2-2000 && mb<xx[9]+xx[1]-xx[0]*2+2000 && ma+mnobia>xx[8]-400 && ma<xx[8]+xx[1] && md<=0){
if (txtype[t]==0)tb[t]=mb+fy-1200-xx[1];
}

if (txtype[t]==1){
if (xx[17]==1){
if (ma+mnobia>xx[8]-400 && ma<xx[8]+xx[1]/2-1500){ta[t]+=3000;}
else if (ma+mnobia>=xx[8]+xx[1]/2-1500 && ma<xx[8]+xx[1]){ta[t]-=3000;}
}}

if (xx[17]==1 && txtype[t]==0){
ot(oto[4]);
eyobi(ta[t]+10,tb[t],0,-800,0,40,3000,3000,0,16);
ttype[t]=3;
}
}//100

//�G�o��
if (ttype[t]==101){//xx[9]+xx[1]+3000<mb && // && mb>xx[9]-xx[0]*2
if (xx[17]==1){
ot(oto[8]);
ttype[t]=3;
abrocktm[aco]=16;
if (txtype[t]==0)ayobi(ta[t],tb[t],0,0,0,0,0);
if (txtype[t]==1)ayobi(ta[t],tb[t],0,0,0,4,0);
if (txtype[t]==3)ayobi(ta[t],tb[t],0,0,0,101,0);
if (txtype[t]==4){abrocktm[aco]=20;ayobi(ta[t]-400,tb[t]-1600,0,0,0,6,0);}
if (txtype[t]==10)ayobi(ta[t],tb[t],0,0,0,101,0);
}
}//101

//�����������̂��o��
if (ttype[t]==102){
if (xx[17]==1){
ot(oto[8]);
ttype[t]=3;abrocktm[aco]=16;
if (txtype[t]==0)ayobi(ta[t],tb[t],0,0,0,100,0);
if (txtype[t]==2)ayobi(ta[t],tb[t],0,0,0,100,2);
if (txtype[t]==3)ayobi(ta[t],tb[t],0,0,0,102,1);
}}//102

//�܂������̂��o��
if (ttype[t]==103){
if (xx[17]==1){
ot(oto[8]);
ttype[t]=3;abrocktm[aco]=16;ayobi(ta[t],tb[t],0,0,0,100,1);
}}//103


//���X�^�[�o��
if (ttype[t]==104){
if (xx[17]==1){
ot(oto[8]);
ttype[t]=3;abrocktm[aco]=16;ayobi(ta[t],tb[t],0,0,0,110,0);
}}//104




//�ł��̂��ʎY
if (ttype[t]==110){
if (xx[17]==1){
ttype[t]=111;thp[t]=999;
}}//110
if (ttype[t]==111 && ta[t]-fx>=0){
thp[t]++;if (thp[t]>=16){thp[t]=0;
ot(oto[8]);
abrocktm[aco]=16;ayobi(ta[t],tb[t],0,0,0,102,1);
}}


//�R�C���ʎY
if (ttype[t]==112){
if (xx[17]==1){
ttype[t]=113;thp[t]=999;titem[t]=0;
}}//110
if (ttype[t]==113 && ta[t]-fx>=0){
if (titem[t]<=19)thp[t]++;
if (thp[t]>=3){thp[t]=0;titem[t]++;
ot(oto[4]);
eyobi(ta[t]+10,tb[t],0,-800,0,40,3000,3000,0,16);
//ttype[t]=3;
}}


//�B���ł��̂�
if (ttype[t]==114){
if (xx[17]==1){
if (txtype[t]==0){
ot(oto[8]);ttype[t]=3;
abrocktm[aco]=16;ayobi(ta[t],tb[t],0,0,0,102,1);
}
if (txtype[t]==2){ot(oto[4]);eyobi(ta[t]+10,tb[t],0,-800,0,40,3000,3000,0,16);ttype[t]=115;txtype[t]=0;}
if (txtype[t]==10){
if (stageonoff==1){ttype[t]=130;stageonoff=0;ot(oto[13]);txtype[t]=2;for (t=0;t<amax;t++){if (atype[t]==87 || atype[t]==88){if (axtype[t]==105){axtype[t]=110;}}}}
else{ot(oto[4]);eyobi(ta[t]+10,tb[t],0,-800,0,40,3000,3000,0,16);ttype[t]=3;}
}

}
}//114


//���낢�u���b�N
if (ttype[t]==115){

}//115


//P�X�C�b�`
if (ttype[t]==116){
if (xx[17]==1){
ot(oto[8]);
//ot(oto[13]);
ttype[t]=3;//abrocktm[aco]=18;ayobi(ta[t],tb[t],0,0,0,104,1);
tyobi(ta[t]/100,(tb[t]/100)-29,400);
}}//116


//�t�@�C�A�o�[����
if (ttype[t]==124){
if (xx[17]==1){
ot(oto[13]);
for (t=0;t<amax;t++){if (atype[t]==87 || atype[t]==88){if (axtype[t]==101){axtype[t]=120;}}}
ttype[t]=3;
}}

//ON�X�C�b�`
if (ttype[t]==130){
if (xx[17]==1){
if (txtype[t]!=1){
stageonoff=0;ot(oto[13]);
}}}
else if (ttype[t]==131){
if (xx[17]==1 && txtype[t]!=2){
stageonoff=1;ot(oto[13]);
if (txtype[t]==1){
for (t=0;t<amax;t++){if (atype[t]==87 || atype[t]==88){if (axtype[t]==105){axtype[t]=110;}}}
bxtype[3]=105;
}
}}

//�q���g
if (ttype[t]==300){
if (xx[17]==1){
ot(oto[15]);
if (txtype[t]<=100){
tmsgtype=1;tmsgtm=15;tmsgy=300+(txtype[t]-1);tmsg=(txtype[t]);
}
if (txtype[t]==540){
tmsgtype=1;tmsgtm=15;tmsgy=400;tmsg=100;txtype[t]=541;
}}
}//300


if (ttype[t]==301){
if (xx[17]==1){
ot(oto[3]);
eyobi(ta[t]+1200,tb[t]+1200,300,-1000,0,160,1000,1000,1,120);eyobi(ta[t]+1200,tb[t]+1200,-300,-1000,0,160,1000,1000,1,120);eyobi(ta[t]+1200,tb[t]+1200,240,-1400,0,160,1000,1000,1,120);eyobi(ta[t]+1200,tb[t]+1200,-240,-1400,0,160,1000,1000,1,120);
brockbreak(t);
}}//300


}
else if (mtype==1){
if (ma+mnobia>xx[8] && ma<xx[8]+xx[1] && mb+mnobib>xx[9] && mb<xx[9]+xx[1]){

ot(oto[3]);
eyobi(ta[t]+1200,tb[t]+1200,300,-1000,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,-300,-1000,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,240,-1400,0,160,1000,1000,1,120);
eyobi(ta[t]+1200,tb[t]+1200,-240,-1400,0,160,1000,1000,1,120);
brockbreak(t);

}}


//ONOFF
if (ttype[t]==130 && stageonoff==0){ttype[t]=131;}
if (ttype[t]==131 && stageonoff==1){ttype[t]=130;}

//�q���g
if (ttype[t]==300){
if (txtype[t]>=500 && ta[t]>=-6000){// && ta[t]>=-6000){
if (txtype[t]<=539)txtype[t]++;
if (txtype[t]>=540){ta[t]-=500;}
}}//300


}}//�u���b�N







//��
for (t=0;t<smax;t++){
if (sa[t]-fx+sc[t]>=-12000 && sa[t]-fx<=fxmax){
xx[0]=200;xx[1]=2400;xx[2]=1000;xx[7]=0;

xx[8]=sa[t]-fx;xx[9]=sb[t]-fy;
if ((stype[t]<=99 || stype[t]==200) && mtype<10){

//������u���b�N
if (stype[t]==51){
if (ma+mnobia>xx[8]+xx[0]+3000 && ma<xx[8]+sc[t]-xx[0] && mb+mnobib>xx[9]+3000 && sgtype[t]==0){
if (sxtype[t]==0){
sgtype[t]=1;sr[t]=0;
}}
if (ma+mnobia>xx[8]+xx[0]+1000 && ma<xx[8]+sc[t]-xx[0] && mb+mnobib>xx[9]+3000 && sgtype[t]==0){
if ((sxtype[t]==10) && sgtype[t]==0){
sgtype[t]=1;sr[t]=0;
}}

if ((sxtype[t]==1) && sb[27]>=25000 && sa[27]>ma+mnobia && t!=27 && sgtype[t]==0){
sgtype[t]=1;sr[t]=0;
}
if (sxtype[t]==2 && sb[28]>=48000 && t!=28 && sgtype[t]==0 && mhp>=1){
sgtype[t]=1;sr[t]=0;
}
if ((sxtype[t]==3 && mb>=30000 || sxtype[t]==4 && mb>=25000) && sgtype[t]==0 && mhp>=1 && ma+mnobia>xx[8]+xx[0]+3000-300 && ma<xx[8]+sc[t]-xx[0]){
sgtype[t]=1;sr[t]=0;
if (sxtype[t]==4)sr[t]=100;
}

if (sgtype[t]==1 && sb[t]<=fymax+18000){
sr[t]+=120;if (sr[t]>=1600){sr[t]=1600;}
sb[t]+=sr[t];
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+sc[t]-xx[0] && mb+mnobib>xx[9] && mb<xx[9]+sd[t]+xx[0]){
mhp--;xx[7]=1;
}}
}

//������u���b�N2
if (stype[t]==52){
if (sgtype[t]==0 && ma+mnobia>xx[8]+xx[0]+2000 && ma<xx[8]+sc[t]-xx[0]-2500 && mb+mnobib>xx[9]-3000){
sgtype[t]=1;sr[t]=0;
}
if (sgtype[t]==1){
sr[t]+=120;if (sr[t]>=1600){sr[t]=1600;}
sb[t]+=sr[t];
}
}



//�ʏ�n��
if (xx[7]==0){
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+sc[t]-xx[0] && mb+mnobib>xx[9] && mb+mnobib<xx[9]+xx[1] && md>=-100){mb=sb[t]-fy-mnobib+100;md=0;mzimen=1;}
if (ma+mnobia>xx[8]-xx[0] && ma<xx[8]+xx[2] && mb+mnobib>xx[9]+xx[1]*3/4 && mb<xx[9]+sd[t]-xx[2]){ma=xx[8]-xx[0]-mnobia;mc=0;}
if (ma+mnobia>xx[8]+sc[t]-xx[0] && ma<xx[8]+sc[t]+xx[0] && mb+mnobib>xx[9]+xx[1]*3/4 && mb<xx[9]+sd[t]-xx[2]){ma=xx[8]+sc[t]+xx[0];mc=0;}
if (ma+mnobia>xx[8]+xx[0]*2 && ma<xx[8]+sc[t]-xx[0]*2 && mb>xx[9]+sd[t]-xx[1] && mb<xx[9]+sd[t]+xx[0]){
mb=xx[9]+sd[t]+xx[0];if (md<0){md=-md*2/3;}
}
}//xx[7]

//����y��
if (stype[t]==50){
if (ma+mnobia>xx[8]+2800 && ma<xx[8]+sc[t]-3000 && mb+mnobib>xx[9]-1000 && mb+mnobib<xx[9]+xx[1]+3000 && mzimen==1 && actaon[3]==1 && mtype==0){
//��яo��
if (sxtype[t]==0){
mtype=100;mtm=0;ot(oto[7]);mxtype=0;
}
//����
if (sxtype[t]==1){
mtype=100;mtm=0;ot(oto[7]);mxtype=1;
}
//����
if (sxtype[t]==2){
mtype=100;mtm=0;ot(oto[7]);mxtype=2;
}
if (sxtype[t]==5){
mtype=100;mtm=0;ot(oto[7]);mxtype=5;
}
// ���[�v
if (sxtype[t]==6){
mtype=100;mtm=0;ot(oto[7]);mxtype=6;
}
}}//50

//����y��(������)
if (stype[t]==40){
if (ma+mnobia>xx[8]-300 && ma<xx[8]+sc[t]-1000 && mb>xx[9]+1000 && mb+mnobib<xx[9]+xx[1]+4000 && mzimen==1 && actaon[4]==1 && mtype==0){//end();
//��яo��
if (sxtype[t]==0){
mtype=500;mtm=0;ot(oto[7]);//mxtype=1;
mtype=100;mxtype=10;
}

if (sxtype[t]==2){
mxtype=3;
mtm=0;ot(oto[7]);//mxtype=1;
mtype=100;
}
// ���[�v
if (sxtype[t]==6){
mtype=3;mtm=0;ot(oto[7]);mxtype=6;
}
}}//40




}//stype
else{
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+sc[t]-xx[0] && mb+mnobib>xx[9] && mb<xx[9]+sd[t]+xx[0]){
if (stype[t]==100){
if (sxtype[t]==0 || sxtype[t]==1 && ttype[1]!=3){
ayobi(sa[t]+1000,32000,0,0,0,3,0);sa[t]=-800000000;ot(oto[10]);
}
}
if (stype[t]==101){ayobi(sa[t]+6000,-4000,0,0,0,3,1);sa[t]=-800000000;ot(oto[10]);}
if (stype[t]==102){
if (sxtype[t]==0){
for (t3=0;t3<=3;t3++){ayobi(sa[t]+t3*3000,-3000,0,0,0,0,0);}
}
if (sxtype[t]==1 && mb>=16000){ayobi(sa[t]+1500,44000,0,-2000,0,4,0);}
else if (sxtype[t]==2){ayobi(sa[t]+4500,30000,0,-1600,0,5,0);ot(oto[10]);sxtype[t]=3;sa[t]-=12000;}
else if (sxtype[t]==3){sa[t]+=12000;sxtype[t]=4;}
else if (sxtype[t]==4){ayobi(sa[t]+4500,30000,0,-1600,0,5,0);ot(oto[10]);sxtype[t]=5;sxtype[t]=0;}

else if (sxtype[t]==7){mainmsgtype=1;}
else if (sxtype[t]==8){ayobi(sa[t]-5000-3000*1,26000,0,-1600,0,5,0);ot(oto[10]);}
else if (sxtype[t]==9){for (t3=0;t3<=2;t3++){ayobi(sa[t]+t3*3000+3000,48000,0,-6000,0,3,0);}}
if (sxtype[t]==10){sa[t]-=5*30*100;stype[t]=101;}

if (sxtype[t]==12){
for (t3=1;t3<=3;t3++){ayobi(sa[t]+t3*3000-1000,40000,0,-2600,0,9,0);}
}

//�X�N���[������
if (sxtype[t]==20){
scrollx=0;
}

//�N���A
if (sxtype[t]==30){sa[t]=-80000000;md=0;
StopSoundMem(oto[0]);mtype=302;mtm=0;ot(oto[16]);
}

if (sxtype[t]!=3 && sxtype[t]!=4 && sxtype[t]!=10){sa[t]=-800000000;}
}

if (stype[t]==103){
if (sxtype[t]==0){
amsgtm[aco]=10;amsgtype[aco]=50;ayobi(sa[t]+9000,sb[t]+2000,0,0,0,79,0);sa[t]=-800000000;
}

if (sxtype[t]==1 && ttype[6]<=6){
amsgtm[aco]=10;amsgtype[aco]=50;ayobi(sa[t]-12000,sb[t]+2000,0,0,0,79,0);sa[t]=-800000000;
txtype[9]=500;//ttype[9]=1;
}
}//103

if (stype[t]==104){
if (sxtype[t]==0){
ayobi(sa[t]+12000,sb[t]+2000+3000,0,0,0,79,0);
ayobi(sa[t]+12000,sb[t]+2000+3000,0,0,0,79,1);
ayobi(sa[t]+12000,sb[t]+2000+3000,0,0,0,79,2);
ayobi(sa[t]+12000,sb[t]+2000+3000,0,0,0,79,3);
ayobi(sa[t]+12000,sb[t]+2000+3000,0,0,0,79,4);
sa[t]=-800000000;
}}

if (stype[t]==105 && mzimen==0 && md>=0){ta[1]-=1000;ta[2]+=1000;sxtype[t]++;if (sxtype[t]>=3)sa[t]=-8000000;}


if (stype[t]==300 && mtype==0 && mb<xx[9]+sd[t]+xx[0]-3000 && mhp>=1){StopSoundMem(oto[0]);mtype=300;mtm=0;ma=sa[t]-fx-2000;ot(oto[11]);}

//���ԃQ�[�g
if (stype[t]==500 && mtype==0 && mhp>=1){
tyuukan+=1;
sa[t]=-80000000;
}

}

if (stype[t]==180){
sr[t]++;
if (sr[t]>=sgtype[t]){sr[t]=0;
ayobi(sa[t],30000,rand(600)-300,-1600-rand(900),0,84,0);
}
}

}
}}//��










//�L�[���͏�����
//for (t=0;t<=6;t++)
actaon[0]=0;actaon[4]=0;





//���t�g
for (t=0;t<srmax;t++){
xx[10]=sra[t];xx[11]=srb[t];xx[12]=src[t];xx[13]=srd[t];
xx[8]=xx[10]-fx;xx[9]=xx[11]-fy;
if (xx[8]+xx[12]>=-10-12000 && xx[8]<=fxmax+12100){
xx[0]=500;xx[1]=1200;xx[2]=1000;xx[7]=2000;
if (md>=100){xx[1]=900+md;}

//if (srtype[t]==1){xx[0]=600;}
if (md>xx[1])xx[1]=md+100;
//xx[18]=0;

srb[t]+=sre[t];
sre[t]+=srf[t];
//if (srf[t]>=500)srf[t]=0;




//����
switch(sracttype[t]){

case 1:
if (sron[t]==1)srf[t]=60;
break;


case 2:
/*
if (sra[t]<=srmovep[t]-srmove[t])srmuki[t]=1;
if (sra[t]>=srmovep[t]+srmove[t])srmuki[t]=0;
*/
break;

case 3:
/*
if (srb[t]<=srmovep[t]-srmove[t])srmuki[t]=1;
if (srb[t]>=srmovep[t]+srmove[t])srmuki[t]=0;
*/
break;

/*
case 4:
if (srmove[t]==0){srmuki[t]=0;}else{srmuki[t]=1;}
if (sra[t]-fx<-1100-src[t]){sra[t]=fymax+fx+scrollx;}
if (sra[t]-fx>24000+scrollx){sra[t]=-1100-src[t]+fx;}
break;
*/

case 5:
if (srmove[t]==0){srmuki[t]=0;}else{srmuki[t]=1;}
if (srb[t]-fy<-2100){srb[t]=fymax+fy+scrolly+2000;}
if (srb[t]-fy>fymax+scrolly+2000){srb[t]=-2100+fy;}
break;

case 6:
if (sron[t]==1)srf[t]=40;
break;

case 7:
break;


}//sw

//if (srtype[t]==1){sre[10]=300;sre[11]=300;}

//������Ƃ�
if (!(mztm>=1 && mztype==1 && actaon[3]==1) && mhp>=1){
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+xx[12]-xx[0] && mb+mnobib>xx[9] && mb+mnobib<xx[9]+xx[1] && md>=-100){
mb=xx[9]-mnobib+100;
//if (sracttype[t]!=7)mzimen=1;

if (srtype[t]==1){sre[10]=900;sre[11]=900;}

if (srsp[t]!=12){
mzimen=1;md=0;
}else {
//���ׂ�
//md=0;mrzimen=1;mzimen=1;
md=-800;
}


/*
md=0;
if ((sracttype[t]==1 || sracttype[t]==6) && sron[t]==1)mb+=sre[t];

if (sracttype[t]==2 || sracttype[t]==4){
if (srmuki[t]==0)ma-=srsok[t];
if (srmuki[t]==1)ma+=srsok[t];
}
*/

//����
if ((sracttype[t]==1) && sron[t]==0)sron[t]=1;

if (sracttype[t]==1 && sron[t]==1 || sracttype[t]==3 || sracttype[t]==5){
mb+=sre[t];
//if (srmuki[t]==0)
//if (srf[t]<0)
//if (srmuki[t]==1)
//if (srf[t]>0)
//mb+=srsok[t];
}

if (sracttype[t]==7){
if (actaon[2]!=1){md=-600;mb-=810;}
if (actaon[2]==1){mb-=400;md=-1400;mjumptm=10;}
}


//����
if (srsp[t]==1){
ot(oto[3]);
eyobi(sra[t]+200,srb[t]-1000,-240,-1400,0,160,4500,4500,2,120);
eyobi(sra[t]+4500-200,srb[t]-1000,240,-1400,0,160,4500,4500,3,120);
sra[t]=-70000000;
}





if (srsp[t]==2){
mc=-2400;srmove[t]+=1;
if (srmove[t]>=100){mhp=0;mmsgtype=53;mmsgtm=30;srmove[t]=-5000;}
}

if (srsp[t]==3){
mc=2400;srmove[t]+=1;
if (srmove[t]>=100){mhp=0;mmsgtype=53;mmsgtm=30;srmove[t]=-5000;}
}

//if (srtype[t]==1){md=-600;mb-=610;mhp-=1;if (mmutekion!=1)mmutekitm=40;}
}//�����


//��ꏉ����
if ((srsp[t]==2 || srsp[t]==3) && mc!=-2400 && srmove[t]>0){srmove[t]--;}

if (srsp[t]==11){
if (ma+mnobia>xx[8]+xx[0]-2000 && ma<xx[8]+xx[12]-xx[0]){sron[t]=1;}// && mb+mnobib>xx[9]-1000 && mb+mnobib<xx[9]+xx[1]+2000)
if (sron[t]==1){srf[t]=60;srb[t]+=sre[t];}
}


//�g�Q(��)
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+xx[12]-xx[0] && mb>xx[9]-xx[1]/2 && mb<xx[9]+xx[1]/2){
if (srtype[t]==2){if (md<0){md=-md;}mb+=110;if (mmutekitm<=0)mhp-=1;if (mmutekion!=1)mmutekitm=40;}
}
//����
if (sracttype[t]==6){
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+xx[12]-xx[0]){sron[t]=1;}
}

}//!

/*
//�W�����v��
if (sracttype[t]==7){
if (ma+mnobia>xx[8]+xx[0] && ma<xx[8]+xx[12]-xx[0] && mb+mnobib>xx[9]+xx[1]/2 && mb+mnobib<xx[9]+xx[1]*3/2 && md>=-100){
if (actaon[2]!=1){md=-600;mb-=810;}
if (actaon[2]==1){mb-=400;md=-1400;mjumptm=10;}
}}
*/


if (sracttype[t]==2 || sracttype[t]==4){
if (srmuki[t]==0)sra[t]-=srsok[t];
if (srmuki[t]==1)sra[t]+=srsok[t];
}
if (sracttype[t]==3 || sracttype[t]==5){
if (srmuki[t]==0)srb[t]-=srsok[t];
if (srmuki[t]==1)srb[t]+=srsok[t];
}






//�G�L�����K�p
for (tt=0;tt<amax;tt++){
if (azimentype[tt]==1){
if (aa[tt]+anobia[tt]-fx>xx[8]+xx[0] && aa[tt]-fx<xx[8]+xx[12]-xx[0] && ab[tt]+anobib[tt]>xx[11]-100 && ab[tt]+anobib[tt]<xx[11]+xx[1]+500 && ad[tt]>=-100){
ab[tt]=xx[9]-anobib[tt]+100;ad[tt]=0;axzimen[tt]=1;
}}}


}}//���t�g



















//�O��
for (t=0;t<emax;t++){
xx[0]=ea[t]-fx;xx[1]=eb[t]-fy;
xx[2]=enobia[t]/100;xx[3]=enobib[t]/100;
if (etm[t]>=0)etm[t]--;
if (xx[0]+xx[2]*100>=-10 && xx[1]<=fxmax && xx[1]+xx[3]*100>=-10-8000 && xx[3]<=fymax && etm[t]>=0){
ea[t]+=ec[t];eb[t]+=ed[t];
ec[t]+=ee[t];ed[t]+=ef[t];

}else{ea[t]=-9000000;}

}//emax






//�G�L�����̔z�u
for (t=0;t<bmax;t++){
if (ba[t]>=-80000){

if (btm[t]>=0){btm[t]=btm[t]-1;}

for (tt=0;tt<=1;tt++){
xx[0]=0;xx[1]=0;


if (bz[t]==0 && btm[t]<0 && ba[t]-fx>=fxmax+2000 && ba[t]-fx<fxmax+2000+mc && tt==0){xx[0]=1;amuki[aco]=0;}// && mmuki==1
if (bz[t]==0 && btm[t]<0 && ba[t]-fx>=-400-anx[btype[t]]+mc && ba[t]-fx<-400-anx[btype[t]] && tt==1){xx[0]=1;xx[1]=1;amuki[aco]=1;}// && mmuki==0
if (bz[t]==1 && ba[t]-fx>=0-anx[btype[t]] && ba[t]-fx<=fxmax+4000 && bb[t]-fy>=-9000 && bb[t]-fy<=fymax+4000 && btm[t]<0){xx[0]=1;bz[t]=0;}// && xza<=5000// && tyuukan!=1
//if (bz[t]==2){xx[0]=0;xx[1]=0;}
//if (btype[t]>=100){bz[t]=2;}

if (xx[0]==1){//400
btm[t]=401;xx[0]=0;//if (btype[t]>=20 && btype[t]<=23){btm[t]=90000;}
if (btype[t]>=10){btm[t]=9999999;}


//10
ayobi(ba[t],bb[t],0,0,0,btype[t],bxtype[t]);

}

}//tt

}}//t





//�G�L����
for (t=0;t<amax;t++){
xx[0]=aa[t]-fx;xx[1]=ab[t]-fy;
xx[2]=anobia[t];xx[3]=anobib[t];xx[14]=12000*1;
if (anotm[t]>=0)anotm[t]--;
if (xx[0]+xx[2]>=-xx[14] && xx[0]<=fxmax+xx[14] && xx[1]+xx[3]>=-10-9000 && xx[1]<=fymax+20000){
aacta[t]=0;aactb[t]=0;

xx[10]=0;

switch(atype[t]){
case 0:
xx[10]=100;
break;

//������̓G
case 1:
xx[10]=100;
break;

//������
case 2:
xx[10]=0;xx[17]=800;
if (axtype[t]>=1)xx[10]=xx[17];
//if (axtype[t]==1)xx[10]=xx[17];
//if (axtype[t]==2)xx[10]=-xx[17];
//���̓G��|��
if (axtype[t]>=1){
for (tt=0;tt<amax;tt++){
xx[0]=250;xx[5]=-800;xx[12]=0;xx[1]=1600;
xx[8]=aa[tt]-fx;xx[9]=ab[tt]-fy;
if (t!=tt){
if (aa[t]+anobia[t]-fx>xx[8]+xx[0]*2 && aa[t]-fx<xx[8]+anobia[tt]-xx[0]*2 && ab[t]+anobib[t]-fy>xx[9]+xx[5] && ab[t]+anobib[t]-fy<xx[9]+xx[1]*3+xx[12]+1500){
aa[tt]=-800000;ot(oto[6]);
}}}
}

break;

//����܂�
case 3:
azimentype[t]=0;//end();
if (axtype[t]==0){
ab[t]-=800;
}
if (axtype[t]==1)
ab[t]+=1200;

//xx[10]=100;
break;

//�X�[�p�[�W�G��
case 4:
xx[10]=120;
xx[0]=250;
xx[8]=aa[t]-fx;
xx[9]=ab[t]-fy;
if (atm[t]>=0)atm[t]--;
if (abs(ma+mnobia-xx[8]-xx[0]*2) < 9000 &&
    abs(ma<xx[8]-anobia[t]+xx[0]*2) < 3000 &&
    md<=-600 && atm[t]<=0){
  if (axtype[t]==1 && mzimen==0 && axzimen[t]==1){
    ad[t]=-1600;atm[t]=40;ab[t]-=1000;
  }
}// 
break;

//�N�}�[
case 5:
xx[10]=160;
//azimentype[t]=2;
break;

//�f�t���O����
case 6:
if (azimentype[t]==30){ad[t]=-1600;ab[t]+=ad[t];}

xx[10]=120;
if (atm[t]>=10){
atm[t]++;
if (mhp>=1){
if (atm[t]<=19){ma=xx[0];mb=xx[1]-3000;mtype=0;}
xx[10]=0;
if (atm[t]==20){mc=700;mkeytm=24;md=-1200;mb=xx[1]-1000-3000;amuki[t]=1;if (axtype[t]==1){mc=840;axtype[t]=0;}}
if (atm[t]==40){amuki[t]=0;atm[t]=0;}
}}

//�|�[���̂�
if (axtype[t]==1){
for (tt=0;tt<smax;tt++){
if (stype[tt]==300){
//sa[sco]=xx[21]*100;sb[sco]=xx[22]*100;sc[sco]=3000;sd[sco]=(12-t)*3000;stype[sco]=300;sco++;
if (aa[t]-fx>=-8000 && aa[t]>=sa[tt]+2000 && aa[t]<=sa[tt]+3600 && axzimen[t]==1){sa[tt]=-800000;atm[t]=100;}
}}

if (atm[t]==100){
eyobi(aa[t]+1200-1200,ab[t]+3000-10*3000-1500,0,0,0,0,1000,10*3000-1200,4,20);
if (mtype==300){mtype=0;StopSoundMem(oto[11]);bgmchange(oto[100]);PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP);}
for (t1=0;t1<smax;t1++){if (stype[t1]==104)sa[t1]=-80000000;}
}
if (atm[t]==120){eyobi(aa[t]+1200-1200,ab[t]+3000-10*3000-1500,600,-1200,0,160,1000,10*3000-1200,4,240);amuki[t]=1;}
//mc=700;mkeytm=24;md=-1200;mb=xx[1]-1000-3000;amuki[t]=1;if (axtype[t]==1){mc=840;axtype[t]=0;}}
if (atm[t]==140){amuki[t]=0;atm[t]=0;}
}
if (atm[t]>=220){atm[t]=0;amuki[t]=0;}

//���̓G�𓊂���
for (tt=0;tt<amax;tt++){
xx[0]=250;xx[5]=-800;xx[12]=0;xx[1]=1600;
xx[8]=aa[tt]-fx;xx[9]=ab[tt]-fy;
if (t!=tt && atype[tt]>=100){
if (aa[t]+anobia[t]-fx>xx[8]+xx[0]*2 && aa[t]-fx<xx[8]+anobia[tt]-xx[0]*2 && ab[t]+anobib[t]-fy>xx[9]+xx[5] && ab[t]+anobib[t]-fy<xx[9]+xx[1]*3+xx[12]+1500){
//aa[tt]=-800000;
amuki[tt]=1;aa[tt]=aa[t]+300;ab[tt]=ab[t]-3000;abrocktm[tt]=120;//aa[tt]=0;
atm[t]=200;amuki[t]=1;
}}}

break;

//�W�G����C
case 7:
azimentype[t]=0;
xx[10]=0;xx[11]=400;
if (axtype[t]==0)xx[10]=xx[11];
if (axtype[t]==1)xx[10]=-xx[11];
if (axtype[t]==2)ab[t]-=xx[11];
if (axtype[t]==3)ab[t]+=xx[11];
break;

//�X�[�p�[�u�[��
case 8:
azimentype[t]=0;
xx[22]=20;
if (atm[t]==0){af[t]+=xx[22];ad[t]+=xx[22];}
if (atm[t]==1){af[t]-=xx[22];ad[t]-=xx[22];}
if (ad[t]>300)ad[t]=300;
if (ad[t]<-300)ad[t]=-300;
if (af[t]>=1200)atm[t]=1;
if (af[t]<-0)atm[t]=0;
ab[t]+=ad[t];
//atype[t]=151;
break;
//�m�[�}���u�[��
case 151:
azimentype[t]=2;
break;

//�t�@�C�A�[��
case 9:
azimentype[t]=5;
ab[t]+=ad[t];ad[t]+=100;
if (ab[t]>=fymax+1000){ad[t]=900;}
if (ab[t]>=fymax+12000){
ab[t]=fymax;ad[t]=-2600;
}
break;

//�t�@�C�A�[
case 10:
azimentype[t]=0;
xx[10]=0;xx[11]=400;
if (axtype[t]==0)xx[10]=xx[11];
if (axtype[t]==1)xx[10]=-xx[11];
break;


//�������[
case 30:
atm[t]+=1;
if (axtype[t]==0){
if (atm[t]==50 && mb>=6000){ac[t]=300;ad[t]-=1600;ab[t]-=1000;}

for (tt=0;tt<amax;tt++){
xx[0]=250;xx[5]=-800;xx[12]=0;xx[1]=1600;
xx[8]=aa[tt]-fx;xx[9]=ab[tt]-fy;
if (t!=tt && atype[tt]==102){
if (aa[t]+anobia[t]-fx>xx[8]+xx[0]*2 && aa[t]-fx<xx[8]+anobia[tt]-xx[0]*2 && ab[t]+anobib[t]-fy>xx[9]+xx[5] && ab[t]+anobib[t]-fy<xx[9]+xx[1]*3+xx[12]+1500){
aa[tt]=-800000;axtype[t]=1;ad[t]=-1600;
amsgtm[t]=30;amsgtype[t]=25;
}}}
}
if (axtype[t]==1){
azimentype[t]=0;
ab[t]+=ad[t];ad[t]+=120;
}
break;

//���[�U�[
case 79:
azimentype[t]=0;
xx[10]=1600;
if (axtype[t]==1){xx[10]=1200;ab[t]-=200;}
if (axtype[t]==2){xx[10]=1200;ab[t]+=200;}
if (axtype[t]==3){xx[10]=900;ab[t]-=600;}
if (axtype[t]==4){xx[10]=900;ab[t]+=600;}
break;

//�_�̓G
case 80:
azimentype[t]=0;
//xx[10]=100;
break;
case 81:
azimentype[t]=0;
break;
case 82:
azimentype[t]=0;
break;
case 83:
azimentype[t]=0;
break;

case 84:
azimentype[t]=2;
break;

case 85:
xx[23]=400;
if (axtype[t]==0){axtype[t]=1;amuki[t]=1;}
if (mb>=30000 && ma>=aa[t]-3000*5-fx && ma<=aa[t]-fx && axtype[t]==1){axtype[t]=5;amuki[t]=0;}
if (mb>=24000 && ma<=aa[t]+3000*8-fx && ma>=aa[t]-fx && axtype[t]==1){axtype[t]=5;amuki[t]=1;}
if (axtype[t]==5)xx[10]=xx[23];
break;

case 86:
azimentype[t]=4;
xx[23]=1000;
if (ma>=aa[t]-fx-mnobia-xx[26] && ma<=aa[t]-fx+anobia[t]+xx[26]){atm[t]=1;}
if (atm[t]==1){ab[t]+=1200;}
break;

//�t�@�C�A�o�[
case 87:
azimentype[t]=0;
if (aa[t]%10!=1)atm[t]+=6;
else{atm[t]-=6;}
xx[25]=2;
if (atm[t]>360*xx[25])atm[t]-=360*xx[25];
if (atm[t]<0)atm[t]+=360*xx[25];

for (tt=0;tt<=axtype[t]%100;tt++){
xx[26]=18;
xd[4]=tt*xx[26]*cos(atm[t]*pai/180/2);xd[5]=tt*xx[26]*sin(atm[t]*pai/180/2);

xx[4]=1800;xx[5]=800;
xx[8]=aa[t]-fx+int(xd[4])*100-xx[4]/2;xx[9]=ab[t]-fy+int(xd[5])*100-xx[4]/2;

if (ma+mnobia>xx[8]+xx[5] && ma<xx[8]+xx[4]-xx[5] && mb+mnobib>xx[9]+xx[5] && mb<xx[9]+xx[4]-xx[5]){
mhp-=1;
mmsgtype=51;mmsgtm=30;
}
}

break;

case 88:
azimentype[t]=0;
if (aa[t]%10!=1)atm[t]+=6;
else{atm[t]-=6;}
xx[25]=2;
if (atm[t]>360*xx[25])atm[t]-=360*xx[25];
if (atm[t]<0)atm[t]+=360*xx[25];

for (tt=0;tt<=axtype[t]%100;tt++){
xx[26]=18;
xd[4]=-tt*xx[26]*cos(atm[t]*pai/180/2);
xd[5]=tt*xx[26]*sin(atm[t]*pai/180/2);

xx[4]=1800;
xx[5]=800;
xx[8]=aa[t]-fx+int(xd[4])*100-xx[4]/2;
xx[9]=ab[t]-fy+int(xd[5])*100-xx[4]/2;

if (ma+mnobia>xx[8]+xx[5] && ma<xx[8]+xx[4]-xx[5] && mb+mnobib>xx[9]+xx[5] && mb<xx[9]+xx[4]-xx[5]){
mhp-=1;
mmsgtype=51;mmsgtm=30;
}
}

break;


case 90:
xx[10]=160;
//azimentype[t]=0;
break;


//���������L�m�R
case 100:
azimentype[t]=1;
xx[10]=100;

//�ق��̓G�����剻
if (axtype[t]==2){
for (tt=0;tt<amax;tt++){
xx[0]=250;xx[5]=-800;xx[12]=0;xx[1]=1600;
xx[8]=aa[tt]-fx;xx[9]=ab[tt]-fy;
if (t!=tt){
if (aa[t]+anobia[t]-fx>xx[8]+xx[0]*2 && aa[t]-fx<xx[8]+anobia[tt]-xx[0]*2 && ab[t]+anobib[t]-fy>xx[9]+xx[5] && ab[t]+anobib[t]-fy<xx[9]+xx[1]*3+xx[12]){
if (atype[tt]==0 || atype[tt]==4){
atype[tt]=90;//ot(oto[6]);
anobia[tt]=6400;anobib[tt]=6300;axtype[tt]=0;
aa[tt]-=1050;ab[tt]-=1050;
ot(oto[9]);aa[t]=-80000000;
}
}}}}

break;

//�ŃL�m�R
case 102:
azimentype[t]=1;
xx[10]=100;
if (axtype[t]==1)xx[10]=200;
break;

//���X�^�[
case 110:
azimentype[t]=1;
xx[10]=200;
if (axzimen[t]==1){
ab[t]-=1200;ad[t]=-1400;
}
break;


case 200:
azimentype[t]=1;
xx[10]=100;
break;

/*
case 1:
xx[10]=180;
if (axtype[t]==2)xx[10]=0;
if (axzimen[t]==1){
ab[t]-=1000;ad[t]=-1200;
if (axtype[t]==1)ad[t]=-1600;
if (axtype[t]==2){
atm[t]+=1;
if (atm[t]>=2){atm[t]=0;ad[t]=-1600;}else{ad[t]=-1000;}
}
}

break;

case 2:
xx[10]=160;
if (axtype[t]==1)azimentype[t]=2;xx[10]=100;
if (axtype[t]==2)xx[10]=0;
break;

case 3:
xx[10]=180;
if (ae[t]==0)ad[t]+=10;
if (ae[t]==1)ad[t]-=10;
if (ad[t]>=100)ae[t]=1;
if (ad[t]<=-100)ae[t]=0;
ab[t]+=ad[t];//ad[t]+=

if (axtype[t]==1){
if (ab[t]<mb){ab[t]+=100;}
}
if (axtype[t]==2)xx[10]=0;
break;

case 4:
if (ae[t]==0)ad[t]+=8;
if (ae[t]==1)ad[t]-=8;
if (ad[t]>=80)ae[t]=1;
if (ad[t]<=-80)ae[t]=0;
ab[t]+=ad[t];

//sstr=""+atm[t];
if (axtype[t]>=1){
xx[22]=200;xx[21]=3600;

if (atm[t]==0){atm[t]=ab[t]%2+1;a2tm[t]=aa[t];if (axtype[t]%2==0)a2tm[t]=ab[t];}

if (axtype[t]%2==1){
if (aa[t]<a2tm[t]-xx[21]){atm[t]=2;}
if (aa[t]>a2tm[t]+xx[21]){atm[t]=1;}
if (atm[t]==1){aa[t]-=xx[22];amuki[t]=0;}
if (atm[t]==2){aa[t]+=xx[22];amuki[t]=1;}
}
if (axtype[t]%2==0){
if (ab[t]<a2tm[t]-xx[21]){atm[t]=2;}
if (ab[t]>a2tm[t]+xx[21]){atm[t]=1;}
if (atm[t]==1){ab[t]-=xx[22];}
if (atm[t]==2){ab[t]+=xx[22];}
}

}//axtype1

break;

case 5:
xx[10]=120;atm[t]++;
if (axtype[t]==2){xx[10]=200;azimentype[t]=2;}
if (ma+mnobia>=aa[t]-fx && ma<=aa[t]+anobia[t]-fx && mb+mnobib+1000<ab[t]-fy){
xx[10]=300;
if (axtype[t]>=1){
//xx[10]=240;
if (atm[t]>=16){amuki[t]+=1;if (amuki[t]>=2)amuki[t]=0;atm[t]=0;
//if (axtype[t]==2){ab[t]-=600;ad[t]=-900;}
}}
}
break;

case 6:
atm[t]+=1;xx[10]=0;
if (axtype[t]==1)atm[t]+=(rand(9)-4);
if (axtype[t]==2)xx[10]=100;
if (atm[t]>=40){
xx[22]=360;if (amuki[t]==0)xx[22]=-xx[22];
cyobi(aa[t]+amuki[t]*anobia[t],ab[t]+1600,xx[22],0,0,0,0,60);
atm[t]=0;
}

if (axtype[t]!=2){
if (ma+mnobia/2<=aa[t]+anobia[t]/2-fx){amuki[t]=0;}else{amuki[t]=1;}
}
break;


case 7:
xx[10]=160;
if (axtype[t]==1)xx[10]=240;
if (axtype[t]==2)xx[10]=60;
break;

case 8:
atm[t]+=1;xx[10]=0;
xx[15]=12;xx[17]=0;
if (axtype[t]==1)xx[15]=8;
if (axtype[t]==2){xx[15]=40;xx[17]=3;}

if (atm[t]>=xx[15]){
for (t3=0;t3<=xx[17];t3++){
xx[16]=300;xx[22]=rand(xx[16])*5/4-xx[16]/4;
a2tm[t]+=1;if (a2tm[t]>=1){xx[22]=-xx[22];a2tm[t]=-1;}
cyobi(aa[t]+amuki[t]*anobia[t]/2,ab[t]+600,xx[22],-400-rand(600),0,80,1,60);
//if ((xx[16]==0) || t3==xx[16])atm[t]=0;
}//t
atm[t]=0;
}

break;


*/


}//sw


if (abrocktm[t]>=1)xx[10]=0;



if (amuki[t]==0)aacta[t]-=xx[10];
if (amuki[t]==1)aacta[t]+=xx[10];



//�ő�l
xx[0]=850;xx[1]=1200;

//if (mc>xx[0]){mc=xx[0];}
//if (mc<-xx[0]){mc=-xx[0];}
if (ad[t]>xx[1] && azimentype[t]!=5){ad[t]=xx[1];}


//�s��
aa[t]+=aacta[t];//ab[t]+=aactb[t];






if ((azimentype[t]>=1 || azimentype[t]==-1) && abrocktm[t]<=0){
//if (atype[t]==4)end();

//�ړ�
aa[t]+=ac[t];
if (azimentype[t]>=1 && azimentype[t]<=3){ab[t]+=ad[t];ad[t]+=120;}//ad[t]+=180;


if (axzimen[t]==1){
xx[0]=100;
if (ac[t]>=200){ac[t]-=xx[0];}
else if (ac[t]<=-200){ac[t]+=xx[0];}
else {ac[t]=0;}
}

axzimen[t]=0;




//�n�ʔ���
if (azimentype[t]!=2){
tekizimen();
}



}//azimentype[t]>=1

//�u���b�N����o�����邳��
if (abrocktm[t]>0){
abrocktm[t]--;
if (abrocktm[t]<100){ab[t]-=180;}
if (abrocktm[t]>100){}
if (abrocktm[t]==100){ab[t]-=800;ad[t]=-1200;ac[t]=700;abrocktm[t]=0;}
}//abrocktm[t]>0





//�v���C���[����̔���
xx[0]=250;xx[1]=1600;xx[2]=1000;
xx[4]=500;xx[5]=-800;

xx[8]=aa[t]-fx;xx[9]=ab[t]-fy;
xx[12]=0;if (md>=100)xx[12]=md;
xx[25]=0;

if (ma+mnobia>xx[8]+xx[0]*2 && ma<xx[8]+anobia[t]-xx[0]*2 && mb+mnobib>xx[9]-xx[5] && mb+mnobib<xx[9]+xx[1]+xx[12] && (mmutekitm<=0 || md>=100) && abrocktm[t]<=0){
if (atype[t]!=4 && atype[t]!=9 && atype[t]!=10 && (atype[t]<=78 || atype[t]==85) && mzimen!=1 && mtype!=200){// && atype[t]!=4 && atype[t]!=7){

if (atype[t]==0){
if (axtype[t]==0)
aa[t]=-900000;
if (axtype[t]==1){ot(oto[5]);
mb=xx[9]-900-anobib[t];md=-2100;xx[25]=1;actaon[2]=0;
}
}

if (atype[t]==1){
atype[t]=2;anobib[t]=3000;axtype[t]=0;
}

//������
else if (atype[t]==2 && md>=0){
if (axtype[t]==1 || axtype[t]==2){axtype[t]=0;}
else if (axtype[t]==0){
if (ma+mnobia>xx[8]+xx[0]*2 && ma<xx[8]+anobia[t]/2-xx[0]*4){
axtype[t]=1;amuki[t]=1;
}else{axtype[t]=1;amuki[t]=0;}}
}
if (atype[t]==3){
xx[25]=1;
}

if (atype[t]==6){
atm[t]=10;md=0;actaon[2]=0;
}

if (atype[t]==7){
aa[t]=-900000;
}

if (atype[t]==8){
atype[t]=151;ad[t]=0;
}

//if (atype[t]==4){
//xx[25]=1;
//}

if (atype[t]!=85){
if (xx[25]==0){ot(oto[5]);mb=xx[9]-1000-anobib[t];md=-1000;}
}
if (atype[t]==85){
if (xx[25]==0){ot(oto[5]);mb=xx[9]-4000;md=-1000;axtype[t]=5;}
}

if (actaon[2]==1){md=-1600;actaon[2]=0;}
}
//if (atype[t]==200){mb=xx[9]-900-anobib[t];md=-2400;}
}

//if (aa[t]+anobia[t]-fx>xx[8]-xx[0] && aa[t]-fx<xx[8]){md=-1000;}//aa[t]=-9000000;
// && ab[t]-fy<xx[9]+xx[1]/2 && ab[t]+anobib[t]-fy>xx[9]+mnobib-xx[2]

xx[15]=-500;


//�v���C���[�ɐG�ꂽ��
xx[16]=0;
if (atype[t]==4 || atype[t]==9 || atype[t]==10)xx[16]=-3000;
if (atype[t]==82 || atype[t]==83 || atype[t]==84)xx[16]=-3200;
if (atype[t]==85)xx[16]=-anobib[t]+6000;
if (ma+mnobia>xx[8]+xx[4] && ma<xx[8]+anobia[t]-xx[4] && mb<xx[9]+anobib[t]+xx[15] && mb+mnobib>xx[9]+anobib[t]-xx[0]+xx[16] && anotm[t]<=0 && abrocktm[t]<=0){
if (mmutekion==1){aa[t]=-9000000;}
if (mmutekitm<=0 && (atype[t]<=99 || atype[t]>=200)){
if (mmutekion!=1 && mtype!=200){
//if (mmutekitm<=0)

//�_���[�W
if ((atype[t]!=2 || axtype[t]!=0) && mhp>=1){
if (atype[t]!=6){
mhp-=1;
//mmutekitm=40;
}}



if (atype[t]==6){
atm[t]=10;
}


//�����
if (mhp==0){

if (atype[t]==0 || atype[t]==7){
amsgtm[t]=60;amsgtype[t]=rand(7)+1+1000+(stb-1)*10;
}

if (atype[t]==1){
amsgtm[t]=60;amsgtype[t]=rand(2)+15;
}

if (atype[t]==2 && axtype[t]>=1 && mmutekitm<=0){
amsgtm[t]=60;amsgtype[t]=18;
}

if (atype[t]==3){
amsgtm[t]=60;amsgtype[t]=20;
}

if (atype[t]==4){
amsgtm[t]=60;amsgtype[t]=rand(7)+1+1000+(stb-1)*10;
}

if (atype[t]==5){
amsgtm[t]=60;amsgtype[t]=21;
}

if (atype[t]==9 || atype[t]==10){
mmsgtm=30;mmsgtype=54;
}



if (atype[t]==31){
amsgtm[t]=30;amsgtype[t]=24;
}


if (atype[t]==80 || atype[t]==81){
amsgtm[t]=60;amsgtype[t]=30;
}

if (atype[t]==82){
amsgtm[t]=20;amsgtype[t]=rand(1)+31;
xx[24]=900;atype[t]=83;aa[t]-=xx[24]+100;ab[t]-=xx[24]-100*0;
}//82

if (atype[t]==84){
mmsgtm=30;mmsgtype=50;
}

if (atype[t]==85){
amsgtm[t]=60;amsgtype[t]=rand(1)+85;
}


//�_
if (atype[t]==80){
atype[t]=81;
}


}//mhp==0


//������
if (atype[t]==2){
//if (axtype[t]==1 || axtype[t]==2){axtype[t]=0;}
if (axtype[t]==0){
if (ma+mnobia>xx[8]+xx[0]*2 && ma<xx[8]+anobia[t]/2-xx[0]*4){
axtype[t]=1;amuki[t]=1;aa[t]=ma+mnobia+fx+mc;mmutekitm=5;
}else{
axtype[t]=1;amuki[t]=0;aa[t]=ma-anobia[t]+fx-mc;mmutekitm=5;
}}else{mhp-=1;}//mmutekitm=40;}
}


}}
//else if (mmutekitm>=0 && mmutekitm<=2){mmutekitm+=1;}
//�A�C�e��
if (atype[t]>=100 && atype[t]<=199){

if (atype[t]==100 && axtype[t]==0){mmsgtm=30;mmsgtype=1;ot(oto[9]);}
if (atype[t]==100 && axtype[t]==1){mmsgtm=30;mmsgtype=2;ot(oto[9]);}
if (atype[t]==100 && axtype[t]==2){mnobia=5200;mnobib=7300;ot(oto[9]);ma-=1100;mb-=4000;mtype=1;mhp=50000000;}

if (atype[t]==101){mhp-=1;mmsgtm=30;mmsgtype=11;}
if (atype[t]==102){mhp-=1;mmsgtm=30;mmsgtype=10;}


//?�{�[��
if (atype[t]==105){
if (axtype[t]==0){
ot(oto[4]);sgtype[26]=6;
}
if (axtype[t]==1){
txtype[7]=80;
ot(oto[4]);

//ayobi(aa[t]-6*3000+1000,-3*3000,0,0,0,110,0);
ayobi(aa[t]-8*3000-1000,-4*3000,0,0,0,110,0);
ayobi(aa[t]-10*3000+1000,-1*3000,0,0,0,110,0);

ayobi(aa[t]+4*3000+1000,-2*3000,0,0,0,110,0);
ayobi(aa[t]+5*3000-1000,-3*3000,0,0,0,110,0);
ayobi(aa[t]+6*3000+1000,-4*3000,0,0,0,110,0);
ayobi(aa[t]+7*3000-1000,-2*3000,0,0,0,110,0);
ayobi(aa[t]+8*3000+1000,-2*3000-1000,0,0,0,110,0);
tb[0]+=3000*3;
}
}//105



if (atype[t]==110){mhp-=1;mmsgtm=30;mmsgtype=3;}

/*
if (atype[t]==101){mmutekitm=120;mmutekion=1;}
if (atype[t]==102){mhp-=1;mmutekitm=20;}
if (atype[t]==103){
//xx[24]=2400;
eyobi(aa[t]-500,ab[t],0,-600,0,80,2500,1600,2,32);
}
if (atype[t]==104){mztm=120;mztype=1;}
if (atype[t]==105){mztm=160;mztype=2;}

if (atype[t]==120){mtype=3;mnobia=3800;mnobib=2300;}


if (atype[t]==130){msoubi=1;}
if (atype[t]==131){msoubi=2;}
if (atype[t]==132){msoubi=3;}
if (atype[t]==133){msoubi=4;}

*/
aa[t]=-90000000;
}

}//(ma






}
else{aa[t]=-9000000;}

}//t







//�X�N���[��
//xx[0]=xx[0];
//x
if (kscroll!=1 && kscroll!=2){
xx[2]=mascrollmax;xx[3]=0;
xx[1]=xx[2];if (ma>xx[1] && fzx<scrollx){xx[5]=ma-xx[1];ma=xx[1];fx+=xx[5];fzx+=xx[5];if (xx[1]<=5000)xx[3]=1;}
//if (kscroll!=5){//�߂�Ȃ�
//xx[1]=xx[2]-500;if (ma<xx[1] && fzx>700){xx[5]=xx[1]-ma;ma=xx[1];fx-=xx[5];fzx-=xx[5];}
//}
//if (xx[3]==1){if (tyuukan==1)tyuukan=1;}
}//kscroll





}//if (main==1){


//�X�^�b�t���[��
if (main==2){
maintm++;

xx[7]=46;
if (CheckHitKey(KEY_INPUT_1)==1){end();}
if (CheckHitKey(KEY_INPUT_SPACE)==1){for (t=0;t<=xx[7];t+=1){xx[12+t]-=300;}}

if (maintm<=1){
maintm=2;bgmchange(oto[106]);PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP);xx[10]=0;
for (t=0;t<=xx[7];t+=1){xx[12+t]=980000;}
//for (t=0;t<=xx[7];t+=2){xx[12+t]=46000;}
xx[12]=460;
xx[13]=540;xx[14]=590;
xx[15]=650;xx[16]=700;
xx[17]=760;xx[18]=810;
xx[19]=870;xx[20]=920;

xx[21]=1000;xx[22]=1050;xx[23]=1100;
xx[24]=1180;xx[25]=1230;

xx[26]=1360;xx[27]=1410;
xx[28]=1540;xx[29]=1590;

xx[30]=1800;

for (t=0;t<=xx[7];t+=1){xx[12+t]*=100;}
}

xx[10]+=1;
for (t=0;t<=xx[7];t+=1){xx[12+t]-=100;}//t

if (xx[30]==-200){bgmchange(oto[106]);}
if (xx[30]<=-400){main=100;nokori=2;maintm=0;ending=0;}

}//main==2


if (main==10){
maintm++;

if (fast==1)maintm+=2;
if (maintm>=30){maintm=0;main=1;zxon=0;}
}//if (main==10){


//�^�C�g��
if (main==100){
maintm++;xx[0]=0;
if (maintm<=10){maintm=11;sta=1;stb=1;stc=0;over=0;}

if (CheckHitKey(KEY_INPUT_1)==1){sta=1;stb=1;stc=0;}
if (CheckHitKey(KEY_INPUT_2)==1){sta=1;stb=2;stc=0;}
if (CheckHitKey(KEY_INPUT_3)==1){sta=1;stb=3;stc=0;}
if (CheckHitKey(KEY_INPUT_4)==1){sta=1;stb=4;stc=0;}
if (CheckHitKey(KEY_INPUT_5)==1){sta=2;stb=1;stc=0;}
if (CheckHitKey(KEY_INPUT_6)==1){sta=2;stb=2;stc=0;}
if (CheckHitKey(KEY_INPUT_7)==1){sta=2;stb=3;stc=0;}
if (CheckHitKey(KEY_INPUT_8)==1){sta=2;stb=4;stc=0;}
if (CheckHitKey(KEY_INPUT_9)==1){sta=3;stb=1;stc=0;}
if (CheckHitKey(KEY_INPUT_0)==1){xx[0]=1;over=1;}


//if (CheckHitKeyAll() == 0){end();}
if (CheckHitKey(KEY_INPUT_RETURN)==1){xx[0]=1;}
//if (CheckHitKey(KEY_INPUT_SPACE)==1){xx[0]=1;}
if (CheckHitKey(KEY_INPUT_Z)==1){xx[0]=1;}

if (xx[0]==1){
main=10;zxon=0;maintm=0;
nokori=2;

fast=0;trap=0;tyuukan=0;
}

}//100



//�`��
rpaint();


//30-fps
xx[0]=30;
if (CheckHitKey(KEY_INPUT_SPACE)==1){xx[0]=60;}
wait2(stime,long(GetNowCount()),1000/xx[0]);
//wait(20);

}//Mainprogram()


void tekizimen(){

//��
for (tt=0;tt<smax;tt++){
if (sa[tt]-fx+sc[tt]>=-12010 && sa[tt]-fx<=fxmax+12100 && stype[tt]<=99){
xx[0]=200;xx[2]=1000;
xx[1]=2000;//anobia[t]

xx[8]=sa[tt]-fx;xx[9]=sb[tt]-fy;
if (aa[t]+anobia[t]-fx>xx[8]-xx[0] && aa[t]-fx<xx[8]+xx[2] && ab[t]+anobib[t]-fy>xx[9]+xx[1]*3/4 && ab[t]-fy<xx[9]+sd[tt]-xx[2]){aa[t]=xx[8]-xx[0]-anobia[t]+fx;amuki[t]=0;}
if (aa[t]+anobia[t]-fx>xx[8]+sc[tt]-xx[0] && aa[t]-fx<xx[8]+sc[tt]+xx[0] && ab[t]+anobib[t]-fy>xx[9]+xx[1]*3/4 && ab[t]-fy<xx[9]+sd[tt]-xx[2]){aa[t]=xx[8]+sc[tt]+xx[0]+fx;amuki[t]=1;}

//if (aa[t]+anobia[t]-fx>xx[8]+xx[0] && aa[t]-fx<xx[8]+sc[tt]-xx[0] && ab[t]+anobib[t]-fy>xx[9] && ab[t]+anobib[t]-fy<xx[9]+xx[1] && ad[t]>=-100){ab[t]=sb[tt]-fy-anobib[t]+100+fy;ad[t]=0;}//mzimen=1;}
if (aa[t]+anobia[t]-fx>xx[8]+xx[0] && aa[t]-fx<xx[8]+sc[tt]-xx[0] && ab[t]+anobib[t]-fy>xx[9] && ab[t]+anobib[t]-fy<xx[9]+sd[tt]-xx[1] && ad[t]>=-100){ab[t]=sb[tt]-fy-anobib[t]+100+fy;ad[t]=0;axzimen[t]=1;}

if (aa[t]+anobia[t]-fx>xx[8]+xx[0] && aa[t]-fx<xx[8]+sc[tt]-xx[0] && ab[t]-fy>xx[9]+sd[tt]-xx[1] && ab[t]-fy<xx[9]+sd[tt]+xx[0]){
ab[t]=xx[9]+sd[tt]+xx[0]+fy;if (ad[t]<0){ad[t]=-ad[t]*2/3;}//axzimen[t]=1;
}

}}






//�u���b�N
for (tt=0;tt<tmax;tt++){
xx[0]=200;xx[1]=3000;xx[2]=1000;
xx[8]=ta[tt]-fx;xx[9]=tb[tt]-fy;
if (ta[tt]-fx+xx[1]>=-12010 && ta[tt]-fx<=fxmax+12000){
if (atype[t]!=86 && atype[t]!=90 && ttype[tt]!=140){

//��
if (ttype[tt]!=7){
//if (ttype[tt]==117 && txtype[t]==1){ad[t]=-1500;}
if (!(ttype[tt]==117)){
//if (!(ttype[tt]==120 && txtype[t]==0)){
if (aa[t]+anobia[t]-fx>xx[8]+xx[0] && aa[t]-fx<xx[8]+xx[1]-xx[0]*1 && ab[t]+anobib[t]-fy>xx[9] && ab[t]+anobib[t]-fy<xx[9]+xx[1] && ad[t]>=-100){
ab[t]=xx[9]-anobib[t]+100+fy;ad[t]=0;axzimen[t]=1;
//�W�����v��
if (ttype[tt]==120){ad[t]=-1600;azimentype[t]=30;}
//}

}
}}


//��
if (ttype[tt]!=117){
if (aa[t]+anobia[t]-fx>xx[8]+xx[0] && aa[t]-fx<xx[8]+xx[1]-xx[0]*1 && ab[t]-fy>xx[9]+xx[1]-xx[1] && ab[t]-fy<xx[9]+xx[1]+xx[0]){
ab[t]=xx[9]+xx[1]+xx[0]+fy;if (ad[t]<0){ad[t]=0;}//=-ad[t]*2/3;}
//if (ttype[t]==7){
//for (t2=0;t2<tmax;t2++){if (ttype[t2]==5){ttype[t2]=6;}else if (ttype[t2]==6){ttype[t2]=5;}}
//}
}}

//���E
xx[27]=0;
if ((atype[t]>=100 || (ttype[tt]!=7 || ttype[tt]==7 && atype[t]==2)) && ttype[tt]!=117){
if (aa[t]+anobia[t]-fx>xx[8] && aa[t]-fx<xx[8]+xx[2] && ab[t]+anobib[t]-fy>xx[9]+xx[1]/2-xx[0] && ab[t]-fy<xx[9]+xx[2]){aa[t]=xx[8]-anobia[t]+fx;ac[t]=0;amuki[t]=0;xx[27]=1;}
if (aa[t]+anobia[t]-fx>xx[8]+xx[1]-xx[0]*2 && aa[t]-fx<xx[8]+xx[1] && ab[t]+anobib[t]-fy>xx[9]+xx[1]/2-xx[0] && ab[t]-fy<xx[9]+xx[2]){aa[t]=xx[8]+xx[1]+fx;ac[t]=0;amuki[t]=1;xx[27]=1;}
//������u���C�N
if (xx[27]==1 && (ttype[tt]==7 || ttype[tt]==1) && atype[t]==2){
if (ttype[tt]==7){
ot(oto[4]);ttype[tt]=3;
eyobi(ta[tt]+10,tb[tt],0,-800,0,40,3000,3000,0,16);
}
else if (ttype[tt]==1){
ot(oto[3]);
eyobi(ta[tt]+1200,tb[tt]+1200,300,-1000,0,160,1000,1000,1,120);
eyobi(ta[tt]+1200,tb[tt]+1200,-300,-1000,0,160,1000,1000,1,120);
eyobi(ta[tt]+1200,tb[tt]+1200,240,-1400,0,160,1000,1000,1,120);
eyobi(ta[tt]+1200,tb[tt]+1200,-240,-1400,0,160,1000,1000,1,120);
brockbreak(tt);
}

}
}}
if (atype[t]==86 || atype[t]==90){
if (aa[t]+anobia[t]-fx>xx[8] && aa[t]-fx<xx[8]+xx[1] && ab[t]+anobib[t]-fy>xx[9] && ab[t]-fy<xx[9]+xx[1]){
ot(oto[3]);
eyobi(ta[tt]+1200,tb[tt]+1200,300,-1000,0,160,1000,1000,1,120);
eyobi(ta[tt]+1200,tb[tt]+1200,-300,-1000,0,160,1000,1000,1,120);
eyobi(ta[tt]+1200,tb[tt]+1200,240,-1400,0,160,1000,1000,1,120);
eyobi(ta[tt]+1200,tb[tt]+1200,-240,-1400,0,160,1000,1000,1,120);
brockbreak(tt);

}
}//90


}
//���Ƃ��ăN���A
if (ttype[tt]==140){
if (ab[t]-fy>xx[9]-xx[0]*2-2000 && ab[t]-fy<xx[9]+xx[1]-xx[0]*2+2000 && aa[t]+anobia[t]-fx>xx[8]-400 && aa[t]-fx<xx[8]+xx[1]){
ta[tt]=-800000;//ot(oto[4]);
sracttype[20]=1;sron[20]=1;
}}
}//tt

}//tekizimen



//�X���[�v
static void wait(int interval){
WaitTimer(interval) ;
}

//�^�C�}�[����
static void wait2(long stime, long etime,int FLAME_TIME){
if (etime-stime<FLAME_TIME)
wait(FLAME_TIME-(etime-stime));
}


//�����쐬
static int rand(int Rand){
return GetRand(Rand);
}

//�I��
void end(){
//maint=3;
DxLib_End() ;
}


//�摜�֌W
//{
//�F����(�w��)
void setcolor(int red, int green, int blue){
color=GetColor(red,green,blue) ;
}
//�F����(��)(��)
void setc0(){color=GetColor(0,0,0);}
void setc1(){color=GetColor(255,255,255);}

//�_
void drawpixel(int a,int b){DrawPixel(a,b,color);}
//��
void drawline(int a,int b,int c,int d){DrawLine(a,b,c,d,color);}
//�l�p�`(�h�薳��)
void drawrect(int a,int b,int c,int d){DrawBox(a,b,a+c,b+d,color,FALSE);}
//�l�p�`(�h��L��)
void fillrect(int a,int b,int c,int d){DrawBox(a,b,a+c,b+d,color,TRUE);}
//�~(�h�薳��)
void drawarc(int a,int b,int c,int d){DrawOval(a,b,c,d,color,FALSE);}
//�~(�h��L��)
void fillarc(int a,int b,int c,int d){DrawOval(a,b,c,d,color,TRUE);}

//�摜�̓ǂݍ���
int loadimage(string x){
//mgrap[a]=LoadGraph(b);
return LoadGraph(x.c_str());
}
int loadimage(int a,int x,int y,int r,int z){
return DerivationGraph(x,y,r,z,a);
}

//�摜�\��
void drawimage(int mx,int a,int b){
if (mirror==0)
DrawGraph(a,b,mx,TRUE);
if (mirror==1)
DrawTurnGraph(a,b,mx,TRUE);
}
void drawimage(int mx,int a,int b,int c,int d,int e,int f){
int m;
m=DerivationGraph(c,d,e,f,mx);
if (mirror==0)
DrawGraph(a,b,m,TRUE);
if (mirror==1)
DrawTurnGraph(a,b,m,TRUE);
}

//���]
void setre(){}//g.setFlipMode(Graphics.FLIP_HORIZONTAL);}
void setre2(){}//g.setFlipMode(Graphics.FLIP_VERTICAL);}
void setno(){}//g.setFlipMode(Graphics.FLIP_NONE);}

/*
//����
void str(char d[],int a,int b){
//char d[]=c;
DrawString(a,b,d,color);
}
*/

//����
void str(string x,int a,int b){
//char d[]="��";
DrawString(a,b,x.c_str(),color);
//DrawString(10,10,xs[3].c_str(),color);

xx[2]=4;


}

/*
//���l�𕶎��ɕϊ�
void strchange(string x,int a){
}
*/

/*
//�����ɂ��킹��//(font)
void str1(String c,int r,int b){
int a=0,x=0;
int d=6;

//x=c.length()*d;//tiny.6
x=r*d;
a=120-x/2;

g.drawString(c,a,b);
}
*/


//string��int
/*
char str[] = "12345";
int num;

num = atoi(str);
*/


//�������x���ύX
void setfont(int a){
/*
if (a==0)g.setFont(Font.getFont(Font.SIZE_TINY));
if (a==1)g.setFont(Font.getFont(Font.SIZE_SMALL));
if (a==2)g.setFont(Font.getFont(Font.SIZE_MEDIUM));
if (a==3)g.setFont(Font.getFont(Font.SIZE_LARGE));
*/
}

//���y�Đ�
void ot(int x){
PlaySoundMem(x, DX_PLAYTYPE_BACK) ;
}



void stagecls(){
for (t=0;t<smax;t++){sa[t]=-9000000;sb[t]=1;sc[t]=1;sd[t]=1;sgtype[t]=0;stype[t]=0;sxtype[t]=0;}
//for (t=0;t<spmax;t++){spa[t]=-9000000;szyunni[t]=t;spb[t]=1;spc[t]=1;spd[t]=1;sptype[t]=0;spgtype[t]=0;}
for (t=0;t<tmax;t++){ta[t]=-9000000;tb[t]=1;tc[t]=1;td[t]=1;titem[t]=0;txtype[t]=0;}
for (t=0;t<srmax;t++){sra[t]=-9000000;srb[t]=1;src[t]=1;srd[t]=1;sre[t]=0;srf[t]=0;srmuki[t]=0;sron[t]=0;sree[t]=0;srsok[t]=0;srmove[t]=0;srmovep[t]=0;srsp[t]=0;}
//for (t=0;t<sqmax;t++){sqa[t]=-9000000;sqb[t]=1;sqc[t]=1;sqd[t]=1;sqgtype[t]=0;sqtype[t]=0;}
//for (t=0;t<kmax;t++){ka[t]=-9000000;kmuki[t]=0;ksoka[t]=0;ksokb[t]=0;kxsoka[t]=0;kxsokb[t]=0;}
//for (t=0;t<imax;t++){ia[t]=-9000000;ib[t]=1;ic[t]=1;id[t]=1;}
for (t=0;t<amax;t++){aa[t]=-9000000;ab[t]=1;ac[t]=0;ad[t]=1;azimentype[t]=0;atype[t]=0;axtype[t]=0;ae[t]=0;af[t]=0;atm[t]=0;a2tm[t]=0;abrocktm[t]=0;amsgtm[t]=0;}
for (t=0;t<bmax;t++){ba[t]=-9000000;bb[t]=1;bz[t]=1;btm[t]=0;bxtype[t]=0;}
for (t=0;t<emax;t++){ea[t]=-9000000;eb[t]=1;ec[t]=1;ed[t]=1;egtype[t]=0;}
for (t=0;t<nmax;t++){na[t]=-9000000;nb[t]=1;nc[t]=1;nd[t]=1;ne[t]=1;nf[t]=1;ng[t]=0;ntype[t]=0;}
//for (t=0;t<cmax;t++){ca[t]=-9000000;cb[t]=1;contm[t]=0;ctype[t]=0;ce[t]=0;cf[t]=0;}
//for (t=0;t<vmax;t++){va[t]=-9000000;vtype[t]=0;vb[t]=0;vc[t]=1;vd[t]=1;}
//for (t=0;t<gmax;t++){ga[t]=-9000000;gx[t]=0;gstring[t]="";}

sco=0;tco=0;aco=0;bco=0;eco=0;nco=0;
//haikeitouroku();
}//stagecls()




//�X�e�[�W���[�h
void stage(){

//fzx=6000*100;
scrollx=3600*100;

//byte stagedate[16][801];
//byte stagedate2[16][801];


//1-�����K,2-�R�C��,3-��,4-�y��//5-6�n��//7-�B��//




stagep();




for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
xx[10]=0;
if (stagedate[t][tt]>=1 && stagedate[t][tt]<=255)xx[10]=(int)stagedate[t][tt];
xx[21]=tt*29;xx[22]=t*29-12;xx[23]=xx[10];
if (xx[10]>=1 && xx[10]<=19 && xx[10]!=9){tyobi(tt*29,t*29-12,xx[10]);}
if (xx[10]>=20 && xx[10]<=29){sra[srco]=xx[21]*100;srb[srco]=xx[22]*100;src[srco]=3000;srtype[srco]=0;srco++;if (srco>=srmax)srco=0;}
if (xx[10]==30){sa[sco]=xx[21]*100;sb[sco]=xx[22]*100;sc[sco]=3000;sd[sco]=6000;stype[sco]=500;sco++;if (sco>=smax)sco=0;}
if (xx[10]==40){sa[sco]=xx[21]*100;sb[sco]=xx[22]*100;sc[sco]=6000;sd[sco]=3000;stype[sco]=1;sco++;if (sco>=smax)sco=0;}
if (xx[10]==41){sa[sco]=xx[21]*100+500;sb[sco]=xx[22]*100;sc[sco]=5000;sd[sco]=3000;stype[sco]=2;sco++;if (sco>=smax)sco=0;}

if (xx[10]==43){sa[sco]=xx[21]*100;sb[sco]=xx[22]*100+500;sc[sco]=2900;sd[sco]=5300;stype[sco]=1;sco++;if (sco>=smax)sco=0;}
if (xx[10]==44){sa[sco]=xx[21]*100;sb[sco]=xx[22]*100+700;sc[sco]=3900;sd[sco]=5000;stype[sco]=5;sco++;if (sco>=smax)sco=0;}

//����Ȃ����o�O�̌�����
if (xx[10]>=50 && xx[10]<=79){
ba[bco]=xx[21]*100;bb[bco]=xx[22]*100;btype[bco]=xx[23]-50;bco++;if (bco>=bmax)bco=0;
}

if (xx[10]>=80 && xx[10]<=89){na[nco]=xx[21]*100;nb[nco]=xx[22]*100;ntype[nco]=xx[23]-80;nco++;if (nco>=nmax)nco=0;}

//�R�C��
if (xx[10]==9){tyobi(tt*29,t*29-12,800);}
if (xx[10]==99){sa[sco]=xx[21]*100;sb[sco]=xx[22]*100;sc[sco]=3000;sd[sco]=(12-t)*3000;stype[sco]=300;sco++;if (sco>=smax)sco=0;}
}}

if (tyuukan>=1){
xx[17]=0;
for (t=0;t<smax;t++){
if (stype[t]==500 && tyuukan>=1){
fx=sa[t]-fxmax/2;fzx=fx;
ma=sa[t]-fx;
mb=sb[t]-fy;
tyuukan--;xx[17]++;

sa[t]=-80000000;
}}
tyuukan+=xx[17];
}
//tyobi(1,2,3);



}//stage()



void stagep(){


//�X�e�[�W���[�h
//void stage(){



//fzx=6000*100;
scrollx=3600*100;

//byte stagedate[16][801];
//byte stagedate2[16][801];


//1-�����K,2-�R�C��,3-��,4-�y��//5-6�n��//7-�B��//

//1-1
if (sta==1 && stb==1 && stc==0){

//new byte stagedate[16][801]={

//                                                                                                                                                                                     ����                                                                                                                                                                                                                                                           
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98,98,98, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 1,98, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 1,98, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 1,98, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0,80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 7, 7, 7, 7, 7,40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,83, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0,41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 0, 0, 0, 0, 0,50, 0, 0,81,41, 0, 0, 0, 0, 0,81,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 0,50, 0, 0,51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0,41, 0, 0, 0, 0, 0,50, 0,50, 0, 0,41, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5} ,
{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} ;


//�ǉ����
tyobi(8*29,9*29-12,100);
txtype[tco]=2;
tyobi(13*29,9*29-12,102);
txtype[tco]=0;
tyobi(14*29,5*29-12,101);
tyobi(35*29,8*29-12,110);
tyobi(47*29,9*29-12,103);
tyobi(59*29,9*29-12,112);
tyobi(67*29,9*29-12,104);


sco=0;
t=sco;sa[t]=20*29*100+500;sb[t]=-6000;sc[t]=5000;sd[t]=70000;stype[t]=100;sco++;
t=sco;sa[t]=54*29*100-500;sb[t]=-6000;sc[t]=7000;sd[t]=70000;stype[t]=101;sco++;
t=sco;sa[t]=112*29*100+1000;sb[t]=-6000;sc[t]=3000;sd[t]=70000;stype[t]=102;sco++;
t=sco;sa[t]=117*29*100;sb[t]=(2*29-12)*100-1500;sc[t]=15000;sd[t]=3000;stype[t]=103;sco++;
t=sco;sa[t]=125*29*100;sb[t]=-6000;sc[t]=9000;sd[t]=70000;stype[t]=101;sco++;
//t=sco;sa[t]=77*29*100;sb[t]=(6*29-12)*100-1500;sc[t]=12000;sd[t]=3000;stype[t]=103;sco++;
t=28;sa[t]=29*29*100+500;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sco++;
t=sco;sa[t]=49*29*100;sb[t]=(5*29-12)*100;sc[t]=9000-1;sd[t]=3000;stype[t]=51;sgtype[t]=0;sco++;
t=sco;sa[t]=72*29*100;sb[t]=(13*29-12)*100;sc[t]=3000*5-1;sd[t]=3000;stype[t]=52;sco++;

bco=0;
t=bco;ba[t]=27*29*100;bb[t]=(9*29-12)*100;btype[t]=0;bxtype[t]=0;bco++;
t=bco;ba[t]=103*29*100;bb[t]=(5*29-12+10)*100;btype[t]=80;bxtype[t]=0;bco++;
//t=bco;ba[t]=13*29*100;bb[t]=(5*29-12)*100;btype[t]=81;bxtype[t]=0;bco++;

for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta1


//1-2(�n��)
if (sta==1 && stb==2 && stc==0){

//�}���@�n��@����
//StopSoundMem(oto[0]);
bgmchange(oto[100]);
//PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP) ;

scrollx=0*100;
//ma=3000;mb=3000;

byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0,83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,44, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5} ,
{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} ;


tco=0;
//�q���g1
txtype[tco]=1;tyobi(4*29,9*29-12,300);
//tyobi(7*29,9*29-12,300);

//��1
tyobi(13*29,8*29-12,114);

//t=28;
sco=0;
t=sco;sa[t]=14*29*100+500;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=1;sco++;
t=sco;sa[t]=12*29*100;sb[t]=(11*29-12)*100;sc[t]=3000;sd[t]=6000-200;stype[t]=40;sxtype[t]=0;sco++;
t=sco;sa[t]=14*29*100+1000;sb[t]=-6000;sc[t]=5000;sd[t]=70000;stype[t]=100;sxtype[t]=1;sco++;

//�u���b�N���ǂ�
//t=bco;ba[t]=7*29*100;bb[t]=(9*29-12)*100;btype[t]=82;bxtype[t]=0;bco++;


for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta2


//1-2-1(�n��)
if (sta==1 && stb==2 && stc==1){

//�}���@�n���@����
bgmchange(oto[103]);

scrollx=4080*100;
ma=6000;mb=3000;
stagecolor=2;


byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0},
{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,98, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97,44, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,54, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0,98, 2, 2,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 7, 7, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 4, 0,51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1, 1, 4, 4, 4, 4, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 0, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 1, 0, 7, 0, 0, 0, 0, 0, 0, 0,50, 0,50, 0, 4, 0, 4, 0, 4, 0, 4, 0,50, 0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0,50,50,50, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{ 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0} ,
{ 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 6, 6, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 0, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}



tco=0;
txtype[tco]=2;tyobi(7*29,9*29-12,102);
tyobi(10*29,9*29-12,101);

txtype[tco]=2;
tyobi(49*29,9*29-12,114);

for (t=0;t>=-7;t--){
tyobi(53*29,t*29-12,1);
}

txtype[tco]=1;tyobi(80*29,5*29-12,104);
txtype[tco]=2;tyobi(78*29,5*29-12,102);



//txtype[tco]=1;tyobi(11*29,9*29-12,114);//��1

sco=0;
t=sco;sa[t]=2*29*100;sb[t]=(13*29-12)*100;sc[t]=3000*1-1;sd[t]=3000;stype[t]=52;sco++;
//t=sco;sa[t]=19*29*100;sb[t]=(13*29-12)*100;sc[t]=3000*1-1;sd[t]=3000;stype[t]=52;sco++;
t=sco;sa[t]=24*29*100;sb[t]=(13*29-12)*100;sc[t]=3000*1-1;sd[t]=3000;stype[t]=52;sco++;
t=sco;sa[t]=43*29*100+500;sb[t]=-6000;sc[t]=3000;sd[t]=70000;stype[t]=102;sxtype[t]=1;sco++;
t=sco;sa[t]=53*29*100+500;sb[t]=-6000;sc[t]=3000;sd[t]=70000;stype[t]=102;sxtype[t]=2;sco++;
t=sco;sa[t]=129*29*100;sb[t]=(7*29-12)*100;sc[t]=3000;sd[t]=6000-200;stype[t]=40;sxtype[t]=2;sco++;
t=sco;sa[t]=154*29*100;sb[t]=3000;sc[t]=9000;sd[t]=3000;stype[t]=102;sxtype[t]=7;sco++;

//�u���b�N���ǂ�

t=27;sa[t]=69*29*100;sb[t]=(1*29-12)*100;sc[t]=9000*2-1;sd[t]=3000;stype[t]=51;sxtype[t]=0;sgtype[t]=0;sco++;
t=28;sa[t]=66*29*100;sb[t]=(1*29-12)*100;sc[t]=9000-1;sd[t]=3000;stype[t]=51;sxtype[t]=1;sgtype[t]=0;sco++;
t=29;sa[t]=66*29*100;sb[t]=(-2*29-12)*100;sc[t]=9000*3-1;sd[t]=3000;stype[t]=51;sxtype[t]=2;sgtype[t]=0;sco++;

//26 �t�@�C�A�[�y��
t=26;sa[t]=103*29*100-1500;sb[t]=(9*29-12)*100-2000;sc[t]=3000;sd[t]=3000;stype[t]=180;sxtype[t]=0;sr[t]=0;sgtype[t]=48;sco++;
t=sco;sa[t]=102*29*100;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=2;sco++;
t=sco;sa[t]=123*29*100;sb[t]=(9*29-12)*100;sc[t]=3000*5-1;sd[t]=3000*5;stype[t]=52;sxtype[t]=1;sco++;

t=sco;sa[t]=131*29*100;sb[t]=(1*29-12)*100;sc[t]=4700;sd[t]=3000*8-700;stype[t]=1;sxtype[t]=0;sco++;

//t=sco;sa[t]=44*29*100;sb[t]=-6000;sc[t]=9000;sd[t]=70000;stype[t]=102;sco++;

//�I���^�]�[��
t=sco;sa[t]=143*29*100;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=5;sco++;
t=sco;sa[t]=148*29*100;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=5;sco++;
t=sco;sa[t]=153*29*100;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=5;sco++;



bco=0;
t=bco;ba[t]=18*29*100;bb[t]=(10*29-12)*100;btype[t]=82;bxtype[t]=1;bco++;
//t=bco;ba[t]=52*29*100;bb[t]=(2*29-12)*100;btype[t]=82;bxtype[t]=1;bco++;
t=bco;ba[t]=51*29*100+1000;bb[t]=(2*29-12+10)*100;btype[t]=80;bxtype[t]=1;bco++;

//�H�{�[��
t=bco;ba[t]=96*29*100+100;bb[t]=(10*29-12)*100;btype[t]=105;bxtype[t]=0;bco++;


//���t�g
srco=0;
t=srco;sra[t]=111*29*100;srb[t]=(8*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=5;sre[t]=-300;srco++;
t=srco;sra[t]=111*29*100;srb[t]=(0*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=5;sre[t]=-300;srco++;
t=10;sra[t]=116*29*100;srb[t]=(4*29-12)*100;src[t]=90*100;srtype[t]=1;sracttype[t]=5;sre[t]=300;srco++;
t=11;sra[t]=116*29*100;srb[t]=(12*29-12)*100;src[t]=90*100;srtype[t]=1;sracttype[t]=5;sre[t]=300;srco++;


//�q���g1
//tyobi(4*29,9*29-12,300);
//tyobi(7*29,9*29-12,300);

//��1
//tyobi(13*29,8*29-12,114);

//t=28;
//sco=0;
//t=sco;
//sa[t]=14*29*100+500;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=1;sco++;


for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}
//stagedatex[0][0];

}//sta1-2-1




//1-2(�n��)
if (sta==1 && stb==2 && stc==2){

//�}���@�n��@����
//StopSoundMem(oto[0]);
bgmchange(oto[100]);
//PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP) ;

scrollx=900*100;
ma=7500;mb=3000*9;

byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,83, 0, 0,},
{ 0, 0,40, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0,41, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 81,},
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5} ,
{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} ;


/*
//��1
tyobi(13*29,8*29-12,114);

//t=28;
sco=0;
t=sco;sa[t]=14*29*100+500;sb[t]=(9*29-12)*100;sc[t]=6000;sd[t]=12000-200;stype[t]=50;sxtype[t]=1;sco++;
t=sco;sa[t]=12*29*100;sb[t]=(11*29-12)*100;sc[t]=3000;sd[t]=6000-200;stype[t]=40;sxtype[t]=0;sco++;
t=sco;sa[t]=14*29*100+1000;sb[t]=-6000;sc[t]=5000;sd[t]=70000;stype[t]=100;sxtype[t]=1;sco++;
*/

t=sco;sa[t]=5*29*100+500;sb[t]=-6000;sc[t]=3000;sd[t]=70000;stype[t]=102;sxtype[t]=8;sco++;
//���ԓy��
t=28;sa[t]=44*29*100+500;sb[t]=(10*29-12)*100;sc[t]=6000;sd[t]=9000-200;stype[t]=50;sco++;

//�|�[�����ǂ�
bco=0;
t=bco;ba[t]=19*29*100;bb[t]=(2*29-12)*100;btype[t]=85;bxtype[t]=0;bco++;


for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta2



//�K�vBGM+SE

//1-3(�n��)
if (sta==1 && stb==3 && stc==6){stc=0;}
if (sta==1 && stb==3 && stc==0){

//StopSoundMem(oto[0]);
bgmchange(oto[100]);
//PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP) ;

scrollx=3900*100;
//ma=3000;mb=3000;

byte stagedatex[17][1001]={//                                                                                                                                                                                     ����                                                                                                                                                                                                                                                           
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,57, 0, 0, 0,84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,51, 0, 0, 0,84, 0, 0, 0, 0, 0,99, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0,57, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0,83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,30, 0, 0, 0, 0, 0, 0,85,85, 0, 0, 0, 0, 0, 0, 0,97, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,81, 0, 0, 0, 0,50, 0,50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0} ,
{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

tco=0;
tyobi(22*29,3*29-12,1);
//��1
tyobi(54*29,9*29-12,116);
//����+
tyobi(18*29,14*29-12,117);
tyobi(19*29,14*29-12,117);
tyobi(20*29,14*29-12,117);
txtype[tco]=1;tyobi(61*29,9*29-12,101);//5
tyobi(74*29,9*29-12,7);//6

//�q���g2
txtype[tco]=2;tyobi(28*29,9*29-12,300);//7
//�t�@�C�A
txtype[tco]=3;tyobi(7*29,9*29-12,101);
//�q���g3
txtype[tco]=4;tyobi(70*29,8*29-12,300);//9

//���낢�Ԃ�����~�R
txtype[tco]=1;tyobi(58*29,13*29-12,115);
txtype[tco]=1;tyobi(59*29,13*29-12,115);
txtype[tco]=1;tyobi(60*29,13*29-12,115);

//�q���g�u���C�N
txtype[tco]=0;tyobi(111*29,6*29-12,301);
//�W�����v
txtype[tco]=0;tyobi(114*29,9*29-12,120);

//�t�@�C�A
//tyobi(7*29,9*29-12,101);


bco=0;
t=bco;ba[t]=101*29*100;bb[t]=(5*29-12)*100;btype[t]=4;bxtype[t]=1;bco++;
t=bco;ba[t]=146*29*100;bb[t]=(10*29-12)*100;btype[t]=6;bxtype[t]=1;bco++;

t=sco;sa[t]=9*29*100;sb[t]=(13*29-12)*100;sc[t]=9000-1;sd[t]=3000;stype[t]=52;sco++;
//t=sco;sa[t]=58*29*100;sb[t]=(13*29-12)*100;sc[t]=9000-1;sd[t]=3000;stype[t]=52;sco++;

//�y��
t=sco;sa[t]=65*29*100+500;sb[t]=(10*29-12)*100;sc[t]=6000;sd[t]=9000-200;stype[t]=50;sxtype[t]=1;sco++;
//t=28;sa[t]=65*29*100;sb[t]=(10*29-12)*100;sc[t]=6000;sd[t]=9000-200;stype[t]=50;sco++;

//�g���b�v
t=sco;sa[t]=74*29*100;sb[t]=(8*29-12)*100-1500;sc[t]=6000;sd[t]=3000;stype[t]=103;sxtype[t]=1;sco++;
t=sco;sa[t]=96*29*100-3000;sb[t]=-6000;sc[t]=9000;sd[t]=70000;stype[t]=102;sxtype[t]=10;sco++;
//�|�[���C
t=sco;sa[t]=131*29*100-1500;sb[t]=(1*29-12)*100-3000;sc[t]=15000;sd[t]=14000;stype[t]=104;sco++;


//�H�{�[��
t=bco;ba[t]=10*29*100+100;bb[t]=(11*29-12)*100;btype[t]=105;bxtype[t]=1;bco++;
//�u���b�N���ǂ�
t=bco;ba[t]=43*29*100;bb[t]=(11*29-12)*100;btype[t]=82;bxtype[t]=1;bco++;
//t=bco;ba[t]=146*29*100;bb[t]=(12*29-12)*100;btype[t]=82;bxtype[t]=1;bco++;
//���߂�
t=bco;ba[t]=1*29*100;bb[t]=(2*29-12+10)*100-1000;btype[t]=80;bxtype[t]=0;bco++;


//���t�g
srco=0;
t=srco;sra[t]=33*29*100;srb[t]=(3*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=0;sre[t]=0;srsp[t]=1;srco++;
t=srco;sra[t]=39*29*100-2000;srb[t]=(6*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=1;sre[t]=0;srco++;
t=srco;sra[t]=45*29*100+1500;srb[t]=(10*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=0;sre[t]=0;srsp[t]=2;srco++;

t=srco;sra[t]=95*29*100;srb[t]=(7*29-12)*100;src[t]=180*100;srtype[t]=0;sracttype[t]=0;sre[t]=0;srsp[t]=10;srco++;
t=srco;sra[t]=104*29*100;srb[t]=(9*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=0;sre[t]=0;srsp[t]=12;srco++;
t=srco;sra[t]=117*29*100;srb[t]=(3*29-12)*100;src[t]=90*100;srtype[t]=0;sracttype[t]=1;sre[t]=0;srsp[t]=15;srco++;
t=srco;sra[t]=124*29*100;srb[t]=(5*29-12)*100;src[t]=210*100;srtype[t]=0;sracttype[t]=0;sre[t]=0;srsp[t]=10;srco++;



if (stagepoint==1){stagepoint=0;ma=4500;mb=-3000;tyuukan=0;}


for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta3



//1-3(�n��)
if (sta==1 && stb==3 && stc==1){

//�}���@�n��@����
//StopSoundMem(oto[0]);
bgmchange(oto[103]);
//PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP) ;

scrollx=0*100;
ma=6000;mb=6000;
stagecolor=2;


byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,},
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,},
{ 1,54, 0,54, 0,54, 0,54, 0,54, 0,54, 0,54, 0,54, 1, 0,},
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 8, 8, 8, 8,} ,
{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} ;


tco=0;
//tyobi(15*29,12*29-12,111);

stc=0;


for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta3



//1-3(��)
if (sta==1 && stb==3 && stc==5){

stagecolor=3;
bgmchange(oto[104]);

scrollx=0*100;
ma=3000;mb=33000;

stagepoint=1;

byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 9, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0, 0,},
{ 0, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8,} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} ;

sco=0;
t=sco;sa[t]=14*29*100-5;sb[t]=(11*29-12)*100;sc[t]=6000;sd[t]=15000-200;stype[t]=50;sxtype[t]=1;sco++;
//t=sco;sa[t]=12*29*100;sb[t]=(11*29-12)*100;sc[t]=3000;sd[t]=6000-200;stype[t]=40;sxtype[t]=0;sco++;
//t=sco;sa[t]=14*29*100+1000;sb[t]=-6000;sc[t]=5000;sd[t]=70000;stype[t]=100;sxtype[t]=1;sco++;


txtype[tco]=0;tyobi(12*29,4*29-12,112);
//�q���g3
txtype[tco]=3;tyobi(12*29,8*29-12,300);
//txtype[tco]=0;tyobi(13*29,4*29-12,110);


//stc=0;

for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta5





//1-4(�n��)
if (sta==1 && stb==4 && stc==0){

//�}���@�n��@����
//StopSoundMem(oto[0]);
bgmchange(oto[105]);
//PlaySoundMem(oto[0],DX_PLAYTYPE_LOOP) ;

scrollx=4400*100;
ma=12000;mb=6000;
stagecolor=4;


byte stagedatex[17][1001]={//                                                                                                                                                                                     ����                                                                                                                                                                                                                                                           
{ 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 3, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 7, 7, 2, 2, 7, 5, 5, 5, 5, 0, 0, 0, 3, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0,59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,59, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0,59, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,41, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 5, 5, 5,86, 0, 0,86, 0, 5, 5, 5, 5, 5,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,86, 0, 0,86, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,86, 5, 5, 5, 5, 5,86, 0, 0,86, 0, 0, 5, 5, 5, 5, 5, 5, 5,86, 0, 0,86, 5, 5, 5, 5,86, 0, 0,86, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,86, 0, 5, 5,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,41, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
} ;

sco=0;//sco=140;
t=sco;sa[t]=35*29*100-1500+750;sb[t]=(8*29-12)*100-1500;sc[t]=1500;sd[t]=3000;stype[t]=105;sco++;
t=sco;sa[t]=67*29*100;sb[t]=(4*29-12)*100;sc[t]=9000-1;sd[t]=3000*1-1;stype[t]=51;sxtype[t]=3;sgtype[t]=0;sco++;
t=sco;sa[t]=73*29*100;sb[t]=(13*29-12)*100;sc[t]=3000*1-1;sd[t]=3000;stype[t]=52;sco++;
//t=sco;sa[t]=79*29*100;sb[t]=(13*29-12)*100;sc[t]=30*3*100-1;sd[t]=6000-200;stype[t]=51;sxtype[t]=4;sco++;
//t=sco;sa[t]=83*29*100;sb[t]=(-2*29-12)*100;sc[t]=30*5*100-1;sd[t]=3000-200;stype[t]=51;sxtype[t]=4;sco++;
t=sco;sa[t]=123*29*100;sb[t]=(1*29-12)*100;sc[t]=30*6*100-1+0;sd[t]=3000-200;stype[t]=51;sxtype[t]=10;sco++;
//�X�N���[������
t=sco;sa[t]=124*29*100+3000;sb[t]=(2*29-12)*100;sc[t]=3000*1-1;sd[t]=300000;stype[t]=102;sxtype[t]=20;sco++;
t=sco;sa[t]=148*29*100+1000;sb[t]=(-12*29-12)*100;sc[t]=3000*1-1;sd[t]=300000;stype[t]=102;sxtype[t]=30;sco++;

//3�A��
t=sco;sa[t]=100*29*100+1000;sb[t]=-6000;sc[t]=3000;sd[t]=70000;stype[t]=102;sxtype[t]=12;sco++;

//�n��1
t=sco;sa[t]=0*29*100-0;sb[t]=9*29*100+1700;sc[t]=3000*7-1;sd[t]=3000*5-1;stype[t]=200;sxtype[t]=0;sco++;
t=sco;sa[t]=11*29*100;sb[t]=-1*29*100+1700;sc[t]=3000*8-1;sd[t]=3000*4-1;stype[t]=200;sxtype[t]=0;sco++;


bco=0;
t=bco;ba[t]=8*29*100-1400;bb[t]=(2*29-12)*100+500;btype[t]=86;bxtype[t]=0;bco++;
t=bco;ba[t]=42*29*100-1400;bb[t]=(-2*29-12)*100+500;btype[t]=86;bxtype[t]=0;bco++;
t=bco;ba[t]=29*29*100+1500;bb[t]=(7*29-12)*100+1500;btype[t]=87;bxtype[t]=105;bco++;
t=bco;ba[t]=47*29*100+1500;bb[t]=(9*29-12)*100+1500;btype[t]=87;bxtype[t]=110;bco++;
t=bco;ba[t]=70*29*100+1500;bb[t]=(9*29-12)*100+1500;btype[t]=87;bxtype[t]=105;bco++;
t=bco;ba[t]=66*29*100+1501;bb[t]=(4*29-12)*100+1500;btype[t]=87;bxtype[t]=101;bco++;
t=bco;ba[t]=85*29*100+1501;bb[t]=(4*29-12)*100+1500;btype[t]=87;bxtype[t]=105;bco++;

//�X�e���X���߂�
t=bco;ba[t]=57*29*100;bb[t]=(2*29-12+10)*100-500;btype[t]=80;bxtype[t]=1;bco++;
//�u���b�N���ǂ�
t=bco;ba[t]=77*29*100;bb[t]=(5*29-12)*100;btype[t]=82;bxtype[t]=2;bco++;
//�{�X
t=bco;ba[t]=130*29*100;bb[t]=(8*29-12)*100;btype[t]=30;bxtype[t]=0;bco++;
//�N�b�N��
t=bco;ba[t]=142*29*100;bb[t]=(10*29-12)*100;btype[t]=31;bxtype[t]=0;bco++;

//�}�O�}
nco=0;
na[nco]=7*29*100-300;nb[nco]=14*29*100-1200;ntype[nco]=6;nco++;if (nco>=nmax)nco=0;
na[nco]=41*29*100-300;nb[nco]=14*29*100-1200;ntype[nco]=6;nco++;if (nco>=nmax)nco=0;
na[nco]=149*29*100-1100;nb[nco]=10*29*100-600;ntype[nco]=100;nco++;if (nco>=nmax)nco=0;

tco=0;
//ON-OFF�u���b�N
txtype[tco]=1;tyobi(29*29,3*29-12,130);
//1-2
tyobi(34*29,9*29-12,5);
tyobi(35*29,9*29-12,5);
//�B��
tyobi(55*29+15,6*29-12,7);
//tyobi(62*29,9*29-12,2);
//�B��ON-OFF
txtype[tco]=10;tyobi(50*29,9*29-12,114);
//�q���g3
txtype[tco]=5;tyobi(1*29,5*29-12,300);
//�t�@�C�A
txtype[tco]=3;
tyobi(86*29,9*29-12,101);
//�L�m�R�Ȃ��@����
//txtype[tco]=2;tyobi(81*29,1*29-12,5);
//����
txtype[tco]=2;
tyobi(86*29,6*29-12,117);

//���낢�Ԃ�����~�R
for (t=0;t<=2;t++){
txtype[tco]=3;tyobi((79+t)*29,13*29-12,115);
}

//�W�����v
txtype[tco]=3;tyobi(105*29,11*29-12,120);
//��1
txtype[tco]=3;tyobi(109*29,7*29-12,102);
//�f�t���O
txtype[tco]=4;tyobi(111*29,7*29-12,101);
//��
tyobi(132*29,8*29-12-3,140);
tyobi(131*29,9*29-12,141);
//������
tyobi(161*29,12*29-12,142);
//�t�@�C�A�o�[����
tyobi(66*29,4*29-12,124);


//���t�g
srco=0;
t=srco;sra[t]=93*29*100;srb[t]=(10*29-12)*100;src[t]=60*100;srtype[t]=0;sracttype[t]=1;sre[t]=0;srco++;
t=20;sra[t]=119*29*100+300;srb[t]=(10*29-12)*100;src[t]=12*30*100+1000;srtype[t]=0;sracttype[t]=0;srsp[t]=21;sre[t]=0;srco++;


stc=0;


for (tt=0;tt<=1000;tt++){
for (t=0;t<=16;t++){
stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
}}

}//sta4

if (sta==2 && stb==1 && stc==0){// 2-1
  ma=5600;
  mb=32000;
  bgmchange(oto[100]);
  stagecolor=1;
  scrollx=2900*(113-19);
  //
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 4, 4, 4, 4, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 4, 4, 4, 4, 4, 0, 0, 4, 7, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 2,98, 2, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10,10,10, 0, 0,10,10,10,10, 4, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 7, 0, 4, 4, 4, 4, 4, 4, 4, 4} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 4, 7, 7, 7, 4, 4, 4, 0, 0, 0, 0,80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 0, 0,50, 0, 0,50, 0, 0,50,81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,81, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 5, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5} ,
{ 6, 6, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 6, 6, 6} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //�ǉ����
  tco = 0;
  //
  txtype[tco]=6;
  tyobi(1*29,9*29-12,300);
  tco += 1;
  //
  txtype[tco]=0;
  tyobi(40*29,9*29-12,110);
  tco += 1;
  //
  txtype[tco]=7;
  tyobi(79*29,7*29-12,300);
  tco += 1;
  //
  txtype[tco]=2;
  tyobi(83*29,7*29-12,102);
  tco += 1;
  //
  txtype[tco]=0;
  tyobi(83*29,2*29-12,114);
  tco += 1;
  //
  for(int i = -1; i > -7; i -= 1){
    tyobi(85*29, i*29-12, 4);
    tco += 1;
  }
  //
  sco = 0;
  sa[sco]=30*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=12000-1;
  sd[sco]=3000;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=51*29*100;
  sb[sco]=(4*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=3000;
  stype[sco]=51;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=84*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=3000;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=105*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=15000-1;
  sd[sco]=3000;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  bco = 0;
  //
  ba[bco]=6*29*100;
  bb[bco]=(3*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=13*29*100;
  bb[bco]=(6*29-12)*100;
  btype[bco]=4;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=23*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=25*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=27*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=88*29*100;
  bb[bco]=(12*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

if (sta==2 && stb==2 && stc==0){//2-2(�n��)
  bgmchange(oto[100]);
  stagecolor=1;
  scrollx=2900*(19-19);
  //
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0},
{ 0,80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5},
{ 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //
  sa[sco]=14*29*100+200;
  sb[sco]=-6000;
  sc[sco]=5000;
  sd[sco]=70000;
  stype[sco]=100;
  sco += 1;
  //
  sa[sco]=12*29*100+1200;
  sb[sco]=-6000;
  sc[sco]=7000;
  sd[sco]=70000;
  stype[sco]=101;
  sco += 1;
  //
  sa[sco]=12*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=6000-1;
  sd[sco]=3000;
  stype[sco]=52;
  sgtype[sco]=0;
  sco += 1;
  //
  sa[sco]=14*29*100;
  sb[sco]=(9*29-12)*100;
  sc[sco]=6000;
  sd[sco]=12000-200;
  stype[sco]=50;
  sxtype[sco]=1;
  sco += 1;
  //
  tyobi(6*29, 9*29-12, 110);
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

if (sta==2 && stb==2 && stc==1){//2-2(�n��)
  bgmchange(oto[103]);
  stagecolor=2;
  ma=7500;mb=9000;
  scrollx=2900*(137-19);
//
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,98, 4, 4, 4, 4, 4, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,98, 1} ,
{ 4, 0, 0, 0, 0, 0, 0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10,10,10,10,10,10,10,10,10,10, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,10,10,10,10,10,10,10,10,10, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,51, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,57, 0, 0, 0, 0, 0,57, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0,10, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,44, 0, 0, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 7, 7, 7, 0,97, 0, 0, 0, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
{ 4, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 0, 0, 0, 1, 1, 0, 0, 0, 0,44, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 1, 1, 0, 0, 0,97, 0, 0, 0, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1} ,
{ 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1} ,
{ 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1} ,
{ 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //
  bco=0;
  ba[bco]=32*29*100-1400;
  bb[bco]=(-2*29-12)*100+500;
  btype[bco]=86;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=(31*29-12)*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=7;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=38*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=38*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=42*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=42*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=46*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=46*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=58*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=66*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=76*29*100-1400;
  bb[bco]=(-2*29-12)*100+500;
  btype[bco]=86;
  bxtype[bco]=0;
  bco += 1;
  //
  sco = 0;
  sa[sco]=2*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=300000-6001;
  sd[sco]=3000;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=3*29*100;
  sb[sco]=(7*29-12)*100;
  sc[sco]=3000;
  sd[sco]=3000;
  stype[sco]=105;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=107*29*100;
  sb[sco]=(9*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=24000;
  stype[sco]=52;
  sxtype[sco]=1;
  sco += 1;
  //
  sa[sco]=111*29*100;
  sb[sco]=(7*29-12)*100;
  sc[sco]=3000;
  sd[sco]=6000-200;
  stype[sco]=40;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=113*29*100+1100;
  sb[sco]=(0*29-12)*100;
  sc[sco]=4700;
  sd[sco]=27000-1000;
  stype[sco]=0;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=128*29*100;
  sb[sco]=(9*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=24000;
  stype[sco]=52;
  sxtype[sco]=1;
  sco += 1;
  //
  sa[sco]=131*29*100;
  sb[sco]=(9*29-12)*100;
  sc[sco]=3000;
  sd[sco]=6000-200;
  stype[sco]=40;
  sxtype[sco]=2;
  sco += 1;
  //
  sa[sco]=133*29*100+1100;
  sb[sco]=(0*29-12)*100;
  sc[sco]=4700;
  sd[sco]=32000;
  stype[sco]=0;
  sxtype[sco]=0;
  sco += 1;
  //
  tco = 0;
  txtype[tco] = 0;
  tyobi(0*29, 0*29-12, 4);
  tco = 1;
  txtype[tco] = 0;
  tyobi(2*29, 9*29-12, 4);
  tco = 2;
  txtype[tco] = 0;
  tyobi(3*29, 9*29-12, 4);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(5*29, 9*29-12, 115);
  tco += 1;
  txtype[tco] = 1;
  tyobi(6*29, 9*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(5*29, 10*29-12, 115);
  tco += 1;
  txtype[tco] = 1;
  tyobi(6*29, 10*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(5*29, 11*29-12, 115);
  tco += 1;
  txtype[tco] = 1;
  tyobi(6*29, 11*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(5*29, 12*29-12, 115);
  tco += 1;
  txtype[tco] = 1;
  tyobi(6*29, 12*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(70*29, 7*29-12, 115);
  tco += 1;
  txtype[tco] = 1;
  tyobi(71*29, 7*29-12, 115);
  tco += 1;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

if (sta==2 && stb==2 && stc==2){// 2-2 �n��
//
  bgmchange(oto[100]);
  stagecolor = 1;
  scrollx = 2900 * (36 - 19);
  ma = 7500;
  mb = 3000 * 9;
//
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50,51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0,40, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0,41, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0,54, 0, 0},
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //
  bco = 0;
  ba[bco]=9*29*100;
  bb[bco]=(12*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=10*29*100;
  bb[bco]=(11*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=11*29*100;
  bb[bco]=(10*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=12*29*100;
  bb[bco]=(9*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=13*29*100;
  bb[bco]=(8*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=14*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=15*29*100;
  bb[bco]=(6*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=16*29*100;
  bb[bco]=(5*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=17*29*100;
  bb[bco]=(5*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=18*29*100;
  bb[bco]=(5*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=19*29*100;
  bb[bco]=(5*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=20*29*100;
  bb[bco]=(5*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}
//
if (sta==2 && stb==3 && stc == 0){// 2-3
  ma = 7500;
  mb = 3000 * 8;
  bgmchange(oto[100]);
  stagecolor=1;
  scrollx=2900*(126-19);
  //
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0,56, 0, 0, 0, 0, 0, 0, 0, 0, 4,10,10,10,10,10,10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,51, 0, 1, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,82, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 1, 7, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0,10, 4, 4, 4, 0,54, 0,54, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,58, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,52, 0, 0, 0, 0, 4, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 5, 5, 5, 5, 5} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0, 6, 6, 6, 6, 6} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //
  tco = 0;
  txtype[tco] = 0;
  for(int i = -1; i > -7; i -= 1){
    tyobi(55*29, i*29-12, 4);
    tco += 1;
  }
  //
  txtype[tco] = 0;
  tyobi(64*29, 12*29-12, 120);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(66*29, 3*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(67*29, 3*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(68*29, 3*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 8;
  tyobi(60*29, 6*29-12, 300);
  tco += 1;
  /*
  bco = 1;
  ba[bco]=(54*29-12)*100;
  bb[bco]=(1*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=0;
  bco += 1;
  */
  sco = 0;
  ba[sco]=(102*29-12)*100;
  bb[sco]=(10*29-12)*100;
  btype[sco]=50;
  bxtype[sco]=1;
  sco += 1;
  //
  srco=0;
  sra[srco]=1*29*100;
  srb[srco]=(10*29-12)*100;
  src[srco]=5*3000;
  srtype[srco]=0;
  sracttype[srco]=1;
  sre[srco]=0;
  srsp[srco]=10;
  srco++;
  //
  sra[srco]=18*29*100;
  srb[srco]=(4*29-12)*100;
  src[srco]=3*3000;
  srtype[srco]=0;
  sracttype[srco]=0;
  sre[srco]=0;
  srsp[srco]=10;
  srco++;
  //
  sra[srco]=35*29*100;
  srb[srco]=(4*29-12)*100;
  src[srco]=5*3000;
  srtype[srco]=0;
  sracttype[srco]=0;
  sre[srco]=0;
  srsp[srco]=10;
  srco++;
  //
  sra[srco]=35*29*100;
  srb[srco]=(8*29-12)*100;
  src[srco]=5*3000;
  srtype[srco]=0;
  sracttype[srco]=0;
  sre[srco]=0;
  srsp[srco]=10;
  srco++;
  //
  sra[srco]=94*29*100;
  srb[srco]=(6*29-12)*100;
  src[srco]=3*3000;
  srtype[srco]=0;
  sracttype[srco]=0;
  sre[srco]=0;
  srsp[srco]=1;
  srco++;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}
//
if (sta==2 && stb==4 && (stc == 0 || stc == 10 || stc == 12)){// 2-4(1��)
  if(stc == 0){
    ma = 7500;
    mb = 3000 * 4;
  }else{
    ma = 19500;
    mb = 3000*11;
    stc = 0;
  }
  bgmchange(oto[105]);
  stagecolor=4;
  scrollx=2900*(40-19);
  //
byte stagedatex[17][1001]={
{ 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0,10,10,10, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7,10,10,10, 5, 5, 5, 5, 5} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 7, 7, 7, 3, 7, 0, 7, 5, 0, 0, 5, 5, 5, 0,58, 0, 5, 0, 0, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,59,59, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5,59, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 5, 5, 5, 5, 5} ,
{ 5, 5, 5, 5, 5, 5,40, 0, 5, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0,59, 0, 5, 5, 5, 5, 5} ,
{ 5,86, 5, 5, 5, 5,41, 0, 5,86, 0, 0,86, 5, 5, 5, 5,86, 0, 0,86, 0, 0,86, 5, 0,86, 5, 5, 5,86, 0, 0, 5, 5, 5, 5, 5} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,59,59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,59, 0, 0, 0, 0, 0}
};
  //
  tco=0;
  txtype[tco] = 0;
  tyobi(0*29, -1*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(4*29, -1*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(1*29, 14*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(6*29, 14*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(7*29, 14*29-12, 5);
  tco += 1;
  //
  bco=0;
  ba[bco]=2*29*100-1400;
  bb[bco]=(-2*29-12)*100+500;
  btype[bco]=86;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=20*29*100+1500;
  bb[bco]=(5*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=107;
  bco += 1;
  //
  sco=0;
  sa[sco]=17*29*100;
  sb[sco]=(9*29-12)*100;
  sc[sco]=21000-1;
  sd[sco]=3000-1;
  stype[sco]=52;
  sxtype[sco]=2;
  sco += 1;
  //
  sa[sco]=27*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=6000;
  sd[sco]=6000;
  stype[sco]=50;
  sxtype[sco]=6;
  sco += 1;
  //
  sa[sco]=34*29*100;
  sb[sco]=(5*29-12)*100;
  sc[sco]=6000;
  sd[sco]=30000;
  stype[sco]=50;
  sxtype[sco]=1;
  sco += 1;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

if (sta==2 && stb==4 && stc == 1){// 2-4(2��)
  ma = 4500;
  mb = 3000*11;
  bgmchange(oto[105]);
  stagecolor=4;
  scrollx=2900*(21-19);
  //
byte stagedatex[17][1001]={
{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,98} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 7, 7, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0} ,
{ 0,10,10, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0,44, 0, 0} ,
{ 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0,97, 0, 0, 0} ,
{ 0,40, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 5, 5, 5} ,
{86,41, 0,86, 0, 5,86, 0, 0,86, 0, 5,86, 0, 0,86, 0, 0,86} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //
  tco=0;
  txtype[tco] = 1;
  tyobi(12*29, 13*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(13*29, 13*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(14*29, 13*29-12, 115);
  tco += 1;
  //
  sco = 0;
  sa[sco]=6*29*100;
  sb[sco]=(6*29-12)*100;
  sc[sco]=18000-1;
  sd[sco]=6000-1;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=12*29*100;
  sb[sco]=(8*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=3000-1;
  stype[sco]=52;
  sxtype[sco]=2;
  sco += 1;
  //
  sa[sco]=15*29*100;
  sb[sco]=(11*29-12)*100;
  sc[sco]=3000;
  sd[sco]=6000;
  stype[sco]=40;
  sxtype[sco]=2;
  sco += 1;
  //
  sa[sco]=17*29*100+1100;
  sb[sco]=(0*29-12)*100;
  sc[sco]=4700;
  sd[sco]=38000;
  stype[sco]=0;
  sxtype[sco]=0;
  sco += 1;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

if (sta==2 && stb==4 && stc == 2){// 2-4(3��)
  ma = 4500;
  mb = 3000*11;
  bgmchange(oto[107]);
  stagecolor=4;
  scrollx=2900*(128-19);
  //
byte stagedatex[17][1001]={
{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 5, 5, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 5, 0, 0, 5, 0, 5, 0,10,10, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 5, 0, 5, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 3, 0, 5, 0, 3, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 5, 0, 5, 5, 5, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 3, 0, 0, 3, 0, 0, 3, 7, 0, 3, 7, 7, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 0, 0, 5, 0, 5,10,10, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0, 0, 5, 0, 5, 7, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0,30, 0, 5, 0, 0, 0, 0, 0, 0, 7, 7, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 5, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 5, 5, 5, 0, 0, 5, 0, 0, 7, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 5, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 5,59, 0,59, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 5,40, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 5, 0, 5, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 5, 0,59, 0, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 5,41, 0, 5,86, 0, 5,86, 0, 5, 5, 5, 5,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0, 5,86, 0, 0,86, 0, 0,86, 5, 0,86, 0, 5,86, 5, 0, 5,86, 0, 0, 5, 5, 5, 5,86, 0, 0, 5,86,59, 0, 5, 5, 5, 5, 5,86, 0, 0,86, 5, 5,86, 0, 0,86, 0, 0,86, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5,86, 0, 0,86, 0, 0,86, 0, 0,86, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,59, 0, 0, 0, 0, 0,59, 0,59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,59, 0,59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //
  tco=0;
  txtype[tco] = 0;
  tyobi(1*29, 14*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(2*29, 14*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 9;
  tyobi(3*29, 4*29-12, 300);
  tco += 1;
  //
  txtype[tco] = 1;
  tyobi(32*29,9*29-12, 115);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(76*29,14*29-12, 5);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(108*29,11*29-12,141);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(109*29,10*29-12-3,140);
  tco += 1;
  //
  txtype[tco] = 0;
  tyobi(121*29,10*29-12,142);
  tco += 1;
  //
  bco = 0;
  ba[bco]=0*29*100+1500;
  bb[bco]=(8*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=2*29*100;
  bb[bco]=(0*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=3*29*100+1500;
  bb[bco]=(8*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=6*29*100+1500;
  bb[bco]=(8*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=9*29*100+1500;
  bb[bco]=(8*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=107;
  bco += 1;
  //
  ba[bco]=25*29*100-1400;
  bb[bco]=(2*29-12)*100-400;
  btype[bco]=86;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=40*29*100;
  bb[bco]=(8*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=42*29*100;
  bb[bco]=(8*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=43*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=47*29*100+1500;
  bb[bco]=(6*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=57*29*100;
  bb[bco]=(7*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=77*29*100-1400;
  bb[bco]=(2*29-12)*100-400;
  btype[bco]=86;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=83*29*100-1400;
  bb[bco]=(2*29-12)*100-400;
  btype[bco]=86;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=88*29*100+1500;
  bb[bco]=(9*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=88*29*100+1500;
  bb[bco]=(9*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=90*29*100;
  bb[bco]=(9*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=0;
  bco += 1;
  //
  ba[bco]=107*29*100;
  bb[bco]=(10*29-12)*100;
  btype[bco]=30;
  bxtype[bco]=0;
  bco += 1;
  //
  sco = 0;
  sa[sco]=13*29*100;
  sb[sco]=(8*29-12)*100;
  sc[sco]=33000-1;
  sd[sco]=3000-1;
  stype[sco]=52;
  sxtype[sco]=2;
  sco += 1;
  //
  sa[sco]=13*29*100;
  sb[sco]=(0*29-12)*100;
  sc[sco]=33000-1;
  sd[sco]=3000-1;
  stype[sco]=51;
  sxtype[sco]=3;
  sco += 1;
  //
  sa[sco]=10*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=6000;
  sd[sco]=6000;
  stype[sco]=50;
  sxtype[sco]=6;
  sco += 1;
  //
  sa[sco]=46*29*100;
  sb[sco]=(12*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=3000-1;
  stype[sco]=52;
  sxtype[sco]=2;
  sco += 1;
  //
  sa[sco]=58*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=6000;
  sd[sco]=6000;
  stype[sco]=50;
  sxtype[sco]=6;
  sco += 1;
  //
  sa[sco]=101*29*100-1500;
  sb[sco]=(10*29-12)*100-3000;
  sc[sco]=12000;
  sd[sco]=12000;
  stype[sco]=104;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=102*29*100+3000;
  sb[sco]=(2*29-12)*100;
  sc[sco]=3000-1;
  sd[sco]=300000;
  stype[sco]=102;
  sxtype[sco]=20;
  sco += 1;
  //
  srco = 0;
  sra[srco]=74*29*100-1500;
  srb[srco]=(7*29-12)*100;
  src[srco]=2*3000;
  srtype[srco]=0;
  sracttype[srco]=1;
  sre[srco]=0;
  srsp[srco]=0;
  srco = 20;
  //
  sra[srco]=97*29*100;
  srb[srco]=(12*29-12)*100;
  src[srco]=12*3000;
  srtype[srco]=0;
  sracttype[srco]=0;
  sre[srco]=0;
  srsp[srco]=21;
  srco += 1;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

if (sta==3 && stb==1 && stc==0){// 3-1
  ma=5600;
  mb=32000;
  bgmchange(oto[100]);
  stagecolor=5;
  scrollx=2900*(112-19);
byte stagedatex[17][1001]={
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 7, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 7, 7, 7, 4, 0, 0,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,10,10, 0, 0,10,10, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 7, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 4, 4, 4, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 4, 0, 7, 7, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 4} ,
{ 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,51, 1, 0,81, 0, 0, 1, 1, 1, 1, 1, 7, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4} ,
{ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5} ,
{ 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6} ,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
  //�ǉ����
  tco = 0;
  //
  txtype[tco]=10;
  tyobi(2*29,9*29-12,300);
  tco += 1;
  //
  txtype[tco]=1;
  tyobi(63*29,13*29-12,115);
  tco += 1;
  //
  txtype[tco]=1;
  tyobi(64*29,13*29-12,115);
  tco += 1;
  //
  sco = 0;
  sa[sco]=13*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=3000;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  sa[sco]=84*29*100;
  sb[sco]=(13*29-12)*100;
  sc[sco]=9000-1;
  sd[sco]=3000;
  stype[sco]=52;
  sxtype[sco]=0;
  sco += 1;
  //
  bco = 0;
  ba[bco]=108*29*100;
  bb[bco]=(6*29-12)*100;
  btype[bco]=6;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=33*29*100;
  bb[bco]=(10*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=36*29*100;
  bb[bco]=(0*29-12)*100;
  btype[bco]=80;
  bxtype[bco]=1;
  bco += 1;
  //
  ba[bco]=78*29*100+1500;
  bb[bco]=(7*29-12)*100+1500;
  btype[bco]=88;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=80*29*100+1500;
  bb[bco]=(7*29-12)*100+1500;
  btype[bco]=87;
  bxtype[bco]=105;
  bco += 1;
  //
  ba[bco]=85*29*100;
  bb[bco]=(11*29-12)*100;
  btype[bco]=82;
  bxtype[bco]=1;
  bco += 1;
  //
  srco = 0;
  sra[srco]=41*29*100;
  srb[srco]=(3*29-12)*100;
  src[srco]=3*3000;
  srtype[srco]=0;
  sracttype[srco]=0;
  sre[srco]=0;
  srsp[srco]=3;
  srco = 0;
  //
  for (tt=0;tt<=1000;tt++){
    for (t=0;t<=16;t++){
      stagedate[t][tt]=0;stagedate[t][tt]=stagedatex[t][tt];
    }
  }
}

}//stagep

//BGM�ύX
void bgmchange(int x){
StopSoundMem(oto[0]);
oto[0]=0;
oto[0]=x;
}//bgmchange()




//�u���b�N�o��

void tyobi(int x,int y,int type){

ta[tco]=x*100;tb[tco]=y*100;ttype[tco]=type;

tco++;if (tco>=tmax)tco=0;
}//tyobi


//�u���b�N�j��
void brockbreak(int t){
if (titem[t]==1){
//eyobi(ta[t],tb[t],0,-800,0,80,xx[1],xx[1],titem[t],8);
//hosico++;
}
if (titem[t]>=2 && titem[t]<=7){
//ayobi(ta[t],tb[t],-800,10,100+(titem[t]-2),0);//end();
}

ta[t]=-800000;
//}//ty==1
}//brock


//���b�Z�[�W
void ttmsg(){
xx[1]=6000/100;xx[2]=4000/100;
if (tmsgtype==1 || tmsgtype==2){
setc0();	
fillrect(xx[1],xx[2],360,tmsgy/100);
setc1();
drawrect(xx[1],xx[2],360,tmsgy/100);
}
if (tmsgtype==2){
//�t�H���g
setfont(20,5);

if (tmsg==0){
setc1();
//�t�H���g
setfont(20,5);
txmsg("�e�X�g�@hoge",0);
}

if (tmsg==1){
setc1();
txmsg("",0);
txmsg("�X�e�[�W 1 ���",0);
txmsg("����I�Ȃ��̂��������̂�",1);
txmsg("�C�����Ă����`",2);
txmsg("��A�A�C�e���̈ꕔ�𗘗p���邩���c",4);
txmsg("                       ���� ���",6);
}

if (tmsg==2){
txmsg("            �H���K�v�ł� ",3);
txmsg("                         m9(^�D^)",6);
}


if (tmsg==3){
txmsg("   �ʂɃR�C���ɈӖ��Ȃ����ǂ� ",3);
txmsg("                      (�E�ցE )ɼ",6);
}

if (tmsg==4){
txmsg("���̐�ɉB���u���b�N������܂� ",2);
txmsg("���ӂ��Ă������� !!",4);
}


if (tmsg==5){
txmsg("",0);
txmsg(" �O�������Փx�������܂����̂�",1);
txmsg(" �C�y�Ƀv���C���Ă�������    ",3);
txmsg("                       ���� ���",6);
}

if (tmsg==6){
txmsg("",0);
txmsg(" �����ɂ���G�̂��΂ɂ��ƁA      ",1);
txmsg(" �����ƈꏏ�ɃW�����v���Ă���܂��B",2);
txmsg("   �����ł��ˁB                  ",3);
}

if (tmsg==7){
txmsg("",0);
txmsg(" ���̓G�͘A��ė���܂�����?�A     ",1);
txmsg(" �A��ė���Ȃ������M���́A        ",2);
txmsg(" �����̗��Ƃ������� Let's dive!    ",3);
}

if (tmsg==8){
txmsg("����ȗe�Ղ�",1);
txmsg("�q���g�ɗ�����񂶂�Ȃ���",2);
txmsg("�ق�A�������Ǝ��s����!!",3);
}

if (tmsg==9){
txmsg(" ���^�����̃t�@�C�i���X�e�[�W�B    ",1);
txmsg(" �N���A����ΐ��ɃG���f�B���O!!    ",2);
txmsg(" ���̓y�ǂ���߂��Ă������񂾂�?   ",3);
}

if (tmsg==10){
txmsg(" ���������Ă邩��A�������������B",1);
txmsg(" ",2);
txmsg(" �@                      ",3);
}

if (tmsg==100){
txmsg("���H���ł����H ",0);
txmsg("���₟�A�����̒ʂ肷�����",2);
txmsg("�q���g�u���b�N�ł���`",3);
txmsg("�����ĉ������u���b�N����Ȃ��ł���",5);
txmsg("                          (�c�`�b)",6);
}


setfont(16,4);
}//2

if (tmsgtype==3){
xx[5]=(((15-1)*1200+1500)/100-tmsgy/100);
if (xx[5]>0){
setc0();
fillrect(xx[1],xx[2]+tmsgy/100,360,xx[5]);
setc1();
drawrect(xx[1],xx[2]+tmsgy/100,360,xx[5]);
}}

}//ttmsg

void txmsg(string x,int a){
int xx=6;

str(x,60+xx,40+xx+a*24);

}//txmsg


//�t�H���g�ύX
void setfont(int x,int y){
SetFontSize(x);
SetFontThickness(y);
}



//�O���쐬
void eyobi(int xa,int xb,int xc,int xd,int xe,int xf,int xnobia,int xnobib,int xgtype,int xtm){

ea[eco]=xa;eb[eco]=xb;ec[eco]=xc;ed[eco]=xd;ee[eco]=xe;ef[eco]=xf;
egtype[eco]=xgtype;etm[eco]=xtm;
enobia[eco]=xnobia;enobib[eco]=xnobib;

eco++;if (eco>=emax)eco=0;

}//eyobi








//�G�L�����A�A�C�e���쐬
void ayobi(int xa,int xb,int xc,int xd,int xnotm,int xtype,int xxtype){
int rz=0;
for (t1=0;t1<=1;t1++){t1=2;
if (aa[aco]>=-9000 && aa[aco]<=30000)t1=0;rz++;

if (rz<=amax){t1=3;

aa[aco]=xa;
ab[aco]=xb;//ag[aco]=0;ah[aco]=0;ai[aco]=bb[t];//ad[t]=0;aeon[t]=1;
ac[aco]=xc;
ad[aco]=xd;
if (xxtype>100)ac[aco]=xxtype;
//ae[aco]=0;af[aco]=0;
atype[aco]=xtype;
if (xxtype>=0 && xxtype<=99100)axtype[aco]=xxtype;//ahp[aco]=iz[bxtype[t]];aytm[aco]=0;
//if (xxtype==1)end();
anotm[aco]=xnotm;
if (aa[aco]-fx<=ma+mnobia/2)amuki[aco]=1;
if (aa[aco]-fx>ma+mnobia/2)amuki[aco]=0;
if (abrocktm[aco]>=1)amuki[aco]=1;
if (abrocktm[aco]==20)amuki[aco]=0;

anobia[aco]=anx[atype[aco]];anobib[aco]=any[atype[aco]];


//��C��
if (xtype==7 && CheckSoundMem(oto[10])==0){ot(oto[10]);}
//�t�@�C�A��
if (xtype==10 && CheckSoundMem(oto[18])==0){ot(oto[18]);}


azimentype[aco]=1;

//if (atype[aco]<=30 && atype[aco]!=4)atm[aco]=20;



//azimentype[aco]=1;

switch(atype[aco]){
/*
case 0:case 1:case 2:case 5:case 6:case 7:case 8:
azimentype[aco]=2;
break;

case 3:case 4:
azimentype[aco]=0;
break;

case 49:case 50://case 2:case 5:case 6:
azimentype[aco]=4;
break;

case 80:case 81:case 82:case 83:case 84:case 85:
azimentype[aco]=1;
break;

case 100:case 101:case 102:case 103:case 104:case 105:case 106:case 107:case 108:
azimentype[aco]=1;
break;

case 120:case 121:case 122:
azimentype[aco]=1;
break;

case 130:case 131:case 132:case 133:case 134:
azimentype[aco]=1;
break;
*/
}

if (xtype==87){atm[aco]=rand(179)+(-90);}

aco+=1;if (aco>=amax-1){aco=0;}
}//t1

//if (bz[t]==1){bz[t]=0;}
}//rz

}//ayobi