#pragma once

#include <cglm/cglm.h>

#define CAM_MOVE_SPEED 0.01f
#define DIR_FOREWARD 1
#define DIR_LEFT 2
#define DIR_BACK 3
#define DIR_RIGHT 4
#define DIR_UP 5
#define DIR_DOWN 6

struct Camera
{
  vec3 pos;
  mat4 proj;
  mat4 view;
  mat4 model;
  mat4 mvp;
};

struct Camera createCamera(float fov, unsigned int width, unsigned int height, float ncp, float fcp);

void calculateMVP(struct Camera *cam);
void moveCamera(struct Camera *cam, unsigned int direction);
void rotateCamera(struct Camera *cam, double xOffset, double yOffset);