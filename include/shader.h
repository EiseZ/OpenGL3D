#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <stdio.h>

unsigned int genShader();

void uniformMatrix4f(unsigned int shader, char *name, mat4 mat);

int getUniformLocation(unsigned int shader, char *name);