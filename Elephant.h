#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"
#include <cmath>
#define ELEPHANT_HEIGHT 5.0

class Elephant {
    public:
        Elephant(GLfloat x, GLfloat z);
        void draw();
        void turn(bool positiveDir);
        void walk();
        void moveHead(unsigned char key);
        void moveTail(unsigned char key);
        GLfloat x; // the elephant x position
        GLfloat z; // the elephant z position
        GLfloat angle;
        GLfloat head_angle_vertical;
        GLfloat head_angle_horizontal;
        GLfloat tail_angle_vertical;
        GLfloat tail_angle_horizontal;
    private:
        unsigned int texture; // the allocated texture id
        GLUquadric* texQuad;
        void drawFace();
        void drawEars();
        void drawBody();
        void drawLegs();
        void drawTail();
        void drawTrunk();
        void drawTusks();
        void drawEyes();
        void setMaterialLight();
};