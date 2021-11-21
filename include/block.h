#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "renderer.h"

struct Block
{
  int xPos;
  int yPos;
  int zPos;
};

struct Block createBlock(int xPos, int yPos, int zPos);
void renderBlock(struct Block block, unsigned int shader, struct Camera cam);