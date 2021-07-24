#define GL_SILENCE_DEPRECATION
#include "MetalObject.h"

MetalObject::MetalObject(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void MetalObject::draw() {
  glPushMatrix();
  setMaterialLight();
  glTranslatef(x, y, z);
  glutSolidTeapot(2);
  glPopMatrix();
}

void MetalObject::setMaterialLight() {
  GLfloat mat_ambient[] ={0.25f, 0.25f, 0.25f, 1.0f  };
  GLfloat mat_diffuse[] ={0.4f, 0.4f, 0.4f, 0.5f };
  GLfloat mat_specular[] ={0.9f, 0.9f, 0.9f, 1.0f };
  GLfloat shine = 80.0f;
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialf(GL_FRONT, GL_SHININESS, shine);
}