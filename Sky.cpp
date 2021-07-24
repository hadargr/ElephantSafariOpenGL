#define GL_SILENCE_DEPRECATION
#include "Sky.h"

Sky::Sky() {
}

void setMaterialLight() {
  GLfloat mat_ambient[] ={0.0f, 0.5f, 1.0f, 1.0f  };
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
}

void Sky::draw() {
  glPushMatrix();
  setMaterialLight();
  glTranslatef(0, 0, 0);
  glutSolidSphere(300,100,100);
  glPopMatrix();
}
