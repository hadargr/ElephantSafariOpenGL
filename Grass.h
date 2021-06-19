#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"

class Grass {
    public:
        Grass(GLfloat xMin, GLfloat xMax, GLfloat zMin, GLfloat zMax);
        void draw();
        void move(GLfloat xMove, GLfloat zMove);
        GLfloat xMin; // grass surface left x coordinate
        GLfloat xMax; // grass surface right x coordinate
        GLfloat zMin; // grass surface top y coordinate
        GLfloat zMax; // grass surface bottom y coordinate
    private:
        unsigned int texture; // the allocated texture id
};