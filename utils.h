#include "./stb_image/stb_image.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

unsigned int generateTexture(const char *filename, GLenum targe); // loads a texture from filename