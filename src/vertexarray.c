#include "vertexarray.h"

unsigned int createVAO()
{
  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  return vao;
}

void addAttrib(unsigned int vao, unsigned int vbo, unsigned int index, int size, unsigned int type, int stride, void *offset)
{
  bindVAO(vao);
  bindVBO(vbo);

  // If the type is some type of int, use glVertexAttribIPointer, because openGL
  switch (type)
  {
  case GL_BYTE:
  case GL_UNSIGNED_BYTE:
  case GL_SHORT:
  case GL_UNSIGNED_SHORT:
  case GL_INT:
  case GL_UNSIGNED_INT:
  case GL_INT_2_10_10_10_REV:
  case GL_UNSIGNED_INT_2_10_10_10_REV:
    glVertexAttribIPointer(index, size, type, stride, (void *)offset);
    break;
  default:
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void *)offset);
    break;
  }

  glEnableVertexAttribArray(index);
}

void bindVAO(unsigned int vao)
{
  glBindVertexArray(vao);
}