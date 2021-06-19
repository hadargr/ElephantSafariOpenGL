#define GL_SILENCE_DEPRECATION
#include "Grass.h"

Grass::Grass(GLfloat xMin, GLfloat xMax, GLfloat zMin, GLfloat zMax) {
	this->xMax = xMax;
	this->xMin = xMin;
	this->zMax = zMax;
	this->zMin = zMin;
  this->texture = generateTexture("./textures/grass.jpeg", GL_TEXTURE_2D);
}

void Grass::draw() {
  // glEnable(GL_TEXTURE_2D);
  // glDisable(GL_LIGHTING);
  // glBindTexture(GL_TEXTURE_2D, texture);
  // //glColor3f(1, 1, 1);
  // glBegin(GL_QUADS);
  // glTexCoord2f(0.0f, 0.0f);
  // glVertex3f(xMin, 0, zMin);
  // glTexCoord2f(15.0f, 0.0f);
  // glVertex3f(xMin, 0, zMax);
  // glTexCoord2f(15.0f, 15.0f);
  // glVertex3f(xMax, 0, zMax);
  // glTexCoord2f(0.0f, 15.0f);
  // glVertex3f(xMax, 0, zMin);
  // glEnd();
  // glBindTexture(GL_TEXTURE_2D, 0);
  // glDisable( GL_TEXTURE_2D );
  // glEnable(GL_LIGHTING);



  // glEnable(GL_TEXTURE_2D);
  // glBindTexture(GL_TEXTURE_2D, texture);
  // glPushMatrix();
  // glScalef(1,0.01,1);
  // glutSolidCube(100);
  // glPopMatrix();
  // glBindTexture(GL_TEXTURE_2D, 0);
  // glDisable( GL_TEXTURE_2D );

  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  GLUquadric* texQuad = gluNewQuadric();
  gluQuadricDrawStyle(texQuad, GLU_FILL);
  glBindTexture(GL_TEXTURE_2D, texture);
  gluQuadricTexture(texQuad, GL_TRUE);
  gluQuadricNormals(texQuad, GLU_SMOOTH);

  glMatrixMode (GL_TEXTURE);
  glLoadIdentity ();
  glScalef(4, 2, 1);
  glPopMatrix();

  glPushMatrix();
  glMatrixMode (GL_MODELVIEW);
  glRotatef(90,1,0,0);
  glTranslatef(0.0, -2.0, 0.0);
  //glScalef(1,0.1,1);
  gluCylinder(texQuad,50,50,1,20,20);
  glPopMatrix();

}

void move(GLfloat xMove, GLfloat zMove) {
    
}