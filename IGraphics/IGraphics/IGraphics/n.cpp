/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
//#include<stdio.h>
#include<conio.h>
# include "iGraphics.h"
//# include "gl.h"
#include<math.h>
#include<time.h>

int ball_x=100, ball_y=100;
int dx, dy;
int vx,vy,t;
int  vel=50,ang=0;
int x=1;
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
	if(x==1){
	iClear();
	iShowBMP(0,0,"demo1.bmp");
	iShowBMP2(ball_x,ball_y,"axe.bmp",0*65536+255*256+0);
	//iShowBMP(ball_x,ball_y,"a.bmp");
    iSetColor(0, 0, 0);
	//iFilledRectangle(ball_x, ball_y, 30,40);
	
	iText(800,500,"Score:");
	iSetColor(0, 240, 0);
	iText(10,480,"velocity:");
	iText(10,440,"angle:");
	iFilledRectangle(100, 470+vel, 180-vel,20);
	iFilledRectangle(100, 430+ang, 180-ang,20);
	iSetColor(255, 0, 0);
	iFilledCircle(ball_x, ball_y, 15);
    //iFilledCircle(399, 399, 7);
	
	iSetColor(255, 255, 255);
	iText(400, 500, "Welcome to the world of Angry Birds!!");
	}
}


/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		//if(mx>=100 && mx<=280 && my>=470 && my<=490)
	{
		//vel= mx-100;
	
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
	//place your codes for other keys here
}

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

void ballChange(){
	t=t+0.5;
	ball_x = vx*t;
	ball_y = vy*t-4.9*t*t;

	//if(ball_x > 400 || ball_x < 0)dx = -dx;
	//if(ball_y > 400 || ball_y < 0)dy= -dy;
		//ball_y = -ball_y;
}

int main()
{
	vx=vel*cos(50.00);
	vy=vel*sin(50.00);
	t=0;
	//place your own initialization codes here. 
	iSetTimer(1000,ballChange);
	 //= 5;
	
	//dy = 7;
	//vx=43;
	//vy=25;
	
	iInitialize(1024, 512, "Angry Birds");

	return 0;
}	