#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

int r, x=0,y,p;

void draw_pixel(int x, int y)
{       glColor3ub(255, 0, 0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glVertex2i(-x, -y);
        glVertex2i(-x, y);
        glVertex2i(x, -y);
        glVertex2i(y, x);
        glVertex2i(-y, -x);
        glVertex2i(-y, x);
        glVertex2i(y, -x);
        glEnd();

}

void draw_circle()
{
    x = 0;
    y = r;
    int p = 1 - r;

    while(x < y){
       draw_pixel(x, y);
        if(p < 0){
            p = p + 2 * x + 1;
            x++;
        }
        else{
            p = p + 2 * x + 1 - 2 * y;
            x++;
            y--;
        }
    }
}

void myDisplay()
{
    //draw_polygon(-700,-500,700,-500,700,500,-700,500);
    draw_circle();
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
    printf( "Enter radius(r)\n");
    scanf("%d", &r);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Mid point Circle drawing algo");
    init ();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
