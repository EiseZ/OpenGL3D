#pragma once

#include <GLFW/glfw3.h>
#include <stdio.h>

#include "inputHandler.h"

void errorCallback(const int err, const char *desc);
void keypressCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow *window, double x, double y);