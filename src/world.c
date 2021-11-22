#include "world.h"

struct World createWorld()
{
  struct World world;
  struct Chunk chunk;
  int chunkX = 0;
  int chunkY = 0;
  int chunkZ = 0;
  for (int x = 0; x < 16; x++)
  {
    for (int y = 0; y < 16; y++)
    {
      for (int z = 0; z < 16; z++)
      {
        chunk.blocks[x][y][z] = createBlock(x, y, z, chunkX, chunkY, chunkZ);
      }
    }
  }
  world.chunks[1] = chunk;
  return world;
}

void drawWord(struct World *world, unsigned int shader, struct Camera cam)
{
  for (int i = 0; i < sizeof(world->chunks) / sizeof(struct Chunk); i++)
  {
    drawChunk(world->chunks[i].blocks, shader, cam);
  }
}

void drawChunk(struct Block blocks[16][16][16], unsigned int shader, struct Camera cam)
{
  for (int x = 0; x < 16; x++)
  {
    for (int y = 0; y < 16; y++)
    {
      drawBlockArray(blocks[x][y], 16, shader, cam);
    }
  }
}