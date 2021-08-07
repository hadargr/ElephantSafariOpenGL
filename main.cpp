#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Grass.h"
#include "Elephant.h"
#include "Light.h"
#include "MetalObject.h"
#include "Menu.h"
#include "Sky.h"
#include "ControlPanel.h"
#include "MainWindow.h"

using namespace std;

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

ControlPanel* cPanel;
MainWindow* mainWind;;
Menu* mainMenu;

int window, subWindow;

void init (void) {
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  gluPerspective(60, 1, Z_NEAR, Z_FAR);
  glMatrixMode(GL_MODELVIEW);
  mainWind = new MainWindow(window);
  mainMenu = new Menu(mainWind);
}

void initSubWindow(void) {
  glViewport(0, 0, WINDOW_WIDTH, CONTROL_PANEL_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, WINDOW_WIDTH, 0, CONTROL_PANEL_HEIGHT);
  glMatrixMode(GL_MODELVIEW);
  cPanel = new ControlPanel(subWindow, mainWind);
  mainWind->setControlPanelId(subWindow);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (!mainWind->helpMenu->isOpen) {
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glLoadIdentity();
  }
  mainWind->draw();
  glFlush();
}

void displaySubWin(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.8, 0.8, 0.8, 1.0);
  cPanel->draw();
  glFlush();
}

void timer(int) {
  mainWind->redisplay();
 // glutTimerFunc(1000/60, timer,0);
}

void mouseActions(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP
        /*x >= curWidth-EXIT_BUTTON_WIDTH && y >= curHeight-EXIT_BUTTON_HEIGHT*/) {
        cPanel->mouseClicked(x,y);
    }
  glutPostWindowRedisplay(subWindow);
}

void reshape(int w, int h) {
  glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void onKeboardPressed (unsigned char key, int xmouse, int ymouse) {
  mainWind->keyboardPressed(key);
}

void onSpecialKeboardPressed (int key, int xmouse, int ymouse) {
  mainWind->keyboardPressed(key);
}

int main(GLint argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA /*| GLUT_DOUBLE*/ | GLUT_DEPTH);

  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition (WINDOW_POS_X, WINDOW_POS_Y);

  window = glutCreateWindow ("Elephant at the Safari");
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(onKeboardPressed);
  glutSpecialUpFunc(onSpecialKeboardPressed);
  glutTimerFunc(100,timer,0);
  init();
  subWindow = glutCreateSubWindow(window, 0,3*CONTROL_PANEL_HEIGHT,WINDOW_WIDTH, CONTROL_PANEL_HEIGHT);
  initSubWindow();
  glutDisplayFunc(displaySubWin);
  glutMouseFunc(mouseActions);
  glutSpecialUpFunc(onSpecialKeboardPressed);

  glutMainLoop();

  return 0;
} 