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
  double posX = -30.0;
  double posZ = -30.0;
  for (int i=0; i< NUM_TREES; i++) {
    trees[i] = new Tree(posX,5.0,posZ);
    posX += 10;
    posZ += (i%2) ? 5 : -5;
  }
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
      } else if (chosenAction == MOVE_TAIL) {
        elephant->moveTail(key);
      }
      break;
    case GLUT_KEY_UP:
      if (chosenAction == WALK) {
        elephant->walk();
        moveCamera();
      } else if (chosenAction == MOVE_HEAD) {
        elephant->moveHead(key);
      } else if (chosenAction == MOVE_TAIL) {
        elephant->moveTail(key);
      }
      break;
    case GLUT_KEY_DOWN:
      if (chosenAction == MOVE_HEAD) {
        elephant->moveHead(key);
      } else if (chosenAction == MOVE_TAIL) {
        elephant->moveTail(key);
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

void MainWindow::changeCameraDeltaX(bool increase) {
  cameraDeltaX = increase ? cameraDeltaX + 1 : cameraDeltaX - 1;
}

void MainWindow::changeCameraDeltaY(bool increase) {
  cameraDeltaY = increase ? cameraDeltaY + 1 : cameraDeltaY - 1;
}

void MainWindow::changeCameraDeltaZ(bool increase) {
  cameraDeltaZ = increase ? cameraDeltaZ + 1 : cameraDeltaZ - 1;
}

void MainWindow::resetView() {
  cameraXPos = CAMERA_INITIAL_POS_X;
  cameraZPos = CAMERA_INITIAL_POS_Z;
  elephant->x = 0.0;
  elephant->z = 0.0;
  elephant->angle = 0.0;
}

void MainWindow::toggleElephantView() {
  elephantViewOn = !elephantViewOn;
}

void MainWindow::draw() {
  if (elephantViewOn) {
    gluLookAt(elephant->x,
      ELEPHANT_HEIGHT,
      elephant->z,
      elephant->x + (sin(degToRad(elephant->angle))*3) + (sin(degToRad(elephant->head_angle_horizontal))*3),
      ELEPHANT_HEIGHT - (sin(degToRad(elephant->head_angle_vertical))*3),
      elephant->z + (cos(degToRad(elephant->angle))*3),
      0,1,0
    );
  } else {
    gluLookAt(cameraXPos + cameraDeltaX,
      CAMERA_INITIAL_POS_Y + cameraDeltaY,
      cameraZPos + cameraDeltaZ,
      elephant->x,
      0,
      elephant->z,
      0,1,0
    );
  }
  light0->draw();
  grass->draw();
  elephant->draw();
  metalObj->draw();
  sky->draw();
  for(int i=0; i< NUM_TREES; i++) {
    trees[i]->draw();
  }
}