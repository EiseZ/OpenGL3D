#include "block.h"

float vertices[] = {
    // front
    -1.0, -1.0, 1.0,
    1.0, -1.0, 1.0,
    1.0, 1.0, 1.0,
    -1.0, 1.0, 1.0,
    // back
    -1.0, -1.0, -1.0,
    1.0, -1.0, -1.0,
    1.0, 1.0, -1.0,
    -1.0, 1.0, -1.0 //
};

unsigned int indices[] = {
    // front
    0, 1, 2,
    2, 3, 0,
    // right
    1, 5, 6,
    6, 2, 1,
    // back
    7, 6, 5,
    5, 4, 7,
    // left
    4, 0, 3,
    3, 7, 4,
    // bottom
    4, 5, 1,
    1, 0, 4,
    // top
    3, 2, 6,
    6, 7, 3 //
};

struct Block createBlock(int xPos, int yPos, int zPos)
{
  struct Block block;
  block.xPos = xPos;
  block.yPos = yPos;
  block.zPos = zPos;
  return block;
}

void renderBlock(struct Block block, unsigned int shader, struct Camera cam)
{
  float currentVertices[24];
  for (int i = 0; i < sizeof(vertices) / sizeof(float); i++)
  {
    if (i % 3 == 1)
    {
      currentVertices[i] = vertices[i] + 2 * block.xPos;
    }
    else if (i % 3 == 2)
    {
      currentVertices[i] = vertices[i] + 2 * block.yPos;
    }
    else if (i % 3 == 0)
    {
      currentVertices[i] = vertices[i] + 2 * block.zPos;
    }
  }

  unsigned int vbo = createVBO();
  setBufferData(vbo, sizeof(currentVertices), currentVertices);

  unsigned int vao = createVAO();
  addAttrib(vao, vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);

  unsigned int ebo = createEBO();
  setElementBufferData(ebo, sizeof(indices), indices);

  draw(cam, shader, vao, ebo, 0, sizeof(indices) / sizeof(unsigned int), 0);
}