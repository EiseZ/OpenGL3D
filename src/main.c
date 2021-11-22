#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "shader.h"
#include "renderer.h"
#include "camera.h"
#include "vertexarray.h"
#include "elementbuffer.h"
#include "vertexbuffer.h"
#include "texture.h"
#include "block.h"
#include "world.h"

int main()
{
  GLFWwindow *window = init(1);
  if (window == NULL)
  {
    printf("Error: Failed initialization proces!\n");
  }

  unsigned int shader = genShader();

  struct Camera cam = createCamera(90.0f, WIDTH, HEIGHT, 0.1f, 100.0f);
  calculateMVP(&cam);

  // struct Block blocks[] = {
  //     createBlock(0, 0, 0),
  //     createBlock(1, 1, 1),
  //     createBlock(2, 1, 1),
  //     createBlock(3, 1, 1),
  //     createBlock(4, 1, 1),
  //     createBlock(5, 1, 1),
  // };
  struct World world = createWorld();

  while (!glfwWindowShouldClose(window))
  {
    clearWindow(0.2f, 0.3f, 0.3f, 1.0f);

    // drawBlockArray(blocks, sizeof(blocks) / sizeof(struct Block), shader, cam);
    drawWord(&world, shader, cam);

    glfwSwapBuffers(window);
    glfwPollEvents();
    processInput(window, &cam);
  }

  glfwTerminate();
  return 0;
}