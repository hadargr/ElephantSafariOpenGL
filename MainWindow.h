#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"
#include "Grass.h"
#include "Elephant.h"
#include "Light.h"
#include "MetalObject.h"
#include "Sky.h"
#include "constants.h"

class MainWindow {
    public:
        MainWindow(int windowId);
        void draw();
        void setChosenAction(Action chosenAction);
        void setControlPanelId(int controlPanelId);
        void redisplay();
        void destroy();
        void keyboardPressed(unsigned char key);
        void resetView();
        void changeCameraDeltaX(bool increase);
        void changeCameraDeltaY(bool increase);
        void changeCameraDeltaZ(bool increase);
        void toggleElephantView();
        Grass* grass;
        Elephant* elephant;
        Light* light0;
        MetalObject* metalObj;
        Sky* sky;
        Action chosenAction;
        bool elephantViewOn = false;
    private:
        void moveCamera();
        int windowId;
        int controlPanelId;
        GLfloat cameraXPos = CAMERA_INITIAL_POS_X;
        GLfloat cameraZPos = CAMERA_INITIAL_POS_Z;
        GLfloat cameraDeltaX = 0;
        GLfloat cameraDeltaY = 0;
        GLfloat cameraDeltaZ = 0;
};