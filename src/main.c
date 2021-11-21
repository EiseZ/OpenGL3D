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

int main()
{
  GLFWwindow *window = init(1);
  if (window == NULL)
  {
    printf("Error: Failed initialization proces!\n");
  }

  // unsigned int tex = createTex("container.jpg");

  // unsigned int vbo = createVBO();
  // setBufferData(vbo, sizeof(vertices), vertices);

  // unsigned int vao = createVAO();
  // addAttrib(vao, vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  // addAttrib(vao, vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  // unsigned int ebo = createEBO();
  // setElementBufferData(ebo, sizeof(indices), indices);

  unsigned int shader = genShader();

  struct Camera cam = createCamera(90.0f, WIDTH, HEIGHT, 0.1f, 100.0f);
  calculateMVP(&cam);

  struct Block block = createBlock(1, 1, 1);
  struct Block block2 = createBlock(0, 0, 0);

  while (!glfwWindowShouldClose(window))
  {
    clearWindow(0.2f, 0.3f, 0.3f, 1.0f);

    // draw(cam, shader, vao, ebo, 0, sizeof(indices) / sizeof(unsigned int), 0);
    renderBlock(block, shader, cam);
    renderBlock(block2, shader, cam);

    glfwSwapBuffers(window);
    glfwPollEvents();
    processInput(window, &cam);
  }

  glfwTerminate();
  return 0;
}