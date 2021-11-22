#pragma once

#include "block.h"

struct Chunk
{
  struct Block blocks[16][16][16];
};

struct World
{
  struct Chunk chunks[1];
};

struct World createWorld();
void drawWord(struct World *world, unsigned int shader, struct Camera cam);
void drawChunk(struct Block blocks[16][16][16], unsigned int shader, struct Camera cam);