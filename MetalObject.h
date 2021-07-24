#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"

class MetalObject {
    public:
        MetalObject(GLfloat x, GLfloat y, GLfloat z);
        void draw();
        GLfloat x; // center x coordinate
        GLfloat y; // center y coordinate
        GLfloat z; // center z coordinate
    private:
        void setMaterialLight();
};