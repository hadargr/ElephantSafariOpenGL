#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"
#include "MainWindow.h"

class ControlPanel {
    public:
        ControlPanel(int windowId, MainWindow* mainWindow);
        void draw();
        void redisplay();
        void mouseClicked(int x, int y);
    private:
        void drawAmbientLightSection(GLfloat x);
        void drawElephantDataSection(GLfloat x);
        void drawControlSection(GLfloat x);
        void drawButton(GLfloat x, GLfloat y, bool isSelected, string text);
        int windowId;
        MainWindow* mainWindow;
};