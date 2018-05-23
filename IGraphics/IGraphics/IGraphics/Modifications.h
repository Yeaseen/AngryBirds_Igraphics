void iShowBMP(int x, int y, char filename[])
{
    AUX_RGBImageRec *TextureImage;
    TextureImage = auxDIBImageLoad(filename);
    
    int i,j,k;
    int width = TextureImage->sizeX;
    int height = TextureImage->sizeY;
    int nPixels = width * height;
    int *rgPixels = new int[nPixels];
    
    //
    // Specify the color that you would like to ignore.
    // This is the background color of the different small images
    // you would like to add in the scene. In this example, I have
    // chosen white to be the ignore color
    //
    int ignoreColor = ((unsigned int)~0>>8);

    for (i = 0, j=0; i < nPixels; i++, j += 3)
    {
        int rgb = 0;
        for(int k = 2; k >= 0; k--)
        {
            rgb = ((rgb << 8) | TextureImage->data[j+k]);
        }

        rgPixels[i] = (rgb == ignoreColor) ? 0 : 255;
        rgPixels[i] = ((rgPixels[i] << 24) | rgb);
    }

    glRasterPos2f(x, y);
    glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, rgPixels);
    
    delete []rgPixels;
    free(TextureImage->data);
    free(TextureImage);
}

void iInitialize(int width=500, int height=500, char *title="iGraphics")
{
    iScreenHeight = height;
    iScreenWidth = width;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA) ;
    glutInitWindowSize(width , height ) ;
    glutInitWindowPosition( 10 , 10 ) ;
    glutCreateWindow(title) ;
    glClearColor( 0.0 , 0.0 , 0.0 , 0.0 ) ;
    glMatrixMode( GL_PROJECTION) ;
    glLoadIdentity() ;
    glOrtho(0.0 , width , 0.0 , height , -1.0 , 1.0) ;
    //glOrtho(-100.0 , 100.0 , -100.0 , 100.0 , -1.0 , 1.0) ;
    //SetTimer(0, 0, 10, timer_proc);

    iClear();

    glutDisplayFunc(displayFF) ;
    glutKeyboardFunc(keyboardHandler1FF); //normal
    glutSpecialFunc(keyboardHandler2FF); //special keys
    glutMouseFunc(mouseHandlerFF);
    glutMotionFunc(mouseMoveHandlerFF);	
    glutIdleFunc(animFF) ;

    //
    // Setup Alpha channel testing.
    // If alpha value is greater than 0, then those
    // pixels will be rendered. Otherwise, they would not be rendered
    //
    glAlphaFunc(GL_GREATER,0.0f);
    glEnable(GL_ALPHA_TEST);

    glutMainLoop();
}


