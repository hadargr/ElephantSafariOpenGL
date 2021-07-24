#define GL_SILENCE_DEPRECATION
#include "Grass.h"

Grass::Grass(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
  this->texture = generateTexture("./textures/grass.jpeg", GL_TEXTURE_2D);
  this->texQuad = gluNewQuadric();
}

void Grass::setMaterialLight() {
  GLfloat mat_ambient[] ={ 0.115f, 0.5745f, 0.115f, 1.0f };
  GLfloat mat_diffuse[] ={0.07568f, 0.61424f, 0.07568f, 1.0f };
  GLfloat mat_specular[] ={0.633f, 0.727811f, 0.633f, 1.0f };
  GLfloat shine = 10.8f;
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialf(GL_FRONT, GL_SHININESS, shine);
}

void Grass::draw() {

  glEnable(GL_TEXTURE_2D);
  
  gluQuadricDrawStyle(texQuad, GLU_FILL);
  glBindTexture(GL_TEXTURE_2D, texture);
  gluQuadricTexture(texQuad, GL_TRUE);
  gluQuadricNormals(texQuad, GLU_SMOOTH);

  glPushMatrix();
  setMaterialLight();
  glMatrixMode(GL_TEXTURE);
  glScalef(8,8,1);
  glMatrixMode (GL_MODELVIEW);
  glRotatef(90,1,0,0);
  glTranslatef(x,y,z);
  gluDisk(texQuad, 0.0, 500.0, 1000, 1000);

  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable( GL_TEXTURE_2D );
  glPopMatrix();
}