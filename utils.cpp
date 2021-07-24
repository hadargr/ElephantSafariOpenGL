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