#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define WINDOW_WIDTH 550.0
#define WINDOW_HEIGHT 550.0
#define EXIT_BUTTON_WIDTH 100.0
#define EXIT_BUTTON_HEIGHT 30.0

void init (void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,WINDOW_WIDTH,0.0,WINDOW_HEIGHT);
}

void drawEiffelLegs(GLint count, GLfloat width, GLfloat height, GLfloat diff, GLfloat* pX1, GLfloat* pX2, GLfloat* pY) {
  GLfloat x1 = *pX1, x2 = *pX2, y = *pY;
  for(GLint i = 0; i < count; i++) {
    glBegin(GL_LINE_LOOP);
      glVertex2f(x1, y);
      glVertex2f(x1 + width, y);
      glVertex2f(x1 + width + diff, y + height);
      glVertex2f(x1 + diff, y + height);
      glVertex2f(x1, y);
      glVertex2f(x1 + width + diff, y + height);
      glVertex2f(x1 + width, y);
      glVertex2f(x1 + diff, y + height);
    glEnd();
    glBegin(GL_LINE_LOOP);
      glVertex2f(x2, y);
      glVertex2f(x2 - width, y);
      glVertex2f(x2 - width - diff, y + height);
      glVertex2f(x2 - diff, y + height);
      glVertex2f(x2, y);
      glVertex2f(x2 - width - diff, y + height);
      glVertex2f(x2 - width, y);
      glVertex2f(x2 - diff, y + height);
    glEnd();
    x1+=diff;
    y+=height;
    x2-=diff;
  }
  *pX1 = x1;
  *pX2 = x2;
  *pY = y;
}

void upperPartEiffel(GLint x, GLint y) {
  GLfloat lowerW = 70, upperW = lowerW*0.80, height = 30, diff;
  while (upperW > 10) {
    diff = (lowerW-upperW)/2;
    glBegin(GL_LINE_LOOP);
      glVertex2f(x, y);
      glVertex2f(x + lowerW, y);
      glVertex2f(x + upperW + diff, y + height);
      glVertex2f(x + diff, y + height);
      glVertex2f(x, y);
      glVertex2f(x + upperW + diff, y + height);
      glVertex2f(x + lowerW, y);
      glVertex2f(x + diff, y + height);
    glEnd();
    x+=diff;
    y+=height;
    lowerW *= 0.80;
    upperW *= 0.80;
    height *= 0.95;
  }

  glBegin(GL_LINE_LOOP);
    glVertex2f(x - 4, y);
    glVertex2f(x - 4, y + (height/2));
    glVertex2f(x + lowerW + 4, y + (height/2));
    glVertex2f(x + lowerW + 4, y);
  glEnd();
  y+=height/2;
  glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x, y + (height/2));
    glVertex2f(x + lowerW, y + (height/2));
    glVertex2f(x + lowerW, y);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(x + (lowerW/2), y+ (height/2));
    glVertex2f(x + (lowerW/2), 500);
  glEnd();

}

void lowerBridge(GLint x1,GLint x2, GLint y, GLint height, GLint width, GLint diff) {
  GLfloat x = x1 + (diff/2), xLimit = x2 - diff, borderLeftX = x1 - 2,
    borderRightX = x2 + 2, squaresX = x1 + 4, squaresLimitX = x2;

  glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y);
    glVertex2f(x2, y);
    glVertex2f(x2 - (diff/2), y + height);
    glVertex2f(x1 + (diff/2), y + height);
  glEnd();
  glLineWidth(3);
  while (x < xLimit) {
    glBegin(GL_LINE_LOOP);
      glVertex2f(x, y);
      glVertex2f(x + width/2, y + height);
      glVertex2f(x + width, y);
    glEnd();
    x+=width;
  }
  glBegin(GL_LINE_LOOP);
    glVertex2f(borderLeftX, y + height);
    glVertex2f(borderLeftX, y + height + height*1.5);
    glVertex2f(borderRightX, y + height + height*1.5);
    glVertex2f(borderRightX, y + height);
  glEnd();
  width/=3;
  y+=height*2.5;
  GLfloat beginX = squaresX;
  while (squaresX + width < squaresLimitX) {
    glBegin(GL_LINE_LOOP);
      glVertex2f(squaresX, y);
      glVertex2f(squaresX, y + height*2);
      glVertex2f(squaresX + width, y + height*2);
      glVertex2f(squaresX + width, y);
    glEnd();
    squaresX+=width;
  }
  glLineWidth(5);
  glBegin(GL_LINES);
    glVertex2f(beginX - 2, y + height*2);
    glVertex2f(squaresX + 4, y + height*2);
  glEnd();
}

