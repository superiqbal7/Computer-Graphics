#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>

int scale_x = 0, scale_y = 0;
int mov_x = 0, mov_y = 0;

void drawCircle(int radius){
    glBegin(GL_POLYGON);
	for (float angle = 0;angle<360;angle+=5)
	{
		float xc=sin(angle*3.1416/180) * radius;
		float yc=cos(angle*3.1416/180) * radius;
		glVertex2d( xc, yc);
	}
    glEnd();
}

void side_pilar(){

 /* left pillar 1 */
    glColor3ub (234, 237, 237);
    glBegin(GL_POLYGON);
    glVertex2d (250, 250+scale_y);
    glVertex2d (280, 250+scale_y);
    glVertex2d (280, 660);
    glVertex2d (250, 650);
    glEnd();

 /* left pillar 2 */
    mov_x = 150;
    glBegin(GL_POLYGON);
    glVertex2d (250+mov_x, 250+scale_y);
    glVertex2d (280+mov_x, 250+scale_y);
    glVertex2d (280+mov_x, 660);
    glVertex2d (250+mov_x, 660);
    glEnd();

 /* left pillar 3 */
    glBegin(GL_POLYGON);
    glVertex2d (250, 650);
    glVertex2d (430, 660);
    glVertex2d (430, 690);
    glVertex2d (250, 680);
    glEnd();

    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d (295, 250+scale_y);
    glVertex2d (295, 654);      /* left grill 1 vertical */
    glVertex2d (325, 250+scale_y);
    glVertex2d (325, 656);      /* left grill 2 vertical*/
    glVertex2d (355, 250+scale_y);
    glVertex2d (355, 657);      /* left grill 3 vertical*/
    glVertex2d (385, 250+scale_y);
    glVertex2d (385, 658);      /* left grill 4 vertical*/
    glEnd();

 /* left grill 1 horizontal*/
    glBegin(GL_POLYGON);
    glVertex2d (280, 350+scale_y);
    glVertex2d (400, 350+scale_y);
    glVertex2d (400, 352+scale_y);
    glVertex2d (280, 352+scale_y);
    glEnd();

 /* left grill 2 horizontal*/
    glBegin(GL_POLYGON);
    glVertex2d (280, 550+scale_y);
    glVertex2d (400, 550+scale_y);
    glVertex2d (400, 552+scale_y);
    glVertex2d (280, 552+scale_y);
    glEnd();
}


/* middle pillar left 1 */
void middle_pilar(){
    glColor3ub (234, 237, 237);
    glBegin(GL_POLYGON);
    glVertex2d (800, 250);
    glVertex2d (830, 250);
    glVertex2d (830, 730);
    glVertex2d (800, 730);
    glEnd();


 /* middle pillar left 2 */
    glBegin(GL_POLYGON);
    glVertex2d (800, 730);
    glVertex2d (830, 730);
    glVertex2d (815, 880);
    glVertex2d (790, 880);
    glEnd();


 /* middle pillar left 3 */
    mov_x = 150;
    glBegin(GL_POLYGON);
    glVertex2d (800+mov_x, 250);
    glVertex2d (830+mov_x, 250);
    glVertex2d (830+mov_x, 730);
    glVertex2d (800+mov_x, 730);
    glEnd();


 /* middle pillar left 4 */
    glBegin(GL_POLYGON);
    glVertex2d (800+mov_x, 730);
    glVertex2d (830+mov_x, 730);
    glVertex2d (830+mov_x, 880);
    glVertex2d (810+mov_x, 880);
    glEnd();


 /* middle pillar left 5 */
    glBegin(GL_POLYGON);
    glVertex2d (790, 880);
    glVertex2d (980, 880);
    glVertex2d (980, 900);
    glVertex2d (788, 900);
    glEnd();


/* left grill 1 vertical*/
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d (845, 250);
    glVertex2d (845, 730);
    glVertex2d (845, 730);
    glVertex2d (830, 880);

 /* left grill 2 vertical*/
    glVertex2d (875, 250);
    glVertex2d (875, 730);
    glVertex2d (875, 730);
    glVertex2d (875, 880);


/* left grill 3 vertical*/
    glVertex2d (905, 250);
    glVertex2d (905, 730);
    glVertex2d (905, 730);
    glVertex2d (905, 880);

/* left grill 4 vertical*/
    glVertex2d (935, 250);
    glVertex2d (935, 730);
    glVertex2d (935, 730);
    glVertex2d (945, 880);
    glEnd();

 /* left grill 1 horizontal*/
    glBegin(GL_POLYGON);
    glVertex2d (830, 350);
    glVertex2d (950, 350);
    glVertex2d (950, 352);
    glVertex2d (830, 352);
    glEnd();


 /* left grill 2 horizontal*/
    glBegin(GL_POLYGON);
    glVertex2d (830, 550);
    glVertex2d (950, 550);
    glVertex2d (950, 552);
    glVertex2d (830, 552);
    glEnd();


/* left grill 3 horizontal*/
    glBegin(GL_POLYGON);
    glVertex2d (830, 735);
    glVertex2d (950, 735);
    glVertex2d (950, 737);
    glVertex2d (830, 737);
    glEnd();
}
 /* sky*/
