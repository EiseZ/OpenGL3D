#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

unsigned int createTex(char *path)
{
  unsigned int tex;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);

  int width, height, nChannels;
  unsigned char *data = stbi_load(path, &width, &height, &nChannels, 0);

  int colorFormat;
  if (nChannels == 3)
  {
    colorFormat = GL_RGB;
  }
  else
  {
    colorFormat = GL_RGBA;
  }

  if (data)
  {
    glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, width, height, 0, colorFormat, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    printf("Error: Failed to load texture!\n");
  }
  stbi_image_free(data);
  return tex;
}

void bindTex(unsigned int tex)
{
  glBindTexture(GL_TEXTURE_2D, tex);
}