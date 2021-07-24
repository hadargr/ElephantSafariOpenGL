#define GL_SILENCE_DEPRECATION
#include "MainWindow.h"

#define CAMERA_DISTANCE_FROM_ELEPHANT 30

MainWindow::MainWindow(int windowId) {
  this->windowId = windowId;
  grass = new Grass(0.0, 0.0, 0.0);
  elephant = new Elephant(0.0, 0.0);
  light0 = new Light(0.0, 30.0, 0.0, GL_LIGHT0);
  metalObj = new MetalObject(10.0, 3.0, 2.0);
  sky = new Sky();
  chosenAction = WALK;
}

void MainWindow::redisplay() {
  glutPostWindowRedisplay(windowId);
  glutPostWindowRedisplay(controlPanelId);
}

void MainWindow::destroy() {
  glutDestroyWindow(windowId);
}

void MainWindow::setControlPanelId(int controlPanelId) {
  this->controlPanelId = controlPanelId;
}

void MainWindow::keyboardPressed(unsigned char key) {

  // Handle walking
  switch (key)
  {
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
      if (chosenAction == WALK) {
        elephant->turn(key == GLUT_KEY_LEFT);
      } else if (chosenAction == MOVE_HEAD) {
        elephant->moveHead(key);
      }
      break;
    case GLUT_KEY_UP:
      if (chosenAction == WALK) {
        elephant->walk();
        moveCamera();
      } else if (chosenAction == MOVE_HEAD) {
        elephant->moveHead(key);
      }
      break;
    case GLUT_KEY_DOWN:
      if (chosenAction == MOVE_HEAD) {
        elephant->moveHead(key);
      }
      break;
    default:
      break;
  }

  redisplay();
}

void MainWindow::moveCamera() {
  cameraXPos = elephant->x;
  cameraZPos = elephant->z + CAMERA_DISTANCE_FROM_ELEPHANT;
}

void MainWindow::resetView() {
  cameraXPos = CAMERA_INITIAL_POS_X;
  cameraZPos = CAMERA_INITIAL_POS_Z;
  elephant->x = 0.0;
  elephant->z = 0.0;
  elephant->angle = 0.0;
}

void MainWindow::draw() {
  gluLookAt(cameraXPos, CAMERA_INITIAL_POS_Y, cameraZPos,elephant->x,0,elephant->z,0,1,0);
  light0->draw();
  grass->draw();
  elephant->draw();
  metalObj->draw();
  sky->draw();
}