void sky(){
    glColor3ub(133, 193, 233);
    glBegin(GL_POLYGON);
    glVertex2d (0, 400);
    glVertex2d (1900, 400);
    glVertex2d (1900, 950);
    glVertex2d (0, 950);
    glEnd();
}
/* grass*/
void grass(){
    glColor3ub(192, 255, 2);
    glBegin(GL_POLYGON);
    glVertex2d (0, 290);
    glVertex2d (1900, 290);
    glVertex2d (1900, 400);
    glVertex2d (0, 400);
    glEnd();
}
/* floor*/
void solidFloor(){
    glColor3ub(246, 221, 204);
    glBegin(GL_POLYGON);
    glVertex2d (0, 240);
    glVertex2d (1900, 240);
    glVertex2d (1900, 290);
    glVertex2d (0, 290);
    glEnd();
}
/* stair 1*/
void stair(){
    glColor3ub(110, 44, 0);
    glBegin(GL_POLYGON);
    glVertex2d (0, 220+mov_y);
    glVertex2d (1900, 220+mov_y);
    glVertex2d (1900, 240+mov_y);
    glVertex2d (0, 240+mov_y);
    glEnd();
	/* stair 2*/
    glColor3ub(246, 221, 204);
    glBegin(GL_POLYGON);
    glVertex2d (0, 170+mov_y);
    glVertex2d (1900, 170+mov_y);
    glVertex2d (1900, 220+mov_y);
    glVertex2d (0, 220+mov_y);
    glEnd();
}

/* flag stand */
void flag(){
    glColor3ub(97, 106, 107);
    glBegin(GL_POLYGON);
    glVertex2d (50, 250);
    glVertex2d (70, 250);
    glVertex2d (70, 750);
    glVertex2d (50, 750);
    glEnd();

	/* flag body */

    glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
    glVertex2d (50, 750);
    glVertex2d (350, 750);
    glVertex2d (350, 900);
    glVertex2d (50, 900);
    glEnd();

	 //flag circle

    glColor3ub(231, 76, 60);
    glPushMatrix();
    glTranslated(200, 825, 0);
    drawCircle(60);
    glPopMatrix();
}

void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);

sky();
grass();
solidFloor();
flag();

mov_y = 0;
stair();

mov_y = -70;
stair();

mov_y = -140;
stair();

mov_y = -210;
stair();


/// draw circle
glColor3ub(255, 0, 0);
glPushMatrix();
glTranslated(972, 550, 0);
drawCircle(220);
glPopMatrix();

scale_y = 0;
side_pilar(); ///left pillar 1

scale_y = -30;
glPushMatrix();
glTranslated(250, 30, 0);
side_pilar();     ///left pillar 2
glPopMatrix();


scale_y = -30;
glPushMatrix();
glTranslated(1700, 30, 0);
glRotated(180, 0, 1, 0);
side_pilar();     ///right pillar 1
glPopMatrix();

scale_y = 0;
glPushMatrix();
glTranslated(1950, 0, 0);
glRotated(180, 0, 1, 0);
side_pilar();     ///right pillar 2
glPopMatrix();

middle_pilar(); ///left middle pillar

glPushMatrix();
glTranslated(1940, 0, 0);
glRotated(180, 0, 1, 0);
middle_pilar();     ///right middle pillar
glPopMatrix();


glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor(255, 255, 255, 255);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 1900, 0, 950);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_RGB);
glutInitWindowSize (1900, 950);
glutInitWindowPosition (0, 0);
glutCreateWindow ("Shaheed Minar");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

