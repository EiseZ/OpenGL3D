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

int main()
{
  GLFWwindow *window = init(0);
  if (window == NULL)
  {
    printf("Error: Failed initialization proces!\n");
  }

  float vertices[] = {
      // front
      -1.0, -1.0, 1.0, 0.5f, 0.5f, 0.0f,
      1.0, -1.0, 1.0, 0.5f, 0.5f, 0.0f,
      1.0, 1.0, 1.0, 0.5f, 0.5f, 0.0f,
      -1.0, 1.0, 1.0, 0.5f, 0.5f, 0.0f,
      // back
      -1.0, -1.0, -1.0, 0.5f, 0.5f, 0.0f,
      1.0, -1.0, -1.0, 0.5f, 0.5f, 0.0f,
      1.0, 1.0, -1.0, 0.5f, 0.5f, 0.0f,
      -1.0, 1.0, -1.0, 0.5f, 0.5f, 0.0f //
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

  // unsigned int tex = createTex("container.jpg");

  unsigned int vbo = createVBO();
  setBufferData(vbo, sizeof(vertices), vertices);

  unsigned int vao = createVAO();
  addAttrib(vao, vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  addAttrib(vao, vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  unsigned int ebo = createEBO();
  setElementBufferData(ebo, sizeof(indices), indices);

  unsigned int shader = genShader();

  struct Camera cam = createCamera(70.0f, WIDTH, HEIGHT, 0.1f, 100.0f);
  calculateMVP(&cam);

  while (!glfwWindowShouldClose(window))
  {
    clearWindow(0.2f, 0.3f, 0.3f, 1.0f);

    draw(cam, shader, vao, ebo, 0, 6 * 6, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
    processInput(window, &cam);
  }

  glfwTerminate();
  return 0;
}