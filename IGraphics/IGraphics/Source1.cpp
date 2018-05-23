

# include "iGraphics.h"
# include "gl.h"
#include<math.h>




int mainmenu()
{
	iInitialize(1024, 512, "Angry Birds!");
	iClear();
	iShowBMP(0,0,"start.bmp");
}


int main()
{
	mainmenu();

}

