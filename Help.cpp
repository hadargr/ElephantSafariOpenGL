#define GL_SILENCE_DEPRECATION
#include "Help.h"

#define START_POS_TEXT_X 10
#define START_POS_TEXT_Y 25
#define TEXT_HEIGHT 6
#define TAB 5
#define DOT_DEV 2

Help::Help(GLfloat x, GLfloat y, GLfloat z) {
  isOpen = false;
  this-> x = x;
  this->y = y;
  this->z = z;
}

void drawDot(double posX, double posY) {
  glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2f(posX, posY - DOT_DEV);
  glEnd();
}

void Help::draw() {
  string text = "Help";
  int i = 1;
  drawText("Help", START_POS_TEXT_X, START_POS_TEXT_Y, 0,0.3,1);
  drawText("Open the menu:", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0.54,0,0.54);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("You can see the menu by clicking the right mouse button.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Quit:", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0.54,0,0.54);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Select `Quit` in the menu to quit and close the window.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Ambient light:", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0.54,0,0.54);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("You can see the current ambient light parameters for Red, Green and Blue at the left bottom part of the window.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the menu to Increase/Decrease Ambient light - select `Adjust Ambient Light`, then you can either", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Increase/Decrease the ambient parameter for all the colors, or go to `Red` or `Green` or `Blue` to change a", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("specific parameter.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Camera Position:", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0.54,0,0.54);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("You can move the camera in each one of the axes using the menu – select `Adjust Camera position`, then", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("`X` or `Y` or `Z`.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the menu to toggle elephant view on and off – select `Adjust Camera position`,", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("then `Toggle elephant view`", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Select `Reset View` in the menu to put the elephant in its initial position.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Elephant Data:", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0.54,0,0.54);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("At the bottom middle part of the window you can see the current Elephant data.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("The Y axis angle is the elephant current angle in relation to Y.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("The X and Z are the elephant position.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("You can see the Head vertical and horizontal angles.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("You can see the Tail vertical and horizontal angles.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Control panel actions:", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0.54,0,0.54);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("At the right lower part of the window, you can see 3 moving options.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("The selected option is the one with the red border.", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("When `walk` is selected:", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the upper arrow key to make the elephant walk.", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the right arrow to make the elephant turn right.", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the left arrow to make the elephant turn left.", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("When `Move Head` is selected:", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the upper and lower arrow keys to move the elephant’s head up and down.", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the right and left arrow keys to move the elephant’s head right and left..", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("When `Move Tail` is selected:", START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the upper and lower arrow keys to move the elephant’s tail up and down.", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawDot(START_POS_TEXT_X + TAB, START_POS_TEXT_Y + TEXT_HEIGHT*i);
  drawText("Use the right and left arrow keys to move the elephant’s tail right and left..", START_POS_TEXT_X + TAB*2, START_POS_TEXT_Y + TEXT_HEIGHT*(i++), 0,0,0);
  drawText("Press `Esc` to quit the help menu", START_POS_TEXT_X, START_POS_TEXT_Y + TEXT_HEIGHT*i, 0.54,0,0.54);
}