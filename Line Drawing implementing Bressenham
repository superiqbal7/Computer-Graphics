#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

int x1,y1,x2,y2,dx,dy,pk,k;

void draw_pixel(int x, int y)
{
    glColor3ub (255, 255, 255);
    glBegin(GL_POINTS);
    glVertex2d (x, y);
    glEnd();
}

void draw_line(void)
{
    dx= x2-x1;
    dy= y2-y1;
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);

    pk= 2*dy-dx;
    for(k=0; k<dx; k++)
    {
        if(pk<0)
        {
            x1++;
            draw_pixel(x1, y1);
            pk=pk+2*dy;
        }
        else
        {
            x1++;
            y1++;
            draw_pixel(x1, y1);
            pk=pk+2*dy-2*dx;
        }
    }
}
void myDisplay()
{
    //draw_polygon(-700,-500,700,-500,700,500,-700,500);
    draw_line();
    glFlush();
}

void init (void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,1000);
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
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bresenham");
    init ();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
