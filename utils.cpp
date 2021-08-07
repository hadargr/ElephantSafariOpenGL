#define STB_IMAGE_IMPLEMENTATION
#include "utils.h"


unsigned int generateTexture(const char *filename, GLenum target) {
  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(target, texture);
  // set the texture wrapping/filtering options (on the currently bound texture object)
  glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);	
  glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV
 , GL_TEXTURE_ENV_MODE
 , GL_MODULATE
 );
  // load and generate the texture
  int width, height, nrChannels;
  unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
  if (data) {
      glTexImage2D(target, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(target);
  }
  stbi_image_free(data);
  return texture;
}

double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void drawText(string text, double posX, double posY, double red, double green, double blue, void* font) {
  glColor3f(red, green, blue);
  glRasterPos2f(posX,posY);
  for (int i=0; i < text.length(); i++) {
    glutBitmapCharacter(font, text[i]);
  }
  glColor3f(0, 0, 0);
}