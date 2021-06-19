#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Grass.h"
#include "Elephant.h"
using namespace std;

#define WINDOW_WIDTH 550.0
#define WINDOW_HEIGHT 550.0
#define WINDOW_POS_X 100
#define WINDOW_POS_Y 50


/*void nameAndTitle(string name, string title) {
  GLfloat currWidth = glutGet(GLUT_WINDOW_WIDTH), currHeight = glutGet(GLUT_WINDOW_HEIGHT),
    textW = 160, textH = 35;
  glColor3f (0, 0.1, 0.6);
  glRasterPos2f(((currWidth - textW)/currWidth)*WINDOW_WIDTH, (1-((currHeight - textH)/currHeight))*WINDOW_HEIGHT*3);
  for(char& c : title) {
      glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, c);
  }
  glColor3f (0, 0.4, 0.5);
  glRasterPos2f(((currWidth - textW)/currWidth)*WINDOW_WIDTH, (1-((currHeight - textH)/currHeight))*WINDOW_HEIGHT*2);
  for(char& c : name) {
      glutBitmapCharacter (GLUT_BITMAP_9_BY_15, c);
  }
}*/

/*void exitButton(void) {
    // Get window pixels size
    GLint curWidth = glutGet(GLUT_WINDOW_WIDTH);
    GLint curHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glColor3f(0.3, 0, 0.3);
    glRectf(((curWidth - EXIT_BUTTON_WIDTH)/curWidth)*WINDOW_WIDTH, EXIT_BUTTON_HEIGHT, 
              WINDOW_WIDTH, 0.0);

    glColor3f (1.0, 1.0, 1.0);
    string message = "EXIT";
    glRasterPos2f(((curWidth - EXIT_BUTTON_WIDTH)/curWidth)*WINDOW_WIDTH + 5.0, 5.0);
    for(char& c : message) {
        glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}*/

Grass* grass;
Elephant* elephant;

void init (void) {
  glClearColor(0.0, 0.6, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  gluPerspective(60, 1, 2.0, 100.0);
  glMatrixMode(GL_MODELVIEW);

  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 15.0 };
  GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
  //glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  grass = new Grass(-10.0, 10.0, -10.0, 10.0);
  elephant = new Elephant(0.0, 0.0);
}

float angle = 0.0;
float eyeX = 0.0;
float eyeY = 0.0;
float eyeZ = 0.0;
float upZ = 0.0;
float state = 1;

void drawRotatedCube () {

  glPushMatrix();
  glRotatef(60, 1.0, 1.0, 1.0);

  glBegin(GL_QUADS);
  //front
  glColor3f(1.0,0.0,0.0);
  glVertex3f(-1.0,1.0,1.0);
  glVertex3f(-1.0,-1.0,1.0);
  glVertex3f(1.0,-1.0,1.0);
  glVertex3f(1.0,1.0,1.0);
  //back
  glColor3f(0.0,1.0,0.0);
  glVertex3f(1.0,1.0,-1.0);
  glVertex3f(1.0,-1.0,-1.0);
  glVertex3f(-1.0,-1.0,-1.0);
  glVertex3f(-1.0,1.0,-1.0);
  //right
  glColor3f(0.0,0.0,1.0);
  glVertex3f(1.0,1.0,1.0);
  glVertex3f(1.0,-1.0,1.0);
  glVertex3f(1.0,-1.0,-1.0);
  glVertex3f(1.0,1.0,-1.0);
  //left
  glColor3f(1.0,1.0,0.0);
  glVertex3f(-1.0,1.0,-1.0);
  glVertex3f(-1.0,-1.0,-1.0);
  glVertex3f(-1.0,-1.0,1.0);
  glVertex3f(-1.0,1.0,1.0);
  //top
  glColor3f(0.0,1.0,1.0);
  glVertex3f(-1.0,1.0,-1.0);
  glVertex3f(-1.0,1.0,1.0);
  glVertex3f(1.0,1.0,1.0);
  glVertex3f(1.0,1.0,-1.0);
  //bottom
  glColor3f(1.0,0.0,1.0);
  glVertex3f(-1.0,-1.0,-1.0);
  glVertex3f(-1.0,-1.0,1.0);
  glVertex3f(1.0,-1.0,1.0);
  glVertex3f(1.0,-1.0,-1.0);

  glEnd();

  glPopMatrix();

}

