#include "inputHandler.h"

int esc = 0;
int w = 0;
int a = 0;
int s = 0;
int d = 0;
int space = 0;
int shift = 0;

double currentMouseX = 0;
double currentMouseY = 0;
double lastMouseX = 0;
double lastMouseY = 0;
double xOffset = 0;
double yOffset = 0;

void setKeyInput(GLFWwindow *window, int key, int action)
{
  if (action == GLFW_PRESS || action == GLFW_RELEASE)
  {
    switch (key)
    {
    case GLFW_KEY_ESCAPE:
      esc = !esc;
      break;
    case GLFW_KEY_W:
      w = !w;
      break;
    case GLFW_KEY_A:
      a = !a;
      break;
    case GLFW_KEY_S:
      s = !s;
      break;
    case GLFW_KEY_D:
      d = !d;
      break;
    case GLFW_KEY_SPACE:
      space = !space;
      break;
    case GLFW_KEY_LEFT_SHIFT:
    case GLFW_KEY_RIGHT_SHIFT:
      shift = !shift;
      break;
    }
  }
}

void setMouseInput(double x, double y)
{
  currentMouseX = x;
  currentMouseY = y;
}

void processInput(GLFWwindow *window, struct Camera *cam)
{
  if (esc)
  {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
  if (w)
  {
    moveCamera(cam, DIR_FOREWARD);
  }
  if (a)
  {
    moveCamera(cam, DIR_LEFT);
  }
  if (s)
  {
    moveCamera(cam, DIR_BACK);
  }
  if (d)
  {
    moveCamera(cam, DIR_RIGHT);
  }
  if (space)
  {
    moveCamera(cam, DIR_UP);
  }
  if (shift)
  {
    moveCamera(cam, DIR_DOWN);
  }

  xOffset = currentMouseX - lastMouseX;
  yOffset = lastMouseY - currentMouseY;
  lastMouseX = currentMouseX;
  lastMouseY = currentMouseY;
  xOffset *= MOUSE_SENSITIVITY;
  yOffset *= MOUSE_SENSITIVITY;
  rotateCamera(cam, xOffset, yOffset);
}