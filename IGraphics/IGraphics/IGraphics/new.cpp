

/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include "gl.h"
# include<math.h>
#include <string.h>



int z=0,f=0;
int score;
int ball_x=0, ball_y=0;
int dx, dy;
int lvl=1;
int vel;
double x=0,y=0,arg=0,t=0;
int flag=1,flag1=0;
int m2x,m2y;
int chance=3;
char str[50];
char name[4][20];
char scr[4][5];
char temp[20];
char tem[5];
FILE *fp,*fp1;
int high,enter=0,done;
int len;
char sr[20];
char srt[20];

/* 
	function iDraw() is called again and again by the system.
*/
void hall_of_fame();
void iDraw()
{
	//place your drawing codes here	

	iClear();
	iShowBMP(0,0,"start.bmp");
	iSetColor(0,0,0);
	iText(300,100," Made by Mohammod Riad Ashraf & Yeaseen Arafat " );
    
	
	if (flag==2)
	{
		iShowBMP(0,0,"1.bmp");
		iSetColor(0, 255, 10);
		iFilledRectangle(100,290,194,29);
		iFilledRectangle(100,232,194,29);
		iFilledRectangle(100,168,194,29);
		iSetColor(255, 0,0 );
		iText(160,303, "NEW  GAME");
		iText(160,245, "HIGH SCORE");
		iText(160,182, "   EXIT");
	
	}
	
	
	if(flag==3 )
	{
		sprintf(str, "Score is %d", score);
		
		if(lvl==1) iShowBMP(0,0,"dem.bmp");
		if(lvl==2) iShowBMP(0,0,"lvl3.bmp");
		if(lvl==3) iShowBMP(0,0,"bck.bmp");
		if(lvl==4) iShowBMP(0,0,"lvl4.bmp");
		iShowBMP2(ball_x,ball_y,"18.bmp",0*65536+255*256+0);
		if(chance==3) 
		{
			iShowBMP2(20,400,"18.bmp",0*65536+255*256+0);
			iShowBMP2(60,400,"18.bmp",0*65536+255*256+0);
			iShowBMP2(100,400,"18.bmp",0*65536+255*256+0);
		}
		if(chance==2) 
		{
			iShowBMP2(20,400,"18.bmp",0*65536+255*256+0);
			iShowBMP2(60,400,"18.bmp",0*65536+255*256+0);
			//iShowBMP2(100,400,"18.bmp",0*65536+255*256+0);
		}
		if(chance==1) 
		{
			iShowBMP2(20,400,"18.bmp",0*65536+255*256+0);
			//iShowBMP2(60,400,"18.bmp",0*65536+255*256+0);
			//iShowBMP2(100,400,"18.bmp",0*65536+255*256+0);
		}
		iShowBMP2(100,0,"21.bmp",0*65536+255*256+0);
		iShowBMP(200,450,"22.bmp");
		if(lvl==1) iShowBMP2(512+256,0,"12.bmp",0*65536+255*256+0);
		if(lvl==2) 
		{
				iShowBMP2(512+256,0,"12.bmp",0*65536+255*256+0);
				iShowBMP2(512+256+64,128,"box.bmp",0*65536+255*256+0);
		}
		if(lvl==3)
			{
				iShowBMP2(435,0,"box.bmp",0*65536+255*256+0);
				iShowBMP2(827,0,"box.bmp",0*65536+255*256+0);
		}
		if(lvl==1) iShowBMP2(512+256+15,128,"19.bmp",0*65536+255*256+0);
		if(lvl==2) iShowBMP2(512+256+64+32,128+128,"19.bmp",0*65536+255*256+0);
		if(lvl==3) iShowBMP2(663,64,"19.bmp",0*65536+255*256+0);
		iSetColor(0,255,0);
		iFilledRectangle(700,450,150,32);
		iSetColor(255,0,0);
	    iText(740,458,str);

		iSetColor(255,255,255);
		iCircle(0, 0, 100);
		iLine(0,0,100*cos(arg),100*sin(arg));
		iSetColor(0,210,0);
		iFilledRectangle(0,450,150,32);
		if(flag1==1)
			
		{
			vel= m2x;
			iSetColor(0,255,0);
			iFilledRectangle(0,450,m2x,32);
		
		}
		iSetColor(255,0,0);
		iFilledCircle((ball_x-10),(ball_y+15),5);
		iFilledCircle((ball_x-20),(ball_y+10),5);
		iFilledCircle((ball_x-30),(ball_y+5),5);
		
	}
	
	
	

	if(flag==4)
	{
		sprintf(str, "Score is %d", score);
		iSetColor(255,255,255);
		iText(500,500,str);
		if(lvl==1) iShowBMP(0,0,"dem.bmp");
		if(lvl==2) iShowBMP(0,0,"lvl3.bmp");
		if(lvl==3) iShowBMP(0,0,"bck.bmp");
		//iShowBMP2(ball_x,ball_y,"18.bmp",0*65536+255*256+0);
		iShowBMP2(100,0,"21.bmp",0*65536+255*256+0);
		if(lvl==1) iShowBMP2(512+256,0,"12.bmp",0*65536+255*256+0);
		if(lvl==2) 
		{
				iShowBMP2(512+256,0,"12.bmp",0*65536+255*256+0);
				iShowBMP2(512+256+64,128,"box.bmp",0*65536+255*256+0);
		}
		if(lvl==3) 
			{
				iShowBMP2(435,0,"box.bmp",0*65536+255*256+0);
				iShowBMP2(827,0,"box.bmp",0*65536+255*256+0);
		}
		//iShowBMP2(512,0,"17.bmp",0*65536+255*256+0);
		if(lvl==1) iShowBMP2(512+256+15,128,"20.bmp",0*65536+255*256+0);
		if(lvl==2) iShowBMP2(512+256+64+32,128+128,"20.bmp",0*65536+255*256+0);
		if(lvl==3) iShowBMP2(663,64,"20.bmp",0*65536+255*256+0);
		//iShowBMP2(512+256,128,"15.bmp",0*65536+255*256+0);
		iSetColor(0,255,0);
		iFilledRectangle(700,450,150,32);
		iSetColor(255,0,0);
		iText(740,458,str);
		iSetColor(0,255,0);
		iFilledRectangle(500,450,150,32);
		iSetColor(255,0,0);
		iText(520,458,"PLAY AGAIN");
		iSetColor(0,255,0);
		iFilledRectangle(300,450,150,32);
		iSetColor(255,0,0);
		iText(320,458,"NEXT LEVEL");
		iSetColor(0,255,0);
		iFilledRectangle(870,450,150,32);
		iSetColor(255,0,0);
		iText(890,458,"EXIT");
		iSetColor(0,210,0);
		iFilledRectangle(0,450,150,32);
		iPauseTimer(0);
		
		

	}
	if(flag==5)
	{
		//char str[50];
		sprintf(str, "Score is %d", score);
		iSetColor(255,255,255);
		iText(500,500,str);
		iShowBMP2(ball_x,ball_y,"18.bmp",0*65536+255*256+0);
		iShowBMP2(20,400,"18.bmp",0*65536+255*256+0);
		iShowBMP2(60,400,"18.bmp",0*65536+255*256+0);
		iShowBMP2(100,400,"18.bmp",0*65536+255*256+0);
		if(lvl==1) iShowBMP(0,0,"dem.bmp");
		if(lvl==2) iShowBMP(0,0,"lvl3.bmp");
		if(lvl==3) iShowBMP(0,0,"bck.bmp");
		//iShowBMP2(ball_x,ball_y,"18.bmp",0*65536+255*256+0);
		iShowBMP2(100,0,"21.bmp",0*65536+255*256+0);
		if(lvl==1) iShowBMP2(512+256,0,"12.bmp",0*65536+255*256+0);
		if(lvl==2) 
		{
				iShowBMP2(512+256,0,"12.bmp",0*65536+255*256+0);
				iShowBMP2(512+256+64,128,"box.bmp",0*65536+255*256+0);
		}
		if(lvl==3) 
			{
				iShowBMP2(435,0,"box.bmp",0*65536+255*256+0);
				iShowBMP2(827,0,"box.bmp",0*65536+255*256+0);
		}
		//iShowBMP2(512,0,"17.bmp",0*65536+255*256+0);
		if(lvl==1) iShowBMP2(512+256+15,128,"19.bmp",0*65536+255*256+0);
		if(lvl==2) iShowBMP2(512+256+64+32,128+128,"19.bmp",0*65536+255*256+0);
		if(lvl==3) iShowBMP2(663,64,"19.bmp",0*65536+255*256+0);
		//iShowBMP2(512+256,128,"15.bmp",0*65536+255*256+0);
		iSetColor(0,255,0);
		iFilledRectangle(700,450,150,32);
		iSetColor(255,0,0);
		iText(740,458,str);

		iSetColor(0,255,0);
		iFilledRectangle(500,450,150,32);
		iSetColor(255,0,0);
		iText(520,458,"RETRY");
		iSetColor(0,255,0);
		iFilledRectangle(870,450,150,32);
		iSetColor(255,0,0);
		iText(890,458,"EXIT");
		iSetColor(0,210,0);
		iFilledRectangle(0,450,150,32);
		
		iPauseTimer(0);

	}
	if(flag==6)
	{
		iClear();
		iShowBMP(0,0,"bash.bmp");
		iSetColor(255,0,0);
		iFilledRectangle(400,400,150,32);
		iSetColor(0,0,255);
		iText(420,408,"GAME OVER");
		iSetColor(255,0,0);
		iFilledRectangle(400,350,150,32);
		iSetColor(0,0,255);
		iText(420,358,"MAIN MENU");
		if(!done) hall_of_fame();
		done=1;
	}
	
	
	if(flag==8)
	{
		exit(0);
	}

	if(flag==10){
		iSetColor(0,255,0);
		iFilledRectangle(0,0,1024,512);
		iSetColor(255,2,2);
		iText(430,400,"HIGH SCORES!");
		iSetColor(0,0,0);
		int x=400,y=350,i;
		for(i=0;i<4;i++){
			iText(x,y,name[i]);
			iText(x+200,y,scr[i]);
			y=y-50;
		}
		iSetColor(0,0,0);
		iFilledRectangle(450,150,150,32);
		iSetColor(255,255,255);
		iText(500,158,"BACK");
	}

	if(high==1){
		
		iText(350,300,"CONGRATULATION !!!! YOU HAVE MADE A NEW HIGH SCORE"); 
		iText(370,250,"INPUT YOUR NAME");
		iFilledRectangle(380,200,150,32);
		iSetColor(255,255,255);
		iText(400,208,sr);
	}

	if(enter==1){
		int i,j;
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(strcmp(scr[i],scr[i+1])<0){
					strcpy(tem,scr[i]);
					strcpy(scr[i],scr[i+1]);
					strcpy(scr[i+1],tem);
					strcpy(temp,name[i]);
					strcpy(name[i],name[i+1]);
					strcpy(name[i+1],temp);
				}
			}
		}
		enter=0;
	}
	
	
	iSetColor(255, 255, 255);
	iText(100, 10, "Press p for pause, r for resume, END for exit.");
	
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	int i;
	for(i=0;i<4;i++){
		printf("%s %s\n",scr[i],name[i]);}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			printf("%d %d\n",mx,my);
			if(mx>405 && mx<615 && my>175 && my<251 && flag==1)

			{
				flag=2;
				
				
				
			}
			if(mx>450 && mx<600 && my>150 && my<182 && flag==10)
			{
					flag=2;
			}
			if(mx>0 && mx<86 && my>0 && my<63 && flag==1)
			{
				flag=8;
				int i;
				fp=fopen("highscore.txt","w");
				for(i=0;i<4;i++){
					fprintf(fp,"%s %s\n",name[i],scr[i]);
				}
				fclose(fp);
			}
			if(mx>100 && mx<292 && my>290 && my<319 && flag==2)
			{
				flag=3;//new game
				srand(time(NULL));
				PlaySound("music\\Birds Intro",NULL,SND_LOOP | SND_ASYNC);
				
			}
			if(mx>100 && mx<292 && my>232 && my<264 && flag==2)
			{
				flag=10;
				
			}
			
			if(mx>100 && mx<292 && my>(290-2*58) && my<(319-2*58) && flag==2)
			{
				flag=1;
			}
			if(mx>0 && my>450 && mx<150 && my< 450+32 && flag==3)
			{
				flag1=1;
				m2x=mx;
				m2y=my;
			}
			if(mx>0 && mx<100 && my>0 && my<100 && flag==3)
			{

				flag1=9;
				arg = atan((double)my/mx);
				iResumeTimer(0);
			}
			if(mx>500 && mx<650 && my>450 && my<479 && flag==4)
			{
				
				flag=3;//play again
				chance=3;
				
				
			}
			if(mx>300 && mx<450 && my>450 && my<479 && flag==4)
			{
				flag=3;//nxt lvl
				lvl=lvl+1;
				chance=3;
				if(lvl==4) flag=6;

			}
			if(mx>870 && mx<1024 && my>450 && my<479 && flag==4)
			{
				flag=6;//exit
				lvl=1;
			}
			if(mx>500 && mx<650 && my>450 && my<479 && flag==5)
			{
				flag=3;//PLAY GAIN
				chance=chance-1;
				if(chance==0) flag=6;
			}
			if(mx>870 && mx<1024 && my>450 && my<479 && flag==5)
			{
				flag=6;//exit
				lvl=1;
			}
			if(mx>400 && mx<550 && my>358 && my<390 && flag==6)
			{
				flag=2;//main menu
				lvl=1;
				srand(time(NULL));
				PlaySound("music\\Entry",NULL,SND_LOOP | SND_ASYNC);
			}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	if(key == 'm') PlaySound(0,0,0);
	

	int i;
	if(high == 1)
	{
		if(key == '\r'){
			enter=1;
			high = 0;
			strcpy(name[3], sr);
			strcpy(scr[3],srt);
			for(i = 0; i < len; i++)  sr[i] = 0;
			len = 0;}
		else{
			if(len<=12) sr[len] = key,len++;;}

	}
}


	//place your codes for other keys here

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}

