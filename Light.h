#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"

class Light {
    public:
        Light(GLfloat x, GLfloat y, GLfloat z, GLenum lightId);
        void draw();
        GLfloat* getAmbient();
        void setAmbientRed(bool increase);
        void setAmbientGreen(bool increase);
        void setAmbientBlue(bool increase);
        void setAmbient(bool increase);
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat diffuse[4] = { 0.7, 0.7, 0.7, 1.0 };
        GLfloat specular[4] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat ambient[4] = { 0.3, 0.3, 0.3, 1.0 };
        GLenum lightId;
};