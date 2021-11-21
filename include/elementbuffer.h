#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

unsigned int createEBO();
void setElementBufferData(unsigned int ebo, long long int size, void *data);
void bindEBO(unsigned int ebo);