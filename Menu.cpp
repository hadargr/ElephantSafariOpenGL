#define GL_SILENCE_DEPRECATION
#include "Menu.h"
MainWindow* mainWindow;

Menu::Menu(MainWindow* mainWind) {
  mainWindow = mainWind;
  createMenu();
}

void menuCallback(int value) {
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
    case (RESET_VIEW):
      mainWindow->resetView();
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

  // Second submenu
  int sub2 = glutCreateMenu(menuCallback);

  glutAddMenuEntry("Option 3", 100);
	glutAddMenuEntry("Option 4", 200);

  menuId = glutCreateMenu(menuCallback);
  glutAddSubMenu("Adjust Ambient Light", adjustAmbient);
  glutAddSubMenu("Sub2", sub2);
  glutAddMenuEntry("Reset view", RESET_VIEW);
  glutAddMenuEntry("Quit", QUIT);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
