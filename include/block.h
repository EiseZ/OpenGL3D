#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "renderer.h"

struct Block
{
  int xPos;
  int yPos;
  int zPos;
  int chunkX;
  int chunkY;
  int chunkZ;
};

struct Block createBlock(int xPos, int yPos, int zPos, int chunkX, int chunkY, int chunkZ);
void drawBlock(struct Block block, unsigned int shader, struct Camera cam);
void drawBlockArray(struct Block blocks[], unsigned int blockAmount, unsigned int shader, struct Camera cam);