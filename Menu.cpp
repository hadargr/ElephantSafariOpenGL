#define GL_SILENCE_DEPRECATION
#include "Menu.h"
MainWindow* mainWindow;

Menu::Menu(MainWindow* mainWind) {
  mainWindow = mainWind;
  createMenu();
}

void menuCallback(int value) {
  if (mainWindow->helpMenu->isOpen) {
    return;
  }
  switch(value) {
    case (INCREASE_AMBIENT):
    case (DECREASE_AMBIENT):
      mainWindow->light0->setAmbient(value == INCREASE_AMBIENT);
      break;
    case (INCREASE_AMBIENT_RED):
    case (DECREASE_AMBIENT_RED):
      mainWindow->light0->setAmbientRed(value == INCREASE_AMBIENT_RED);
      break;
    case (INCREASE_AMBIENT_GREEN):
    case (DECREASE_AMBIENT_GREEN):
      mainWindow->light0->setAmbientGreen(value == INCREASE_AMBIENT_GREEN);
      break;
    case (INCREASE_AMBIENT_BLUE):
    case (DECREASE_AMBIENT_BLUE):
      mainWindow->light0->setAmbientBlue(value == INCREASE_AMBIENT_BLUE);
      break;
    case (INCREASE_CAMERA_X):
    case (DECREASE_CAMERA_X):
      mainWindow->changeCameraDeltaX(value == INCREASE_CAMERA_X);
      break;
    case (INCREASE_CAMERA_Y):
    case (DECREASE_CAMERA_Y):
      mainWindow->changeCameraDeltaY(value == INCREASE_CAMERA_Y);
      break;
    case (INCREASE_CAMERA_Z):
    case (DECREASE_CAMERA_Z):
      mainWindow->changeCameraDeltaZ(value == INCREASE_CAMERA_Z);
      break;
    case (ELEPHANT_VIEW):
      mainWindow->toggleElephantView();
      break;
    case (RESET_VIEW):
      mainWindow->resetView();
      break;
    case (HELP):
      mainWindow->openHelpMenu();
      break;
    case (QUIT):
      mainWindow->destroy();
      exit(0);
      break;
  }

  mainWindow->redisplay();
}


void Menu::createMenu() {
  int adjustAmbientRed = glutCreateMenu(menuCallback);
  glutAddMenuEntry("Increase", INCREASE_AMBIENT_RED);
	glutAddMenuEntry("Decrease", DECREASE_AMBIENT_RED);

  int adjustAmbientGreen = glutCreateMenu(menuCallback);
  glutAddMenuEntry("Increase", INCREASE_AMBIENT_GREEN);
	glutAddMenuEntry("Decrease", DECREASE_AMBIENT_GREEN);

  int adjustAmbientBlue = glutCreateMenu(menuCallback);
  glutAddMenuEntry("Increase", INCREASE_AMBIENT_BLUE);
	glutAddMenuEntry("Decrease", DECREASE_AMBIENT_BLUE);

  int adjustAmbient = glutCreateMenu(menuCallback);

  glutAddMenuEntry("Increase", INCREASE_AMBIENT);
	glutAddMenuEntry("Decrease", DECREASE_AMBIENT);

  glutAddSubMenu("Red", adjustAmbientRed);
  glutAddSubMenu("Green", adjustAmbientGreen);
  glutAddSubMenu("Blue", adjustAmbientBlue);

  int cameraAdjusmentX = glutCreateMenu(menuCallback);
  glutAddMenuEntry("Increase", INCREASE_CAMERA_X);
	glutAddMenuEntry("Decrease", DECREASE_CAMERA_X);

  int cameraAdjusmentY = glutCreateMenu(menuCallback);
  glutAddMenuEntry("Increase", INCREASE_CAMERA_Y);
	glutAddMenuEntry("Decrease", DECREASE_CAMERA_Y);

  int cameraAdjusmentZ = glutCreateMenu(menuCallback);
  glutAddMenuEntry("Increase", INCREASE_CAMERA_Z);
	glutAddMenuEntry("Decrease", DECREASE_CAMERA_Z);

  // Second submenu
  int cameraAdjusment = glutCreateMenu(menuCallback);

  glutAddSubMenu("X", cameraAdjusmentX);
  glutAddSubMenu("Y", cameraAdjusmentY);
  glutAddSubMenu("Z", cameraAdjusmentZ);
	glutAddMenuEntry("Toggle elephant view", ELEPHANT_VIEW);

  menuId = glutCreateMenu(menuCallback);
  glutAddSubMenu("Adjust Ambient Light", adjustAmbient);
  glutAddSubMenu("Adjust Camera position", cameraAdjusment);
  glutAddMenuEntry("Reset view", RESET_VIEW);
  glutAddMenuEntry("Help", HELP);
  glutAddMenuEntry("Quit", QUIT);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
