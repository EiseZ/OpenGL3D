#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vertexbuffer.h"

unsigned int createVAO();

void addAttrib(unsigned int vao, unsigned int vbo, unsigned int index, int size, unsigned int type, int stride, void *offset);

void bindVAO(unsigned int vao);
