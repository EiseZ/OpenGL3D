#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

unsigned int createVBO();
void setBufferData(unsigned int vbo, long long int size, void *data);
void bindVBO(unsigned int vbo);