void upperBridge(GLint eSquareLeftX, GLint eSquareRightX, GLint height, GLint width,
  GLint squaresX, GLint squaresLimitX, GLint y) {
  glLineWidth(3);
  glBegin(GL_LINE_LOOP);
    glVertex2f(eSquareLeftX, y);
    glVertex2f(eSquareLeftX, y + height);
    glVertex2f(eSquareRightX, y + height);
    glVertex2f(eSquareRightX, y);
  glEnd();
  while (squaresX + width < squaresLimitX) {
    glBegin(GL_LINE_LOOP);
      glVertex2f(squaresX, y + height);
      glVertex2f(squaresX, y + height + height*1.5);
      glVertex2f(squaresX + width, y + height + height*1.5);
      glVertex2f(squaresX + width, y + height);
    glEnd();
    squaresX+=width;
  }
  glRectf(eSquareLeftX, y + height*2.5, eSquareRightX, y + height*3.5);
}

void eiffelTower(void) {
  GLfloat width=50, height=30, diff=15, heightS=10;
  GLfloat x1=110, y=10, x2=390;
  glColor3f(0.1,0.1,0.1);
  glLineWidth(5);
  drawEiffelLegs(3, width, height, diff, &x1, &x2, &y);
  lowerBridge(x1, x2, y, heightS, 30, diff);
  x1+=diff*1.5;
  y+=height*1.5;
  x2-=diff*1.5;
  width = 40;
  height = 20;
  diff = 10;
  drawEiffelLegs(2, width, height, diff, &x1, &x2, &y);
  glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y);
    glVertex2f(x1 + width, y);
    glVertex2f(x1 + width + diff, y + height);
    glVertex2f(x1 + diff, y + height);
    glEnd();
  glBegin(GL_LINE_LOOP);
    glVertex2f(x2, y);
    glVertex2f(x2 - width, y);
    glVertex2f(x2 - width - diff, y + height);
    glVertex2f(x2 - diff, y + height);
  glEnd();
  x1+=diff;
  y+=height;
  x2-=diff;
  upperBridge(x1 - 3, x2 + 3, heightS, 5, x1 + 2, x2, y);
  glLineWidth(5);
  upperPartEiffel(x1+7, y + heightS*3.5);
}

void grass(void) {
  GLfloat greens[3][3] = {{0.0, 0.4, 0.2}, {0.0, 0.6, 0.3}, {0.0, 0.5, 0.0}};
  GLint color, addition = 0;
  glLineWidth(1.5);
  for (GLint j = 0; j < WINDOW_HEIGHT/10; j+=10) {
    for (GLint i = 0; i < WINDOW_WIDTH; i++) {
      color = rand() % 3;
      glColor3f (greens[color][0], greens[color][1], greens[color][2]);
      glBegin (GL_LINES);
        glVertex2i (i, j);
        glVertex2i (i, j + 10 + addition);    
      glEnd();
      if (j + 10 >= WINDOW_HEIGHT/10) {
        addition = i % 4 ? 0 : 3;
      }
    }
  }
 }

void nameAndTitle(string name, string title) {
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
}

void exitButton(void) {
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
}

void drawEiffelTowerScene(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  grass();
  eiffelTower();
  nameAndTitle("Hadar Grossman", "Eiffel Tower Scene");
  exitButton();
  glFlush();
}

void mouseActions(int button, int state, int x, int y) {
    GLint curWidth = glutGet(GLUT_WINDOW_WIDTH), curHeight = glutGet(GLUT_WINDOW_HEIGHT);

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP &&
        x >= curWidth-EXIT_BUTTON_WIDTH && y >= curHeight-EXIT_BUTTON_HEIGHT) {
        glutDestroyWindow(glutGetWindow());
    }
}

GLint main(GLint argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition (50, 100);
  glutCreateWindow ("Eiffel Tower");
  init();
  glutDisplayFunc(drawEiffelTowerScene);
  glutMouseFunc(mouseActions);
  glutMainLoop();
  return 0;
} 