#define GL_SILENCE_DEPRECATION
#include "Light.h"

Light::Light(GLfloat x, GLfloat y, GLfloat z, GLenum lightId) {
	this->x = x;
	this->y = y;
	this->z = z;
  	this->lightId = lightId;
}

void Light::draw() {
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	// add light
	GLfloat light_position[] = { x, y, z, 1.0 };
	glEnable(lightId);
	glLightfv(lightId, GL_DIFFUSE, diffuse);
	glLightfv(lightId, GL_SPECULAR, specular);
	glLightfv(lightId, GL_AMBIENT, ambient);
	glLightfv(lightId, GL_POSITION, light_position);
}

GLfloat* Light::getAmbient() {
	return ambient;
}

void Light::setAmbientRed(bool increase) {
	if ((increase && ambient[0] == 1) || (!increase && ambient[0] == 0)) {
		return;
	}
	ambient[0] = increase ? ambient[0] + 0.1 : ambient[0] - 0.1;

}

void Light::setAmbientGreen(bool increase) {
	if ((increase && ambient[1] == 1) || (!increase && ambient[1] == 0)) {
		return;
	}
	ambient[1] = increase ? ambient[1] + 0.1 : ambient[1] - 0.1;
}

void Light::setAmbientBlue(bool increase) {
	if ((increase && ambient[2] == 1) || (!increase && ambient[2] == 0)) {
		return;
	}
	ambient[2] = increase ? ambient[2] + 0.1 : ambient[2] - 0.1;
}

void Light::setAmbient(bool increase) {
	setAmbientRed(increase);
	setAmbientGreen(increase);
	setAmbientBlue(increase);
}