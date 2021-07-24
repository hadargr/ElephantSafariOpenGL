#define GL_SILENCE_DEPRECATION
#include "ControlPanel.h"

#define BUTTON_WIDTH 170
#define BUTTON_HEIGHT 30
#define TEXT_HEIGHT 20
#define ROW_HEIGHT 30
#define AMBIENT_LIGHT_SECTION_X 10
#define ELEPHANT_DATA_SECTION_X 350
#define CONTROL_SECTION_X 650
#define WALK_BUTTON_Y BUTTON_HEIGHT*2
#define MOVE_HEAD_BUTTON_Y BUTTON_HEIGHT*3.5
#define MOVE_TAIL_BUTTON_Y BUTTON_HEIGHT*5

ControlPanel::ControlPanel(int windowId, MainWindow* mainWindow) {
  this->windowId = windowId;
  this->mainWindow = mainWindow;
}

void ControlPanel::redisplay() {
  mainWindow->redisplay();
}

void ControlPanel::drawText(string text, int scale, double posX, double posY, double red, double green, double blue) {
  glPushMatrix();
  glTranslatef(posX, posY, 1);
  glColor3f(red, green, blue);
  glScalef(0.12,0.12,1);
  // switch(scale) {
  //   case(1) :
  //     glScalef(0.13,0.52,1);
  //     break;
  //   default:
  //     break;
  // }
  
  for (int i=0; i < text.length(); i++) {
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)text[i]);
  }
  glPopMatrix();
}

void ControlPanel::drawAmbientLightSection(GLfloat x) {
  GLfloat initialY = CONTROL_PANEL_HEIGHT - TEXT_HEIGHT;
  Light* ambientLight = mainWindow->light0;
  string text = "Current Ambient light";
  drawText(text, 1, x, initialY, 0,0,0);
  GLfloat* ambient = ambientLight->getAmbient();
  drawText(to_string(ambient[0]).substr(0,4), 1, x, initialY - ROW_HEIGHT, 1,0,0);
  drawText(to_string(ambient[1]).substr(0,4), 1, x, initialY - ROW_HEIGHT*2, 0,1,0);
  drawText(to_string(ambient[2]).substr(0,4), 1, x, initialY - ROW_HEIGHT*3, 0,0,1);
}

void ControlPanel::drawElephantDataSection(GLfloat x) {
  GLfloat initialY = CONTROL_PANEL_HEIGHT - TEXT_HEIGHT;
  Elephant* elephant = mainWindow->elephant;
  string text = "Elephant Data";
  drawText(text, 1, x, initialY, 0,0,0);
  drawText("Y axis Angle: " + to_string(elephant->angle).substr(0,4), 1, x, initialY - ROW_HEIGHT, 0,0,0);
  drawText("X: " + to_string(elephant->x).substr(0,5), 1, x, initialY - ROW_HEIGHT*2, 0,0,0);
  drawText("Z: " + to_string(elephant->z).substr(0,5), 1, x, initialY - ROW_HEIGHT*3, 0,0,0);
  drawText("Head Angle: " + to_string(elephant->head_angle).substr(0,4), 1, x, initialY - ROW_HEIGHT*4, 0,0,0);
}

void ControlPanel::drawControlSection(GLfloat x) {
  string text = "Actions (click to change)";
  drawText(text, 1, x, CONTROL_PANEL_HEIGHT- TEXT_HEIGHT, 0,0,0);
  drawButton(x, CONTROL_PANEL_HEIGHT - WALK_BUTTON_Y, mainWindow->chosenAction == WALK, "Walk");
  drawButton(x, CONTROL_PANEL_HEIGHT - MOVE_HEAD_BUTTON_Y, mainWindow->chosenAction == MOVE_HEAD, "Move Head");
  drawButton(x, CONTROL_PANEL_HEIGHT - MOVE_TAIL_BUTTON_Y, mainWindow->chosenAction == MOVE_TAIL, "Move Tail"); 
}

void ControlPanel::mouseClicked(int x, int y) {
  data = "x:" + to_string(x) + ", y:" + to_string(y) + ", walk: " + to_string(CONTROL_SECTION_X) + ", " + to_string(WALK_BUTTON_Y); 
  if (x >= CONTROL_SECTION_X && x <= CONTROL_SECTION_X + BUTTON_WIDTH) {
    if (y > TEXT_HEIGHT && y<= WALK_BUTTON_Y) {
      mainWindow->chosenAction = mainWindow->chosenAction == WALK ? NONE : WALK;
    } else if (y > WALK_BUTTON_Y && y<= MOVE_HEAD_BUTTON_Y) {
      mainWindow->chosenAction = mainWindow->chosenAction == MOVE_HEAD ? NONE : MOVE_HEAD;
    } else if (y > MOVE_HEAD_BUTTON_Y && y<= MOVE_TAIL_BUTTON_Y) {
      mainWindow->chosenAction = mainWindow->chosenAction == MOVE_TAIL ? NONE : MOVE_TAIL;
    }
  }
}

void ControlPanel::drawButton(GLfloat x, GLfloat y, bool isSelected, string text) {
  glColor3f(0,0,0);
  if (isSelected) {
    glColor3f(1,0,0);
  }

  glBegin(GL_LINE_LOOP);
  glVertex3f (x, y, 0.0);
  glVertex3f (x + BUTTON_WIDTH,  y , 0.0);
  glVertex3f (x + BUTTON_WIDTH,y + BUTTON_HEIGHT, 0.0);
  glVertex3f (x ,y + BUTTON_HEIGHT, 0.0);
  glEnd();
  drawText(text, 1, x+ BUTTON_WIDTH/4, y +BUTTON_HEIGHT/4, 0,0,0);
}

void ControlPanel::draw() {
  drawAmbientLightSection(AMBIENT_LIGHT_SECTION_X);
  drawElephantDataSection(ELEPHANT_DATA_SECTION_X);
  drawControlSection(CONTROL_SECTION_X);
  //drawData(); // TODO - REMOVE
}

void ControlPanel::drawData() {
  drawText(data, 1, 300, 80, 0,0,0);
}