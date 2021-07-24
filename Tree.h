#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"

class Tree {
    public:
        Tree(GLfloat x, GLfloat y, GLfloat z);
        void draw();
        GLfloat x; // center x coordinate
        GLfloat y; // center y coordinate
        GLfloat z; // center z coordinate
    private:
        void setTrunkMaterialLight();
        void setTopMaterialLight();
        unsigned int trunkTexture; // the allocated texture id
        GLUquadric* trunkTexQuad;
        unsigned int topTexture; // the allocated texture id
        GLUquadric* topTexQuad;
};