void drawCube() {
  glBegin(GL_QUADS);
  //fornt
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-1.5,3.0, -3.0);
  glVertex3f(-1.5,0.0, -3.0);
  glVertex3f(1.5,0.0, -3.0);
  glVertex3f(1.5,3.0, -3.0);

  //back
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(1.5,3.0, -6.0);
  glVertex3f(1.5,0.0, -6.0);
  glVertex3f(-1.5,0.0, -6.0);
  glVertex3f(-1.5,3.0, -6.0);

  //right
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(1.5,3.0, -3.0);
  glVertex3f(1.5,0.0, -3.0);
  glVertex3f(1.5,0.0, -6.0);
  glVertex3f(1.5,3.0, -6.0);
  
  //left
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(-1.5,3.0, -6.0);
  glVertex3f(-1.5,0.0, -6.0);
  glVertex3f(-1.5,0.0, -3.0);
  glVertex3f(-1.5,3.0, -3.0);

  //top
  glColor3f(1.0, 1.0, 0.0);
  glVertex3f(-1.5,3.0, -6.0);
  glVertex3f(-1.5,3.0, -3.0);
  glVertex3f(1.5,3.0, -3.0);
  glVertex3f(1.5,3.0, -6.0);

  //bottom
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-1.5,0.0, -6.0);
  glVertex3f(-1.5,0.0, -3.0);
  glVertex3f(1.5,0.0, -3.0);
  glVertex3f(1.5,0.0, -6.0);
  glEnd();
}

void drawSphere() {
  glColor3f(0.0, 1.0, 1.0);
  glPushMatrix();
  glTranslatef(-5.0, 0.0, 0.0);
  glScalef(1,2,1);
  glutSolidSphere(2.0, 20,20);
  glPopMatrix();
}

void drawTeapot() {
  glColor3f(1.0, 0.0, 1.0);
  glPushMatrix();
  glTranslatef(5.0, 0.0, 0.0);
  glutSolidTeapot(2);
  glPopMatrix();
}

void drawTetrahedron() {
  glColor3f(1.0, 0.0, 1.0);
  glPushMatrix();
  //glScalef(0.2,0.2,0.2);
  glTranslatef(5.0, 5.0, 0.0);
  glutSolidIcosahedron();
  glPopMatrix();
}

void drawTry() {
  glBegin(GL_QUADS);
  glColor3f(0.7, 0.7, 0.7);

  glVertex3f(0, 13.0, 0.0);
  glVertex3f(0, 7.5, 0.0);
  glVertex3f(2.5, 7, -0.5);
  glVertex3f(2, 11, -1);

  glVertex3f(-2, 11, -1);
  glVertex3f(-2.5, 7, -0.5);
  glVertex3f(0, 7.5, 0.0);
  glVertex3f(0, 13.0, 0.0);

  glEnd();
}


void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  gluLookAt(20,10,0,0,0,0,0,1,0);

  grass->draw();
  elephant->draw();
  // glEnable(GL_LIGHTING);
  // glEnable(GL_LIGHT1);
  // glLightfv(GL_LIGHT1, GL_POSITION, [3.0,5.0, 3.0, 1.0]);
  glFlush();
}

void timer(int) {
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer,0);
  // angle+=0.8*4;
  // if (angle > 360.0) {
  //   angle = angle -360.0;
  // }

  upZ += 1*state;

  if (upZ > 10) {
    state = -1;
  }
  if (upZ < -10) {
    state = 1;
  }
}

// void mouseActions(int button, int state, int x, int y) {
//     GLint curWidth = glutGet(GLUT_WINDOW_WIDTH), curHeight = glutGet(GLUT_WINDOW_HEIGHT);

//     if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP &&
//         x >= curWidth-EXIT_BUTTON_WIDTH && y >= curHeight-EXIT_BUTTON_HEIGHT) {
//         glutDestroyWindow(glutGetWindow());
//     }
// }

void reshape(int w, int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,WINDOW_WIDTH,0.0,WINDOW_HEIGHT);
  glMatrixMode(GL_MODELVIEW);
}

int main(GLint argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA /*| GLUT_DOUBLE*/ | GLUT_DEPTH);

  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition (WINDOW_POS_X, WINDOW_POS_Y);

  glutCreateWindow ("Elephant at the Safari");

  glutDisplayFunc(display);
  //glutReshapeFunc(reshape);
  glutTimerFunc(0,timer,0);
  init();
  //glutMouseFunc(mouseActions);

  glutMainLoop();

  return 0;
} 