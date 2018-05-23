#include<stdio.h>
#include<conio.h>
#include "iGraphics.h"  
/*   Function iDraw() is called again and again by the system. 

*/ 
void iDraw() 
{  //place your drawing codes here  
}  

/*   Function iMouseMove() is called mouse is dragged while pressed.  (mx, my) is the position where the mouse pointer is. 

*/ 
void iMouseMove(int mx, int my) 
{  //place your codes here 
}  

/*   Function iMouse() is called when mouse is pressed/released.  (mx, my) is the position where the mouse pointer is. 

*/ 
void iMouse(int button, int state, int mx, int my)
{  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ 
}  if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)  {   //place your codes here  
} 
} 

/*  Function iKeyboard() is called whenever a key is hit.  key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{  if(key == 'q') 
 {   exit(0); }  
 //place your codes for other keys here
}  

int main() 

{  //place your own initialization codes here.    
	iInitialize(400, 400, "demooo");  
	return 0; 
} 