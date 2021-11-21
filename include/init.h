#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "callback.h"

#define WIDTH 800
#define HEIGHT 600

GLFWwindow* init(int enableWireframe);