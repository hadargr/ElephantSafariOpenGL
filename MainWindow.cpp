#define GL_SILENCE_DEPRECATION
#include "MainWindow.h"

#define CAMERA_DISTANCE_FROM_ELEPHANT 30
#define ESC_KEY 27

MainWindow::MainWindow(int windowId) {
  this->windowId = windowId;
  grass = new Grass(0.0, 0.0, 0.0);
  elephant = new Elephant(0.0, 0.0);
  light0 = new Light(0.0, 30.0, 0.0, GL_LIGHT0);
  metalObj = new MetalObject(10.0, 3.0, 0.0);
  sky = new Sky();
  helpMenu = new Help(0,0,0);
  chosenAction = WALK;
  double posX, posZ;
  for (int i=0; i< NUM_TREES; i++) {
    posX = fRand(-Z_FAR, Z_FAR);
    posZ = fRand(-Z_FAR, Z_FAR);
    if(abs(posX) < 10 && abs(posZ) < 10) {
      posX +=10;
      posZ += 10;
    }
    trees[i] = new Tree(posX,5.0,posZ);
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

void MainWindow::popOrtho() {
  glutSetWindow(windowId);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  orthoMode = false;
}

void MainWindow::keyboardPressed(unsigned char key) {
  if (helpMenu->isOpen) {
    if (key == ESC_KEY) {
      helpMenu->isOpen = false;
      popOrtho();
    }
    redisplay();
    return;
  }

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
  cameraDeltaY = 0;
  elephant->x = 0.0;
  elephant->z = 0.0;
  elephant->angle = 0.0;
}

void MainWindow::toggleElephantView() {
  elephantViewOn = !elephantViewOn;
}

void MainWindow::openHelpMenu() {
  helpMenu->isOpen = true;
}

void MainWindow::pushOrtho() {
  orthoMode = true;
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_LIGHTING);
  glClearColor(1,1,1,1);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, HELP_MENU_WIDTH, HELP_MENU_HEIGHT, 0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glDisable(GL_DEPTH_TEST);
}

void MainWindow::draw() {
  if(helpMenu->isOpen) {
    if (!orthoMode) {
      pushOrtho();
    }
    helpMenu->draw();

    return;
  }
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