void hall_of_fame(){
	int i;
	sprintf(srt,"%d",score);
	if(strcmp(srt,scr[2])>0) high=1;
}

void ballChange(){
	if(flag1==9){
		x=cos(arg);
		y=sin(arg);
		/*if(ball_y<0 && ball_x>0)
	    {   
			f=ball_y;
			z=ball_x;
			t=.5;
    	}*/
		ball_x = z+vel*x*t;
		ball_y = f+vel*y*t- 4.9*t*t;
		t=t+.1;
		
		if(ball_x<10 || ball_y<10)// ball_x<100 && ball_y>10 && ball_y<100)
			{srand(time(NULL));
			PlaySound("music\\Birds Flying",NULL, SND_ASYNC);
		}	
		if(ball_x>753 && ball_x<848 && ball_y> (128) && ball_y<192 && flag==3 && lvl==1)
		{
			score=score+10;
			flag1=0;
			x=0;
			y=0;
			arg=0;
			t=0;
			z=0;
			f=0;
			ball_x=0;ball_y=0;
			flag=4;
			srand(time(NULL));
			PlaySound("music\\Level Complete",NULL, SND_ASYNC);
		}
		if(ball_x>763+64 && ball_x<848+64+28 && ball_y> (128+128) && ball_y<192+128 && flag==3 && lvl==2 )
		{
			score=score+10;
			flag1=0;
			x=0;
			y=0;
			arg=0;
			t=0;
			z=0;
			f=0;
			ball_x=0;ball_y=0;
			flag=4;
			srand(time(NULL));
			PlaySound("music\\Level Complete",NULL, SND_ASYNC);
		}
		if(ball_x>653 && ball_x<727 && ball_y> (64) && ball_y<128 && flag==3 && lvl==3 )
		{
			score=score+10;
			flag1=0;
			x=0;
			y=0;
			arg=0;
			t=0;
			z=0;
			f=0;
			ball_x=0;ball_y=0;
			flag=4;
			srand(time(NULL));
			PlaySound("music\\Level Complete",NULL, SND_ASYNC);
		}
		if((ball_x>435 && ball_x<563 && ball_y> (0) && ball_y<128 && flag==3 && lvl==3 ) || (ball_x>827 && ball_x<955 && ball_y> (0) && ball_y<128 && flag==3 && lvl==3 ))
		{
			flag=5;
			flag1=0;
			t=0;
			z=0;
			f=0;
			ball_x=0;ball_y=0;
			srand(time(NULL));
			PlaySound("music\\Level Failed",NULL, SND_ASYNC);

		}
		
		if(ball_x>1022 || (ball_y<2 && ball_x>100) )
		{
			flag=5;
			flag1=0;
			t=0;
			z=0;
			f=0;
			ball_x=0;ball_y=0;
			srand(time(NULL));
			PlaySound("music\\Level Failed",NULL, SND_ASYNC);
		}
	}
}

int main()
{
	
	//place your own initialization codes here. 
	fp=fopen("highscore.txt","r");
	int i;
	for(i=0;i<3;i++){
		fscanf(fp,"%s %s",name[i],scr[i]);
	}
	fclose(fp);
	
	if( flag==1)
	{
		srand(time(NULL));
		PlaySound("music\\Entry",NULL,SND_LOOP | SND_ASYNC);
	}
	if(flag==6)
	{
		srand(time(NULL));
		PlaySound("music\\Game Completed",NULL,SND_LOOP | SND_ASYNC);
		
	}
	{
		iSetTimer(20, ballChange);
	}
	
	iInitialize(1024, 512, "Angry Birds!");

	return 0;
}	


