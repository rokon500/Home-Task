#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int windowWidth = 900;
int windowHeight = 600;
bool flagScale = false;
double txval = 0;
double sval = 0;

void moon(){
float theta;

    int i;
glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(i=0;i<360;i++)
	{
	  theta=i*3.142/180;



	  glVertex2f(35+2.5*cos(theta),56+2.5*sin(theta));
	}

	glEnd();
}

void cloud(){
glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2f(62,34);
glVertex2f(62,34);
glVertex2f(65,35);
glVertex2f(62,34);
glVertex2f(64,37);
glVertex2f(65,38);
glVertex2f(65,39);
glVertex2f(64,40);
glVertex2f(62,40);
glVertex2f(61,41);
glVertex2f(59,41);
glVertex2f(58,37);
glVertex2f(59,36);
glVertex2f(60,34);
glVertex2f(63,34);

glEnd();
glPopMatrix();

}
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

    case 'R':
        flagScale=true;
        break;
    case 'r':
        flagScale=false;
        break;



    case 27:
        exit(1);
    }
    glutPostRedisplay();
}

void animate()
{
if (flagScale == true)
{
txval+= 0.003;
sval+= 0.002;
if(txval > 20)
txval = -60;

if(sval>40)
    sval = -20;



}
if (flagScale == false)
{
txval = 1;
sval = 1;

}

glutPostRedisplay();
}


void rectangle(void)
{
glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.867, 0.880, 0.114);
            glVertex2f(12, 0);
            glColor3f(0.774, 0.890, 0.525);
            glVertex2f(14, 0);
            glColor3f(0.656, 0.930, 0.0651);
            glVertex2f(14, 15);
            glColor3f(0.774, 0.890, 0.525);
            glVertex2f(12, 14);
        glEnd();
    glPopMatrix();
}

void quads()
{
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(.0686, 0.707, 0.980);
            glVertex2f(14, 0);
            glColor3f(0.332, 0.790, 0.607);
            glVertex2f(22, 0);
            glColor3f(0.142, 0.750, 0.183);
            glVertex2f(22, 15);
            glColor3f(0.332, 0.790, 0.607);
            glVertex2f(14, 15);
        glEnd();
    glPopMatrix();
}



void cityView()
{
    glPushMatrix();
    glTranslatef(sval,0,0);
    moon();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(txval,0,0);
    cloud();
    glPopMatrix();



    glPushMatrix();
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(150, 0);
    glEnd();
glPopMatrix();
    //one
    glPushMatrix();
    rectangle();
    glPopMatrix();
    // two
    glPushMatrix();
    quads();
glPopMatrix();
    //three
     glPushMatrix();
    glTranslatef(6,0, 1);
    glScalef(1, 0.6,1);
    rectangle();
    glPopMatrix();

    //five
    glPushMatrix();
    glTranslatef(10,0, 1);
    glScalef(1, 1.46,1);
    rectangle();
    glPopMatrix();

    //six
    glPushMatrix();
    glTranslatef(17.05, 0, 1);
    glScalef(0.5, 1.46 ,1);
    quads();
    glPopMatrix();

    //seven
    glPushMatrix();
    glTranslatef(-2,0, 1);
    glScalef(2.5, 2.27,1);
    rectangle();
    glPopMatrix();

    //four
    glPushMatrix();
    glTranslatef(27.5, -16.1, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(1.15, 0.5,1);
    quads();
    glPopMatrix();

    //eight
    glPushMatrix();
    glTranslatef(20.5, 0, 1);
    glScalef(0.875, 2.267 ,1);
    quads();
    glPopMatrix();

    //nine
    glPushMatrix();
    glTranslatef(27.8,0, 1);
    glScalef(1, 1.67,1);
    rectangle();
    glPopMatrix();

    //ten
    glPushMatrix();
    glTranslatef(33.08, 0, 1);
    glScalef(0.625, 1.67 ,1);
    quads();
    glPopMatrix();

    //eleven
    glPushMatrix();
    glTranslatef(34 ,0, 1);
    glScalef(1, 1.13,1);
    rectangle();
    glPopMatrix();

    //twelve
    glPushMatrix();
    glTranslatef(39.3, 0, 1);
    glScalef(0.625, 1.13 ,1);
    quads();
    glPopMatrix();
}


void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluOrtho2D(-10, 90, -10, 90);
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();
glViewport(0, 0 ,windowWidth ,windowHeight);

cityView();

glFlush();
glutSwapBuffers();
}



int main (int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(00,00);
glutInitWindowSize(windowWidth, windowHeight);
glutCreateWindow("Home City view");
glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
