#include "elementbuffer.h"

unsigned int createEBO()
{
  unsigned int ebo;
  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  return ebo;
}

void setElementBufferData(unsigned int ebo, long long int size, void *data)
{
  bindEBO(ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void bindEBO(unsigned int ebo)
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}