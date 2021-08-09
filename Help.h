#pragma once
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include "utils.h"
#include "constants.h"

class Help {
    public:
        Help();
        void draw();
        bool isOpen;
};