#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

int r=250, x=0,y,p;

void draw_pixel(int x, int y,int tx,int ty)
{

    glBegin(GL_POLYGON);
    glVertex2i(x+tx, y+ty);
    glVertex2i(-x+tx, -y+ty);
    glVertex2i(-x+tx, y+ty);
    glVertex2i(x+tx, -y+ty);
    glVertex2i(y+tx, x+ty);
    glVertex2i(-y+tx, -x+ty);
    glVertex2i(-y+tx, x+ty);
    glVertex2i(y+tx, -x+ty);
    glEnd();
}

void draw_polygon()
{
    glClear (GL_COLOR_BUFFER_BIT);
    // draw green polygon
    //glColor3ub(0,179,30);
    glBegin(GL_LINES);
    glVertex2i(-500,250);
    glVertex2i(0,250);
    glBegin(GL_LINES);
    glVertex2i(0,250);
    glVertex2i(-300,750);
    glBegin(GL_LINES);
    glVertex2i(-300,750);
    glVertex2i(-500,250);
    glEnd();

    ////
    glBegin(GL_LINES);
    glVertex2i(-300,750);
    glVertex2i(200,750);
    glBegin(GL_LINES);
    glVertex2i(200,750);
    glVertex2i(250,650);
    glBegin(GL_LINES);
    glVertex2i(250,650);
    glVertex2i(0,250);
    glBegin(GL_LINES);
    glVertex2i(250,650);
    glVertex2i(350,450);
    glBegin(GL_LINES);
    glVertex2i(200,750);
    glVertex2i(250,850);
    glBegin(GL_LINES);
    glVertex2i(100,850);
    glVertex2i(300,850);
    glBegin(GL_LINES);
    glVertex2i(-300,750);
    glVertex2i(-350,850);
    glBegin(GL_LINES);
    glVertex2i(-250,850);
    glVertex2i(-350,850);
    glEnd();
}
void draw_circle(int r,int tx, int ty)
{
    x = 0;
    y = r;
    int p = 1 - r;

    while(x < y)
    {
        draw_pixel(x, y, tx,ty);
        if(p < 0)
        {
            p = p + 2 * x + 1;
            x++;
        }
        else
        {
            p = p + 2 * x + 1 - 2 * y;
            x++;
            y--;
        }
    }
}

void myDisplay()
{
    draw_polygon();
    glColor3ub(255, 0, 0);
    draw_circle(250,-500,250);
    draw_circle(250,500,250);
    //tyre
    glColor3ub(51, 49, 47);
    draw_circle(200,-500,250);
    draw_circle(200,500,250);
    // draw_circle(500,250);
    glFlush();
}

void init (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
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
    //scanf("%d",&r);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bangladesh Flag");
    init ();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
