#include "camera.h"

vec3 cameraPos = {0.0f, 0.0f, 0.0f};
vec3 cameraFront = {0.0f, 0.0f, -1.0f};
vec3 cameraUp = {0.0f, 1.0f, 0.0f};

float yaw = -90.0f;
float pitch = 0.0f;

struct Camera createCamera(float fov, unsigned int width, unsigned int height, float ncp, float fcp)
{
  struct Camera cam;
  glm_perspective(glm_rad(fov), (float)width / (float)height, ncp, fcp, cam.proj);
  vec3 target;
  glm_vec3_add(cameraPos, cameraFront, target);
  glm_lookat(cameraPos, target, cameraUp, cam.view);
  glm_mat4_identity(cam.model);
  return cam;
}

void calculateMVP(struct Camera *cam)
{
  vec3 target;
  glm_vec3_add(cameraPos, cameraFront, target);
  glm_lookat(cameraPos, target, cameraUp, cam->view);
  glm_mat4_mulN((mat4 *[]){&cam->proj, &cam->view, &cam->model}, 3, cam->mvp);
}

void moveCamera(struct Camera *cam, unsigned int direction)
{
  vec3 tempVec;
  switch (direction)
  {
  case DIR_FOREWARD:
    glm_vec3_scale(cameraFront, CAM_MOVE_SPEED, tempVec);
    glm_vec3_add(cameraPos, tempVec, cameraPos);
    break;
  case DIR_BACK:
    glm_vec3_scale(cameraFront, CAM_MOVE_SPEED, tempVec);
    glm_vec3_sub(cameraPos, tempVec, cameraPos);
    break;
  case DIR_LEFT:
    glm_vec3_cross(cameraFront, cameraUp, tempVec);
    glm_normalize(tempVec);
    glm_vec3_scale(tempVec, CAM_MOVE_SPEED, tempVec);
    glm_vec3_sub(cameraPos, tempVec, cameraPos);
    break;
  case DIR_RIGHT:
    glm_vec3_cross(cameraFront, cameraUp, tempVec);
    glm_normalize(tempVec);
    glm_vec3_scale(tempVec, CAM_MOVE_SPEED, tempVec);
    glm_vec3_add(cameraPos, tempVec, cameraPos);
    break;
  case DIR_UP:
    glm_vec3_scale(cameraUp, CAM_MOVE_SPEED, tempVec);
    glm_vec3_add(cameraPos, tempVec, cameraPos);
    break;
  case DIR_DOWN:
    glm_vec3_scale(cameraUp, CAM_MOVE_SPEED, tempVec);
    glm_vec3_sub(cameraPos, tempVec, cameraPos);
    break;
  }
  calculateMVP(cam);
}

void rotateCamera(struct Camera *cam, double xOffset, double yOffset)
{
  yaw += xOffset;
  pitch += yOffset;

  if (pitch > 89.0f)
    pitch = 89.0f;
  if (pitch < -89.0f)
    pitch = -89.0f;

  vec3 direction;
  direction[0] = cos(glm_rad(yaw)) * cos(glm_rad(pitch));
  direction[1] = sin(glm_rad(pitch));
  direction[2] = sin(glm_rad(yaw)) * cos(glm_rad(pitch));
  glm_normalize(direction);
  glm_vec3_copy(direction, cameraFront);
  calculateMVP(cam);
}