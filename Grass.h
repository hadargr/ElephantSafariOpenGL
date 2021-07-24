#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"

class Grass {
    public:
        Grass(GLfloat x, GLfloat y, GLfloat z);
        void draw();
        GLfloat x; // grass surface center x coordinate
        GLfloat y; // grass surface center y coordinate
        GLfloat z; // grass surface center z coordinate
    private:
        unsigned int texture; // the allocated texture id
        GLUquadric* texQuad;
        void setMaterialLight();
};