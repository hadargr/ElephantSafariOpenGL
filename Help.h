#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"
#include "constants.h"

class Help {
    public:
        Help(GLfloat x, GLfloat y, GLfloat z);
        void draw();
        bool isOpen;
        GLfloat x;
        GLfloat y;
        GLfloat z;
};