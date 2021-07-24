#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"
#include "MainWindow.h"

class Menu {
    public:
        Menu(MainWindow* mainWind);
    private:
        void createMenu();
        int menuId;
        int currentValue;
};