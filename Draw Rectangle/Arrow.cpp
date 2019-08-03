#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

void draw_arrow(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3ub (255, 255, 255);

    glBegin(GL_POLYGON);
    glVertex2d(100, 200);
    glVertex2d(400, 200);
    glVertex2d(400, 400);
    glVertex2d(100, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(400, 175);
    glVertex2d(400, 425);
    glVertex2d(500, 300);
    glEnd();
}
void myDisplay()
{
    //draw_polygon(-700,-500,700,-500,700,500,-700,500);
    draw_arrow();
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
