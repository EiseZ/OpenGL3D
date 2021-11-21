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

  float vertices[] = {                                                   // and colors + texcoords
                      0.5f, 0.5f, -2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
                      0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
                      -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
                      -0.5f, 0.5f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f};

  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  unsigned int tex = createTex("container.jpg");

  unsigned int vbo = createVBO();
  setBufferData(vbo, sizeof(vertices), vertices);

  unsigned int vao = createVAO();
  addAttrib(vao, vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
  addAttrib(vao, vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float)));
  addAttrib(vao, vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float)));

  unsigned int ebo = createEBO();
  setElementBufferData(ebo, sizeof(indices), indices);

  unsigned int shader = genShader();

  struct Camera cam = createCamera(70.0f, WIDTH, HEIGHT, 0.1f, 100.0f);
  calculateMVP(&cam);

  while (!glfwWindowShouldClose(window))
  {
    clearWindow(0.2f, 0.3f, 0.3f, 1.0f);

    draw(cam, shader, vao, ebo, tex, 6, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
    processInput(window, &cam);
  }

  glfwTerminate();
  return 0;
}