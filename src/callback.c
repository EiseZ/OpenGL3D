#include "callback.h"

void errorCallback(const int err, const char *desc)
{
  printf("Error: %s\nCode: %d", desc, err);
}

void keypressCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  setKeyInput(window, key, action);
}

void mouseCallback(GLFWwindow *window, double x, double y)
{
  setMouseInput(x, y);
}