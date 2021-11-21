#include "vertexbuffer.h"

unsigned int createVBO()
{
  unsigned int vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  return vbo;
}

void setBufferData(unsigned int vbo, long long int size, void *data)
{
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void bindVBO(unsigned int vbo)
{
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
}