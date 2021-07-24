#define GL_SILENCE_DEPRECATION
#include "Tree.h"

Tree::Tree(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
  this->trunkTexture = generateTexture("./textures/tree.jpeg", GL_TEXTURE_2D);
  this->trunkTexQuad = gluNewQuadric();
  this->topTexture = generateTexture("./textures/leafs.jpeg", GL_TEXTURE_2D);
  this->topTexQuad = gluNewQuadric();
}

void Tree::draw() {
  glPushMatrix();
  glTranslatef(x, y, z);
  glEnable(GL_TEXTURE_2D);
  gluQuadricDrawStyle(trunkTexQuad, GLU_FILL);
  glBindTexture(GL_TEXTURE_2D, trunkTexture);
  gluQuadricTexture(trunkTexQuad, GL_TRUE);
  gluQuadricNormals(trunkTexQuad, GLU_SMOOTH);
  
  glPushMatrix();
  setTrunkMaterialLight();
  glRotatef(90,1,0,0);
  gluCylinder(trunkTexQuad,1,1.5,5,100,100);
  glPopMatrix();

  gluQuadricDrawStyle(topTexQuad, GLU_FILL);
  glBindTexture(GL_TEXTURE_2D, topTexture);
  gluQuadricTexture(topTexQuad, GL_TRUE);
  gluQuadricNormals(topTexQuad, GLU_SMOOTH);

  glPushMatrix();
  setTopMaterialLight();
  glTranslatef(0.0, 2.8, 0.0);
  gluSphere(topTexQuad,3,100,100);
  glPopMatrix();

  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable( GL_TEXTURE_2D );
  glPopMatrix();
}

void Tree::setTrunkMaterialLight() {
  GLfloat mat_ambient[] ={ 0.545f, 0.27f, 0.074f, 1.0f };
  GLfloat shine = 10.8f;
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialf(GL_FRONT, GL_SHININESS, shine);
}

void Tree::setTopMaterialLight() {
  GLfloat mat_ambient[] ={ 0.486f, 0.988f, 0.0f, 1.0f };
  GLfloat mat_diffuse[] ={0.007568f, 0.061424f, 0.007568f, 0.5f };
  GLfloat mat_specular[] ={0.0633f, 0.0727811f, 0.0633f, 0.5f };
  GLfloat shine = 10.8f;
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialf(GL_FRONT, GL_SHININESS, shine);
}