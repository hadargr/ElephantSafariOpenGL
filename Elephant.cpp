#define GL_SILENCE_DEPRECATION
#include "Elephant.h"

#define ANGLE_DELTA 5
#define WALK_DELTA 1
#define MAX_HEAD_ANGLE 50
#define MIN_HEAD_ANGLE -25

Elephant::Elephant(GLfloat x, GLfloat z) {
    this->x = x;
    this->z = z;
    this->angle = 0;
    this->head_angle = 0;
    this->tail_angle = 0;
    this->texture = generateTexture("./textures/elephant.jpeg", GL_TEXTURE_2D);
    this->texQuad = gluNewQuadric();
}

void Elephant::turn(bool positiveDir) {
    if (positiveDir) {
        angle += ANGLE_DELTA;
    } else {
        angle -= ANGLE_DELTA;
    }
    if (abs(angle) == 360) {
        angle = 0;
    }
}

void Elephant::walk() {
    x += (WALK_DELTA) * sin(degToRad(angle));
    z += (WALK_DELTA) * cos(degToRad(angle));
}

void Elephant::moveHead(unsigned char key) {
switch (key)
  {
    case GLUT_KEY_UP:
        if(head_angle >MIN_HEAD_ANGLE) {
            head_angle -= ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_DOWN:
        if(head_angle < MAX_HEAD_ANGLE) {
            head_angle += ANGLE_DELTA;
        }
      break;
    default:
      break;
  }
}

void Elephant::draw() {
    //glColor3f(0.6, 0.6, 0.6);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    
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
    glTranslatef(x, ELEPHANT_HEIGHT, z);
    glRotatef(angle, 0, 1, 0);
    setMaterialLight();

    drawFace();
    drawEars();
    drawBody();
    drawLegs();
    drawTail();
    drawTrunk();
    drawEyes();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable( GL_TEXTURE_2D );
    drawTusks();

    glPopMatrix();
}

void Elephant::setMaterialLight() {
    GLfloat elephant_color[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat diffuse[4] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat ambient[4] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat specular[4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat shininess = 32.0f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, elephant_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, elephant_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
void Elephant::drawFace() {
    glPushMatrix();
    glRotatef(-20,1,0,0);
    glRotatef(head_angle, 1, 0, 0);
    glScalef(0.7,1,0.7);
    gluSphere(texQuad,2.0,20,20);
    glPopMatrix();
}

void Elephant::drawEars() {
    // left ear
    glPushMatrix();
    glTranslatef(2.5, 0.0, 0.0);
    glRotatef(head_angle, 1, 0, 0);
    glScalef(1,1,0.1);
    gluSphere(texQuad,1.8,20,20);
    glPopMatrix();

    // right ear
    glPushMatrix();
    glTranslatef(-2.5, 0.0, 0.0);
    glRotatef(head_angle, 1, 0, 0);
    glScalef(1,1,0.1);
    gluSphere(texQuad,1.8,20,20);
    glPopMatrix();
}

void Elephant::drawBody() {
    glPushMatrix();
    glTranslatef(0.0, -1.6, -3.8);
    glRotatef(90,1,0,0);
    glScalef(0.5,1,0.5);
    gluSphere(texQuad,3.5,20,20);
    glPopMatrix();
}

void Elephant::drawLegs() {
    // left front leg
    glPushMatrix();
    glTranslatef(0.8, -2.2, -1.5);
    glRotatef(90,1,0,0);
    gluCylinder(texQuad,0.5,0.5,2.8,20,20);
    glPopMatrix();

    // right front leg
    glPushMatrix();
    glTranslatef(-0.8, -2.2, -1.5);
    glRotatef(90,1,0,0);
    gluCylinder(texQuad,0.5,0.5,2.8,20,20);
    glPopMatrix();

    // left back leg
    glPushMatrix();
    glTranslatef(0.8, -2.2, -6.2);
    glRotatef(90,1,0,0);
    gluCylinder(texQuad,0.5,0.5,2.8,20,20);
    glPopMatrix();

    // right back leg
    glPushMatrix();
    glTranslatef(-0.8, -2.2, -6.2);
    glRotatef(90,1,0,0);
    gluCylinder(texQuad,0.5,0.5,2.8,20,20);
    glPopMatrix();
}

void Elephant::drawTail() {
    glPushMatrix();
    glTranslatef(0.0, -2.3, -8.3);
    glRotatef(-45,1,0,0);
    gluCylinder(texQuad,0.1,0.1,1.9,20,20);
    glPopMatrix();
}

void Elephant::drawTrunk() {
    double moveZ = head_angle < 0 ? 0 : head_angle;
    // upper part
    glPushMatrix();
    glTranslatef(0.0, -0.2-sin(degToRad(head_angle)), 1.2-sin(degToRad(moveZ)));
    glRotatef(45,1,0,0);
    gluCylinder(texQuad,0.4,0.4,1.9,20,20);
    glPopMatrix();

    // lower part
    glPushMatrix();
    glTranslatef(0.0, -2.9-sin(degToRad(head_angle)), 1.1-sin(degToRad(moveZ)));
    glRotatef(-35,1,0,0);
    gluCylinder(texQuad,0.2,0.4,2.3,20,20);
    glPopMatrix();
}

void Elephant::drawTusks() {
    glColor3f(0.84,0.84,0.75);
    glLineWidth(7);
    glDisable(GL_LIGHTING);

    double moveY = head_angle > 0 ? 0 : sin(degToRad(head_angle))*50;

    // left tusk
    glPushMatrix();
    glTranslatef(1.0, -1.0-sin(degToRad(moveY)), 1.0-sin(degToRad(head_angle)));
    glRotatef(head_angle, 1, 0, 0);
    glBegin(GL_LINE_STRIP);
    double z = 0.0, y;
    while (z <= 0.9) {
       y = pow(z, 2) - z;
       glVertex3f(0.0,y,z);
       z+=0.1;
    }
    glEnd();
    glPopMatrix();

    // right tusk
    glPushMatrix();
    glTranslatef(-1.0, -1.0-sin(degToRad(moveY)), 1.0-sin(degToRad(head_angle)));
    glRotatef(head_angle, 1, 0, 0);
    glBegin(GL_LINE_STRIP);
    z = 0.0;
    while (z <= 0.9) {
       y = pow(z, 2) - z;
       glVertex3f(0.0,y,z);
       z+=0.1;
    }
    glEnd();
    glPopMatrix();

    glColor4f(1.f, 1.f, 1.f, 1.f);
    glEnable(GL_LIGHTING);
}

void Elephant::drawEyes() {
    glColor3f(0.1,0.1,0.1);

    double moveZ = head_angle < 0 ? 0 : head_angle/3;

    // left eye
    glPushMatrix();
    glTranslatef(0.7,-sin(degToRad(head_angle)),1.3-sin(degToRad(moveZ)));
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
   
    // right eye
    glPushMatrix();
    glTranslatef(-0.7,-sin(degToRad(head_angle)),1.3);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    glColor4f(1.f, 1.f, 1.f, 1.f);
}
