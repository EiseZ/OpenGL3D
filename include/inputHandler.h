#pragma once

#include <GLFW/glfw3.h>

#include "camera.h"

#define MOUSE_SENSITIVITY 0.1f

void setKeyInput(GLFWwindow *window, int key, int action);
void setMouseInput(double x, double y);
void processInput(GLFWwindow *window, struct Camera *cam);