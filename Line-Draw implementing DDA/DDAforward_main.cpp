#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

float r, x=0,x1,x2,y1,y2,y,p;
draw_line()
{
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    //draw white polygon (rectangle) with corners at
    //(0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    int m;
    float k;
    m=(y2-y1)/(x2-x1);
    if(m<=1)
    {
        for(k=x1; k<=x2; k++)
        {
            glColor3ub (255, 255, 255);
            glBegin(GL_POINTS);
            glVertex2d(k,y1);
            glEnd();
            y1=y1+m;
        }
    }
    else
    {
        for(k=y1; k<=y2; k++)
        {
            glColor3ub (255, 255, 255);
            glBegin(GL_POINTS);
            glVertex2d(x1,k);
            glEnd();
            x1=(1/m)+x1;
        }
    }
    glFlush ();
}

void myDisplay()
{
    //draw_polygon(-700,-500,700,-500,700,500,-700,500);
    draw_line();
    //glFlush();
}

void init (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000,1000,-1000,1000);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
    printf( "Enter x1,y1,x2,y2\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("DDA Forward");
    init ();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
