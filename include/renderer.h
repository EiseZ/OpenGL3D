#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.h"
#include "shader.h"
#include "vertexarray.h"
#include "elementbuffer.h"
#include "texture.h"

void clearWindow(float f1, float f2, float f3, float f4);
void draw(struct Camera cam, unsigned int shader, unsigned int vao, unsigned int ebo, unsigned int tex /* optional */, int count, void *indices);