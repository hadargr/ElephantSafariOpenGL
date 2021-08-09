#define GL_SILENCE_DEPRECATION
#include "Elephant.h"

#define ANGLE_DELTA 5
#define WALK_DELTA 1
#define MAX_HEAD_ANGLE_VERTICAL 50
#define MIN_HEAD_ANGLE_VERTICAL -25
#define MAX_HEAD_ANGLE_HORIZONTAL 30
#define MAX_TAIL_ANGLE_HORIZONTAL 45

Elephant::Elephant(GLfloat x, GLfloat z) {
    this->x = x;
    this->z = z;
    this->angle = 0;
    this->head_angle_vertical = 0;
    this->head_angle_horizontal = 0;
    this->tail_angle_vertical = 0;
    this->tail_angle_horizontal = 0;
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
        if(head_angle_vertical > MIN_HEAD_ANGLE_VERTICAL) {
            head_angle_vertical -= ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_DOWN:
        if(head_angle_vertical < MAX_HEAD_ANGLE_VERTICAL) {
            head_angle_vertical += ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_RIGHT:
        if(head_angle_horizontal > -MAX_HEAD_ANGLE_HORIZONTAL) {
            head_angle_horizontal -= ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_LEFT:
        if(head_angle_horizontal < MAX_HEAD_ANGLE_HORIZONTAL) {
            head_angle_horizontal += ANGLE_DELTA;
        }
      break;
    default:
      break;
  }
}

void Elephant::moveTail(unsigned char key) {
switch (key)
  {
    case GLUT_KEY_DOWN:
        if(tail_angle_vertical > MIN_HEAD_ANGLE_VERTICAL) {
            tail_angle_vertical -= ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_UP:
        if(tail_angle_vertical < MAX_HEAD_ANGLE_VERTICAL) {
            tail_angle_vertical += ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_LEFT:
        if(tail_angle_horizontal > -MAX_TAIL_ANGLE_HORIZONTAL) {
            tail_angle_horizontal -= ANGLE_DELTA;
        }
      break;
    case GLUT_KEY_RIGHT:
        if(tail_angle_horizontal < MAX_TAIL_ANGLE_HORIZONTAL) {
            tail_angle_horizontal += ANGLE_DELTA;
        }
      break;
    default:
      break;
  }
}

void Elephant::draw() {
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
    glRotatef(head_angle_vertical, 1, 0, 0);
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glScalef(0.7,1,0.7);
    gluSphere(texQuad,2.0,20,20);
    glPopMatrix();
}

void Elephant::drawEars() {
    // left ear
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(2.5, 0.0, 0.0);
    glRotatef(head_angle_vertical, 1, 0, 0);
    glScalef(1,1,0.1);
    gluSphere(texQuad,1.8,20,20);
    glPopMatrix();

    // right ear
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(-2.5, 0.0, 0.0);
    glRotatef(head_angle_vertical, 1, 0, 0);
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
    glTranslatef(0.0, -1.1, -7.0);
    glRotatef(tail_angle_horizontal, 0, 1, 0);
    glRotatef(120,1,0,0);
    glRotatef(tail_angle_vertical, 1, 0, 0);
    gluCylinder(texQuad,0.1,0.1,1.9,20,20);
    glPopMatrix();
}

void Elephant::drawTrunk() {
    double moveZ = head_angle_vertical < 0 ? 0 : head_angle_vertical;
    // upper part
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(0.0, -0.2-sin(degToRad(head_angle_vertical)), 1.2-sin(degToRad(moveZ)));
    glRotatef(45,1,0,0);
    gluCylinder(texQuad,0.4,0.4,1.9,20,20);
    glPopMatrix();

    // lower part
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(0.0, -2.9-sin(degToRad(head_angle_vertical)), 1.1-sin(degToRad(moveZ)));
    glRotatef(-35,1,0,0);
    gluCylinder(texQuad,0.2,0.4,2.3,20,20);
    glPopMatrix();
}

void Elephant::drawTusks() {
    glColor3f(0.84,0.84,0.75);
    glLineWidth(7);
    glDisable(GL_LIGHTING);

    double moveY = head_angle_vertical > 0 ? 0 : sin(degToRad(head_angle_vertical))*50;

    // left tusk
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(1.0, -1.0-sin(degToRad(moveY)), 1.0-sin(degToRad(head_angle_vertical)));
    glRotatef(head_angle_vertical, 1, 0, 0);
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
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(-1.0, -1.0-sin(degToRad(moveY)), 1.0-sin(degToRad(head_angle_vertical)));
    glRotatef(head_angle_vertical, 1, 0, 0);
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

    double moveZ = head_angle_vertical < 0 ? 0 : head_angle_vertical/3;

    // left eye
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(0.7,-sin(degToRad(head_angle_vertical)),1.3-sin(degToRad(moveZ)));
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
   
    // right eye
    glPushMatrix();
    glRotatef(head_angle_horizontal, 0, 1, 0);
    glTranslatef(-0.7,-sin(degToRad(head_angle_vertical)),1.3);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    glColor4f(1.f, 1.f, 1.f, 1.f);
}
