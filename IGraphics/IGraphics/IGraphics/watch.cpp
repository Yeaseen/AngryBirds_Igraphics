/*#include "iGraphics.h"
#include<math.h>
#include<time.h>

double o,x=500,y=360+250,sx,sy,p;
double xm=500,ym=360+220,mx,my,pm;
double xh=500,yh=360+200,hx,hy,ph,H,M,S;
int i, h1, h2, m1, m2, s1, s2, v;

unsigned char key='d';
unsigned char key1='a';

void iDraw()
{
	
	iClear();
		iSetColor(10,10,10);
	iFilledCircle(500,360,300);//Large
	   iSetColor(0,255,0);
	   iCircle(500,360,305);//out
	iSetColor(0,0,255);
	iCircle(500,360,275);//nextout
	iSetColor(255,0,0);
	for (i=1,o=(6/57.29);i<=60;i++,o+=(6/57.29))
	{   if(i%5!=0)
			iFilledCircle(500+295*cos(o),360+295*sin(o),4);
		if (i%5==0)
			iFilledCircle(0,0,0);
	}


	iSetColor(255,0,0);
	iLine(500,360,x,y);///second
	iSetColor(0,120,120);
	iLine(500,360,xm,ym);///minit
	iSetColor(20,200,40);
	iLine(500,360,xh,yh);//HR
	iSetColor(255,0,0);
	iText(500+244,360-150,"IV");//4(500+259,360-150)point
    iText(500+145,360-256,"V");//	iFilledCircle(500+150,360-260,5);//60
	iText(495,60,"VI");//iFilledCircle(500,65,5);//lower
	iText(500-155,360-257,"VII");//iFilledCircle(500-150,360-260,5);//120
	iText(200,360,"IX");//iFilledCircle(205,360,5);//left
	iText(500-255,360+145,"X");//iFilledCircle(500-260,360+150,5);//150
	iText(500+240,360+150,"II");//iFilledCircle(500+259,360+150,5);//330
	iText(500+140,360+252,"I");//	iFilledCircle(500+150,360+260,5);//300
	iText(490,650,"XII");//	iFilledCircle(500,655,5);//upper
	iText(777,360,"III");//	iFilledCircle(795,360,5);//right
	iText(500-150,360+250,"XI");//	iFilledCircle(500-150,360+260,5);//240
	iText(500-260,360-150,"VIII");//	iFilledCircle(500-260,360-150,5);//210
    iSetColor(20,50,210);
	iFilledCircle(500,360,20);//small
}

void digit()
{
	iClear();

	double dx=800, dy=300;

	for(i=1; i<=6; i++)
	{	
		if(i==1) v=s1;
		else if(i==2)v=s2;
		else if(i==3)v=m1;
		else if(i==4)v=m2;
		else if(i==5)v=h1;
		else if(i==6)v=h2;
		if(v==0){
			iSetColor(255,0,0);
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+60,10,60);//vert right top
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
			//iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx-60,dy,10,60);//ver left bottom
			iFilledRectangle(dx-60,dy+60,10,60);//vert left top
		}
		else if(v==1){
			iSetColor(255,0,0);
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+70,10,60);//vert right top
		}
		else if(v==2){
			iSetColor(255,0,0);
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx,dy+70,10,60);//vert right top
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-70,dy,10,60);//ver left bottom
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
		}
		else if(v==3){
			iSetColor(255,0,0);
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+70,10,60);//vert right top
		}
		else if(v==4){
			iSetColor(255,0,0);
			iFilledRectangle(dx-70,dy+70,10,60);//vert left top
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+70,10,60);//vert right top
		}
		else if(v==5){
			iSetColor(255,0,0);
			iFilledRectangle(dx-70,dy+70,10,60);//vert left top
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx,dy,10,60);//vert right bottom
		}
		else if(v==6){
			iSetColor(255,0,0);
			iFilledRectangle(dx-70,dy,10,60);//ver left bottom
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx-70,dy+70,10,60);//vert left top
		}
		else if(v==7){
			iSetColor(255,0,0);
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+70,10,60);//vert right top
		}
		else if(v==8){
			iSetColor(255,0,0);
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+70,10,60);//vert right top
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx-70,dy,10,60);//ver left bottom
			iFilledRectangle(dx-70,dy+70,10,60);//vert left top
		}
		else{
			iSetColor(255,0,0);
			iFilledRectangle(dx,dy,10,60);//vert right bottom
			iFilledRectangle(dx,dy+70,10,60);//vert right top
			iFilledRectangle(dx-60,dy-10,60,10);//hor bottom
			iFilledRectangle(dx-60,dy+60,60,10);//hor mid
			iFilledRectangle(dx-60,dy+130,60,10);//hor top
			iFilledRectangle(dx-70,dy+70,10,60);//vert left top
		}
		if(i==2|| i==4){
			iSetColor(255, 0, 0);
			iFilledRectangle(dx-100, dy+30, 10, 10);
			iSetColor(255, 0, 0);
			iFilledRectangle(dx-100, dy+100, 10, 10);
			dx=dx-40;
		}
		dx=dx-90;
	}
	

}

}


void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

void second()
 
{
	  sx=250*cos(p/57.29);
	  sy=250*sin(p/57.29);
	  x=500+sx;
	  y=360+sy;
      p=p-6;
}
void minute()
{
      mx=220*cos(pm/57.29);
	  my=220*sin(pm/57.29);
	  xm=500+mx;
	  ym=360+my;
	  pm=pm-.1;
}
void hour()
{
	hx=200*cos(ph/57.29);
	hy=200*sin(ph/57.29);
	xh=500+hx;
	yh=360+hy;
	ph=ph-1/600;
}
int main()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	M=ptm->tm_min;
	S=(ptm->tm_sec)+2;


	ph =(3-H)*30.0-30*M/60.0-30*S/3600.0+.1/600+270+90;
     
	pm= (15-M)*6.0-S/60.0+.1+270+90;

	p = (15-S)*6.0+6+270+90;

    second();
    minute();
    hour();

   
	
    iSetTimer(1000,second);
	iSetTimer(1000,minute);
	iSetTimer(1000,hour);
	iInitialize(1000, 720, "demo");
	return 0;
}
*/